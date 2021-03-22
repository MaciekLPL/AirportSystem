#include "view.h"
#include "city.h"
#include "connection.h"
#include "staff.h"
#include "airplane.h"
#include "ticket.h"
#include "airport.h"


View::View(int _startX, int _startY, int _endX, int _endY, std::string _panelTitle) {
	
	this->startX = _startX;
	this->startY = _startY;
	this->endX = _endX;
	this->endY = _endY;
	this->panelTitle = _panelTitle;

	drawFrame();
	drawView();
	
	if (!panelTitle.empty())
		printTitle();

}

View::View(int _startX, int _startY, int _endX, int _endY) {

	this->startX = _startX;
	this->startY = _startY;
	this->endX = _endX;
	this->endY = _endY;

	//drawFrame();
	drawView();
}

void View::drawView() {
	gotoxy(startX, startY);
	for (int i = startY; i <= endY; i++) {
		for (int j = startX; j <= endX; j++) {

			if (j == startX || j == endX)
				putc(179, stdout);
			else if (i == startY || i == endY)
				putc(196, stdout);
			else
				putc(' ', stdout);
		}
		gotoxy(startX, i + 1);
	}
	gotoxy(startX, startY);
	putc(218, stdout);
	gotoxy(endX, startY);
	putc(191, stdout);
	gotoxy(startX, endY);
	putc(192, stdout);
	gotoxy(endX, endY);
	putc(217, stdout);
	gotoxy(0, endY + 1);
}

void View::drawFrame() {
	int height = 30;
	int width = 120;

	gotoxy(0, 0);

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {

			if (w == 0 || w == width - 1)
				putc(179, stdout);
			else if (h == 0 || h == height - 1)
				putc(196, stdout);
			else
				putc(' ', stdout);
		}
	}
	gotoxy(0, 0);
	putc(218, stdout);
	gotoxy(width - 1, 0);
	putc(191, stdout);
	gotoxy(0, height - 1);
	putc(192, stdout);
	gotoxy(width - 1, height - 1);
	putc(217, stdout);
	gotoxy(0, height - 1);

}

void View::printTitle() {

	gotoxy((((endX - startX)/2) - (panelTitle.size()/2) + 1) + startX, startY + 1);
	std::cout << panelTitle;
	gotoxy(startX, startY + 2);
	putc(195, stdout);
	for (int i = startX + 1; i < endX; i++)
		putc(196, stdout);
	putc(180, stdout);
}

void View::updateTitle(std::string newTitle) {

	gotoxy(startX + 1, startY + 1);
	for (int i = startX; i < endX - 1; i++)		//usuwanie obecnego
		putc(' ', stdout);
	
	this->panelTitle = newTitle;
	printTitle();
}

void View::clearPanelContent() {
	gotoxy(startX + 1, startY + 3);
	for (int i = startY + 3; i < endY; i++) {
		for (int j = startX + 1; j < endX; j++) {
			putc(' ', stdout);
		}
		gotoxy(startX + 1, i + 1);
	}

	updateTitle(" ");
}

void View::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void View::ShowConsoleCursor(int showFlag) {

	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = showFlag;
	cursorInfo.dwSize = 100;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
