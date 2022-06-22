#include <iostream>

using namespace std;

class Instance {
	private:
		int customers;
		int stations;
		double maxTime;
		double maxDistance;
		double speed;
		double serviceTime;
		double refuelTime;
	public:
		// constructor
		Instance(int c, int s, double mt, double md, double sp, double st, double rt);
		// setters
		void setCustomers(int c);
		void setStations(int s);
		void setMaxTime(double mt);
		void setMaxDistance(double md);
		void setSpeed(double sp);
		void setServiceTime(double st);
		void setRefuelTime(double rt);
		// getters
		int getCustomers();
		int getStations();
		int getMaxTime();
		int getMaxDistance();
		int getSpeed();
		int getServiceTime();
		int getRefuelTime();
};

Instance extractInstanceData(string fileName);