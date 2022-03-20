#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <list>

class Airport;
class Ticket;
//! Klasa reprezentuj�ca po��czenie.
/*!
	Reprezentuje po��czenie, jest klas� podrz�dn� do klasy Airport
*/
class Connection {
public:

	std::weak_ptr<Airport> pOrigin; //!< Wska�nik do lotniska pocz�tkowego
	std::weak_ptr<Airport> pDestination; //!< Wska�nik do lotniska docelowego
	std::string connectionCode; //!< Kod lotniska
	/*!
		Konstruktor
		@param destination Wska�nik do lotniska docelowego
		@param code Kod lotniska
	*/
	Connection(std::shared_ptr<Airport> destination, std::string code);
	/*!
		Destruktor, usuwa z listy obiekty podrz�dne (bilety)
	*/
	~Connection();
	/*!
		Dodawanie biletu na dane po��czenie do listy.
		@param pTicket Wska�nik do obiektu Ticket
	*/
	void addTicket(std::shared_ptr<Ticket> pTicket);

private:
	std::list<std::shared_ptr<Ticket>> ticketList; //!< Lista podrz�dnych obiekt�w typu Ticket

};

#endif