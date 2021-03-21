#include "view.h"
#include "city.h"
#include "connection.h"
#include "staff.h"
#include "airplane.h"
#include "ticket.h"
#include "airport.h"


View::View(int _startX, int _startY, int _endX, int _endY, std::string _panelTitle) {
	
	this->startX = _startX;
	this->startY = _startY;
	this->endX = _endX;
	this->endY = _endY;
	this->panelTitle = _panelTitle;

	drawView();
	if (!panelTitle.empty())
		printTitle();

}

View::View(int _startX, int _startY, int _endX, int _endY) {

	this->startX = _startX;
	this->startY = _startY;
	this->endX = _endX;
	this->endY = _endY;

	drawView();
}

void View::drawView() {
	gotoxy(startX, startY);
	for (int i = startY; i <= endY; i++) {
		for (int j = startX; j <= endX; j++) {

			if (j == startX || j == endX)
				putc(179, stdout);
			else if (i == startY || i == endY)
				putc(196, stdout);
			else
				putc(' ', stdout);
		}
		gotoxy(startX, i + 1);
	}
	gotoxy(startX, startY);
	putc(218, stdout);
	gotoxy(endX, startY);
	putc(191, stdout);
	gotoxy(startX, endY);
	putc(192, stdout);
	gotoxy(endX, endY);
	putc(217, stdout);
	gotoxy(0, endY + 1);
}

void View::printTitle() {

	gotoxy((((endX - startX)/2) - (panelTitle.size()/2) + 1) + startX, startY + 1);
	std::cout << panelTitle;
	gotoxy(startX, startY + 2);
	putc(195, stdout);
	for (int i = startX + 1; i < endX; i++)
		putc(196, stdout);
	putc(180, stdout);
}

void View::updateTitle(std::string newTitle) {

	gotoxy(startX + 1, startY + 1);
	for (int i = startX; i < endX - 1; i++)		//usuwanie obecnego
		putc(' ', stdout);
	
	this->panelTitle = newTitle;
	printTitle();
}

void View::clearPanelContent() {
	gotoxy(startX + 1, startY + 3);
	for (int i = startY + 3; i < endY; i++) {
		for (int j = startX + 1; j < endX; j++) {
			putc(' ', stdout);
		}
		gotoxy(startX + 1, i + 1);
	}

	updateTitle(" ");
}

void View::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void View::printCities(std::list <City*> cities) {

	int i = this->startY + 3;
	gotoxy(this->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "City" << std::setw(15) << "Postal code" << std::endl;
	i++;

	for (City* city : cities) {
		gotoxy(this->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*city).cityName;
		std::cout << std::setw(15) << std::left << (*city).postalCode;
	}
	updateTitle("Cities");
}

void View::printAirports(std::list <Airport*> airports) {

	int i = this->startY + 3;
	gotoxy(this->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Airport name" << std::setw(15) << "Airport code" << std::setw(15) << "City" << std::endl;
	i++;

	for (Airport* airport : airports) {
		gotoxy(this->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*airport).airportName;
		std::cout << std::setw(15) << std::left << (*airport).airportCode;
		std::cout << std::setw(15) << std::left << (*airport).pCity->cityName;
	}
	updateTitle("Airports");
}

void View::printConnections(std::list <Connection*> connections) {

	int i = this->startY + 3;
	gotoxy(this->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Departure" << std::setw(10) << "Code" << std::setw(15) << "Arrival" << std::setw(10) << "Code" << std::setw(15) << "Connection" << std::endl;
	i++;

	for (Connection* connection : connections) {
		gotoxy(this->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*connection).pOrigin->airportName;
		std::cout << std::setw(10) << std::left << (*connection).pOrigin->airportCode;
		std::cout << std::setw(15) << std::left << (*connection).pDestination->airportName;
		std::cout << std::setw(10) << std::left << (*connection).pDestination->airportCode;
		std::cout << std::setw(15) << std::left << (*connection).connectionCode;
	}
	updateTitle("Connections");
}


void View::printStaff(std::list <Staff*> staffList) {

	int i = this->startY + 3;
	gotoxy(this->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Airport" << std::setw(20) << "Name" << std::setw(10) << "Age" << std::endl;
	i++;

	for (Staff* staff : staffList) {
		gotoxy(this->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*staff).airport->airportName;
		std::cout << std::setw(20) << std::left << (*staff).name;
		std::cout << std::setw(10) << std::left << (*staff).age;
	}
	updateTitle("Staff");
}


void View::printAirplanes(std::list <Airplane*> airplanes) {

	int i = this->startY + 3;
	gotoxy(this->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Airport" << std::setw(15) << "Registration" << std::setw(15) << "Type" << std::endl;
	i++;

	for (Airplane* airplane : airplanes) {
		gotoxy(this->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*airplane).airport->airportName;
		std::cout << std::setw(15) << std::left << (*airplane).registration;
		std::cout << std::setw(15) << std::left << (*airplane).type;
	}
	updateTitle("Airplanes");
}


void View::printTickets(std::list <Ticket*> tickets) {

	int i = this->startY + 3;
	gotoxy(this->startX + 2, i++);
	std::cout << std::left << std::setw(15) << "Connection" << std::setw(15) << "Passengers" << std::setw(15) << "Price" << std::endl;
	i++;

	for (Ticket* ticket : tickets) {
		gotoxy(this->startX + 2, i++);
		std::cout << std::setw(15) << std::left << (*ticket).connectionCode;
		std::cout << std::setw(15) << std::left << (*ticket).numOfPassengers;
		std::cout << std::setw(15) << std::left << (*ticket).price;
	}
	updateTitle("Tickets");
}
