#include <math.h>
#include "filter.h"

// constructor
Filter::Filter(
	vector<Node> ss, 
	vector<Node> nfss, 
	Node d, 
	Node cn
) {
	setSearchSpace(ss);
	setNotFilterSearchSpace(nfss);
	setDepot(d);
	setCurrentNode(cn);
}

// setters
void Filter::setSearchSpace(vector<Node> ss) { searchSpace = ss; }
void Filter::setNotFilterSearchSpace(vector<Node> nfss) {
	notFilterSearchSpace = nfss;
}
void Filter::setDepot(Node d) { depot = d; }
void Filter::setCurrentNode(Node cn) { currentNode = cn; }
// getters
vector<Node> Filter::getSearchSpace() { return searchSpace; }
vector<Node> Filter::getNotFilterSearchSpace() {
	return notFilterSearchSpace;
}
Node Filter::getDepot() { return depot; }
Node Filter::getCurrentNode() { return currentNode; }

double Filter::haversineFormula(
	double r, double longitude1, double longitude2, double latitude1, double latitude2
) {
	double haversineDistance;
	double halfOfDeltaLatitude  = (latitude1  - latitude2)/2;
	double halfOfDeltaLongitude = (longitude1 - longitude2)/2;
	double sinPowTwoLatitude		= pow(sin(halfOfDeltaLatitude),2.0);
	double sinPowTwoLongitude		= pow(sin(halfOfDeltaLongitude),2.0);
	double cosLatitude1					= cos(latitude1);
	double cosLatitude2					= cos(latitude2);
	double sqrtArgument					= sinPowTwoLatitude+cosLatitude1*cosLatitude2+sinPowTwoLongitude;
	double asinArguemnt					= sqrt(sqrtArgument);
	haversineDistance 					= 2*r*asin(asinArguemnt);
	return haversineDistance;
}

double Filter::getDistanceNodeToNode(Node node1, Node node2) {
	double distance;
	const double r    = 4182.44949; // [mile]
	double longitude1 = node1.getLongitude();
	double longitude2 = node2.getLongitude();
	double latitude1 = node1.getLatitude();
	double latitude2 = node2.getLongitude();
	return haversineFormula(r,longitude1,longitude2,latitude1,latitude2);
}

bool Filter::enoughTankNodeToNode(Node node1, Node node2, double currentTankAvailable) {
	double distance = getDistanceNodeToNode(node1,node2);
	if (distance <= currentTankAvailable) return true;
	else return false;
}

double Filter::getTimeNodeToNode(Node node1, Node node2, double speed) {
	double distance = getDistanceNodeToNode(node1, node2);
	return distance/speed;
}

bool Filter::enoughTimeNodeToNode(
	Node node1, Node node2, double currentTimeAvailable, double speed, double serviceTime, double refuelTime
) {
	double timeNodeToNode = getTimeNodeToNode(node1, node2, speed);
	double timeNeed;
	if (node2.getType() == 'f') timeNeed = timeNodeToNode + refuelTime;
	if (timeNodeToNode <= currentTimeAvailable) return true;
	else return false;
}

void Filter::filterSearchSpace(double currentTimeAvailable, double currentTankAvailable, double speed, double serviceTime, double refuelTime) {
	for (auto& node: searchSpace) {
		bool changes = false;
		// check enough service time available to back to depot
		if (!enoughTimeNodeToNode(node,depot,currentTimeAvailable, speed,serviceTime, refuelTime)) {
			setNotFilterSearchSpace(removeElementById(getNotFilterSearchSpace(), node.getId()));
			changes = true;
		}
		// check enough service time available to go to refuel station
		if (!changes) {
			for (auto& notFilterNode: getNotFilterSearchSpace()) {
				if (!enoughTimeNodeToNode(node,notFilterNode,currentTimeAvailable, speed,serviceTime, refuelTime)) {
					setNotFilterSearchSpace(removeElementById(getNotFilterSearchSpace(), node.getId()));
					changes = true;
				}
			}
		}
		if (!changes) {
			// check enough tank yo back yo depot
			if (!enoughTankNodeToNode(node,depot,currentTankAvailable)) {
				setNotFilterSearchSpace(removeElementById(getNotFilterSearchSpace(),node.getId()));
				changes = true;
			}
			if (!changes) {
				// check enough tank to go to refuel station
				for (auto& notFilterNode: getNotFilterSearchSpace()) {
					if (!enoughTankNodeToNode(node,notFilterNode,currentTankAvailable)) {
						setNotFilterSearchSpace(removeElementById(getNotFilterSearchSpace(),node.getId()));
						changes = true;
					}
				}
			}
		}
		if (!changes) {
			// check enough service time available to go from currentNode to refuelNode
			if (!enoughTimeNodeToNode(node,currentNode,currentTimeAvailable,speed,serviceTime, refuelTime)) {
				setNotFilterSearchSpace(removeElementById(getNotFilterSearchSpace(),node.getId()));
				changes = true;
			}
			if (!changes) {
				// check enough tank to go from currentNode to refuelNode
				if (!enoughTankNodeToNode(node,currentNode,currentTankAvailable)) {
					setNotFilterSearchSpace(removeElementById(getNotFilterSearchSpace(),node.getId()));
					changes = true;
				}
			}
		}
	}
}