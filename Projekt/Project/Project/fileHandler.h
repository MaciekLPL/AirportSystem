#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>

class CommandHandler;

class FileHandler {
public:
	FileHandler(std::string _fileName, CommandHandler* _cmdHandler);
	void readFile();

private:
	std::string fileName = "";
	CommandHandler* cmdHandler;


};


#endif