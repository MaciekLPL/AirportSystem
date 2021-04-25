#ifndef TICKET_H
#define TICKET_H

#include <iostream>

class Connection;

class Ticket {
public:
	static int id;
	int thisID;

	std::shared_ptr<Connection> pConnection;
	int numOfPassengers;
	int price;
	

	Ticket(std::shared_ptr<Connection> connection, int _numOfPassengers, int _price);

private:


};

#endif