#include "airport.h"
#include "staff.h"
#include "airplane.h"
#include "connection.h"
#include "ticket.h"


Airport::Airport(std::string code, std::string name) {
	this->airportCode = code;
	this->airportName = name;
}

void Airport::addConnection(Connection& pConnection) {
	pConnection.pOrigin = this;
	this->connectionList.push_back(pConnection);
}

void Airport::addStaff(Staff& pStaff) {
	pStaff.pAirport = this;
	this->staffList.push_back(pStaff);
}

void Airport::addAirplane(Airplane& pAirplane) {
	pAirplane.pAirport = this;
	this->airplaneList.push_back(pAirplane);
}
