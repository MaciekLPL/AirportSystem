#include "connection.h"

Connection::Connection(Airport* destination, std::string code) {
	//this->pOrigin = origin;
	this->pDestination = destination;
	this->connectionCode = code;
}

Connection::Connection() {
	this->pDestination = nullptr;
	this->pOrigin = nullptr;
	this->connectionCode = "";
}

Connection::Connection(Connection* connection) {
	this->pOrigin = connection->pOrigin;
	this->pDestination = connection->pDestination;
	this->connectionCode = connection->connectionCode;

}
