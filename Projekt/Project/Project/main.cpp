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

	View panelLeft(2, 1, 57, 22, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	View panelRight(62, 1, 117, 22, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	View panelBottom(2, 24, 117, 28);

	City m1("Miasto1");
	City m2("Miasto2");

	Airport l1("LOTN1", "Lotnisko1", &m1);
	Airport l2("LOTN2", "Lotnisko2", &m1);
	Airport l3("LOTN3", "Lotnisko3", &m2);
	Airport l4("LOTN4", "Lotnisko4", &m2);

	Connection c1(&l2, "Polaczenie 1-2");
	Connection c2(&l3, "Polaczenie 2-3");
	Connection c3(&l4, "Polaczenie 3-4");
	Connection c4(&l4, "Polaczenie 4-5");

	l1.addConnection(&c1);
	l2.addConnection(&c2);
	l3.addConnection(&c3);
	l4.addConnection(&c4);

	Ticket t1(&c1, 2, 200);
	Ticket t2(&c1, 3, 300);
	Ticket t3(&c2, 2, 400);

	Staff s1("Elon Elon", 69);
	Staff s2("Elon Musk", 69);
	Staff s3("Musk Musk", 69);

	m1.addAirport(&l1);
	m1.addAirport(&l2);
	m1.addAirport(&l3);
	m2.addAirport(&l4);
	m2.addAirport(&l1);
	m2.addAirport(&l2);



	l1.addStaff(&s1);
	l2.addStaff(&s2);
	l3.addStaff(&s3);


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

	return 0;
}