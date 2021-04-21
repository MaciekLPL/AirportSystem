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

	Connection(std::shared_ptr<Airport> destination, std::string code);
	~Connection();
	void addTicket(std::shared_ptr<Ticket> pTicket);
	std::list<std::shared_ptr<Ticket>> ticketList;

private:

};

#endif