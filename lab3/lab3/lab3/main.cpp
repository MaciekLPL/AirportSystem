#include <iostream>
#include <string>

template <class dataType>
class Queue;

template <class dataType>
std::ostream& operator<<(std::ostream& out, const Queue<dataType>& q);


template <class dataType>
struct QueueNode {
	dataType value;
	QueueNode<dataType>* pNext;
};


template <class dataType>
class Queue {
public:
	Queue();
	~Queue();
	void addItem(dataType x);
	void deleteItem();
	friend std::ostream& operator<< <dataType> (std::ostream& out, const Queue<dataType>& q);
	
private:	
	QueueNode<dataType>* pHead;
	QueueNode<dataType>* pTail;
};


template<class dataType>
std::ostream& operator<< <dataType> (std::ostream& out, const Queue<dataType>& q) {

	QueueNode<dataType>* p = q.pHead;
	out << "Wypisuje kolejke:";

	while (p != nullptr) {
		out << " | " << p->value;
		p = p->pNext;
	}
	out << " | " << std::endl;
	return out;
}


template <class dataType>
Queue<dataType>::Queue() {
	pHead = nullptr;
	pTail = nullptr;
}


template<class dataType>
Queue<dataType>::~Queue() {
	QueueNode<dataType>* p = pHead;

	while (pHead) {
		p = pHead->pNext;
		delete pHead;
		pHead = p;
	}
	pHead = pTail = nullptr;
}


template<class dataType>
void Queue<dataType>::addItem(dataType newEl) {
	QueueNode<dataType>* newElement = new QueueNode<dataType>;

	newElement->value = newEl;
	newElement->pNext = nullptr;

	if (pHead == nullptr)
		pHead = pTail = newElement;
	else {
		pTail->pNext = newElement;
		pTail = newElement;
	}

	std::cout << "Dodaje element | " << newEl << " | do kolejki." << std::endl;

}


template<class dataType>
void Queue<dataType>::deleteItem() {
	if (pHead == nullptr) {
		std::cout << "Nie mozna usunac elementu. Kolejka jest pusta." << std::endl;
	}
	else if (pHead == pTail) {
		delete pHead, pTail;
		pHead = pTail = nullptr;
		std::cout << "Kolejka od teraz jest pusta." << std::endl;
	}
	else {
		std::cout << "Usuwam element | " << pHead->value << " | z kolejki." << std::endl;
		pHead = pHead->pNext;
	}
}


int main() {

	Queue<double> q;
	q.addItem(1.2);
	q.addItem(1.3);
	q.deleteItem();
	q.deleteItem();
	q.deleteItem();
	q.addItem(3.6);
	q.addItem(1.6);
	std::cout << q;
	std::cout << "----------------------------------------------------- Pierwsza" << std::endl;

	Queue<int> q2;
	q2.addItem(1);
	q2.addItem(2);
	q2.addItem(3);
	q2.addItem(4);
	q2.addItem(5);
	std::cout << q2;
	q2.deleteItem();
	std::cout << q2;
	std::cout << "----------------------------------------------------- Druga" << std::endl;

	Queue<std::string> q3;
	q3.addItem("aa");
	q3.addItem("sa");
	q3.addItem("da");
	q3.addItem("fa");
	std::cout << q3;
	q3.deleteItem();
	std::cout << q3;
	std::cout << "----------------------------------------------------- Trzecia" << std::endl;

}