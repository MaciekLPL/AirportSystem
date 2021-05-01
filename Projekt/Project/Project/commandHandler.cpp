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

	parentView->ShowConsoleCursor(1);

	parentView->gotoxy(parentView->startX + 2, parentView->startY + 3);
	std::getline(std::cin, currentCmd);

	parentView->ShowConsoleCursor(0);

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


void CommandHandler::printInformation(std::string info) {

	parentView->clearPanelContent();
	parentView->gotoxy(parentView->startX + 2, parentView->startY + 3);
	std::cout << info;
}


void CommandHandler::splitCommand() {
	
	std::string token = getToken(currentCmd);
	std::transform(token.begin(), token.end(), token.begin(), ::toupper);

	if (token == "ADD")
		addCommand();
	else if (token == "REMOVE")
		removeCommand();
	else
		printInformation("Invalid command. Use 'add' or 'remove'.");
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
		printInformation("Invalid data type.");
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
		printInformation("Invalid data type.");
}


void CommandHandler::addCity() {

	std::string cityName = getToken(currentCmd);
	std::string postalCode = getToken(currentCmd);


	if ((std::regex_match(cityName, namePattern)) && 
		(std::regex_match(postalCode, postalCodePattern))) {

		auto tmp = std::make_shared<City>(cityName, postalCode);
		mainContent->cityList.push_back(tmp);
		parentView->clearPanelContent();
	}
	else
		printInformation("Invalid data. Use 'add City [CityName] [PostalCode]'.");
}


void CommandHandler::addAirport() {

	std::string postalCode = getToken(currentCmd);
	std::string airportCode = getToken(currentCmd);
	std::string airportName = getToken(currentCmd);

	auto parentCity = std::find_if(std::begin(mainContent->cityList), std::end(mainContent->cityList),
		[&](std::shared_ptr<City> c) { return c->postalCode == postalCode; });

	if (parentCity == mainContent->cityList.end()) {
		printInformation("Invalid data. Couldn't find given city.");
		return;
	}

	if ((std::regex_match(airportCode, airportCodePattern)) &&
		(std::regex_match(airportName, namePattern))) {

		auto tmp = std::make_shared<Airport>(airportCode, airportName);
		mainContent->airportList.push_back(tmp);
		(*parentCity)->addAirport(tmp);
		parentView->clearPanelContent();
	}
	else
		printInformation("Invalid data. Use 'add Airport [ExistingCity] [AirportCode] [AirportName]'.");
}


void CommandHandler::addAirplane() {

	std::string airportCode = getToken(currentCmd);
	std::string registation = getToken(currentCmd);
	std::string type = getToken(currentCmd);

	auto parentAirport = std::find_if(std::begin(mainContent->airportList), std::end(mainContent->airportList),
		[&](std::shared_ptr<Airport> a) { return a->airportCode == airportCode; });

	if (parentAirport == mainContent->airportList.end()) {
		printInformation("Invalid data. Couldn't find given airport.");
		return;
	}

	if ((std::regex_match(registation, registrationPattern)) &&
		(std::regex_match(type, typePattern))) {

		auto tmp = std::make_shared<Airplane>(registation, type);
		mainContent->airplaneList.push_back(tmp);
		(*parentAirport)->addAirplane(tmp);
		parentView->clearPanelContent();
	}
	else
		printInformation("Invalid data. Use 'add Airplane [ExistingAirport] [Registration] [Type]'.");
}


void CommandHandler::addStaff() {

	try {
		std::string airportCode = getToken(currentCmd);
		std::string name = getToken(currentCmd);
		std::string surname = getToken(currentCmd);
		std::string position = getToken(currentCmd);
		int age = std::stoi(getToken(currentCmd));

		auto parentAirport = std::find_if(std::begin(mainContent->airportList), std::end(mainContent->airportList),
			[airportCode](std::shared_ptr<Airport> a) { return a->airportCode == airportCode; });

		if (parentAirport == mainContent->airportList.end()) {
			printInformation("Invalid data. Couldn't find given airport.");
			return;
		}

		if ((std::regex_match(name, namePattern)) &&
			(std::regex_match(surname, namePattern)) &&
			(std::regex_match(position, namePattern))) {

			auto tmp = std::make_shared<Staff>(name, surname, position, age);
			mainContent->staffList.push_back(tmp);
			(*parentAirport)->addStaff(tmp);
			parentView->clearPanelContent();
		}
		else
			throw;
	}
	catch (...) {
		printInformation("Invalid data. Use 'add Staff [ExistingAirport] [Name] [Surname] [Position] [Age]'.");
		return;
	}
}


void CommandHandler::addConnection() {
	std::string orgAirportCode = getToken(currentCmd);
	std::string destAirportCode = getToken(currentCmd);
	std::string connCode = getToken(currentCmd);


	auto orgAirport = std::find_if(std::begin(mainContent->airportList), std::end(mainContent->airportList),
		[&](std::shared_ptr<Airport> a) { return a->airportCode == orgAirportCode; });

	auto destAirport = std::find_if(std::begin(mainContent->airportList), std::end(mainContent->airportList),
		[&](std::shared_ptr<Airport> a) { return a->airportCode == destAirportCode; });

	if (orgAirport == mainContent->airportList.end() || destAirport == mainContent->airportList.end()) {
		printInformation("Invalid data. Couldn't find given airports.");
		return;
	}

	if ((std::regex_match(connCode, connCodePattern))) {

		auto tmp = std::make_shared<Connection>(*destAirport, connCode);
		(*orgAirport)->addConnection(tmp);
		mainContent->connectionList.push_back(tmp);
		parentView->clearPanelContent();
	}
	else
		printInformation("Invalid data. Use 'add Connection [From (Airport Code)] [To (Airport Code)] [Connection Code]'.");
}


