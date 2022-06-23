/**
 * @brief Clase Node para representar un nodo
 * 
 */
class Node {
	/**
	 * @brief Atributos
	 * 
	 * id					-	id del nodo
	 * type				-	tipo de nodo (d=deposito,f=refuel_station,c=customer)
	 * longitude	-	coordenada longitud
	 * latitude		-	coordenada latitude
	 * 
	 */
	private:
		int id;
		char type;
		double longitude;
		double latitude;
	public:
		// constructor
		Node();
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