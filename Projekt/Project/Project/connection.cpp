#include "airport.h"
#include "connection.h"
#include "ticket.h"

Connection::Connection(std::shared_ptr<Airport> destination, std::string code) {

	pDestination = destination;
	connectionCode = code;
}

Connection::~Connection() {

	/*while (!ticketList.empty()) {
		ticketList.pop_front();
	}*/
	ticketList.clear();
}

void Connection::addTicket(std::shared_ptr<Ticket> pTicket) {
	this->ticketList.push_back(pTicket);
}