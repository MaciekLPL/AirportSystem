#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <list>

class Airport;
class Ticket;
//! Klasa reprezentująca połączenie.
/*!
	Reprezentuje połączenie, jest klasą podrzędną do klasy Airport
*/
class Connection {
public:

	std::weak_ptr<Airport> pOrigin; //!< Wskaźnik do lotniska początkowego
	std::weak_ptr<Airport> pDestination; //!< Wskaźnik do lotniska docelowego
	std::string connectionCode; //!< Kod lotniska
	/*!
		Konstruktor
		@param destination Wskaźnik do lotniska docelowego
		@param code Kod lotniska
	*/
	Connection(std::shared_ptr<Airport> destination, std::string code);
	/*!
		Destruktor, usuwa z listy obiekty podrzędne (bilety)
	*/
	~Connection();
	/*!
		Dodawanie biletu na dane połączenie do listy.
		@param pTicket Wskaźnik do obiektu Ticket
	*/
	void addTicket(std::shared_ptr<Ticket> pTicket);

private:
	std::list<std::shared_ptr<Ticket>> ticketList; //!< Lista podrzędnych obiektów typu Ticket

};

#endif