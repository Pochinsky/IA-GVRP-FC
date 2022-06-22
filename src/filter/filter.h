#include <vector>
#include "../nodes/nodes.h"

class Filter {
	private:
		vector<Node> searchSpace;
		vector<Node> notFilterSearchSpace;
		vector<vector<Node>> memoryOfIteration;
		Node depot;
		Node currentNode;
		double getTimeNodeToNode(Node node1, Node node2, double speed);
		double haversineFormula(
			double r, double longitude1, double longitude2, double latitude1, double latitude2
		);
		double getDistanceNodeToNode(Node node1, Node node2);
		bool enoughTankNodeToNode(Node node1, Node node2, double currentTankAvailable);
		double getTimeNodeToNode(Node node1, Node node2, double speed);
		bool enoughTimeNodeToNode(Node node1, Node node2, double currentTimeAvailable, double speed);
	public:
		// constructor
		Filter(
			vector<Node> ss, 
			vector<Node> nfss, 
			vector<vector<Node>> moi,
			Node d, 
			Node cn
		);
		// setters
		void setSearchSpace(vector<Node> ss);
		void setNotFilterSearchSpace(vector<Node> nfss);
		void setDepot(Node d);
		void setCurrentNode(Node cn);
		// getters
		vector<Node> getSearchSpace();
		vector<Node> getNotFilterSearchSpace();
		Node getDepot();
		Node getCurrentNode();

		void filterSearchSpace(double currentTimeAvailable, double currentTankAvailable, double speed);
};