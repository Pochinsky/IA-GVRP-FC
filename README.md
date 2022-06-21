# Entrega 2 de proyecto de Inteligencia Artificial

## Green Vehicle Routing Problem (GVRP)

Implmentacion de resolucion del GVRP en C++ utilizando un algoritmo Forward Checking.

Las instancias de entrada estan en la carpeta `Instancias` tienen el siguiente formato:

`Name   #Customers   #Stations   MaxTime(min.)   MaxDistance(miles)   Speed(miles\min.)   ServiceTime(min.)   RefuelTime(min.)`

`NodeID   NodeType(d=depot, f=refueling_station, c=customer)   Longitude   Latitude`

Para cambiar el archivo de entrada se debe modificar la variable `filename` del archivo `main.cpp`.
