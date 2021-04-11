#include "city.h"
#include "airport.h"
#include "staff.h"
#include "airplane.h"
#include "connection.h"
#include "ticket.h"

City::City(std::string name, std::string postal) {
	this->cityName = name;
	this->postalCode = postal;
}

void City::addAirport(Airport& airport) {
	airport.pCity = this;
	this->airportList.push_back(airport);
}
