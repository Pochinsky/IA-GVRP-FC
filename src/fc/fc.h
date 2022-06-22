#include <vector>
#include "../instance/instance.h"
#include "../filter/filter.h"

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

void forwardChecking(
	double maxTime,
	double maxDistance,
	double speed,
	double serviceTime,
	double refuelTime,
	Node depot,
	vector<Node> refuelNodes,
	vector<Node> customerNodes
);

