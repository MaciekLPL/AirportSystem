#include "connection.h"
#include "ticket.h"

Ticket::Ticket(std::shared_ptr<Connection> connection, int _numOfPassengers, int _price) : thisID(id++) {
	
	this->pConnection = connection.get();
	this->numOfPassengers = _numOfPassengers;
	this->price = _price;
}
