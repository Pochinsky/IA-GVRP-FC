#include <iostream>
#include <fstream>
#include "src/instance/instance.h"

using namespace std;

int main() {
	string filename = "./Instancias/AB218.dat";
	Instance newInstance = extractInstanceData(filename);
	cout << "customers:   " << newInstance.getCustomers()   << endl;
	cout << "stations:    " << newInstance.getStations()    << endl;
	cout << "maxtime:     " << newInstance.getMaxtime()     << endl;
	cout << "maxdistance: " << newInstance.getMaxdistance() << endl;
	cout << "speed:       " << newInstance.getSpeed()       << endl;
	cout << "servicetime: " << newInstance.getServicetime() << endl;
	cout << "refueltime:  " << newInstance.getRefueltime()  << endl;
	return 0;
}