#include "city.h"
#include "airport.h"


City::City(std::string name, std::string postal) {
	this->cityName = name;
	this->postalCode = postal;
}

City::~City() {
	this->airportList.clear();
}

void City::addAirport(Airport* airport) {
	this->airportList.push_back(airport);
	airport->pCity = this;
}

void City::listAirports() {
	for (Airport* n : airportList)
		std::cout << (*n).airportCode << " - " << (*n).airportName << " - " << (*n).pCity->cityName << std::endl;
}