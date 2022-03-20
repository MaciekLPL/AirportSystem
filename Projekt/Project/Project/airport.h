#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <list>

class City;
class Connection;
class Staff;
class Airplane;
//! Klasa reprezentuj¹ca lotnisko.
/*!
	Reprezentuje lotnisko, jest klas¹ podrzêdn¹ do klasy City
	Dziedziczy z enable_shared_from_this by uzyskaæ mo¿lwiwoœæ tworzenia weak_ptr z this
*/
class Airport : public std::enable_shared_from_this <Airport> {
public:

	std::weak_ptr<City> pCity; //!< WskaŸnik do obiektu nadrzêdnego typu City
	std::string airportCode; //!< Kod lotniska
	std::string airportName; //!< Nazwa lotniska
	/*!
		Konstruktor
		@param code Kod lotniska
		@param name Nazwa lotniska
	*/
	Airport(std::string code, std::string name);
	/*!
		Desturktor, usuwa podrzêdne obiekty
	*/
	~Airport();
	/*!
		Dodawanie po³¹czenia do listy po³¹czeñ lotniska
		@param connection WskaŸnik na dodawane po³¹czenie
	*/
	void addConnection(std::shared_ptr<Connection> connection);
	/*!
		Dodawanie pracownika do listy pracowników lotniska
		@param pStaff WskaŸnik na dodawanego pracownika
	*/
	void addStaff(std::shared_ptr<Staff> pStaff);
	/*!
		Dodawanie samolotu do listy samolotów lotniska
		@param pAirplane WskaŸnik na dodawany samolot
	*/
	void addAirplane(std::shared_ptr<Airplane> pAirplane);

private:

	std::list<std::shared_ptr<Connection>> connectionList; //!< Lista po³¹czeñ lotniska
	std::list<std::shared_ptr<Staff>> staffList; //!< Lista pracowników lotniska
	std::list<std::shared_ptr<Airplane>> airplaneList; //!< Lista samolotów lotniska

};

#endif
