#include "node.h"

/**
 * Constructor of Node class
 */
Node::Node(int i, char t, double lo, double la) {
	setId(i);
	setType(t);
	setLongitude(lo);
	setLatitude(la);
}

/**
 * Setters of Node class
 */
void Node::setId(int i) { id = i; }
void Node::setType(char t) { type = t; }
void Node::setLongitude(double lo) { longitude = lo; }
void Node::setLatitude(double la) { latitude = la; }
/**
 * Getters of Node class
 */
int Node::getId() { return id; }
char Node::getType() { return type; }
double Node::getLongitude() { return longitude; }
double Node::getLatitude() { return latitude; }