#include <iostream>

using namespace std;

class Instance {
	private:
		int customers;
		int stations;
		int maxtime;
		int maxdistance;
		int speed;
		int servicetime;
		int refueltime;
	public:
		// constructor
		Instance(int c, int s, int mt, int md, int sp, int st, int rt);
		// setters
		void setCustomers(int c);
		void setStations(int s);
		void setMaxtime(int mt);
		void setMaxdistance(int md);
		void setSpeed(int sp);
		void setServicetime(int st);
		void setRefueltime(int rt);
		// getters
		int getCustomers();
		int getStations();
		int getMaxtime();
		int getMaxdistance();
		int getSpeed();
		int getServicetime();
		int getRefueltime();
};

Instance extractInstanceData(string filename);