#include <fstream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#include "list.h"

vector<Node> extractNodes(string fileName) {
	/**
	 * Define variables and
	 * open the file
	 */
	ifstream inputFile;
	string line;
	int id, n = 0;
	char type;
	double longitude, latitude;
	inputFile.open(fileName,ios::in);
	if (!inputFile.is_open()) {
		cerr << "No se pudo abrir el archivo: " << fileName << endl;
		abort();
	}
	/**
	 * Get number of nodes
	 */
	getline(inputFile,line);
	while (true) {
		getline(inputFile,line);
		if (line.size() == 1) break;
		if (line.size() == 42) n++;
	}
	inputFile.close();
	/**
	 * Get nodes
	 */
	inputFile.open(fileName,ios::in);
	if (!inputFile.is_open()) {
		cerr << "No se pudo abrir el archivo: " << fileName << endl;
		abort();
	}
	vector<Node> nodes;
	while (true) {
		getline(inputFile,line);
		if (line.size() == 1) break;
		if (line.size() == 42) {
			if (line[1] == ' ')
				id = stoi(line.substr(2,1));
			else {
				if (line[3] == ' ')
					id = stoi(line.substr(1,2));
				else
					id = stoi(line.substr(1,3));
			}
			type = line[5];
			longitude = stof(line.substr(11,14));
			latitude  = stof(line.substr(28,13));
			Node newNode(id,type,longitude,latitude);
			nodes.push_back(newNode);
		}
	}
	return nodes;
}