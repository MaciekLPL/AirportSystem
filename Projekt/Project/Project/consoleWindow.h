#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include <iostream>
#include <list>
#include <Windows.h>

class View;

class ConsoleWindow {
public:

	ConsoleWindow(int _width = 120, int _height = 30);
	void ShowConsoleCursor(int showFlag);
	void gotoxy(int x, int y);
	void drawFrame();
	void addView(View* _view);
	int currentView;


private:
	std::list<View*> listOfViews;
	int width;
	int height;

};


#endif