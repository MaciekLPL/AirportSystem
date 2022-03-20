#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <list>

class City;
class Connection;
class Staff;
class Airplane;
//! Klasa reprezentuj�ca lotnisko.
/*!
	Reprezentuje lotnisko, jest klas� podrz�dn� do klasy City
	Dziedziczy z enable_shared_from_this by uzyska� mo�lwiwo�� tworzenia weak_ptr z this
*/
class Airport : public std::enable_shared_from_this <Airport> {
public:

	std::weak_ptr<City> pCity; //!< Wska�nik do obiektu nadrz�dnego typu City
	std::string airportCode; //!< Kod lotniska
	std::string airportName; //!< Nazwa lotniska
	/*!
		Konstruktor
		@param code Kod lotniska
		@param name Nazwa lotniska
	*/
	Airport(std::string code, std::string name);
	/*!
		Desturktor, usuwa podrz�dne obiekty
	*/
	~Airport();
	/*!
		Dodawanie po��czenia do listy po��cze� lotniska
		@param connection Wska�nik na dodawane po��czenie
	*/
	void addConnection(std::shared_ptr<Connection> connection);
	/*!
		Dodawanie pracownika do listy pracownik�w lotniska
		@param pStaff Wska�nik na dodawanego pracownika
	*/
	void addStaff(std::shared_ptr<Staff> pStaff);
	/*!
		Dodawanie samolotu do listy samolot�w lotniska
		@param pAirplane Wska�nik na dodawany samolot
	*/
	void addAirplane(std::shared_ptr<Airplane> pAirplane);

private:

	std::list<std::shared_ptr<Connection>> connectionList; //!< Lista po��cze� lotniska
	std::list<std::shared_ptr<Staff>> staffList; //!< Lista pracownik�w lotniska
	std::list<std::shared_ptr<Airplane>> airplaneList; //!< Lista samolot�w lotniska

};

#endif
