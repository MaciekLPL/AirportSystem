#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <Windows.h>

class View {
public:
	
	View(int startX, int startY, int endX, int endY);
	View(int startX, int startY, int endX, int endY, std::string _panelTitle);
	void drawView();
	void printTitle();
	void gotoxy(int x, int y);


private:
	int startX;
	int startY;
	int endX;
	int endY;
	std::string panelTitle;
};

#endif
