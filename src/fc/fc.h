#include <vector>
#include "../instance/instance.h"
#include "../filter/filter.h"

/**
 * @brief Algoritmo forward checking para la resolucion del GVRP.
 * 
 * @details El algoritmo no esta iterando, pues solo se logro
 * 					implementar el filtrado del espacio de busqueda y
 * 					los casos de elegir un cliente o una estacion de
 * 					recarga como siguiente nodo.
 * 
 * @param maxTime 			Tiempo maximo de servicio
 * @param maxDistance 	Distancia maxima que pueden recorrer
 * 											los vehiculos segun varia el estanque
 * @param speed 				Velocidad constante, en [mile/min]
 * 											de todos los vehiculos
 * @param serviceTime 	Tiempo de servicio al cliente
 * @param refuelTime 		Tiempo de recarga
 * @param depot 				Nodo correspondiente al deposito
 * @param refuelNodes 	Conjunto de nodos que corresponden 
 * 											a estaciones de recarga
 * @param customerNodes	Conjunto de nodos que corresponden 
 * 											a clientes
 * @todo Falta construir el procedimiento de volver atras,
 * 			 detectar soluciones, etc. y, por ende, lo que resta
 * 			 del algoritmo.
 * 
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
);

