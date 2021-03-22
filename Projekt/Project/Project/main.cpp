#include <iostream>
#include <list>
#include <conio.h>
#include "city.h"
#include "airport.h"
#include "connection.h"
#include "staff.h"
#include "airplane.h"
#include "ticket.h"
#include "view.h"



int main() {

	View panelMain(22, 1, 97, 22, " ");
	//View panelRight(62, 1, 117, 22, " ");
	//View panelBottom(22, 24, 97, 28);


	City m1("Miasto1", "44-303");
	City m2("Miasto2", "44-333");
	City m3("Miasto2", "34-333");

	std::list<City*> cityList;

	cityList.push_back(&m1);
	cityList.push_back(&m2);
	cityList.push_back(&m3);
	
	Airport l1("LNO1", "Lotnisko1");
	Airport l2("LNO2", "Lotnisko2");
	Airport l3("LNO3", "Lotnisko3");
	Airport l4("LNO4", "Lotnisko4");

	std::list<Airport*> mainAirportList;
	mainAirportList.push_back(&l1);
	mainAirportList.push_back(&l2);
	mainAirportList.push_back(&l3);
	mainAirportList.push_back(&l4);

	Connection c1(&l2, "POL1-2");
	Connection c2(&l3, "POL2-3");
	Connection c3(&l4, "POL3-4");
	Connection c4(&l4, "POL4-5");

	std::list<Connection*> mainConnList;
	mainConnList.push_back(&c1);
	mainConnList.push_back(&c2);
	mainConnList.push_back(&c3);
	mainConnList.push_back(&c4);

	l1.addConnection(&c1);
	l1.addConnection(&c2);
	l1.addConnection(&c3);
	l4.addConnection(&c4);

	Ticket t1(&c1, 2, 200);
	Ticket t2(&c1, 3, 300);
	Ticket t3(&c1, 2, 400);

	std::list<Ticket*> mainTicketsList;
	mainTicketsList.push_back(&t1);
	mainTicketsList.push_back(&t2);
	mainTicketsList.push_back(&t3);

	Staff s1("Imie Nazwisko1", 30);
	Staff s2("Imie Nazwisko2", 12);
	Staff s3("Imie Nazwisko3", 32);

	std::list<Staff*> mainStaffList;
	mainStaffList.push_back(&s1);
	mainStaffList.push_back(&s2);
	mainStaffList.push_back(&s3);

	Airplane a1("SP-LLA", "B737");
	Airplane a2("SP-PLA", "B787");
	Airplane a3("SP-DLA", "B747");
	Airplane a4("SP-SPA", "B777");

	std::list<Airplane*> mainAirplaneList;
	mainAirplaneList.push_back(&a1);
	mainAirplaneList.push_back(&a2);
	mainAirplaneList.push_back(&a3);
	mainAirplaneList.push_back(&a4);

	m1.addAirport(&l1);
	m1.addAirport(&l2);
	m1.addAirport(&l3);
	m2.addAirport(&l4);
	m2.addAirport(&l1);
	m2.addAirport(&l2);

	l1.addStaff(&s1);
	l1.addStaff(&s2);
	l1.addStaff(&s3);

	l1.addAirplane(&a1);
	l1.addAirplane(&a2);
	l1.addAirplane(&a3);
	l1.addAirplane(&a4);


	/*std::cout << std::endl;
	m1.listAirports();
	m2.listAirports();

	l1.listConnections();
	l2.listConnections();
	l3.listConnections();
	l4.listConnections();

	l1.listStaff();
	l2.listStaff();
	l3.listStaff();

	std::cout << t1 << std::endl;

	std::cout << (*l1.searchForConnection("POL1-2"));
	std::cout << (*l2.searchForConnection("POL2-3"));*/
	panelMain.printCities(cityList);
	panelMain.ShowConsoleCursor(0);

	while (1) {

		int c = _getch();
		if (c == 0xE0) {
			c = _getch();
			switch (c) {
			case 0x4B:		//lewo
				//panelMain.clearPanelContent();
				break;
			case 0x4D:		//prawo
				//panelRight.clearPanelContent();
				break;
			case 0x48:		//góra
				//panelMain.printAirplanes(l1.airplaneList);
				break;
			case 0x50:		//dó³
				//panelRight.printAirports(m1.airportList);
				break;
			default:
				break;
			}
		}
		else {
			if (c == 9)	{
				//tab
				panelMain.clearPanelContent();

				panelMain.currentView++;
				if (panelMain.currentView == 1)
					panelMain.printCities(cityList);
				else if (panelMain.currentView == 2)
					panelMain.printAirports(mainAirportList);
				else if (panelMain.currentView == 3)
					panelMain.printConnections(mainConnList);
				else if (panelMain.currentView == 4)
					panelMain.printStaff(mainStaffList);
				else if (panelMain.currentView == 5)
					panelMain.printAirplanes(mainAirplaneList);
				else if (panelMain.currentView == 6){
					panelMain.printTickets(mainTicketsList);
					panelMain.currentView = 0;
				}
			}
			else if (c == 27)	//esc
				break;
		}
	}
	system("cls");
	return 0;
}