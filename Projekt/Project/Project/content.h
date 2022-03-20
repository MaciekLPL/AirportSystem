#ifndef CONTENT_H
#define CONTENT_H

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
class View;
//! Klasa obs�uguj�ca wy�wietlanie danych.
/*!
	Obs�uguje wy�wietlanie danych w oknie konsoli, obs�uguje przewijanie danych, od�wie�anie zawarto�ci
*/
class Content {
public:

	/*!
		Konstruktor
		@param _parentView Wska�nik do panelu, w kt�rym dane b�d� wy�wietlane
	*/
	Content(View* _parentView);

	class View* parentView; //!< Wska�nik do panelu, w kt�rym dane b�d� wy�wietlane
	/*!
		Zmienia aktualnie wy�wietlany widok
	*/
	void changeCurrentContent();
	/*!
		Obs�uga przewijania w d�
	*/
	void scrollDown();
	/*!
		Obs�uga przewijania w g�r�
	*/
	void scrollUp();
	/*!
		Obs�uga od�wie�ania zawarto�ci panelu
	*/
	void refreshContent();
	/*!
		Destruktor
	*/
	~Content();
	std::list <std::shared_ptr<City>> cityList; //!< Lista og�lna programu zawieraj�ca zapisane miasta
	std::list <std::shared_ptr<Airport>> airportList; //!< Lista og�lna programu zawieraj�ca zapisane lotniska
	std::list <std::shared_ptr<Airplane>> airplaneList; //!< Lista og�lna programu zawieraj�ca zapisane samoloty
	std::list <std::shared_ptr<Staff>> staffList; //!< Lista og�lna programu zawieraj�ca zapisanych pracownik�w
	std::list <std::shared_ptr<Connection>> connectionList; //!< Lista og�lna programu zawieraj�ca zapisane po��czenia
	std::list <std::shared_ptr<Ticket>> ticketList; //!< Lista og�lna programu zawieraj�ca zapisane bilety
	
private:
	/*!
		Wypisywanie na ekran zapisanych miast oraz ich danych
	*/
	void printCities();
	/*!
		Wypisywanie na ekran zapisanych lotnisk oraz ich danych
	*/
	void printAirports();
	/*!
		Wypisywanie na ekran zapisanych po��cze� oraz ich danych
	*/
	void printConnections();
	/*!
		Wypisywanie na ekran zapisanych pracownik�w oraz ich danych
	*/
	void printStaff();
	/*!
		Wypisywanie na ekran zapisanych samolot�w oraz ich danych
	*/
	void printAirplanes();
	/*!
		Wypisywanie na ekran zapisanych bilet�w oraz ich danych
	*/
	void printTickets();

	int currentContent = 1; //!< Aktualnie wy�wietlany widok
	int skip = 0; //!< Zmienna przechowuj�ca ilo�� przewini�tych wierszy.
};

#endif
