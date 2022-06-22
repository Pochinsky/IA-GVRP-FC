#include <fstream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#include "nodes.h"

Node extractDepot(string fileName) {
	ifstream inputFile;
	string line;
	int id;
	char type;
	double longitude, latitude;
	inputFile.open(fileName,ios::in);
	if (!inputFile.is_open()) {
		cerr << "No se pudo abrir el archivo: " << fileName << endl;
		abort();
	}
	getline(inputFile,line);
	getline(inputFile,line);
	id = stoi(line.substr(2,1));
	type = line[5];
	longitude = stod(line.substr(11,14));
	latitude = stod(line.substr(28,13));
	Node depot(id,type,longitude,latitude);
	return depot;
}

vector<Node> extractRefuelNodes(string fileName) {
	/**
	 * Define variables and
	 * open the file
	 */
	ifstream inputFile;
	string line;
	int id;
	char type;
	double longitude, latitude;
	inputFile.open(fileName,ios::in);
	if (!inputFile.is_open()) {
		cerr << "No se pudo abrir el archivo: " << fileName << endl;
		abort();
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
	vector<Node> refuelNodes;
	while (true) {
		getline(inputFile,line);
		if (line.size() == 1) break;
		if (line.size() == 42 && line[5] == 'f') {
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
			refuelNodes.push_back(newNode);
		}
	}
	return refuelNodes;
}

vector<Node> extractCustomerNodes(string fileName) {
	/**
	 * Define variables and
	 * open the file
	 */
	ifstream inputFile;
	string line;
	int id;
	char type;
	double longitude, latitude;
	inputFile.open(fileName,ios::in);
	if (!inputFile.is_open()) {
		cerr << "No se pudo abrir el archivo: " << fileName << endl;
		abort();
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
	vector<Node> customerNodes;
	while (true) {
		getline(inputFile,line);
		if (line.size() == 1) break;
		if (line.size() == 42 && line[5] == 'c') {
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
			customerNodes.push_back(newNode);
		}
	}
	return customerNodes;
}

vector<Node> removeElementById(vector<Node> nodes, int id) {
	int i = 0;
	for (auto& node: nodes) {
		if (node.getId() == id)
			break;
		i++;
	}
	nodes.erase(next(nodes.begin(),i));
	return nodes;
}