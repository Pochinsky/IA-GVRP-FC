#include <iostream>

using namespace std;

class Instance {
	private:
		int customers;
		int stations;
		double maxTime;
		double maxDistance;
		double speed;
		int serviceTime;
		int refuelTime;
	public:
		// constructor
		Instance(int c, int s, double mt, double md, double sp, int st, int rt);
		// setters
		void setCustomers(int c);
		void setStations(int s);
		void setMaxTime(double mt);
		void setMaxDistance(double md);
		void setSpeed(double sp);
		void setServiceTime(int st);
		void setRefuelTime(int rt);
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