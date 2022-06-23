/**
 * @brief Clase Vehicle que almacena los datos a entregar
 * 				en la solucion de un vehiculo
 * 
 */
class Vehicle {
	/**
	 * @brief Atributos
	 * 
	 * id								-	id del vehiculo
	 * distanceTraveled	-	distancia recorrida hasta el momento
	 * timeElapsed			- tiempo transcurrido hasta el momento
	 * distanceExceeded
	 * 
	 */
	private:
		int id;
		double distanceTraveled;
		double timeElapsed;
		double distanceExceeded;
	public:
		// Constructor
		Vehicle(int i, double dt, double te, double de);
		// Setters
		void setId(int i);
		void setDistanceTraveled(double dt);
		void setTimeElapsed(double te);
		void setDistanceExceeded(double de);
		// Getters
		int getId();
		double getDistanceTraveled();
		double getTimeElapsed();
		double getDistanceExceeded();
};