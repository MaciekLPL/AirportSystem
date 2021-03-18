#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include <iostream>
#include <Windows.h>

class ConsoleWindow {
public:

private:
	void ShowConsoleCursor(int showFlag);
	void gotoxy(int x, int y);

	int xDimension = 120;
	int yDimension = 30;

};


#endif