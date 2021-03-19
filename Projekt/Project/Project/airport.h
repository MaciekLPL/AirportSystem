#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <list>

class Connection;
class Staff;

class Airport {
public:

	class City* pCity;
	std::string airportCode;
	std::string airportName;

	Airport(std::string code, std::string name);
	void addConnection(Connection* connection);
	void addStaff(Staff* pStaff);
	void listConnections();
	void listStaff();
	Connection* searchForConnection(std::string code);

private:
	std::list<Connection*> connectionList;
	std::list<Staff*> staffList;
};

#endif

