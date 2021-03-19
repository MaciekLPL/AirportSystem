#include <iostream>
#include <vector>
#include <algorithm>
#include "stack.h"

int main() {

	std::vector<double> v{ 1.2, 32.23, 123.4, 1.2 };
	std::cout << "WSTEPNY STOS" << std::endl;
	Stack s1(v);
	Stack s2(2.2);
	s2.add(4.3);
	s2.add(2.3);
	s2.add(3.3);
	s2.add(4.3);
	s2.add(5.3);
	s2.add(7.3);

	std::cout << s1;
	std::cout << s2;
	std::cout << "SORTOWANIE ROSNACO" << std::endl;
	s1.sortAsc();
	s2.sortAsc();

	std::cout << s1;
	std::cout << s2;
	std::cout << "SORTOWANIE MALEJACO" << std::endl;
	s1.sortDesc();
	s2.sortDesc();

	std::cout << s1;
	std::cout << s2;

	std::cout << "Max: " << s1.max() << std::endl;
	std::cout << "Min: " << s1.min() << std::endl;
	std::cout << "Max: " << s2.max() << std::endl;
	std::cout << "Min: " << s2.min() << std::endl;

	std::cout << "USUWANIE 2 ELEMENTOW" << std::endl;
	s1.del();
	s1.del();
	s2.del();
	s2.del();
	std::cout << s1;
	std::cout << s2;

}