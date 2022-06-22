#include <iostream>
#include <vector>
#include "../node/node.h"

using namespace std;

Node extractDepot(string fileName);
vector<Node> extractRefuelNodes(string fileName);
vector<Node> extractCustomerNodes(string fileName);
vector<Node> removeElementById(vector<Node> nodes, int id);