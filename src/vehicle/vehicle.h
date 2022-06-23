class Vehicle {
	private:
		int id;
		double distanceTraveled;
		double timeElapsed;
		double distanceExceeded;
	public:
		// constructor
		Vehicle(int i, double dt, double te, double de);
		// setters
		void setId(int i);
		void setDistanceTraveled(double dt);
		void setTimeElapsed(double te);
		void setDistanceExceeded(double de);
		// getters
		int getId();
		double getDistanceTraveled();
		double getTimeElapsed();
		double getDistanceExceeded();
};