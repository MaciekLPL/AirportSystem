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
//! Klasa obs³uguj¹ca wyœwietlanie danych.
/*!
	Obs³uguje wyœwietlanie danych w oknie konsoli, obs³uguje przewijanie danych, odœwie¿anie zawartoœci
*/
class Content {
public:

	/*!
		Konstruktor
		@param _parentView WskaŸnik do panelu, w którym dane bêd¹ wyœwietlane
	*/
	Content(View* _parentView);

	class View* parentView; //!< WskaŸnik do panelu, w którym dane bêd¹ wyœwietlane
	/*!
		Zmienia aktualnie wyœwietlany widok
	*/
	void changeCurrentContent();
	/*!
		Obs³uga przewijania w dó³
	*/
	void scrollDown();
	/*!
		Obs³uga przewijania w górê
	*/
	void scrollUp();
	/*!
		Obs³uga odœwie¿ania zawartoœci panelu
	*/
	void refreshContent();
	/*!
		Destruktor
	*/
	~Content();
	std::list <std::shared_ptr<City>> cityList; //!< Lista ogólna programu zawieraj¹ca zapisane miasta
	std::list <std::shared_ptr<Airport>> airportList; //!< Lista ogólna programu zawieraj¹ca zapisane lotniska
	std::list <std::shared_ptr<Airplane>> airplaneList; //!< Lista ogólna programu zawieraj¹ca zapisane samoloty
	std::list <std::shared_ptr<Staff>> staffList; //!< Lista ogólna programu zawieraj¹ca zapisanych pracowników
	std::list <std::shared_ptr<Connection>> connectionList; //!< Lista ogólna programu zawieraj¹ca zapisane po³¹czenia
	std::list <std::shared_ptr<Ticket>> ticketList; //!< Lista ogólna programu zawieraj¹ca zapisane bilety
	
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
		Wypisywanie na ekran zapisanych po³¹czeñ oraz ich danych
	*/
	void printConnections();
	/*!
		Wypisywanie na ekran zapisanych pracowników oraz ich danych
	*/
	void printStaff();
	/*!
		Wypisywanie na ekran zapisanych samolotów oraz ich danych
	*/
	void printAirplanes();
	/*!
		Wypisywanie na ekran zapisanych biletów oraz ich danych
	*/
	void printTickets();

	int currentContent = 1; //!< Aktualnie wyœwietlany widok
	int skip = 0; //!< Zmienna przechowuj¹ca iloœæ przewiniêtych wierszy.
};

#endif
