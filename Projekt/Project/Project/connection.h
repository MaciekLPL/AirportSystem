#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>

class Connection {
public:
	class Airport* pOrigin;
	class Airport* pDestination;
	std::string connectionCode;
	Connection();
	Connection(Connection* connection);
	~Connection() {};
	Connection(Airport* destination, std::string code);

private:

};




#endif