#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <list>

class Connection;
class Staff;
class Airplane;

class Airport {
public:

	class City* pCity;
	std::string airportCode;
	std::string airportName;

	Airport(std::string code, std::string name);
	void addConnection(Connection* connection);
	void addStaff(Staff* pStaff);
	void addAirplane(Airplane* pAirplane);
	void listConnections();
	void listStaff();
	Connection* searchForConnection(std::string code);
	void remove(std::string code);

	std::list<Connection*> connectionList;
	std::list<Staff*> staffList;
	std::list<Airplane*> airplaneList;

private:
};

#endif
