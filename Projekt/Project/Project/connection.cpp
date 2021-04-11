#include "airport.h"
#include "connection.h"
#include "ticket.h"

Connection::Connection(Airport& destination, std::string code) {

	this->pDestination = &destination;
	this->connectionCode = code;
}

void Connection::addTicket(Ticket& pTicket) {
	this->ticketList.push_back(pTicket);
}