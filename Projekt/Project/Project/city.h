#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <list>

class Airport;
//! Klasa reprezentująca miasto.
/*!
	Reprezentuje miasto, jest klasą nadrzędną do klasy Airport
	Dziedziczy z enable_shared_from_this by uzyskać możlwiwość tworzenia weak_ptr z this
*/
class City : public std::enable_shared_from_this <City> {
public:
	/*!
		Konstruktor
		@param name Nazwa miasta
		@param postal Kod pocztowy
	*/
	City(std::string name, std::string postal);
	/*!
		Destruktor, usuwa podrzędne obiekty
	*/
	~City();
	/*!
		Dodawanie lotniska do listy danego miasta.
		@param airport Wskaźnik do obiektu podrzędnego Airport
	*/
	void addAirport(std::shared_ptr<Airport> airport);

	std::string cityName; //!< Nazwa miasta
	std::string postalCode; //!< Kod pocztowy
	std::list<std::shared_ptr<Airport>> airportList; //!< Lista podrzędnych obiektów typu Airport

};


#endif
