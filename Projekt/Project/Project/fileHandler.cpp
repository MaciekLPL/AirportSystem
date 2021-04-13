#include "fileHandler.h"
#include "commandHandler.h"


FileHandler::FileHandler(std::string _fileName, CommandHandler* _cmdHandler) {

	fileName = _fileName;
	cmdHandler = _cmdHandler;

	std::ifstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	file.open(fileName);

	for (std::string line; getline(file, line); ) {
		(*cmdHandler).currentCmd = line;
		(*cmdHandler).splitCommand();
	}

	file.close();
}
