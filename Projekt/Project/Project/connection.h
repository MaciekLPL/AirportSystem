#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <list>

class Airport;
class Ticket;
//! Klasa reprezentuj¹ca po³¹czenie.
/*!
	Reprezentuje po³¹czenie, jest klas¹ podrzêdn¹ do klasy Airport
*/
class Connection {
public:

	std::weak_ptr<Airport> pOrigin; //!< WskaŸnik do lotniska pocz¹tkowego
	std::weak_ptr<Airport> pDestination; //!< WskaŸnik do lotniska docelowego
	std::string connectionCode; //!< Kod lotniska
	/*!
		Konstruktor
		@param destination WskaŸnik do lotniska docelowego
		@param code Kod lotniska
	*/
	Connection(std::shared_ptr<Airport> destination, std::string code);
	/*!
		Destruktor, usuwa z listy obiekty podrzêdne (bilety)
	*/
	~Connection();
	/*!
		Dodawanie biletu na dane po³¹czenie do listy.
		@param pTicket WskaŸnik do obiektu Ticket
	*/
	void addTicket(std::shared_ptr<Ticket> pTicket);

private:
	std::list<std::shared_ptr<Ticket>> ticketList; //!< Lista podrzêdnych obiektów typu Ticket

};

#endif