#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <iostream>
#include <string>
#include <algorithm>

class View;
class Content;

class CommandHandler {
public:
	CommandHandler(View* _parentView, Content* _mainContent);
	void getCommand();


private:
	View* parentView;
	Content* mainContent;

	std::string getToken(std::string& s);
	void splitCommand(std::string cmd);
	void addCommand(std::string cmd);

};



#endif
