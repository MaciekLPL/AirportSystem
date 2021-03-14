#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <list>

class Airport;

class City {
public:

	City() {};
	City(std::string name);
	~City();
	void addAirport(Airport* airport);
	void listAirports();
	std::string cityName;

private:
	std::list<Airport*> airportList;
};


#endif

