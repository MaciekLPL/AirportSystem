#include <iostream>
#include <conio.h>
#include <string>
#include "commandHandler.h"
#include "fileHandler.h"
#include "content.h"
#include "view.h"
#include "city.h"
#include "airport.h"
#include "staff.h"
#include "airplane.h"
#include "connection.h"
#include "ticket.h"


int Staff::id = 0;
int Ticket::id = 0;

int main() {

	View panelMain(22, 1, 97, 22);
	View panelBottom(11, 23, 109, 27, "Command line");
	
	Content mainContent(&panelMain);

	CommandHandler cmdHandler(&panelBottom, &mainContent);
	
	panelMain.ShowConsoleCursor(0);

	try {
		FileHandler inputFile("basicInput.txt", &cmdHandler);
	}
	catch (std::exception& e) {
		system("cls");
		std::cerr << "Exception while reading file: " << e.what() << std::endl;
		return 1;
	}

	mainContent.refreshContent();
	cmdHandler.printInformation("Press '/' to enter command line, 'TAB' to change view, 'ESC' to quit.");

	while (1) {
		
		int c = _getch();
		
		if (c == 0xE0) {
			c = _getch();
			switch (c) {

			case 0x48:		//góra
				mainContent.scrollUp();
				break;
			
			case 0x50:		//dó³
				mainContent.scrollDown();
				break;

			default:
				break;
			}
		}

		else if (c == 9) {	//tab
			mainContent.changeCurrentContent();
		}

		else if (c == 47) {	//slash
			panelBottom.clearPanelContent();
			cmdHandler.getCommand();
			mainContent.refreshContent();
		}

		else if (c == 27) {	//esc
			break;
		}
	}

	system("cls");	//koñcówka while
	return 0;
}