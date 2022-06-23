#include <math.h>
#include <chrono>
#include "fc.h"
#include "../vehicle/vehicle.h"

using namespace std::chrono;

/**
 * Forward checking algorithm
 */
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
	// solution variables
	double solutionQuality = 0; // [mile]
	int costumersAttended  = 0;
	int nVehicles					 = 1;
	Vehicle currentVehicle(nVehicles,0.0,0.0,0.0);
	vector<Vehicle> allVehicles;
	// helpers variables
	double currentTimeAvailable     = maxTime;
	double currentTankAvailable     = maxDistance;
	Node currentNode						    = depot;
	vector<Node> notFilterRefuel    = refuelNodes;
	vector<Node> notFilterCustomers = customerNodes;
	vector<Filter> memoryRefuel;
	vector<Filter> memoryCustomers;
	// forward checking in action
	while (true) {
		// 1. filter
		Filter refuel(refuelNodes,notFilterRefuel,depot,currentNode);
		refuel.filterSearchSpace(currentTimeAvailable,currentTankAvailable,speed,serviceTime,refuelTime);
		Filter customers(customerNodes,notFilterCustomers,depot,currentNode);
		customers.filterSearchSpace(currentTimeAvailable,currentTankAvailable,speed,serviceTime,refuelTime);
		// 2. check empty domain
		if (customers.getNotFilterSearchSpace().empty() && refuel.getNotFilterSearchSpace().empty()) {
			// 2.a. go back

		}
		else if (!customers.getNotFilterSearchSpace().empty()) {
			// 3.a. choice a customer node and set parameters for new iteration
			currentNode				 = customers.getNotFilterSearchSpace().front();
			// save domains
			notFilterCustomers = customers.getNotFilterSearchSpace();
			notFilterRefuel 	 = refuel.getNotFilterSearchSpace();
			vector<Node> copyOfNotFilterCustomers = notFilterCustomers;
			copyOfNotFilterCustomers.erase(copyOfNotFilterCustomers.begin());
			customers.setNotFilterSearchSpace(copyOfNotFilterCustomers);
			notFilterCustomers = customers.getNotFilterSearchSpace();
			// memorize domains
			memoryCustomers.push_back(customers);
			memoryRefuel.push_back(refuel);
			// update tank available
			currentTankAvailable -= refuel.getDistanceNodeToNode(customers.getCurrentNode(),currentNode);
			// update time available
			currentTimeAvailable -= customers.getTimeNodeToNode(customers.getCurrentNode(),currentNode,speed);
			currentTimeAvailable -= serviceTime;
			// update vehicle data
			currentVehicle.setDistanceTraveled(
				currentVehicle.getDistanceTraveled()+customers.getDistanceNodeToNode(customers.getCurrentNode(),currentNode)
			);
			currentVehicle.setTimeElapsed(
				currentVehicle.getTimeElapsed()+customers.getTimeNodeToNode(customers.getCurrentNode(),currentNode,speed)
			);
		}
		else {
			// 3.b. choice a refuel and set parameters for new iteration
			currentNode				 = refuel.getNotFilterSearchSpace().front();
			// save domains
			notFilterCustomers = customers.getNotFilterSearchSpace();
			notFilterRefuel 	 = refuel.getNotFilterSearchSpace();
			vector<Node> copyOfNotFilterRefuel = notFilterRefuel;
			copyOfNotFilterRefuel.erase(copyOfNotFilterRefuel.begin());
			refuel.setNotFilterSearchSpace(copyOfNotFilterRefuel);
			notFilterRefuel = refuel.getNotFilterSearchSpace();
			// memorize domains
			memoryCustomers.push_back(customers);
			memoryRefuel.push_back(refuel);
			// udpate tank available
			currentTankAvailable = maxDistance;
			// update time available
			currentTimeAvailable -= refuel.getTimeNodeToNode(refuel.getCurrentNode(),currentNode,speed);
			currentTimeAvailable -= refuelTime;
			// update solution quality
			solutionQuality += refuel.getDistanceNodeToNode(refuel.getCurrentNode(),currentNode);
			// update vehicle data
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