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
	Content(View* _parentView, std::list <City*>* cityL,
		std::list <Airport*>* airportL, std::list <Airplane*>* airplaneL,
		std::list <Staff*>* staffL, std::list <Connection*>* connL,
		std::list <Ticket*>* ticketL);
	void printCities(int skip = 0);
	void printAirports(int skip = 0);
	void printConnections(int skip = 0);
	void printStaff(int skip = 0);
	void printAirplanes(int skip = 0);
	void printTickets(int skip = 0);

	std::list <City*>* cityList;
	std::list <Airport*>* airportList;
	std::list <Airplane*>* airplaneList;
	std::list <Staff*>* staffList;
	std::list <Connection*>* connectionList;
	std::list <Ticket*>* ticketList;

	int currentContent = 1;
private:

	
};

#endif
