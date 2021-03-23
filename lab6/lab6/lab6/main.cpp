#include <iostream>


class nodeL {
public:
	nodeL(int data);
	std::shared_ptr<nodeL> pNext;
	int value;
};

class list {
public:
	list();
	void pushfront(int value);
	void pushback(int value);
	friend std::ostream& operator<<(std::ostream& os, const list l);
	std::shared_ptr<nodeL> pHead;
};

nodeL::nodeL(int data) : value(data), pNext(nullptr) {}
list::list() : pHead(nullptr) {}

void list::pushfront(int value) {

	std::shared_ptr<nodeL> p = pHead;
	nodeL newElement(value);

	auto ptr = std::make_shared<nodeL>(newElement);
	pHead = ptr;
	ptr->pNext = p;
}

void list::pushback(int value) {

	nodeL newElement(value);

	if (!pHead)
		pHead = std::make_shared<nodeL>(newElement);

	else {
		std::shared_ptr<nodeL> p = pHead;

		while (p->pNext)
			p = p->pNext;

		p->pNext = std::make_shared<nodeL>(newElement);
	}
}

std::ostream& operator<<(std::ostream& os, const list l) {

	std::shared_ptr<nodeL> tmp = l.pHead;
	if (tmp)
		os << "Wypisuje liste: | ";
	else
		os << "Lista jest pusta";

	while (tmp) {
		os << tmp->value << " | ";
		tmp = tmp->pNext;
	}
	os << std::endl;
	return os;
}


int main() {

	list l1;

	std::cout << l1;

	l1.pushback(10);
	l1.pushback(21);

	std::cout << l1;

	l1.pushback(32);
	l1.pushback(45);
	l1.pushback(66);

	std::cout << l1;

	l1.pushfront(11);
	l1.pushfront(12);
	l1.pushfront(13);

	std::cout << l1;

	return 0;
}