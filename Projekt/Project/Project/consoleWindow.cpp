#include "consoleWindow.h"
#include "view.h"



ConsoleWindow::ConsoleWindow() {};

ConsoleWindow::ConsoleWindow(int _width, int _height) {

	this->width = _width;
	this->height = _height;
	drawFrame();

}

void ConsoleWindow::ShowConsoleCursor(int showFlag) {

	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = showFlag;
	cursorInfo.dwSize = 100;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void ConsoleWindow::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void ConsoleWindow::drawFrame() {

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			
			if (w == 0 || w == width-1)
				putc(179, stdout);
			else if (h == 0 || h == height-1)
				putc(196, stdout);
			else
				putc(' ', stdout);
		}
	}
	gotoxy(0, 0);
	putc(218, stdout);
	gotoxy(width-1, 0);
	putc(191, stdout);
	gotoxy(0, height-1);
	putc(192, stdout);
	gotoxy(width-1, height-1);
	putc(217, stdout);
	gotoxy(0, height-1);
}

void ConsoleWindow::addView(View* _view) {
	
	listOfViews.push_back(_view);

}