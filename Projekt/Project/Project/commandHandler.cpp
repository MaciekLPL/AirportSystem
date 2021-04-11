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
		removeCommand();
	else
		printError("Invalid command. Use 'add' or 'remove'.");
}

void CommandHandler::addCommand() {
	
	std::string type = getToken(currentCmd);
	std::transform(type.begin(), type.end(), type.begin(), ::toupper);

	if (type == "CITY")
		addCity();
	else if (type == "AIRPORT")
		addAirport();
	else
		printError("Invalid data type.");
}

void CommandHandler::removeCommand() {

	std::string type = getToken(currentCmd);
	std::transform(type.begin(), type.end(), type.begin(), ::toupper);

	if (type == "CITY")
		removeCity();
	else if (type == "AIRPORT")
		removeAirport();
	else
		printError("Invalid data type.");
}

void CommandHandler::addCity() {

	std::string cityName = getToken(currentCmd);
	std::string postalCode = getToken(currentCmd);
	std::regex cityNamePattern("^[a-zA-Z-]+$");
	std::regex postalCodePattern("[0-9]{2}-[0-9]{3}");


	if ((std::regex_match(cityName, cityNamePattern)) && 
		(std::regex_match(postalCode, postalCodePattern))) {

		(*mainContent).cityList.push_back(City(cityName, postalCode));
		(*parentView).clearPanelContent();
	}
	else
		printError("Invalid data. Use 'add City [CityName] [PostalCode]'.");
}

void CommandHandler::removeCity() {

	std::string cityName = getToken(currentCmd);
	const size_t orgSize = (*mainContent).cityList.size();

	(*mainContent).cityList.erase(
		std::remove_if((*mainContent).cityList.begin(), (*mainContent).cityList.end(),
		[cityName](const City& city) { return city.cityName == cityName; }),
		(*mainContent).cityList.end());

	if ((*mainContent).cityList.size() == orgSize)
		printError("Couldn't remove city.");
	else
		(*parentView).clearPanelContent();
}

void CommandHandler::addAirport() {

	std::string cityName = getToken(currentCmd);
	std::string airportCode = getToken(currentCmd);
	std::string airportName = getToken(currentCmd);
	std::regex airportCodePattern("[A-Z]{4}");
	std::regex airportNamePattern("^[a-zA-Z-]+$");


	auto result = std::find_if(std::begin((*mainContent).cityList), std::end((*mainContent).cityList),
		[cityName](City const& c) { return c.cityName == cityName; });

	if (result == (*mainContent).cityList.end()) {
		printError("Invalid data. Couldn't find given city.");
		return;
	}

	if ((std::regex_match(airportCode, airportCodePattern)) && 
		(std::regex_match(airportName, airportNamePattern))) {
		
		Airport tmp = Airport(airportCode, airportName);
		(*result).addAirport(tmp);
		(*mainContent).airportList.push_back(tmp);
		(*parentView).clearPanelContent();
	}
	else
		printError("Invalid data. Use 'add Airport [ExistingCity] [AirportCode] [AirportName]'.");
}

void CommandHandler::removeAirport() {

	std::string airportCode = getToken(currentCmd);
	const size_t orgSize = (*mainContent).airportList.size();

	/*auto result = std::find_if(std::begin((*mainContent).airportList), std::end((*mainContent).airportList),
		[airportCode](Airport const& a) { return a.airportCode == airportCode; });

	if (result == (*mainContent).airportList.end()) {
		printError("Invalid data. Couldn't find given airport.");
		return;
	}*/

	(*mainContent).airportList.erase(
		std::remove_if((*mainContent).airportList.begin(), (*mainContent).airportList.end(),
			[airportCode](const Airport& a) { return a.airportCode == airportCode; }),
		(*mainContent).airportList.end());

	//(*result).pCity->airportList.erase(
	//	std::remove_if((*result).pCity->airportList.begin(), (*result).pCity->airportList.end(),	//Usuwa obiekt?? Do sprawdzenia
	//		[airportCode](const Airport& a) { return a.airportCode == airportCode; }),
	//	(*result).pCity->airportList.end());


	if ((*mainContent).airportList.size() == orgSize)
		printError("Couldn't remove city.");
	else
		(*parentView).clearPanelContent();
}
