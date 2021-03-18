#include "view.h";


View::View(int _startX, int _startY, int _endX, int _endY, std::string _panelTitle) {
	
	this->startX = _startX;
	this->startY = _startY;
	this->endX = _endX;
	this->endY = _endY;
	this->panelTitle = _panelTitle;

	drawView();
	if (!panelTitle.empty())
		printTitle();

}

View::View(int _startX, int _startY, int _endX, int _endY) {

	this->startX = _startX;
	this->startY = _startY;
	this->endX = _endX;
	this->endY = _endY;

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

void View::printTitle() {

	gotoxy((((endX - startX)/2) - (panelTitle.size()/2) + 1) + startX, startY + 1);
	std::cout << panelTitle;
	gotoxy(startX, startY + 2);
	putc(195, stdout);
	for (int i = startX + 1; i < endX; i++)
		putc(196, stdout);
	putc(180, stdout);

}

void View::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}