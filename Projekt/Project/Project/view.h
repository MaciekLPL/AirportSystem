#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <list>
#include <iomanip>
#include <Windows.h>

class City;
class Airport;

class View {
public:
	
	View(int startX, int startY, int endX, int endY);
	View(int startX, int startY, int endX, int endY, std::string _panelTitle);
	void drawView();
	void printTitle();
	void updateTitle(std::string newTitle);
	void clearPanelContent();
	void gotoxy(int x, int y);
	void printCities(std::list <City*> cities);
	void printAirports(std::list <Airport*> airports);

private:
	int startX;
	int startY;
	int endX;
	int endY;
	std::string panelTitle;
};

#endif
