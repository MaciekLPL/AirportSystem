#include "airport.h"
#include "staff.h"
#include "airplane.h"
#include "connection.h"
#include "ticket.h"


Airport::Airport(std::string code, std::string name) {
	this->airportCode = code;
	this->airportName = name;
}

Airport::~Airport() {
	while (!connectionList.empty()) {
		connectionList.pop_front();
	}

	while (!staffList.empty()) {
		staffList.pop_front();
	}

	while (!airplaneList.empty()) {
		airplaneList.pop_front();
	}
	connectionList.clear();
	staffList.clear();
	airplaneList.clear();
}

void Airport::addConnection(std::shared_ptr<Connection> pConnection) {
	pConnection->pOrigin = weak_from_this();
	this->connectionList.push_back(pConnection);
}

void Airport::addStaff(std::shared_ptr<Staff> pStaff) {
	pStaff->pAirport = weak_from_this();
	this->staffList.push_back(pStaff);
}

void Airport::addAirplane(std::shared_ptr<Airplane> pAirplane) {
	pAirplane->pAirport = weak_from_this();
	this->airplaneList.push_back(pAirplane);
}
