#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>

class Airport;
//! Klasa reprezentująca samolot.
/*!
	Reprezentuje samolot, jest klasą podrzędną do klasy Airport
*/
class Airplane {
public:
	/*!
		Konstruktor
		@param _registration Rejestracja samolotu
		@param _type Typ samolotu
	*/
	Airplane(std::string _registration, std::string _type);

	std::weak_ptr<Airport> pAirport; //!< Wskaźnik do obiektu nadrzędnego typu Airport
	std::string registration; //!< Rejestracja samolotu
	std::string type; //!< Typ samolotu
	

};

#endif