#ifndef TICKET_H
#define TICKET_H

#include <iostream>

class Airport;
class Connection;

class Ticket : public Connection{
public:

	int numOfPassengers;
	int price;

	Ticket(Connection* connection, int _numOfPassengers, int _price);
	friend std::ostream& operator<< (std::ostream& os, Ticket& t);

private:


};

#endif