#ifndef CONTENT_H
#define CONTENT_H

#include <iostream>
#include <list>
#include <iomanip>
#include <Windows.h>

class City;
class Airport;
class Connection;
class Staff;
class Airplane;
class Ticket;
class View;

class Content {
public:
	class View* parentView;
	Content(View* _parentView);

	void changeCurrentContent();
	void scrollDown();
	void scrollUp();
	void refreshContent();

	std::list <std::shared_ptr<City>> cityList;
	std::list <std::shared_ptr<Airport>> airportList;
	std::list <std::shared_ptr<Airplane>> airplaneList;
	std::list <std::shared_ptr<Staff>> staffList;
	std::list <std::shared_ptr<Connection>> connectionList;
	std::list <std::shared_ptr<Ticket>> ticketList;

private:
	void printCities();
	void printAirports();
	void printConnections();
	void printStaff();
	void printAirplanes();
	void printTickets();

	int currentContent = 1;
	int skip = 0;
};

#endif
