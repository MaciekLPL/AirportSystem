#ifndef STAFF_H
#define STAFF_H

#include <iostream>

class Airport;

class Staff {
public:
	std::weak_ptr<Airport> pAirport;
	static int id;
	int thisID;
	std::string name;
	std::string surname;
	std::string position;
	int age;

	Staff(std::string name, std::string surname, std::string position, int age);

};




#endif