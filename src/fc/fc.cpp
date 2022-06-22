#include <math.h>
#include <chrono>
#include "fc.h"

using namespace std::chrono;

/**
 * Constructor of Memory class
 */
Memory::Memory(Node n, vector<Node> nf) {
	setNode(n);
	setNodesFiltered(nf);
}

/**
 * Setters of Memory class
 */
void Memory::setNode(Node n) { node = n; }
void Memory::setNodesFiltered(vector<Node> nf) { nodesFiltered = nf; }

/**
 * Helpers to forwardChecking function
 */

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
	int vehicles 					 = 0;
	// helpers variables
	double currentTimeAvailable     = maxTime;
	double currentTankAvailable     = maxDistance;
	Node currentNode						    = depot;
	vector<Node> notFilterRefuel    = refuelNodes;
	vector<Node> notFilterCustomers = customerNodes;
	vector<Filter> memoryRefuel;
	vector<Filter> memoryCustomers;
	// forward checking in action
	// example to first iteration
	// 1. filtrar
	Filter refuel(refuelNodes,notFilterRefuel,depot,currentNode);
	Filter customers(customerNodes,notFilterCustomers,depot,currentNode);
}