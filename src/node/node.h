class Node {
	private:
		int id;
		char type;
		double longitude;
		double latitude;
	public:
		// constructor
		Node(int i, char t, double lo, double la);
		// setters
		void setId(int i);
		void setType(char t);
		void setLongitude(double lo);
		void setLatitude(double la);
		// getters
		int getId();
		char getType();
		double getLongitude();
		double getLatitude();
};