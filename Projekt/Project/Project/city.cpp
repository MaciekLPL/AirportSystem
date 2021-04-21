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

City::~City() {
	/*while (!airportList.empty()) {
		airportList.pop_front();
	}*/
	airportList.clear();
}

void City::addAirport(std::shared_ptr<Airport> airport) {
	airport->pCity = this;
	this->airportList.push_back(airport);
}
