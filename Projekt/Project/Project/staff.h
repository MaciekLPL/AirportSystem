#ifndef STAFF_H
#define STAFF_H

#include <iostream>

class Airport;
//! Klasa reprezentuj�ca pracownika.
/*!
	Reprezentuje pracownika, jest klas� podrz�dn� do klasy Airport
*/
class Staff {
public:
	/*!
		Konstruktor
		@param name Imi� pracownika
		@param surname Nazwisko pracownika
		@param position Zajmowana pozycja
		@param age Wiek pracownika
	*/
	Staff(std::string name, std::string surname, std::string position, int age);
	
	std::weak_ptr<Airport> pAirport; //!< Wska�nik do obiektu nadrz�dnego
	static int id; //!< Statyczna zmienna klasy reprezentuj�ca ID.
	int thisID;	//!< Reprezentuje ID danego obiektu.
	std::string name; //!< Imi� pracownika
	std::string surname; //!< Nazwisko pracownika
	std::string position; //!< Zajmowana pozycja
	int age; //!< Wiek pracownika
	

};




#endif