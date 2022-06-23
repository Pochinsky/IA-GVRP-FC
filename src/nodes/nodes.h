#include <iostream>
#include <vector>
#include "../node/node.h"

using namespace std;

/**
 * @brief Extrae el nodo de deposito del archivo
 * 
 * @param fileName	Nombre del archivo de entrada
 * @return Node 		Nodo de deposito
 */
Node extractDepot(string fileName);
/**
 * @brief Extrae todos los nodos de estaciones de recarga
 * 
 * @param fileName 			archivo de entrada
 * @return vector<Node>	Conjunto de estaciones de recarga
 */
vector<Node> extractRefuelNodes(string fileName);
/**
 * @brief Extrae todos los nodos de clientes
 * 
 * @param fileName 			Archivo de entrada
 * @return vector<Node> Conjunto de clientes
 */
vector<Node> extractCustomerNodes(string fileName);
/**
 * @brief elimina un nodo de un conjunto de nodos segun id
 * 
 * @param nodes 				Conjunto de nodos
 * @param id 						Id del nodo a eliminar
 * @return vector<Node> Conjunto de nodos con el nodo buscado
 * 											por id eliminado
 */
vector<Node> removeElementById(vector<Node> nodes, int id);