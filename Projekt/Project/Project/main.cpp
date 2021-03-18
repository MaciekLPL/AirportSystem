#include <iostream>
#include <list>
#include "view.h"
#include "consoleWindow.h"
#include "city.h"
#include "airport.h"
#include "connection.h"
#include "staff.h"
#include "ticket.h"



int main() {

	ConsoleWindow mainWindow(120,30);

	View panelLeft(2, 1, 57, 22, "Tytul panelu lewego");
	View panelRight(62, 1, 117, 22, "Tytul panelu prawego");
	View panelBottom(2, 24, 117, 28);


	std::list<City> cityList;

	City m1("Miasto1");
	City m2("Miasto2");

	cityList.push_back(m1);
	cityList.push_back(m2);

	Airport l1("LOTN1", "Lotnisko1", &m1);
	Airport l2("LOTN2", "Lotnisko2", &m1);
	Airport l3("LOTN3", "Lotnisko3", &m2);
	Airport l4("LOTN4", "Lotnisko4", &m2);

	Connection c1(&l2, "POL1-2");
	Connection c2(&l3, "POL2-3");
	Connection c3(&l4, "POL3-4");
	Connection c4(&l4, "POL4-5");

	l1.addConnection(&c1);
	l2.addConnection(&c2);
	l3.addConnection(&c3);
	l4.addConnection(&c4);

	Ticket t1(&c1, 2, 200);
	Ticket t2(&c1, 3, 300);
	Ticket t3(&c2, 2, 400);

	Staff s1("Imie Nazwisko1", 30);
	Staff s2("Imie Nazwisko2", 12);
	Staff s3("Imie Nazwisko3", 32);

	m1.addAirport(&l1);
	m1.addAirport(&l2);
	m1.addAirport(&l3);
	m2.addAirport(&l4);
	m2.addAirport(&l1);
	m2.addAirport(&l2);

	l1.addStaff(&s1);
	l2.addStaff(&s2);
	l3.addStaff(&s3);

	std::cout << std::endl;

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
	std::cout << (*l2.searchForConnection("POL2-3"));

	return 0;
}