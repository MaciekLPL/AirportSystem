#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

class View;
class Content;

class CommandHandler {
public:
	CommandHandler(View* _parentView, Content* _mainContent);
	void getCommand();
	void splitCommand();
	std::string currentCmd;

private:
	View* parentView;
	Content* mainContent;

	std::regex namePattern = std::regex("^[a-zA-Z-]+$");
	std::regex postalCodePattern = std::regex("[0-9]{2}-[0-9]{3}");
	std::regex airportCodePattern = std::regex("[A-Z]{4}");
	std::regex registrationPattern = std::regex("[A-Z]{2}-[A-Z]{3}");
	std::regex typePattern = std::regex("[A-Z][0-9]{3}");
	std::regex connCodePattern = std::regex("[A-Z]{3}[0-9]{5}");

	std::string getToken(std::string& s);
	void printError(std::string errorString);
	void addCommand();
	void removeCommand();
	
	void addCity();
	void removeCity();

	void addAirport();
	void removeAirport();

	void addAirplane();
	void removeAirplane();

	void addStaff();
	void removeStaff();

	void addConnection();
	void removeConnection();

	void addTicket();
	void removeTicket();
};



#endif
