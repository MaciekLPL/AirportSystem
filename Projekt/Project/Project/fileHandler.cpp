#include "fileHandler.h"
#include "commandHandler.h"


FileHandler::FileHandler(std::string _fileName, CommandHandler* _cmdHandler) {

	fileName = _fileName;
	cmdHandler = _cmdHandler;

	readFile();
}

void FileHandler::readFile() {

	std::ifstream file(fileName);

	if (file.is_open()) {
		for (std::string line; getline(file, line); ) {
			(*cmdHandler).currentCmd = line;
			(*cmdHandler).splitCommand();
		}
	}

	file.close();
}