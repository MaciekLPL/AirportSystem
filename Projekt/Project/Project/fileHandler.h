#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <exception>

class CommandHandler;

class FileHandler {
public:
	FileHandler(std::string _fileName, CommandHandler* _cmdHandler);

private:
	std::string fileName = "";
	CommandHandler* cmdHandler;


};


#endif