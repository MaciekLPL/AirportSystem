#ifndef TICKET_H
#define TICKET_H

#include <iostream>

class Connection;
//! Klasa reprezentuj�ca bilet.
/*!
	Reprezentuje bilet, jest klas� podrz�dn� do klasy Connection
*/
class Ticket {
public:
	/*!
		Konstruktor 
		@param connection Wska�nik do obiektu nadrz�dnego
		@param _numOfPassengers Ilo�� pasa�er�w przypisanych do biletu
		@param _price Koszt biletu
	*/
	Ticket(std::shared_ptr<Connection> connection, int _numOfPassengers, int _price);

	static int id;	//!< Statyczna zmienna klasy reprezentuj�ca ID.
	int thisID;	//!< Reprezentuje ID danego obiektu.
	std::weak_ptr<Connection> pConnection;	//!< Wska�nik do obiektu nadrz�dnego
	int numOfPassengers; //!< Ilo�� pasa�er�w przypisanych do biletu
	int price;	//!< Koszt biletu
	

};

#endif