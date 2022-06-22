#include <fstream>
#include <cstring>
#include "instance.h"

using namespace std;

/**
 * Constructor of Instance class
 */
Instance::Instance(int c, int s, double mt, double md, double sp, double st, double rt) {
	setCustomers(c);
	setStations(s);
	setMaxTime(mt);
	setMaxDistance(md);
	setSpeed(sp);
	setServiceTime(st);
	setRefuelTime(rt);
}

/**
 * Setters of Instance class
 */
void Instance::setCustomers(int c) { customers = c; }
void Instance::setStations(int s) {	stations = s; }
void Instance::setMaxTime(double mt) {	maxTime = mt; }
void Instance::setMaxDistance(double md) {	maxDistance = md; }
void Instance::setSpeed(double sp) {	speed = sp; }
void Instance::setServiceTime(double st) { serviceTime = st; }
void Instance::setRefuelTime(double rt) { refuelTime = rt; }

/**
 * Getters of Instance class
 */
int Instance::getCustomers() { return customers; }
int Instance::getStations() { return stations; }
int Instance::getMaxTime() { return maxTime; }
int Instance::getMaxDistance() { return maxDistance; }
int Instance::getSpeed() { return speed; }
int Instance::getServiceTime() { return serviceTime; }
int Instance::getRefuelTime() { return refuelTime; }

/**
 * @brief extract data of instance and save in a Instance object
 * 
 * @param filename name of file to open
 * @return Instance object that storage data of instance
 */
Instance extractInstanceData(string fileName) {
	/**
	 * Define variables and
	 * open the file
	 */
	ifstream inputFile;
	string line;
	int
		customers, 
		stations, 
		serviceTime, 
		refuelTime;
	double
		maxTime,
		maxDistance, 
		speed;
	inputFile.open(fileName,ios::in);
	if (!inputFile.is_open()) {
		cerr << "No se pudo abrir el archivo: " << fileName << endl;
		abort();
	}
	/**
	 * Get info of instance
	 */
	getline(inputFile,line);
	inputFile.close();
	if (line[8] == '1')
		customers = stoi(line.substr(8,3));
	else
		customers = stoi(line.substr(9,2));
	stations 		= stoi(line.substr(14,2));
	maxTime 		= stod(line.substr(19,3));
	maxDistance	= stod(line.substr(25,3));
	speed 			= stod(line.substr(32,10));
	serviceTime	= stoi(line.substr(45,2));
	refuelTime	= stoi(line.substr(50,2));
	Instance newInstance(
		customers,
		stations,
		maxTime,
		maxDistance,
		speed,
		serviceTime,
		refuelTime
	);
	return newInstance;
}