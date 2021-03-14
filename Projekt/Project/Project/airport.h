#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <list>

class Connection;

class Airport {
public:
	class City* pCity;
	std::string airportCode;
	std::string airportName;
	Airport(std::string code, std::string name, City* city);
	void addConnection(Connection* connection);
	void listConnections();

private:
	std::list<Connection*> connectionList;
};

#endif

