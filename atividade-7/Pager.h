#ifndef PAGER_H
#define PAGER_H

#include <string>
#include <iostream>
using namespace std;

class Pager {
protected:
	string p;
public:
	Pager (const string &s="1") :p(s) {};
	Pager (const Pager &that);
	~Pager() {};
	Pager& operator = (const Pager &Right);
	void set(const string &set);
	void print();
};

Pager::Pager(const Pager& That) {
	this->p = That.p;
}
Pager& Pager::operator = (const Pager &Right) {
	if (this == &Right) {
		return *this;
	}
	this->p = Right.p;
	return *this;
}

void Pager::set(const string &set)
{
	p = set;
}
void Pager::print() {
	cout << p;
}

#endif 
