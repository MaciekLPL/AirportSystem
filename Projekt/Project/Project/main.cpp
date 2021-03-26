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
#include "content.h"



int main() {

	View panelMain(22, 1, 97, 22, " ");
	View panelBottom(22, 24, 97, 28);

	

	std::list<City*> mainCityList;
	std::list<Airport*> mainAirportList;
	std::list<Airplane*> mainAirplaneList;
	std::list<Ticket*> mainTicketsList;
	std::list<Connection*> mainConnList;
	std::list<Staff*> mainStaffList;
	Content mainContent(&panelMain, &mainCityList, &mainAirportList, &mainAirplaneList, &mainStaffList, &mainConnList, &mainTicketsList);

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

	mainCityList.push_back(&m1);
	mainCityList.push_back(&m2);
	mainCityList.push_back(&m4);
	mainCityList.push_back(&m5);
	mainCityList.push_back(&m6);
	mainCityList.push_back(&m7);
	mainCityList.push_back(&m8);
	mainCityList.push_back(&m9);
	mainCityList.push_back(&m10);
	mainCityList.push_back(&m11);
	mainCityList.push_back(&m12);
	mainCityList.push_back(&m13);
	mainCityList.push_back(&m14);
	mainCityList.push_back(&m15);
	mainCityList.push_back(&m16);
	mainCityList.push_back(&m17);
	mainCityList.push_back(&m18);
	mainCityList.push_back(&m19);
	mainCityList.push_back(&m20);

	
	Airport l1("LNO1", "Lotnisko1");
	Airport l2("LNO2", "Lotnisko2");
	Airport l3("LNO3", "Lotnisko3");
	Airport l4("LNO4", "Lotnisko4");

	mainAirportList.push_back(&l1);
	mainAirportList.push_back(&l2);
	mainAirportList.push_back(&l3);
	mainAirportList.push_back(&l4);

	Connection c1(&l2, "POL1-2");
	Connection c2(&l3, "POL2-3");
	Connection c3(&l4, "POL3-4");
	Connection c4(&l4, "POL4-5");

	
	mainConnList.push_back(&c1);
	mainConnList.push_back(&c2);
	mainConnList.push_back(&c3);
	mainConnList.push_back(&c4);

	l1.addConnection(&c1);
	l2.addConnection(&c2);
	l1.addConnection(&c3);
	l4.addConnection(&c4);

	Ticket t1(&c1, 2, 200);
	Ticket t2(&c1, 3, 300);
	Ticket t3(&c1, 2, 400);
	
	mainTicketsList.push_back(&t1);
	mainTicketsList.push_back(&t2);
	mainTicketsList.push_back(&t3);

	Staff s1("Imie Nazwisko1", 30);
	Staff s2("Imie Nazwisko2", 12);
	Staff s3("Imie Nazwisko3", 32);

	mainStaffList.push_back(&s1);
	mainStaffList.push_back(&s2);
	mainStaffList.push_back(&s3);

	Airplane a1("SP-LLA", "B737");
	Airplane a2("SP-PLA", "B787");
	Airplane a3("SP-DLA", "B747");
	Airplane a4("SP-SPA", "B777");

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

	std::cout << (*l1.searchForConnection("POL1-2"));*/
	
	int skip = 0;
	mainContent.printCities();
	panelMain.ShowConsoleCursor(0);
	while (1) {

		int c = _getch();
		if (c == 0xE0) {
			c = _getch();
			switch (c) {
			case 0x4B:		//lewo
				//l2.remove("POL2-3");
				//l2.listConnections();

				break;
			case 0x4D:		//prawo
				//panelRight.clearPanelContent();
				break;
			case 0x48:		//góra
				if (skip != 0) {
					skip--;
					if (panelMain.currentView == 1)
						mainContent.printCities(skip);
					else if (panelMain.currentView == 2)
						mainContent.printAirports(skip);
					else if (panelMain.currentView == 3)
						mainContent.printConnections(skip);
					else if (panelMain.currentView == 4)
						mainContent.printStaff(skip);
					else if (panelMain.currentView == 5)
						mainContent.printAirplanes(skip);
					else if (panelMain.currentView == 6)
						mainContent.printTickets(skip);
				}
				break;
			case 0x50:		//dó³
				if (panelMain.currentView == 1) {
					if (mainContent.cityList->size() + skip > 16 && skip < mainContent.cityList->size() - 16) {
						skip++;
						mainContent.printCities(skip);
					}
					else if (panelMain.currentView == 2) {
						if (mainContent.airportList->size() + skip > 16 && skip < mainContent.airportList->size() - 16) {
							skip++;
							mainContent.printAirports(skip);
						}
					}
					else if (panelMain.currentView == 3) {
						if (mainContent.connectionList->size() + skip > 16 && skip < mainContent.connectionList->size() - 16) {
							skip++;
							mainContent.printConnections(skip);
						}
					}
					else if (panelMain.currentView == 4) {
						if (mainContent.staffList->size() + skip > 16 && skip < mainContent.staffList->size() - 16) {
							skip++;
							mainContent.printStaff(skip);
						}
					}
					else if (panelMain.currentView == 5) {
						if (mainContent.airplaneList->size() + skip > 16 && skip < mainContent.airplaneList->size() - 16) {
							skip++;
							mainContent.printAirplanes(skip);
						}
						else if (panelMain.currentView == 6) {
							if (mainContent.ticketList->size() + skip > 16 && skip < mainContent.ticketList->size() - 16) {
								skip++;
								mainContent.printTickets(skip);
							}
						}
						break;
			default:
				break;
					}
				}
			}
		}
		else {
			if (c == 9)	{
				//tab
				panelMain.clearPanelContent();
				skip = 0;
				panelMain.currentView++;
				if (panelMain.currentView == 1)
					mainContent.printCities();
				else if (panelMain.currentView == 2)
					mainContent.printAirports();
				else if (panelMain.currentView == 3)
					mainContent.printConnections();
				else if (panelMain.currentView == 4)
					mainContent.printStaff();
				else if (panelMain.currentView == 5)
					mainContent.printAirplanes();
				else if (panelMain.currentView == 6){
					mainContent.printTickets();
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