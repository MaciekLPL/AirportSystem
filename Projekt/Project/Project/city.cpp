#include "city.h"
#include "airport.h"


City::City(std::string name) {
	this->cityName = name;
}

City::~City() {
	this->airportList.clear();
}

void City::addAirport(Airport* airport) {
	this->airportList.push_back(airport);
}

void City::listAirports() {
	for (Airport* n : airportList)
		std::cout << (*n).airportCode << " - " << (*n).airportName << " - " << (*n).pCity->cityName << std::endl;
}
