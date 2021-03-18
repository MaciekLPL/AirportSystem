#include "airport.h"
#include "connection.h"

Connection::Connection(Airport* destination, std::string code) {
	//this->pOrigin = origin;
	this->pDestination = destination;
	this->connectionCode = code;
}

Connection::Connection() {
	this->pDestination = nullptr;
	this->pOrigin = nullptr;
	this->connectionCode = "";
}

Connection::Connection(Connection* connection) {
	this->pOrigin = connection->pOrigin;
	this->pDestination = connection->pDestination;
	this->connectionCode = connection->connectionCode;
}

Connection::Connection(Airport* origin, Airport* destination, std::string code) {

	this->pOrigin = origin;
	this->pDestination = destination;
	this->connectionCode = code;
}


std::ostream& operator<<(std::ostream& os, Connection& c) {

	os << "Polaczenie " << c.connectionCode << std::endl << " z: " << c.pOrigin->airportName << std::endl << " do: " << c.pDestination->airportName << std::endl;
	return os;

}