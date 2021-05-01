#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>

class Airport;

class Airplane {
public:
	std::weak_ptr<Airport> pAirport;
	std::string registration;
	std::string type;
	Airplane(std::string _registration, std::string _type);

private:

};

#endif