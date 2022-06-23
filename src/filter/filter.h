#include <vector>
#include "../nodes/nodes.h"

/**
 * @brief Clase Filter para realizar el filtrado de
 * 				espacio de busqueda en cada iteracion y
 * 				almacenar la informacion de dihco filtrado
 * 
 */
class Filter {
	private:
		/**
		 * @brief Atributos
		 * searchSpace					- espacio de busqueda a filtrar
		 * notFilterSearchSpace	-	conjunto de nodos no filtrados
		 * depot								- nodo de deposito
		 * currentNode					- nodo actual
		 * 
		 */
		vector<Node> searchSpace;
		vector<Node> notFilterSearchSpace;
		Node depot;
		Node currentNode;
		/**
		 * @brief Calcula la distancia entre dos puntos de la
		 * 				superficie terrestre
		 * 
		 * @param r 
		 * @param longitude1	Coordenada de longitud del punto 1
		 * @param longitude2	Coordenada de longitud del punto 2
		 * @param latitude1 	Coordenada de latitud del punto 1
		 * @param latitude2 	Coordenada de latitud del punto 2
		 * @return double 		Distancia entre los puntos 1 y 2
		 */
		double haversineFormula(
			double r, double longitude1, double longitude2, double latitude1, double latitude2
		);
		/**
		 * @brief Corrobora si hay combustible suficiente de un punto a otro
		 * 
		 * @param node1 								Punto 1
		 * @param node2 								Punto 2
		 * @param currentTankAvailable	Nivel actual del estanque
		 * @return true 								Si hay combustible suficiente
		 * @return false 								Si no hay combustible suficiente
		 */
		bool enoughTankNodeToNode(Node node1, Node node2, double currentTankAvailable);
		/**
		 * @brief Corrobora si hay tiempo suficiente para ir de un punto a otro
		 * 
		 * @param node1 								Punto 1
		 * @param node2 								Punto 2
		 * @param currentTimeAvailable	Tiempo disponible actualmente
		 * @param speed 								Velocidad constante de los vehiculos
		 * @param serviceTime 					Tiempo de servicio al cliente
		 * @param refuelTime 						Tiempo de recarga de combustible
		 * @return true 								Si hay tiempo suficiente
		 * @return false 								Si no hay tiempo suficiente
		 */
		bool enoughTimeNodeToNode(
			Node node1, Node node2, double currentTimeAvailable, double speed, double serviceTime, double refuelTime
		);
	public:
		// constructor
		Filter(
			vector<Node> ss, 
			vector<Node> nfss, 
			Node d, 
			Node cn
		);
		// setters
		void setSearchSpace(vector<Node> ss);
		void setNotFilterSearchSpace(vector<Node> nfss);
		void setDepot(Node d);
		void setCurrentNode(Node cn);
		// getters
		vector<Node> getSearchSpace();
		vector<Node> getNotFilterSearchSpace();
		Node getDepot();
		Node getCurrentNode();
		/**
		 * @brief Obtiene la distancia entre dos puntos
		 * 
		 * @param node1 	Punto 1
		 * @param node2 	Punto 2
		 * @return double	Distancia entre puntos 1 y 2
		 */
		double getDistanceNodeToNode(Node node1, Node node2);
		/**
		 * @brief Obtiene el tiempo entre dos puntos
		 * 
		 * @param node1 	Punto 1
		 * @param node2 	Punto 2
		 * @param speed 	Velocidad constante de los vehiculos
		 * @return double	Tiempo entre puntos 1 y 2
		 */
		double getTimeNodeToNode(Node node1, Node node2, double speed);
		/**
		 * @brief filtra el espacio de busqueda
		 * 
		 * @param currentTimeAvailable	Tiempo disponible actualmente
		 * @param currentTankAvailable 	Nivel del estanque actualmente
		 * @param speed 								Velocidad constante de los vehiculos
		 * @param serviceTime 					Tiempo de servicio al cliente
		 * @param refuelTime 						Tiempo de recarga de combustible
		 */
		void filterSearchSpace(
			double currentTimeAvailable, double currentTankAvailable, double speed, double serviceTime, double refuelTime
		);
};