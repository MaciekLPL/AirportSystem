#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <exception>

class CommandHandler;
//! Klasa obs�uguj�ca wczytywanie plik�w.
/*!
	Obs�uguje wst�pne �adowanie danych z plik�w
*/
class FileHandler {
public:
	/*!
		Konstruktor, wczytuje dane z pliku
		@param _fileName Nazwa pliku
		@param _cmdHandler Wska�nik do obiektu obs�uguj�cego komendy
	*/
	FileHandler(std::string _fileName, CommandHandler* _cmdHandler);

private:
	std::string fileName = ""; //!< Nazwa pliku
	CommandHandler* cmdHandler; //!< Wska�nik do obiektu obs�uguj�cego komendy


};


#endif