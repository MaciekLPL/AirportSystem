#include "content.h"
#include "view.h"
#include "city.h"
#include "airport.h"
#include "staff.h"
#include "airplane.h"
#include "connection.h"
#include "ticket.h"


Content::Content(View* _parentView) {
	this->parentView = _parentView;
}

Content::~Content() {
	//while (!cityList.empty()) {
	//	cityList.pop_front();
	//}
	//cityList.clear();
	//while (!airportList.empty()) {
	//	airportList.pop_front();
	//}
	//airportList.clear();
	//while (!staffList.empty()) {
	//	staffList.pop_front();
	//}
	//staffList.clear();
	//while (!airplaneList.empty()) {
	//	airplaneList.pop_front();
	//}
	//airplaneList.clear();
	//while (!connectionList.empty()) {
	//	connectionList.pop_front();
	//}
	//connectionList.clear();
	//while (!ticketList.empty()) {
	//	ticketList.pop_front();
	//}
	//ticketList.clear();
}


void Content::changeCurrentContent() {
	parentView->clearPanelContent();
	skip = 0;
	currentContent++;
	if (currentContent == 1)
		printCities();
	else if (currentContent == 2)
		printAirports();
	else if (currentContent == 3)
		printStaff();
	else if (currentContent == 4)
		printAirplanes();
	else if (currentContent == 5)
		printConnections();
	else if (currentContent == 6)
		printTickets();
	else {
		currentContent = 1;
		printCities();
	}
}


void Content::scrollUp() {

	if (skip > 0){
		skip--;
		if (currentContent == 1)
			printCities();
		else if (currentContent == 2)
			printAirports();
		else if (currentContent == 3)
			printStaff();
		else if (currentContent == 4)
			printAirplanes();
		else if (currentContent == 5)
			printConnections();
		else if (currentContent == 6)
			printTickets();
	}
}


void Content::scrollDown() {
	
	if (currentContent == 1) {
		if (cityList.size() + skip > 16 && skip < cityList.size() - 16) {
			skip++;
			printCities();
		}
	}
	else if (currentContent == 2) {
		if (airplaneList.size() + skip > 16 && skip < airportList.size() - 16) {
			skip++;
			printAirports();
		}
	}
	else if (currentContent == 3) {
		if (staffList.size() + skip > 16 && skip < staffList.size() - 16) {
			skip++;
			printStaff();
		}
	}
	else if (currentContent == 4) {
		if (airplaneList.size() + skip > 16 && skip < airplaneList.size() - 16) {
			skip++;
			printAirplanes();
		}
	}
	else if (currentContent == 5) {
		if (connectionList.size() + skip > 16 && skip < connectionList.size() - 16) {
			skip++;
			printConnections();
		}
	}
	else if (currentContent == 6) {
		if (ticketList.size() + skip > 16 && skip < ticketList.size() - 16) {
			skip++;
			printTickets();
		}
	}
}


void Content::refreshContent() {
	currentContent--;
	changeCurrentContent();
}


void Content::printCities() {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "City" << std::setw(15) << "Postal code" << std::setw(15) << "Airports count" << std::endl;
	i++;

	auto iter = cityList.begin();
	std::advance(iter, skip);

	for (auto x = iter; x != cityList.end(); ++x) {
		if (i >= 22) 
			break;
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*x)->cityName;
		std::cout << std::setw(15) << std::left << (*x)->postalCode;
		std::cout << std::setw(15) << std::left << (*x)->airportList.size();
	}
	parentView->updateTitle("Cities (1/6)");
}


void Content::printAirports() {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Airport name" << std::setw(15) << "Airport code" << std::setw(15) << "City" << std::endl;
	i++;

	auto iter = airportList.begin();
	std::advance(iter, skip);

	for (auto x = iter; x != airportList.end(); ++x) {
		if (i >= 22)
			break;
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*x)->airportName;
		std::cout << std::setw(15) << std::left << (*x)->airportCode;
		std::cout << std::setw(15) << std::left << (*x)->pCity.lock()->cityName;
	}
	parentView->updateTitle("Airports (2/6)");
}


void Content::printStaff() {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(4) << "ID" << std::setw(10) << "Name" << std::setw(15) << "Surname" << std::setw(15) << "Position" << std::setw(4) << "Age" << std::setw(15) << "Airport" << std::endl;
	i++;

	auto iter = staffList.begin();
	std::advance(iter, skip);

	for (auto x = iter; x != staffList.end(); ++x) {
		if (i >= 22)
			break;
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(4) << std::left << (*x)->thisID;
		std::cout << std::setw(10) << std::left << (*x)->name;
		std::cout << std::setw(15) << std::left << (*x)->surname;
		std::cout << std::setw(15) << std::left << (*x)->position;
		std::cout << std::setw(4) << std::left << (*x)->age;
		std::cout << std::setw(15) << std::left << (*x)->pAirport.lock()->airportName;
	}
	parentView->updateTitle("Staff (3/6)");
}


void Content::printAirplanes() {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Airport" << std::setw(15) << "Registration" << std::setw(15) << "Type" << std::endl;
	i++;

	auto iter = airplaneList.begin();
	std::advance(iter, skip);

	for (auto x = iter; x != airplaneList.end(); ++x) {
		if (i >= 22)
			break;
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*x)->pAirport.lock()->airportName;
		std::cout << std::setw(15) << std::left << (*x)->registration;
		std::cout << std::setw(15) << std::left << (*x)->type;
	}
	parentView->updateTitle("Airplanes (4/6)");
}


void Content::printConnections() {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Departure" << std::setw(10) << "Code" << std::setw(15) << "Arrival" << std::setw(10) << "Code" << std::setw(15) << "Connection" << std::endl;
	i++;

	auto iter = connectionList.begin();
	std::advance(iter, skip);

	for (auto x = iter; x != connectionList.end(); ++x) {
		if (i >= 22)
			break;
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*x)->pOrigin.lock()->airportName;
		std::cout << std::setw(10) << std::left << (*x)->pOrigin.lock()->airportCode;
		std::cout << std::setw(15) << std::left << (*x)->pDestination.lock()->airportName;
		std::cout << std::setw(10) << std::left << (*x)->pDestination.lock()->airportCode;
		std::cout << std::setw(15) << std::left << (*x)->connectionCode;
	}
	parentView->updateTitle("Connections (5/6)");
}


void Content::printTickets() {

	int i = parentView->startY + 3;
	parentView->gotoxy(parentView->startX + 2, i++);
	std::cout << std::left << std::setw(4) << "ID" << std::setw(15) << "Connection" << std::setw(15) << "Passengers" << std::setw(15) << "Price" << std::endl;
	i++;

	auto iter = ticketList.begin();
	std::advance(iter, skip);

	for (auto x = iter; x != ticketList.end(); ++x) {
		if (i >= 22)
			break;
		parentView->gotoxy(parentView->startX + 2, i++);
		std::cout << std::setw(4) << std::left << (*x)->thisID;
		std::cout << std::setw(15) << std::left << (*x)->pConnection.lock()->connectionCode;
		std::cout << std::setw(15) << std::left << (*x)->numOfPassengers;
		std::cout << std::setw(15) << std::left << (*x)->price;
	}
	parentView->updateTitle("Tickets (6/6)");
}
