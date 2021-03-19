#ifndef STACK_H
#define STACK_H

class Stack {
public:
	Stack(std::vector<double> initVector);
	Stack(double d);
	void add(double d);
	void del();
	void sortAsc();
	void sortDesc();
	double min();
	double max();
	friend std::ostream& operator << (std::ostream& os, const Stack& s);
	std::vector<double> stack;
};

std::ostream& operator << (std::ostream& os, const Stack& s) {
	for (auto i = s.stack.begin(); i != s.stack.end(); i++)
		os << *i << " ";
	os << std::endl;
	return os;
}

Stack::Stack(std::vector<double> initVector) {
	this->stack = initVector;
}

Stack::Stack(double d) {
	this->stack.push_back(d);
}

void Stack::add(double d) {
	this->stack.push_back(d);
}

void Stack::del() {
	if(!stack.empty())
		this->stack.pop_back();
}

void Stack::sortAsc() {
	std::sort(stack.begin(), stack.end());
}

void Stack::sortDesc() {
	std::sort(stack.begin(), stack.end(), std::greater<>());
	//std::sort(stack.begin(), stack.end(), [](double d1, double d2) {return d1 > d2; });
}

double Stack::min() {
	return (*std::min_element(stack.begin(), stack.end()));
}

double Stack::max() {
	return (*std::max_element(stack.begin(), stack.end()));
}

#endif
