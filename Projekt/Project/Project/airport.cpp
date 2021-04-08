#include "connection.h"
#include "staff.h"
#include "airplane.h"
#include "airport.h"


Airport::Airport(std::string code, std::string name) {
	this->airportCode = code;
	this->airportName = name;
}

void Airport::addConnection(Connection* pConnection) {
	this->connectionList.push_back(pConnection);
	pConnection->pOrigin = this;
}

void Airport::addStaff(Staff* pStaff) {
	this->staffList.push_back(pStaff);
	pStaff->airport = this;
}

void Airport::addAirplane(Airplane* pAirplane) {
	this->airplaneList.push_back(pAirplane);
	pAirplane->airport = this;
}

void Airport::listConnections() {
	for (Connection* x : connectionList)
		std::cout << (*x).pOrigin->airportName << " - " << (*x).pDestination->airportName << " - " << (*x).connectionCode << std::endl;
}

void Airport::listStaff() {
	for (Staff* x : staffList)
		std::cout << (*x).airport->airportName << " - " << (*x).name << " - " << (*x).age << std::endl;
}

Connection* Airport::searchForConnection(std::string code) {

	auto result = std::find_if(connectionList.begin(), connectionList.end(), [&code](const Connection& connection)
		{ return connection.connectionCode == code; });

	return *result;
}

void Airport::remove(std::string code) {
	connectionList.erase(
		std::remove_if(connectionList.begin(), connectionList.end(), 
		[code](const Connection& connection) { return connection.connectionCode == code; }), 
		connectionList.end());
}