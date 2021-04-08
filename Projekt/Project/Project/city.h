#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <list>

class Airport;

class City {
public:

	City(std::string name, std::string postal);

	void addAirport(Airport* airport);
	void listAirports();

	std::string cityName;
	std::string postalCode;
	std::list<Airport*> airportList;
private:
};


#endif
