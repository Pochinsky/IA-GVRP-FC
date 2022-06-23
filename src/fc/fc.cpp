#include <math.h>
#include <chrono>
#include "fc.h"
#include "../vehicle/vehicle.h"

using namespace std::chrono;

void forwardChecking(
	double maxTime,
	double maxDistance,
	double speed,
	double serviceTime,
	double refuelTime,
	Node depot,
	vector<Node> refuelNodes,
	vector<Node> customerNodes
) {
	// Variables a usar para construir la solucion
	double solutionQuality = 0; // [mile]
	int customersAttended  = 0;
	int nVehicles					 = 1;
	Vehicle currentVehicle(nVehicles,0.0,0.0,0.0);
	vector<Vehicle> allVehicles;
	// Variables 'helpers'
	double currentTimeAvailable     = maxTime;
	double currentTankAvailable     = maxDistance;
	Node currentNode						    = depot;
	vector<Node> notFilterRefuel    = refuelNodes;
	vector<Node> notFilterCustomers = customerNodes;
	vector<Filter> memoryRefuel;
	vector<Filter> memoryCustomers;
	// Ejecucion de forward checking
	while (true) {
		// 1. Filtrar
		Filter refuel(refuelNodes,notFilterRefuel,depot,currentNode);
		refuel.filterSearchSpace(currentTimeAvailable,currentTankAvailable,speed,serviceTime,refuelTime);
		Filter customers(customerNodes,notFilterCustomers,depot,currentNode);
		customers.filterSearchSpace(currentTimeAvailable,currentTankAvailable,speed,serviceTime,refuelTime);
		// 2. Chequear dominio vacio
		if (customers.getNotFilterSearchSpace().empty() && refuel.getNotFilterSearchSpace().empty()) {
			// 2.a. Go back
		}
		else if (!customers.getNotFilterSearchSpace().empty()) {
			// 3.a. Elegir un nodo cliente y establecer parametros para la nueva iteracion
			currentNode				 = customers.getNotFilterSearchSpace().front();
			// Guardar dominios
			notFilterCustomers = customers.getNotFilterSearchSpace();
			notFilterRefuel 	 = refuel.getNotFilterSearchSpace();
			vector<Node> copyOfNotFilterCustomers = notFilterCustomers;
			copyOfNotFilterCustomers.erase(copyOfNotFilterCustomers.begin());
			customers.setNotFilterSearchSpace(copyOfNotFilterCustomers);
			notFilterCustomers = customers.getNotFilterSearchSpace();
			// Memorizar dominios
			memoryCustomers.push_back(customers);
			memoryRefuel.push_back(refuel);
			// Actualizar nivel del estanque
			currentTankAvailable -= refuel.getDistanceNodeToNode(customers.getCurrentNode(),currentNode);
			// Actualizar tiempo de servicio restante
			currentTimeAvailable -= customers.getTimeNodeToNode(customers.getCurrentNode(),currentNode,speed);
			currentTimeAvailable -= serviceTime;
			// Actualizar la calidad de la solucion
			solutionQuality += customers.getDistanceNodeToNode(customers.getCurrentNode(),currentNode);
			customersAttended++;
			// Actualizar los datos del vehiculo
			currentVehicle.setDistanceTraveled(
				currentVehicle.getDistanceTraveled()+customers.getDistanceNodeToNode(customers.getCurrentNode(),currentNode)
			);
			currentVehicle.setTimeElapsed(
				currentVehicle.getTimeElapsed()+customers.getTimeNodeToNode(customers.getCurrentNode(),currentNode,speed)
			);
		}
		else {
			// 3.b. Elegir un nodo estacion de recarga y establecer parametros para la nueva iteracion
			currentNode				 = refuel.getNotFilterSearchSpace().front();
			// Guardar dominios
			notFilterCustomers = customers.getNotFilterSearchSpace();
			notFilterRefuel 	 = refuel.getNotFilterSearchSpace();
			vector<Node> copyOfNotFilterRefuel = notFilterRefuel;
			copyOfNotFilterRefuel.erase(copyOfNotFilterRefuel.begin());
			refuel.setNotFilterSearchSpace(copyOfNotFilterRefuel);
			notFilterRefuel = refuel.getNotFilterSearchSpace();
			// Memorizar dominios
			memoryCustomers.push_back(customers);
			memoryRefuel.push_back(refuel);
			// Actualizar nivel del estanque
			currentTankAvailable = maxDistance;
			// Actualizar tiempo de servicio restante
			currentTimeAvailable -= refuel.getTimeNodeToNode(refuel.getCurrentNode(),currentNode,speed);
			currentTimeAvailable -= refuelTime;
			// Actualizar la calidad de la solucion
			solutionQuality += refuel.getDistanceNodeToNode(refuel.getCurrentNode(),currentNode);
			// Actualizar los datos del vehiculo
			currentVehicle.setDistanceTraveled(
				currentVehicle.getDistanceTraveled()+refuel.getDistanceNodeToNode(refuel.getCurrentNode(),currentNode)
			);
			currentVehicle.setTimeElapsed(
				currentVehicle.getTimeElapsed()+refuel.getTimeNodeToNode(refuel.getCurrentNode(),currentNode,speed)
			);
		}
		break;
	}
}