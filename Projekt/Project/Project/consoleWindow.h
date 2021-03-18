#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include <iostream>
#include <Windows.h>

class ConsoleWindow {
public:

	ConsoleWindow();
	ConsoleWindow(int _width = 120, int _height = 30);
	void ShowConsoleCursor(int showFlag);
	void gotoxy(int x, int y);
	void drawFrame();

private:

	int width;
	int height;

};


#endif