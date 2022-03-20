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
//! Klasa obs³uguj¹ca komendy.
/*!
	Obs³uguje komendy, dodawanie, usuwanie, pobieranie komend, rozdzielanie poleceñ
*/
class CommandHandler {
public:
	/*!
		Konstruktor
		@param _parentView WskaŸnik do nadrzêdnego panelu konsoli
		@param _mainContent WskaŸnik do obiektu zarz¹dzaj¹cego wyœwietlaniem
	*/
	CommandHandler(View* _parentView, Content* _mainContent);
	/*!
		Pobieranie komendy od u¿ytkownika
	*/
	void getCommand();
	/*!
		Rozdzielenie komend na dodawanie i usuwanie, skierowanie polecenia do odpowiedniej funkcji
	*/
	void splitCommand();
	/*!
		Wyœwietlanie informacji/b³êdu w panelu w konsoli
	*/
	void printInformation(std::string info);
	std::string currentCmd; //!< Aktualnie przetwarzana komenda

private:
	View* parentView; //!< WskaŸnik do nadrzêdnego panelu konsoli
	Content* mainContent; //!< WskaŸnik do obiektu zarz¹dzaj¹cego wyœwietlaniem

	std::regex namePattern = std::regex("^[a-zA-Z-]+$"); //!< Wzorzec wyra¿enia regularnego dla nazw miast, lotnisk, imion, nazwisk
	std::regex postalCodePattern = std::regex("[0-9]{2}-[0-9]{3}"); //!< Wzorzec wyra¿enia regularnego dla kodu pocztowego
	std::regex airportCodePattern = std::regex("[A-Z]{4}"); //!< Wzorzec wyra¿enia regularnego dla kodu lotniska
	std::regex registrationPattern = std::regex("[A-Z]{2}-[A-Z]{3}"); //!< Wzorzec wyra¿enia regularnego dla rejestracji samolotów
	std::regex typePattern = std::regex("[A-Z][0-9]{3}"); //!< Wzorzec wyra¿enia regularnego dla typu samolotu
	std::regex connCodePattern = std::regex("[A-Z]{3}[0-9]{5}"); //!< Wzorzec wyra¿enia regularnego dla kodu po³¹czenia

	/*!
		Pobieranie z aktualnie przetwarzanego polecenia jednego tokenu/s³owa/wyrazu
		@return Pobrane z polecenia s³owo
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
	/*! Dodawanie nowego po³¹czenia */
	void addConnection();
	/*! Usuwanie po³¹czenia */
	void removeConnection();
	/*! Dodawanie nowego biletu */
	void addTicket();
	/*! Usuwanie biletu */
	void removeTicket();
	/*! Dodatkowa funkcja zapewniaj¹ca poprawne usuwanie zagnie¿d¿eñ w lotniskach */
	void delAirports(std::shared_ptr<City> c);
	/*! Dodatkowa funkcja zapewniaj¹ca poprawne usuwanie zagnie¿d¿eñ w po³¹czeniach */
	void delConns(std::shared_ptr<Airport> a);

};



#endif
