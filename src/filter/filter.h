#include <vector>
#include "../nodes/nodes.h"

class Filter {
	private:
		vector<Node> searchSpace;
		vector<Node> notFilterSearchSpace;
		Node depot;
		Node currentNode;
		double haversineFormula(
			double r, double longitude1, double longitude2, double latitude1, double latitude2
		);
		bool enoughTankNodeToNode(Node node1, Node node2, double currentTankAvailable);
		bool enoughTimeNodeToNode(
			Node node1, Node node2, double currentTimeAvailable, double speed, double serviceTime, double refuelTime
		);
	public:
		// constructor
		Filter(
			vector<Node> ss, 
			vector<Node> nfss, 
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

		double getDistanceNodeToNode(Node node1, Node node2);
		double getTimeNodeToNode(Node node1, Node node2, double speed);
		void filterSearchSpace(
			double currentTimeAvailable, double currentTankAvailable, double speed, double serviceTime, double refuelTime
		);
};