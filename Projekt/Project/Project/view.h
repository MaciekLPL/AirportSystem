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


//! Klasa zarz¹dzaj¹ca panelami.
/*!
	Zajmuje siê rysowaniem ich na ekranie, ich pozycjami, tytu³ami oraz widocznoœci¹ kursora.
*/
class View {
public:
	/*!
		Konstruktor bez wyœwietlania tytu³u panelu
		@param startX Wspó³rzêdna pocz¹tkowa na osi X
		@param startY Wspó³rzêdna pocz¹tkowa na osi Y
		@param endX Wspó³rzêdna koñcowa na osi X
		@param endY Wspó³rzêdna koñcowa na osi Y
	*/
	View(int startX, int startY, int endX, int endY);
	/*!
		Konstruktor z wyœwietlaniem tytu³u panelu
		@param startX Wspó³rzêdna pocz¹tkowa na osi X
		@param startY Wspó³rzêdna pocz¹tkowa na osi Y
		@param endX Wspó³rzêdna koñcowa na osi X
		@param endY Wspó³rzêdna koñcowa na osi Y
		@param _panelTitle Tytu³ panelu
	*/
	View(int startX, int startY, int endX, int endY, std::string _panelTitle);
	/*!
		Zmienia widocznoœæ kursora
		@param showFlag Flaga wyœwietlania (0/1)
	*/
	void ShowConsoleCursor(int showFlag);
	/*!
		Zmienia tytu³ panelu
		@param newTitle Nowy tytu³
	*/
	void updateTitle(std::string newTitle);
	/*!
		Czyœci panel z wyœwietlonej w nim zawartoœci
	*/
	void clearPanelContent();
	/*!
		Przenosi kursor na wskazane wspó³rzêdne
	*/
	void gotoxy(int x, int y);

	int startX; //!< Wspó³rzêdna pocz¹tkowa na osi X
	int startY; //!< Wspó³rzêdna pocz¹tkowa na osi Y
	int endX; //!< Wspó³rzêdna koñcowa na osi X
	int endY; //!< Wspó³rzêdna koñcowa na osi Y

private:
	std::string panelTitle; /*!< Aktualny tytu³ panelu */
	/*!
		Wypisuje tytu³ panelu w konsoli.
	*/
	void printTitle();
	/*!
		Rysuje panel w konsoli
	*/
	void drawView();
	/*!
		Rysuje zewnêtrzn¹ ramkê okna konsoli
	*/
	void drawFrame();

};

#endif
