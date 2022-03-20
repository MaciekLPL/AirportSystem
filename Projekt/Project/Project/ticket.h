#ifndef TICKET_H
#define TICKET_H

#include <iostream>

class Connection;
//! Klasa reprezentuj¹ca bilet.
/*!
	Reprezentuje bilet, jest klas¹ podrzêdn¹ do klasy Connection
*/
class Ticket {
public:
	/*!
		Konstruktor 
		@param connection WskaŸnik do obiektu nadrzêdnego
		@param _numOfPassengers Iloœæ pasa¿erów przypisanych do biletu
		@param _price Koszt biletu
	*/
	Ticket(std::shared_ptr<Connection> connection, int _numOfPassengers, int _price);

	static int id;	//!< Statyczna zmienna klasy reprezentuj¹ca ID.
	int thisID;	//!< Reprezentuje ID danego obiektu.
	std::weak_ptr<Connection> pConnection;	//!< WskaŸnik do obiektu nadrzêdnego
	int numOfPassengers; //!< Iloœæ pasa¿erów przypisanych do biletu
	int price;	//!< Koszt biletu
	

};

#endif