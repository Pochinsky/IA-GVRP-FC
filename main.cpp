#include <iostream>
#include <fstream>
#include <vector>
#include "src/fc/fc.h"

using namespace std;

int main() {
	string fileName      = "./Instancias/AB101.dat";
	Instance newInstance = extractInstanceData(fileName);
	vector<Node> nodes 	 = extractNodes(fileName);
	forwardChecking(newInstance,nodes);
	return 0;
}