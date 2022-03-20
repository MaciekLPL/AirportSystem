#ifndef STAFF_H
#define STAFF_H

#include <iostream>

class Airport;
//! Klasa reprezentuj¹ca pracownika.
/*!
	Reprezentuje pracownika, jest klas¹ podrzêdn¹ do klasy Airport
*/
class Staff {
public:
	/*!
		Konstruktor
		@param name Imiê pracownika
		@param surname Nazwisko pracownika
		@param position Zajmowana pozycja
		@param age Wiek pracownika
	*/
	Staff(std::string name, std::string surname, std::string position, int age);
	
	std::weak_ptr<Airport> pAirport; //!< WskaŸnik do obiektu nadrzêdnego
	static int id; //!< Statyczna zmienna klasy reprezentuj¹ca ID.
	int thisID;	//!< Reprezentuje ID danego obiektu.
	std::string name; //!< Imiê pracownika
	std::string surname; //!< Nazwisko pracownika
	std::string position; //!< Zajmowana pozycja
	int age; //!< Wiek pracownika
	

};




#endif