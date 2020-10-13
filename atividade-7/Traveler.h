#ifndef TRAVELER_H
#define TRAVELER_H

#include <string>
#include <iostream>
using namespace std;


class Traveler{
protected:
	string t;
public:
	Traveler (const string& s="1") :t(s) {};
	Traveler (const Traveler& Trav);
	~Traveler() {};
	Traveler& operator = (const Traveler &Right);
	void set(const string &set);
	void print();
};
Traveler::Traveler(const Traveler& That) {
	this->t = That.t;
}
Traveler& Traveler::operator = (const Traveler &Right) {
	if (this == &Right) {
		return *this;
	}
	this->t = Right.t;
	return *this;
}
void Traveler::set(const string &set)
{
	t = set;
}

void Traveler::print() {
	cout << t << endl;
}
#endif