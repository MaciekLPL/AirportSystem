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

	std::list <City> cityList;
	std::list <Airport> airportList;
	std::list <Airplane> airplaneList;
	std::list <Staff> staffList;
	std::list <Connection> connectionList;
	std::list <Ticket> ticketList;

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
