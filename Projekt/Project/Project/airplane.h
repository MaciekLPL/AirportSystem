#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>

class Airplane {
public:
	class Airport* airport;
	std::string registration;
	std::string airplaneType;
	Airplane(std::string _registration, std::string _arplaneType);

private:

};

#endif