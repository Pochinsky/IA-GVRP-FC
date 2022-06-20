#include "extract.h"
#include <fstream>
#include <cstring>

using namespace std;

void extractData(string filename) {
	string 
		line, 
		customers, 
		stations, 
		maxtime, 
		maxdistance, 
		speed,
		servicetime, 
		refueltime;
	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cerr << "No se pudo abrir el archivo: " << filename << endl;
		return;
	}
	/**
	 * Get info of instance
	 */
	getline(input_file,line);
	customers 	= line.substr(9,2);	
	if (customers[0] == '1') customers += "0";
	stations 		= line.substr(14,2);
	maxtime 		= line.substr(19,3);
	maxdistance	= line.substr(25,3);
	speed 			= line.substr(32,10);
	servicetime	= line.substr(45,2);
	refueltime	= line.substr(50,2);
	input_file.close();
}