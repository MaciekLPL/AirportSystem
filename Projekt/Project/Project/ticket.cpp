#include "connection.h"
#include "airport.h"
#include "ticket.h"

Ticket::Ticket(Connection* connection, int _numOfPassengers, int _price) {
	this->pOrigin = connection->pOrigin;
	this->pDestination = connection->pDestination;
	this->numOfPassengers = _numOfPassengers;
	this->price = _price;

}

std::ostream& operator<<(std::ostream& os, Ticket& t) {

	os << "Bilet na lot " << t.connectionCode << std::endl << " z: " << t.pOrigin->airportName << std::endl << " do: " << t.pDestination->airportName << std::endl;
	os << "Bilet dla " << t.numOfPassengers << " osob. Koszt: " << t.price << "." << std::endl;

	return os;

}