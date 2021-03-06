#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

class View;
class Content;
class City;
class Airport;
class Connection;
//! Klasa obsługująca komendy.
/*!
	Obsługuje komendy, dodawanie, usuwanie, pobieranie komend, rozdzielanie poleceń
*/
class CommandHandler {
public:
	/*!
		Konstruktor
		@param _parentView Wskaźnik do nadrzędnego panelu konsoli
		@param _mainContent Wskaźnik do obiektu zarządzającego wyświetlaniem
	*/
	CommandHandler(View* _parentView, Content* _mainContent);
	/*!
		Pobieranie komendy od użytkownika
	*/
	void getCommand();
	/*!
		Rozdzielenie komend na dodawanie i usuwanie, skierowanie polecenia do odpowiedniej funkcji
	*/
	void splitCommand();
	/*!
		Wyświetlanie informacji/błędu w panelu w konsoli
	*/
	void printInformation(std::string info);
	std::string currentCmd; //!< Aktualnie przetwarzana komenda

private:
	View* parentView; //!< Wskaźnik do nadrzędnego panelu konsoli
	Content* mainContent; //!< Wskaźnik do obiektu zarządzającego wyświetlaniem

	std::regex namePattern = std::regex("^[a-zA-Z-]+$"); //!< Wzorzec wyrażenia regularnego dla nazw miast, lotnisk, imion, nazwisk
	std::regex postalCodePattern = std::regex("[0-9]{2}-[0-9]{3}"); //!< Wzorzec wyrażenia regularnego dla kodu pocztowego
	std::regex airportCodePattern = std::regex("[A-Z]{4}"); //!< Wzorzec wyrażenia regularnego dla kodu lotniska
	std::regex registrationPattern = std::regex("[A-Z]{2}-[A-Z]{3}"); //!< Wzorzec wyrażenia regularnego dla rejestracji samolotów
	std::regex typePattern = std::regex("[A-Z][0-9]{3}"); //!< Wzorzec wyrażenia regularnego dla typu samolotu
	std::regex connCodePattern = std::regex("[A-Z]{3}[0-9]{5}"); //!< Wzorzec wyrażenia regularnego dla kodu połączenia

	/*!
		Pobieranie z aktualnie przetwarzanego polecenia jednego tokenu/słowa/wyrazu
		@return Pobrane z polecenia słowo
	*/
	std::string getToken();
	/*! Rozdzielenie komend na dodawanie odpowiednich typów, skierowanie polecenia do odpowiedniej funkcji */
	void addCommand();
	/*! Rozdzielenie komend na usuwanie odpowiednich typów, skierowanie polecenia do odpowiedniej funkcji */
	void removeCommand();
	/*! Dodawanie nowego miasta */
	void addCity();
	/*! Usuwanie miasta */
	void removeCity();
	/*! Dodawanie nowego lotniska */
	void addAirport();
	/*! Usuwanie lotniska */
	void removeAirport();
	/*! Dodawanie nowego samolotu */
	void addAirplane();
	/*! Usuwanie samolotu */
	void removeAirplane();
	/*! Dodawanie nowego pracownika */
	void addStaff();
	/*! Usuwanie pracownika */
	void removeStaff();
	/*! Dodawanie nowego połączenia */
	void addConnection();
	/*! Usuwanie połączenia */
	void removeConnection();
	/*! Dodawanie nowego biletu */
	void addTicket();
	/*! Usuwanie biletu */
	void removeTicket();
	/*! Dodatkowa funkcja zapewniająca poprawne usuwanie zagnieżdżeń w lotniskach */
	void delAirports(std::shared_ptr<City> c);
	/*! Dodatkowa funkcja zapewniająca poprawne usuwanie zagnieżdżeń w połączeniach */
	void delConns(std::shared_ptr<Airport> a);

};



#endif
