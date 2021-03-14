#include "airport.h"
#include "connection.h"


Airport::Airport(std::string code, std::string name, City* city) {
	this->airportCode = code;
	this->airportName = name;
	this->pCity = city;
}

void Airport::addConnection(Connection* connection) {
	this->connectionList.push_back(connection);
	connection->pOrigin = this;
}

void Airport::listConnections() {
	for (Connection* n : connectionList)
		std::cout << (*n).pOrigin->airportName << " - " << (*n).pDestination->airportName << " - " << (*n).connectionCode << std::endl;
}
