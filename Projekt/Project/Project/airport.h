#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <list>

class City;
class Connection;
class Staff;
class Airplane;

class Airport : public std::enable_shared_from_this <Airport> {
public:

	std::weak_ptr<City> pCity;
	std::string airportCode;
	std::string airportName;

	Airport(std::string code, std::string name);
	~Airport();
	void addConnection(std::shared_ptr<Connection> connection);
	void addStaff(std::shared_ptr<Staff> pStaff);
	void addAirplane(std::shared_ptr<Airplane> pAirplane);

	std::list<std::shared_ptr<Connection>> connectionList;
	std::list<std::shared_ptr<Staff>> staffList;
	std::list<std::shared_ptr<Airplane>> airplaneList;

private:
};

#endif
