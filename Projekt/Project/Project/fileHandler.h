#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <exception>

class CommandHandler;
//! Klasa obs³uguj¹ca wczytywanie plików.
/*!
	Obs³uguje wstêpne ³adowanie danych z plików
*/
class FileHandler {
public:
	/*!
		Konstruktor, wczytuje dane z pliku
		@param _fileName Nazwa pliku
		@param _cmdHandler WskaŸnik do obiektu obs³uguj¹cego komendy
	*/
	FileHandler(std::string _fileName, CommandHandler* _cmdHandler);

private:
	std::string fileName = ""; //!< Nazwa pliku
	CommandHandler* cmdHandler; //!< WskaŸnik do obiektu obs³uguj¹cego komendy


};


#endif