#include "commandHandler.h"
#include "content.h"
#include "view.h"
#include "city.h"
#include "connection.h"
#include "staff.h"
#include "airplane.h"
#include "ticket.h"
#include "airport.h"

CommandHandler::CommandHandler(View* _parentView, Content* _mainContent) {
	this->parentView = _parentView;
	this->mainContent = _mainContent;
}

void CommandHandler::getCommand() {

	(*parentView).ShowConsoleCursor(1);

	(*parentView).gotoxy((*parentView).startX + 2, (*parentView).startY + 3);
	std::getline(std::cin, currentCmd);

	(*parentView).ShowConsoleCursor(0);

	if (currentCmd.empty())
		return;
	else
		splitCommand();
}

std::string CommandHandler::getToken(std::string& s) {

	size_t pos = 0;
	std::string token;
	pos = currentCmd.find(" ");
	token = currentCmd.substr(0, pos);
	currentCmd.erase(0, pos + 1);

	return token;
}

void CommandHandler::printError(std::string errorString) {

	(*parentView).clearPanelContent();
	(*parentView).gotoxy((*parentView).startX + 2, (*parentView).startY + 3);
	std::cout << errorString;

}

void CommandHandler::splitCommand() {
	
	std::string token = getToken(currentCmd);
	std::transform(token.begin(), token.end(), token.begin(), ::toupper);

	if (token == "ADD")
		addCommand();
	else if (token == "REMOVE")
		return;
	else
		printError("Invalid command. Use 'add' or 'remove'.");
}

void CommandHandler::addCommand() {
	
	std::string type = getToken(currentCmd);
	std::transform(type.begin(), type.end(), type.begin(), ::toupper);

	if (type == "CITY")
		addCity();
	else
		printError("Invalid data type.");
}

void CommandHandler::addCity() {

	std::string cityName = getToken(currentCmd);
	std::string postalCode = getToken(currentCmd);
	std::regex cityNamePattern("^[a-zA-Z-]+$");
	std::regex postalCodePattern("[0-9]{2}-[0-9]{3}");


	if ((std::regex_match(cityName, cityNamePattern)) && (std::regex_match(postalCode, postalCodePattern))) {
		(*mainContent).cityList.push_back(City(cityName, postalCode));
		(*parentView).clearPanelContent();
	}
	else
		printError("Invalid data. Use 'add City CityName PostalCode'.");
}
