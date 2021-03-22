#ifndef VIEW_H
#define VIEW_H

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

class View {
public:
	
	View(int startX, int startY, int endX, int endY);
	View(int startX, int startY, int endX, int endY, std::string _panelTitle);
	void drawView();
	void drawFrame();
	void ShowConsoleCursor(int showFlag);
	void printTitle();
	void updateTitle(std::string newTitle);
	void clearPanelContent();
	void gotoxy(int x, int y);

	void printCities(std::list <City*> cities);
	void printAirports(std::list <Airport*> airports);
	void printConnections(std::list <Connection*> connections);
	void printStaff(std::list <Staff*> staff);
	void printAirplanes(std::list <Airplane*> airplanes);
	void printTickets(std::list <Ticket*> tickets);
	int currentView = 1;

private:
	int startX;
	int startY;
	int endX;
	int endY;
	std::string panelTitle;
};

#endif
