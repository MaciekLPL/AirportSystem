#include "airport.h"
#include "connection.h"
#include "staff.h"


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
