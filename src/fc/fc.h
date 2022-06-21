#include <vector>
#include "../instance/instance.h"
#include "../list/list.h"

class Memory {
	private:
		Node node;
		vector<Node> nodesFiltered;
	public:
		// constructor
		Memory(Node n, vector<Node> nf);
		// setters
		void setNode(Node n);
		void setNodesFiltered(vector<Node> nf);
};

double toRadians(double degrees);
double haversineDistance(Node n1, Node n2);
void forwardChecking(Instance instance, vector<Node> nodes);