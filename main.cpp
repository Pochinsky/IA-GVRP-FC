#include <iostream>
#include <fstream>
#include <vector>
#include "src/instance/instance.h"
#include "src/list/list.h"

using namespace std;

int main() {
	string filename      = "./Instancias/AB101.dat";
	Instance newInstance = extractInstanceData(filename);
	vector<Node> nodes 	 = extractNodes(filename);
	return 0;
}