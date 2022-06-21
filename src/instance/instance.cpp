#include "instance.h"
#include <fstream>
#include <cstring>

using namespace std;

/**
 * Constructor of Instance Class
 */
Instance::Instance(int c, int s, int mt, int md, int sp, int st, int rt) {
	setCustomers(c);
	setStations(s);
	setMaxtime(mt);
	setMaxdistance(md);
	setSpeed(sp);
	setServicetime(st);
	setRefueltime(rt);
}

/**
 * Setters of Instance Class
 */
void Instance::setCustomers(int c) {
	customers = c;
}

void Instance::setStations(int s) {
	stations = s;
}

void Instance::setMaxtime(int mt) {
	maxtime = mt;
}

void Instance::setMaxdistance(int md) {
	maxdistance = md;
}

void Instance::setSpeed(int sp) {
	speed = sp;
}

void Instance::setServicetime(int st) {
	servicetime = st;
}

void Instance::setRefueltime(int rt) {
	refueltime = rt;
}

int Instance::getCustomers() { return customers; }

int Instance::getStations() { return stations; }

int Instance::getMaxtime() { return maxtime; }

int Instance::getMaxdistance() { return maxdistance; }

int Instance::getSpeed() { return speed; }

int Instance::getServicetime() { return servicetime; }

int Instance::getRefueltime() { return refueltime; }

Instance extractInstanceData(string filename) {
	/**
	 * Define variables and
	 * open the file
	 */
	ifstream inputfile;
	string line;
	int
		customers, 
		stations, 
		maxtime, 
		maxdistance, 
		speed,
		servicetime, 
		refueltime;
	inputfile.open(filename,ios::in);
	if (!inputfile.is_open()) {
		cerr << "No se pudo abrir el archivo: " << filename << endl;
		abort();
	}
	/**
	 * Get info of instance
	 */
	getline(inputfile,line);
	inputfile.close();
	if (line[8] == '1')
		customers = stoi(line.substr(8,3));
	else
		customers = stoi(line.substr(9,2));
	stations 		= stoi(line.substr(14,2));
	maxtime 		= stoi(line.substr(19,3));
	maxdistance	= stoi(line.substr(25,3));
	speed 			= stoi(line.substr(32,10));
	servicetime	= stoi(line.substr(45,2));
	refueltime	= stoi(line.substr(50,2));
	Instance newInstance(
		customers,
		stations,
		maxtime,
		maxdistance,
		speed,
		servicetime,
		refueltime
	);
	return newInstance;
}