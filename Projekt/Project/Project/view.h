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


//! Klasa zarz�dzaj�ca panelami.
/*!
	Zajmuje si� rysowaniem ich na ekranie, ich pozycjami, tytu�ami oraz widoczno�ci� kursora.
*/
class View {
public:
	/*!
		Konstruktor bez wy�wietlania tytu�u panelu
		@param startX Wsp�rz�dna pocz�tkowa na osi X
		@param startY Wsp�rz�dna pocz�tkowa na osi Y
		@param endX Wsp�rz�dna ko�cowa na osi X
		@param endY Wsp�rz�dna ko�cowa na osi Y
	*/
	View(int startX, int startY, int endX, int endY);
	/*!
		Konstruktor z wy�wietlaniem tytu�u panelu
		@param startX Wsp�rz�dna pocz�tkowa na osi X
		@param startY Wsp�rz�dna pocz�tkowa na osi Y
		@param endX Wsp�rz�dna ko�cowa na osi X
		@param endY Wsp�rz�dna ko�cowa na osi Y
		@param _panelTitle Tytu� panelu
	*/
	View(int startX, int startY, int endX, int endY, std::string _panelTitle);
	/*!
		Zmienia widoczno�� kursora
		@param showFlag Flaga wy�wietlania (0/1)
	*/
	void ShowConsoleCursor(int showFlag);
	/*!
		Zmienia tytu� panelu
		@param newTitle Nowy tytu�
	*/
	void updateTitle(std::string newTitle);
	/*!
		Czy�ci panel z wy�wietlonej w nim zawarto�ci
	*/
	void clearPanelContent();
	/*!
		Przenosi kursor na wskazane wsp�rz�dne
	*/
	void gotoxy(int x, int y);

	int startX; //!< Wsp�rz�dna pocz�tkowa na osi X
	int startY; //!< Wsp�rz�dna pocz�tkowa na osi Y
	int endX; //!< Wsp�rz�dna ko�cowa na osi X
	int endY; //!< Wsp�rz�dna ko�cowa na osi Y

private:
	std::string panelTitle; /*!< Aktualny tytu� panelu */
	/*!
		Wypisuje tytu� panelu w konsoli.
	*/
	void printTitle();
	/*!
		Rysuje panel w konsoli
	*/
	void drawView();
	/*!
		Rysuje zewn�trzn� ramk� okna konsoli
	*/
	void drawFrame();

};

#endif
