#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <list>

class Airport;

class City : public std::enable_shared_from_this <City> {
public:
	City(std::string name, std::string postal);
	~City();
	void addAirport(std::shared_ptr<Airport> airport);

	std::string cityName;
	std::string postalCode;
	std::list<std::shared_ptr<Airport>> airportList;


private:
};


#endif
