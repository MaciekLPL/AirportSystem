#include "commandHandler.h"
#include "content.h"
#include "view.h"
#include "city.h"
#include "airport.h"
#include "staff.h"
#include "airplane.h"
#include "connection.h"
#include "ticket.h"


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
	else if (type == "AIRPLANE")
		addAirplane();
	else if (type == "STAFF")
		addStaff();
	else if (type == "CONNECTION")
		addConnection();
	else if (type == "TICKET")
		addTicket();
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
	else if (type == "AIRPLANE")
		removeAirplane();
	else if (type == "STAFF")
		removeStaff();
	else if (type == "CONNECTION")
		removeConnection();
	else if (type == "TICKET")
		removeTicket();
	else
		printError("Invalid data type.");
}


void CommandHandler::addCity() {

	std::string cityName = getToken(currentCmd);
	std::string postalCode = getToken(currentCmd);


	if ((std::regex_match(cityName, namePattern)) && 
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

	auto parentCity = std::find_if(std::begin((*mainContent).cityList), std::end((*mainContent).cityList),
		[cityName](City const& c) { return c.cityName == cityName; });

	if (parentCity == (*mainContent).cityList.end()) {
		printError("Invalid data. Couldn't find given city.");
		return;
	}

	if ((std::regex_match(airportCode, airportCodePattern)) && 
		(std::regex_match(airportName, namePattern))) {
		
		Airport tmp = Airport(airportCode, airportName);
		(*parentCity).addAirport(tmp);
		(*mainContent).airportList.push_back(tmp);
		(*parentView).clearPanelContent();
	}
	else
		printError("Invalid data. Use 'add Airport [ExistingCity] [AirportCode] [AirportName]'.");
}


void CommandHandler::removeAirport() {

	std::string airportCode = getToken(currentCmd);
	const size_t orgSize = (*mainContent).airportList.size();

	(*mainContent).airportList.erase(
		std::remove_if((*mainContent).airportList.begin(), (*mainContent).airportList.end(),
			[airportCode](const Airport& a) { return a.airportCode == airportCode; }),
		(*mainContent).airportList.end());


	if ((*mainContent).airportList.size() == orgSize)
		printError("Couldn't remove airport.");
	else
		(*parentView).clearPanelContent();
}


void CommandHandler::addAirplane() {

	std::string airportCode = getToken(currentCmd);
	std::string registation = getToken(currentCmd);
	std::string type = getToken(currentCmd);


	auto parentAirport = std::find_if(std::begin((*mainContent).airportList), std::end((*mainContent).airportList),
		[airportCode](Airport const& a) { return a.airportCode == airportCode; });

	if (parentAirport == (*mainContent).airportList.end()) {
		printError("Invalid data. Couldn't find given airport.");
		return;
	}

	if ((std::regex_match(registation, registrationPattern)) &&
		(std::regex_match(type, typePattern))) {

		Airplane tmp = Airplane(registation, type);
		(*parentAirport).addAirplane(tmp);
		(*mainContent).airplaneList.push_back(tmp);
		(*parentView).clearPanelContent();
	}
	else
		printError("Invalid data. Use 'add Airplane [ExistingAirport] [Registration] [Type]'.");
}


void CommandHandler::removeAirplane() {
	
	std::string registration = getToken(currentCmd);
	const size_t orgSize = (*mainContent).airplaneList.size();

	(*mainContent).airplaneList.erase(
		std::remove_if((*mainContent).airplaneList.begin(), (*mainContent).airplaneList.end(),
			[registration](const Airplane& a) { return a.registration == registration; }),
		(*mainContent).airplaneList.end());


	if ((*mainContent).airplaneList.size() == orgSize)
		printError("Couldn't remove airplane.");
	else
		(*parentView).clearPanelContent();
}


void CommandHandler::addStaff(){
	std::string airportCode = getToken(currentCmd);
	std::string name = getToken(currentCmd);
	std::string surname = getToken(currentCmd);
	std::string position = getToken(currentCmd);
	int age = std::stoi(getToken(currentCmd));


	auto parentAirport = std::find_if(std::begin((*mainContent).airportList), std::end((*mainContent).airportList),
		[airportCode](Airport const& a) { return a.airportCode == airportCode; });

	if (parentAirport == (*mainContent).airportList.end()) {
		printError("Invalid data. Couldn't find given airport.");
		return;
	}

	if ((std::regex_match(name, namePattern)) &&
		(std::regex_match(surname, namePattern)) &&
		(std::regex_match(position, namePattern))) {

		Staff tmp = Staff(name, surname, position, age);
		(*parentAirport).addStaff(tmp);
		(*mainContent).staffList.push_back(tmp);
		(*parentView).clearPanelContent();
	}
	else
		printError("Invalid data. Use 'add Staff [ExistingAirport] [Name] [Surname] [Position] [Age]'.");
}


void CommandHandler::removeStaff() {
	int id = std::stoi(getToken(currentCmd));
	const size_t orgSize = (*mainContent).staffList.size();

	(*mainContent).staffList.erase(
		std::remove_if((*mainContent).staffList.begin(), (*mainContent).staffList.end(),
			[id](const Staff& s) { return s.thisID == id; }),
		(*mainContent).staffList.end());


	if ((*mainContent).staffList.size() == orgSize)
		printError("Couldn't remove staff.");
	else
		(*parentView).clearPanelContent();
}


void CommandHandler::addConnection() {
	std::string orgAirportCode = getToken(currentCmd);
	std::string destAirportCode = getToken(currentCmd);
	std::string connCode = getToken(currentCmd);


	auto orgAirport = std::find_if(std::begin((*mainContent).airportList), std::end((*mainContent).airportList),
		[orgAirportCode](Airport const& a) { return a.airportCode == orgAirportCode; });

	auto destAirport = std::find_if(std::begin((*mainContent).airportList), std::end((*mainContent).airportList),
		[destAirportCode](Airport const& a) { return a.airportCode == destAirportCode; });

	if (orgAirport == (*mainContent).airportList.end() || destAirport == (*mainContent).airportList.end()) {
		printError("Invalid data. Couldn't find given airports.");
		return;
	}

	if ((std::regex_match(connCode, connCodePattern))) {

		Connection tmp = Connection(*destAirport, connCode);
		(*orgAirport).addConnection(tmp);
		(*mainContent).connectionList.push_back(tmp);
		(*parentView).clearPanelContent();
	}
	else
		printError("Invalid data. Use 'add Connection [From (Airport Code)] [To (Airport Code)] [Connection Code]'.");
}


void CommandHandler::removeConnection() {
	std::string connCode = getToken(currentCmd);
	const size_t orgSize = (*mainContent).connectionList.size();

	(*mainContent).connectionList.erase(
		std::remove_if((*mainContent).connectionList.begin(), (*mainContent).connectionList.end(),
			[connCode](const Connection& c) { return c.connectionCode == connCode; }),
		(*mainContent).connectionList.end());


	if ((*mainContent).staffList.size() == orgSize)
		printError("Couldn't remove connection.");
	else
		(*parentView).clearPanelContent();
}

void CommandHandler::addTicket() {
	std::string connCode = getToken(currentCmd);
	int numOfPassenger = stoi(getToken(currentCmd));
	int price = stoi(getToken(currentCmd));


	auto connection = std::find_if(std::begin((*mainContent).connectionList), std::end((*mainContent).connectionList),
		[connCode](Connection const& c) { return c.connectionCode == connCode; });


	if (connection == (*mainContent).connectionList.end()) {
		printError("Invalid data. Couldn't find given connection.");
		return;
	}

	if (numOfPassenger > 0) {

		Ticket tmp = Ticket(*connection, numOfPassenger, price);
		(*connection).addTicket(tmp);
		(*mainContent).ticketList.push_back(tmp);
		(*parentView).clearPanelContent();
	}
	else
		printError("Invalid data. Use 'add Ticket [Connection code] [No. of passengers] [Price]'.");
}

void CommandHandler::removeTicket() {
	int id = std::stoi(getToken(currentCmd));
	const size_t orgSize = (*mainContent).ticketList.size();

	(*mainContent).ticketList.erase(
		std::remove_if((*mainContent).ticketList.begin(), (*mainContent).ticketList.end(),
			[id](const Ticket& t) { return t.thisID == id; }),
		(*mainContent).ticketList.end());


	if ((*mainContent).ticketList.size() == orgSize)
		printError("Couldn't remove ticket.");
	else
		(*parentView).clearPanelContent();
}
