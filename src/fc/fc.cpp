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

double toRadians(double degrees) {
	return (M_PI/180)*degrees;
}

double haversineDistance(Node n1, Node n2) {
	double R 							= 4182.44949;
	double deltaLongitude = toRadians(n1.getLongitude() - n2.getLongitude());
	double deltaLatitude  = toRadians(n1.getLatitude()  - n2.getLatitude());
	double sqrtArgument   = 
		pow(sin(deltaLatitude/2),2.0) + cos(n1.getLatitude())*cos(n2.getLatitude())*pow(sin(deltaLongitude/2),2.0);
	double d = 2*R*asin(sqrt(sqrtArgument));
	return d;
}

void forwardChecking(Instance instance, vector<Node> nodes) {
	double distance = 0;
	int customersAttended = 0;
	int vehicles = 0;
	Node currentNode = nodes.front();
	nodes.erase(nodes.begin());
	int currentDistance = 0;
	auto start = high_resolution_clock::now();
	while (true) {
		/**
		 * Filter search space
		 */
		
	}
}