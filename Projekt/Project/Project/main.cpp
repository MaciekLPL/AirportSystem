#include <iostream>
#include <list>
#include <conio.h>
#include <string>
#include "city.h"
#include "airport.h"
#include "connection.h"
#include "staff.h"
#include "airplane.h"
#include "ticket.h"
#include "view.h"
#include "content.h"
#include "commandHandler.h"



int main() {

	View panelMain(22, 1, 97, 22);
	View panelBottom(11, 23, 109, 27, "Command line");
	
	Content mainContent(&panelMain);

	CommandHandler cmdHandler(&panelBottom, &mainContent);

	City m1("Miasto1", "44-1");
	City m2("Miasto2", "44-2");
	City m4("Miasto2", "34-3");
	City m5("Miasto2", "34-4");
	City m6("Miasto2", "34-5");
	City m7("Miasto2", "34-6");
	City m8("Miasto2", "34-7");
	City m9("Miasto2", "34-8");
	City m10("Miasto2", "34-9");
	City m11("Miasto2", "34-10");
	City m12("Miasto2", "34-11");
	City m13("Miasto2", "34-12");
	City m14("Miasto2", "34-13");
	City m15("Miasto2", "34-14");
	City m16("Miasto2", "34-15");
	City m17("Miasto2", "34-16");
	City m18("Miasto2", "34-17");
	City m19("Miasto2", "34-18");
	City m20("Miasto2", "34-19");

	
	Airport l1("LNO1", "Lotnisko1");
	Airport l2("LNO2", "Lotnisko2");
	Airport l3("LNO3", "Lotnisko3");
	Airport l4("LNO4", "Lotnisko4");

	Connection c1(&l2, "POL1-2");
	Connection c2(&l3, "POL2-3");
	Connection c3(&l4, "POL3-4");
	Connection c4(&l4, "POL4-5");

	l1.addConnection(c1);
	l2.addConnection(c2);
	l1.addConnection(c3);
	l4.addConnection(c4);

	Ticket t1(&c1, 2, 200);
	Ticket t2(&c1, 3, 300);
	Ticket t3(&c1, 2, 400);

	Staff s1("Imie Nazwisko1", 30);
	Staff s2("Imie Nazwisko2", 12);
	Staff s3("Imie Nazwisko3", 32);

	Airplane a1("SP-LLA", "B737");
	Airplane a2("SP-PLA", "B787");
	Airplane a3("SP-DLA", "B747");
	Airplane a4("SP-SPA", "B777");

	m1.addAirport(l1);
	m1.addAirport(l2);
	m1.addAirport(l3);
	m2.addAirport(l4);
	m2.addAirport(l1);
	m2.addAirport(l2);

	l1.addStaff(s1);
	l1.addStaff(s2);
	l1.addStaff(s3);

	l1.addAirplane(a1);
	l1.addAirplane(a2);
	l1.addAirplane(a3);
	l1.addAirplane(a4);

	mainContent.cityList.push_back(m1);
	mainContent.cityList.push_back(m2);
	mainContent.cityList.push_back(m4);
	mainContent.cityList.push_back(m5);
	mainContent.cityList.push_back(m6);
	mainContent.cityList.push_back(m7);
	mainContent.cityList.push_back(m8);
	mainContent.cityList.push_back(m9);
	mainContent.cityList.push_back(m10);
	mainContent.cityList.push_back(m11);
	mainContent.cityList.push_back(m12);
	mainContent.cityList.push_back(m13);
	mainContent.cityList.push_back(m14);
	mainContent.cityList.push_back(m15);
	mainContent.cityList.push_back(m16);
	mainContent.cityList.push_back(m17);
	mainContent.cityList.push_back(m18);
	mainContent.cityList.push_back(m19);
	mainContent.cityList.push_back(m20);

	mainContent.airportList.push_back(l1);
	mainContent.airportList.push_back(l2);
	mainContent.airportList.push_back(l3);
	mainContent.airportList.push_back(l4);

	mainContent.connectionList.push_back(c1);
	mainContent.connectionList.push_back(c2);
	mainContent.connectionList.push_back(c3);
	mainContent.connectionList.push_back(c4);

	mainContent.ticketList.push_back(t1);
	mainContent.ticketList.push_back(t2);
	mainContent.ticketList.push_back(t3);

	mainContent.staffList.push_back(s1);
	mainContent.staffList.push_back(s2);
	mainContent.staffList.push_back(s3);
	
	mainContent.airplaneList.push_back(a1);
	mainContent.airplaneList.push_back(a2);
	mainContent.airplaneList.push_back(a3);
	mainContent.airplaneList.push_back(a4);

	panelMain.ShowConsoleCursor(0);
	mainContent.refreshContent();

	while (1) {
		
		int c = _getch();
		
		if (c == 0xE0) {
			c = _getch();
			switch (c) {
			//case 0x4B:		//lewo
			//	l2.remove("POL2-3");
			//	l2.listConnections();
			//	break;
			//case 0x4D:		//prawo
			//	panelRight.clearPanelContent();
			//	break;
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