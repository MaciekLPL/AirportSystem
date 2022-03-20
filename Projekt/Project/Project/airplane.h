#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>

class Airport;
//! Klasa reprezentuj�ca samolot.
/*!
	Reprezentuje samolot, jest klas� podrz�dn� do klasy Airport
*/
class Airplane {
public:
	/*!
		Konstruktor
		@param _registration Rejestracja samolotu
		@param _type Typ samolotu
	*/
	Airplane(std::string _registration, std::string _type);

	std::weak_ptr<Airport> pAirport; //!< Wska�nik do obiektu nadrz�dnego typu Airport
	std::string registration; //!< Rejestracja samolotu
	std::string type; //!< Typ samolotu
	

};

#endif