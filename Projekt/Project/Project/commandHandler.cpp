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
	
	std::string cmd;
	std::getline(std::cin, cmd);
	
	(*parentView).ShowConsoleCursor(0);

	if (cmd.empty())
		return;
	else
		splitCommand(cmd);

}

std::string CommandHandler::getToken(std::string& s) {

	size_t pos = 0;
	std::string token;
	pos = s.find(" ");
	token = s.substr(0, pos);
	s.erase(0, pos + 1);

	return token;

}

void CommandHandler::splitCommand(std::string cmd) {
	
	std::string token = getToken(cmd);
	std::transform(token.begin(), token.end(), token.begin(), ::toupper);

	if (token == "ADD")
		addCommand(cmd);
	else if (token == "REMOVE")
		return;
	else
		return;

}

void CommandHandler::addCommand(std::string cmd) {
	
	std::string type = getToken(cmd);
	std::transform(type.begin(), type.end(), type.begin(), ::toupper);

	if (type == "CITY")
		(*mainContent).cityList.push_back(City("ala", "34-322"));

	(*mainContent).refreshContent();
}