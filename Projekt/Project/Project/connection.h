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
	std::list<Ticket*> ticketList;
	
	Connection();
	Connection(Connection* connection);
	~Connection() {};
	Connection(Airport* destination, std::string code);
	Connection(Airport* origin, Airport* destination, std::string code);
	friend std::ostream& operator<<(std::ostream& os, Connection& c);


private:

};




#endif