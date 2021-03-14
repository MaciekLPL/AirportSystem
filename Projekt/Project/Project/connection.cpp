#include "connection.h"

Connection::Connection(Airport* destination, std::string code) {
	//this->pOrigin = origin;
	this->pDestination = destination;
	this->connectionCode = code;
}