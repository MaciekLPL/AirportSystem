#include "connection.h"
#include "staff.h"
#include "airport.h"


Airport::Airport(std::string code, std::string name, City* city) {
	this->airportCode = code;
	this->airportName = name;
	this->pCity = city;
}

void Airport::addConnection(Connection* pConnection) {
	this->connectionList.push_back(pConnection);
	pConnection->pOrigin = this;
}

void Airport::addStaff(Staff* pStaff) {
	this->staffList.push_back(pStaff);
	pStaff->airport = this;
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