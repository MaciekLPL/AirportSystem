#include "content.h"
#include "view.h"
#include "city.h"
#include "connection.h"
#include "staff.h"
#include "airplane.h"
#include "ticket.h"
#include "airport.h"


Content::Content(View* _parentView) {

	this->parentView = _parentView;

}

Content::Content(View* _parentView, std::list <City*>* cityL, 
	std::list <Airport*>* airportL, std::list <Airplane*>* airplaneL,
	std::list <Staff*>* staffL, std::list <Connection*>* connL, 
	std::list <Ticket*>* ticketL) {

	this->parentView = _parentView;
	this->cityList = cityL;
	this->airportList = airportL;
	this->airplaneList = airplaneL;
	this->staffList = staffL;
	this->connectionList = connL;
	this->ticketList = ticketL;

}

void Content::printCities(int skip) {


	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "City" << std::setw(15) << "Postal code" << std::endl;
	i++;

	auto iter = (*cityList).begin();
	std::advance(iter, skip);

	for (auto x = iter; x != (*cityList).end(); ++x) {
		if (i >= 22) 
			break;
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*x)->cityName;
		std::cout << std::setw(15) << std::left << (*x)->postalCode;
	}
	parentView->updateTitle("Cities");
}

void Content::printAirports(int skip) {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Airport name" << std::setw(15) << "Airport code" << std::setw(15) << "City" << std::endl;
	i++;

	auto iter = (*cityList).begin();
	std::advance(iter, skip);

	for (Airport* airport : *airportList) {
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*airport).airportName;
		std::cout << std::setw(15) << std::left << (*airport).airportCode;
		std::cout << std::setw(15) << std::left << (*airport).pCity->cityName;
	}
	parentView->updateTitle("Airports");
}

void Content::printConnections(int skip) {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Departure" << std::setw(10) << "Code" << std::setw(15) << "Arrival" << std::setw(10) << "Code" << std::setw(15) << "Connection" << std::endl;
	i++;

	for (Connection* connection : *connectionList) {
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*connection).pOrigin->airportName;
		std::cout << std::setw(10) << std::left << (*connection).pOrigin->airportCode;
		std::cout << std::setw(15) << std::left << (*connection).pDestination->airportName;
		std::cout << std::setw(10) << std::left << (*connection).pDestination->airportCode;
		std::cout << std::setw(15) << std::left << (*connection).connectionCode;
	}
	parentView->updateTitle("Connections");
}


void Content::printStaff(int skip) {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Airport" << std::setw(20) << "Name" << std::setw(10) << "Age" << std::endl;
	i++;

	for (Staff* staff : *staffList) {
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*staff).airport->airportName;
		std::cout << std::setw(20) << std::left << (*staff).name;
		std::cout << std::setw(10) << std::left << (*staff).age;
	}
	parentView->updateTitle("Staff");
}


void Content::printAirplanes(int skip) {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Airport" << std::setw(15) << "Registration" << std::setw(15) << "Type" << std::endl;
	i++;

	for (Airplane* airplane : *airplaneList) {
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*airplane).airport->airportName;
		std::cout << std::setw(15) << std::left << (*airplane).registration;
		std::cout << std::setw(15) << std::left << (*airplane).type;
	}
	parentView->updateTitle("Airplanes");
}


void Content::printTickets(int skip) {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Connection" << std::setw(15) << "Passengers" << std::setw(15) << "Price" << std::endl;
	i++;

	for (Ticket* ticket : *ticketList) {
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*ticket).connectionCode;
		std::cout << std::setw(15) << std::left << (*ticket).numOfPassengers;
		std::cout << std::setw(15) << std::left << (*ticket).price;
	}
	parentView->updateTitle("Tickets");
}
