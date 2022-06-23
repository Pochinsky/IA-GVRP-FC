#include <iostream>

using namespace std;

/**
 * @brief Clase Instance para almacenar la informacion
 * 				la instancia
 * 
 */
class Instance {
	/**
	 * @brief Atributos
	 * 
	 * customers		-	numero de clientes
	 * stations			-	numero de estaciones de recarga
	 * maxTime			-	tiempo de maximo de servicio
	 * maxDistance	-	maxima distancia a recorrer al
	 * 								tener estanque lleno
	 * speed				-	velocidad constante
	 * serviceTime	-	tiempo de servicio al cliente
	 * refuelTime		-	tiempo de recarga de combustible
	 * 
	 */
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

/**
 * @brief Extrae la informacion de la instancia
 * 				desde el archivo
 * 
 * @param fileName 	Nombre del archivo
 * @return Instance Informacion de la instancia
 */
Instance extractInstanceData(string fileName);