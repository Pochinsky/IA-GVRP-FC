#include <iostream>
#include <fstream>
#include "src/extract/extract.h"

using namespace std;

int main() {
	string filename("./Instancias/AB101.dat");
	extractData(filename);
	return 0;
}