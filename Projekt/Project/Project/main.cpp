#include <iostream>
#include <list>
#include "city.h"
#include "airport.h"
#include "connection.h"


int main() {

	City m1("Miasto1");
	City m2("Miasto2");

	Airport l1("LOTN1", "Lotnisko1", &m1);
	Airport l2("LOTN2", "Lotnisko2", &m1);
	Airport l3("LOTN3", "Lotnisko3", &m1);
	Airport l4("LOTN4", "Lotnisko4", &m2);
	Airport l5("LOTN5", "Lotnisko5", &m2);
	Airport l6("LOTN6", "Lotnisko6", &m2);

	Connection c1(&l2, "Polaczenie 1-2");
	Connection c2(&l3, "Polaczenie 2-3");
	Connection c3(&l4, "Polaczenie 3-4");
	Connection c4(&l4, "Polaczenie 4-5");

	m1.addAirport(&l1);
	m1.addAirport(&l2);
	m1.addAirport(&l3);
	m2.addAirport(&l4);
	m2.addAirport(&l5);
	m2.addAirport(&l6);

	l1.addConnection(&c1);
	l2.addConnection(&c2);
	l3.addConnection(&c3);
	l4.addConnection(&c4);

	m1.listAirports();
	m2.listAirports();

	l1.listConnections();
	l2.listConnections();
	l3.listConnections();
	l4.listConnections();


	return 0;
}