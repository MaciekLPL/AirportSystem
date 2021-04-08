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

private:
	View* parentView;
	Content* mainContent;
	std::string currentCmd;

	std::string getToken(std::string& s);
	void printError(std::string errorString);
	void splitCommand();
	void addCommand();
	void removeCommand();
	
	void addCity();
	void removeCity();
};



#endif
