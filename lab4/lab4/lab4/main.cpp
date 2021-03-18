#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>


enum cause { control, cough, fever, bleeding };

class Patient {
public:
	Patient(std::string _name, cause _visitCause) {
		this->name = _name;
		this->visitCause = _visitCause;
	}

	void printInformation() {
		std::cout << name << std::endl;
		std::cout << "Cause of visit: ";
		if (visitCause == 0)
			std::cout << "Kontrola" << std::endl;
		else if (visitCause == 1)
			std::cout << "Kaszel" << std::endl;
		else if (visitCause == 2)
			std::cout << "Gor¹czka" << std::endl;
		else if (visitCause == 3)
			std::cout << "Krawienie" << std::endl;
		else
			std::cout << "Nierozpoznane" << std::endl;

	}

	friend bool operator<(const Patient& p1, const Patient& p2) {
		return p1.visitCause < p2.visitCause;
	}

	friend std::ostream& operator<< (std::ostream& out, const Patient& p) {

		out << "Imie: " << p.name << std::endl;
		out << "Powod wizyty: ";
		if (p.visitCause == 0)
			std::cout << "Kontrola" << std::endl;
		else if (p.visitCause == 1)
			std::cout << "Kaszel" << std::endl;
		else if (p.visitCause == 2)
			std::cout << "Goraczka" << std::endl;
		else if (p.visitCause == 3)
			std::cout << "Krawienie" << std::endl;
		else
			std::cout << "Nierozpoznane" << std::endl;
		return out;
	}

private:
	std::string name;
	cause visitCause;
};


int main() {

	std::string word;
	std::cout << "Wpisz wyraz: ";
	std::cin >> word;

	std::vector<char> charsVector;
	std::deque<char> charsDeque;

	for (auto letter : word)
		charsVector.push_back(letter);

	for (auto letter : charsVector)
		charsDeque.push_front(letter);

	for (auto letter : charsDeque)
		std::cout << letter;

	std::cout << std::endl;

	std::set<int> range;
	for (int i = 1; i <= 12; i++)
		range.insert(i);

	std::map <int, std::string> month;
	month[1] = "Styczen";
	month[2] = "Luty";
	month[3] = "Marzec";
	month[4] = "Kwiecien";
	month[5] = "Maj";
	month[6] = "Czerwiec";
	month[7] = "Lipiec";
	month[8] = "Sierpien";
	month[9] = "Wrzesien";
	month[10] = "Pazdziernik";
	month[11] = "Listopad";
	month[12] = "Grudzien";

	int x = 0;
	std::cout << "Podaj liczbe: ";
	std::cin >> x;

	std::cout << ((range.find(x) != range.end()) ? month[x] : "Otoz nie tym razem") << std::endl;

	std::priority_queue<Patient> q;
	Patient p1("Andrzej", control);
	Patient p2("Marcin", cough);
	Patient p3("Ula", fever);
	Patient p4("Bartosz", bleeding);

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	while (!q.empty()) {
		std::cout << q.top();
		q.pop();
	}
}