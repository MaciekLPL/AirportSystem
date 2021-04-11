#ifndef TICKET_H
#define TICKET_H

#include <iostream>

class Airport;
class Connection;

class Ticket {
public:
	static int id;
	int thisID;

	class Airport* pOrigin;
	class Airport* pDestination;
	std::string connectionCode;
	int numOfPassengers;
	int price;
	

	Ticket(Connection& connection, int _numOfPassengers, int _price);

private:


};

#endif