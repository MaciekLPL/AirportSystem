#include "connection.h"
#include "ticket.h"

Ticket::Ticket(Connection& connection, int _numOfPassengers, int _price) : thisID(id++) {
	
	this->pOrigin = connection.pOrigin;
	this->pDestination = connection.pDestination;
	this->connectionCode = connection.connectionCode;
	this->numOfPassengers = _numOfPassengers;
	this->price = _price;
}
