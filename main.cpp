#include <iostream>
#include <fstream>
#include <vector>
#include "src/fc/fc.h"

using namespace std;

int main() {
	string filename      = "./Instancias/AB101.dat";
	Instance newInstance = extractInstanceData(filename);
	vector<Node> nodes 	 = extractNodes(filename);
	forwardChecking(newInstance,nodes);
	return 0;
}