void CommandHandler::addTicket() {
	
	try {
		std::string connCode = getToken(currentCmd);
		int numOfPassenger = stoi(getToken(currentCmd));
		int price = stoi(getToken(currentCmd));

		auto connection = std::find_if(std::begin(mainContent->connectionList), std::end(mainContent->connectionList),
			[&](std::shared_ptr<Connection> c) { return c->connectionCode == connCode; });

		if (connection == mainContent->connectionList.end()) {
			printInformation("Invalid data. Couldn't find given connection.");
			return;
		}

		if (numOfPassenger != 0) {
			auto tmp = std::make_shared<Ticket>(*connection, numOfPassenger, price);
			(*connection)->addTicket(tmp);
			mainContent->ticketList.push_back(tmp);
			parentView->clearPanelContent();
		}
		else
			throw;
	}
	catch (...) {
		printInformation("Invalid data. Use 'add Ticket [Connection code] [No. of passengers] [Price]'.");
		return;
	}
}


void CommandHandler::removeCity() {

	std::string postalCode = getToken(currentCmd);
	const size_t orgSize = mainContent->cityList.size();

	auto city = std::find_if(std::begin(mainContent->cityList), std::end(mainContent->cityList),
		[&](std::shared_ptr<City> c) { return c->postalCode == postalCode; });

	delAirports(*city);
	mainContent->cityList.erase(city);

	if (mainContent->cityList.size() == orgSize)
		printInformation("Couldn't remove city.");
	else
		parentView->clearPanelContent();
}


void CommandHandler::removeAirport() {

	std::string airportCode = getToken(currentCmd);
	const size_t orgSize = mainContent->airportList.size();

	auto airport = std::find_if(std::begin(mainContent->airportList), std::end(mainContent->airportList),
		[&](std::shared_ptr<Airport> a) { return a->airportCode == airportCode; });

	delConns(*airport);
	mainContent->airplaneList.remove_if([&](std::shared_ptr<Airplane> a) { return a->pAirport.lock() == (*airport); });
	mainContent->staffList.remove_if([&](std::shared_ptr<Staff> s) { return s->pAirport.lock() == (*airport); });
	mainContent->airportList.erase(airport);

	if (mainContent->airportList.size() == orgSize)
		printInformation("Couldn't remove airport.");
	else
		parentView->clearPanelContent();
}


void CommandHandler::removeAirplane() {
	
	std::string registration = getToken(currentCmd);
	const size_t orgSize = mainContent->airplaneList.size();

	mainContent->airplaneList.remove_if([&](std::shared_ptr<Airplane> a) { return a->registration == registration; });

	if (mainContent->airplaneList.size() == orgSize)
		printInformation("Couldn't remove airplane.");
	else
		parentView->clearPanelContent();
}


void CommandHandler::removeStaff() {

	try {
		int id = std::stoi(getToken(currentCmd));
		const size_t orgSize = mainContent->staffList.size();

		mainContent->staffList.remove_if([&](std::shared_ptr<Staff> s) { return s->thisID == id; });

		if (mainContent->staffList.size() == orgSize)
			printInformation("Couldn't remove staff.");
		else
			parentView->clearPanelContent();
	}
	catch (...) {
		printInformation("Invalid data. Use 'remove Staff [id].");
		return;
	}
}


void CommandHandler::removeConnection() {
	std::string connCode = getToken(currentCmd);
	const size_t orgSize = mainContent->connectionList.size();

	auto connection = std::find_if(std::begin(mainContent->connectionList), std::end(mainContent->connectionList),
		[&](std::shared_ptr<Connection> c) { return c->connectionCode == connCode; });

	mainContent->ticketList.remove_if([&](std::shared_ptr<Ticket> t) { return t->pConnection.lock()->connectionCode == (*connection)->connectionCode; });
	mainContent->connectionList.erase(connection);

	if (mainContent->staffList.size() == orgSize)
		printInformation("Couldn't remove connection.");
	else
		parentView->clearPanelContent();
}


void CommandHandler::removeTicket() {

	try {
		int id = std::stoi(getToken(currentCmd));
		const size_t orgSize = mainContent->ticketList.size();

		mainContent->ticketList.remove_if([&](std::shared_ptr<Ticket> t) { return t->thisID == id; });

		if (mainContent->ticketList.size() == orgSize)
			printInformation("Couldn't remove ticket.");
		else
			parentView->clearPanelContent();
	}
	catch (...) {
		printInformation("Invalid data. Use 'remove Ticket [id].");
		return;
	}
}


void CommandHandler::delAirports(std::shared_ptr<City> c) {
	for (auto i = mainContent->airportList.begin(); i != mainContent->airportList.end();) {
		if ((*i)->pCity.lock() == c) {
			delConns(*i);
			mainContent->airplaneList.remove_if([&](std::shared_ptr<Airplane> a) { return a->pAirport.lock() == (*i); });
			mainContent->staffList.remove_if([&](std::shared_ptr<Staff> s) { return s->pAirport.lock() == (*i); });
			i = mainContent->airportList.erase(i);
		}
		else
			i++;
	}
}

void CommandHandler::delConns(std::shared_ptr<Airport> a) {
	
	for (auto i = mainContent->connectionList.begin(); i != mainContent->connectionList.end(); ) {
		if ((*i)->pOrigin.lock() == a || (*i)->pDestination.lock() == a) {
			mainContent->ticketList.remove_if([&](std::shared_ptr<Ticket> t) { return t->pConnection.lock()->connectionCode == (*i)->connectionCode; });
			i = mainContent->connectionList.erase(i);
		}
		else
			i++;
	}
}


