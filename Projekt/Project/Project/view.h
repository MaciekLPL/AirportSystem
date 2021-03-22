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

	int currentView = 1;
	int startX;
	int startY;
	int endX;
	int endY;
	std::string panelTitle;

private:

};

#endif
