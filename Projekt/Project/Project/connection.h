#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <list>

class Airport;
class Ticket;

class Connection {
public:

	
	class Airport* pOrigin;
	class Airport* pDestination;
	std::string connectionCode;
	
	Connection(Airport& destination, std::string code);
	void addTicket(Ticket& pTicket);
	std::list<Ticket> ticketList;

private:

};

#endif