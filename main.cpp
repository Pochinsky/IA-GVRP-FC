#include <iostream>
#include <fstream>
#include <vector>
#include "src/fc/fc.h"

using namespace std;

int main() {
	string fileName      		   = "./Instancias/AB101.dat";
	Instance instance 			   = extractInstanceData(fileName);
	// Set parameters of forward checking algorithm
	double maxTime			 		   = instance.getMaxTime();
	double maxDistance	 		   = instance.getMaxDistance();
	double speed				 		   = instance.getSpeed();
	double serviceTime	 		   = instance.getServiceTime();
	double refuelTime  	 		   = instance.getRefuelTime();
	Node depot 	 				     	 = extractDepot(fileName);
	vector<Node> refuelNodes 	 = extractRefuelNodes(fileName);
	vector<Node> customerNodes = extractCustomerNodes(fileName);
	forwardChecking(
		maxTime,
		maxDistance,
		speed,
		serviceTime,
		refuelTime,
		depot,
		refuelNodes,
		customerNodes
	);
	return 0;
}