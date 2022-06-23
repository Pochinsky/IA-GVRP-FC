#include "vehicle.h"

// constructors
Vehicle::Vehicle(int i, double dt, double te, double de) {
	setId(i);
	setDistanceTraveled(dt);
	setTimeElapsed(te);
	setDistanceExceeded(de);
}
// setters
void Vehicle::setId(int i) { id = i; }
void Vehicle::setDistanceTraveled(double dt) { 
	distanceTraveled = dt;
}
void Vehicle::setTimeElapsed(double te) {
	timeElapsed = te;
}
void Vehicle::setDistanceExceeded(double de) {
	distanceExceeded = de;
}
// getters
int Vehicle::getId() { return id; }
double Vehicle::getDistanceTraveled() { return distanceTraveled; }
double Vehicle::getTimeElapsed() { return timeElapsed; }
double Vehicle::getDistanceExceeded() { return distanceExceeded; }