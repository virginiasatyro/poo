#ifndef BUSINESSTRAVELER_H
#define BUSINESSTRAVELER_H

#include <string>
#include <iostream>
#include "Pager.h"
#include "Traveler.h"
using namespace std;

class BusinessTraveler:public Traveler
{
public:

	BusinessTraveler() :Traveler("1"), Pg("1") {};
	BusinessTraveler (const string &BT);
	~BusinessTraveler() {};
	BusinessTraveler(const BusinessTraveler &That);
	BusinessTraveler& operator= (const BusinessTraveler &Right);
	void print();
	void set(const string &set);
protected:
	Pager Pg;
};

BusinessTraveler::BusinessTraveler(const string &BT){
	Pg.set(BT);
	t = BT;
}

BusinessTraveler::BusinessTraveler(const BusinessTraveler &That){
	Pager::Pager(That.Pg);
}

BusinessTraveler& BusinessTraveler:: operator =(const BusinessTraveler &Right)
{
	if (this == &Right) {
		return *this;
	}
	this->Pg= Right.Pg;
	this->t = Right.t;
	return *this;
}

void BusinessTraveler::print()
{
	Pg.print();
	cout <<"::"<< t<<endl;
}

void BusinessTraveler::set(const string &set)
{
	Pg.set(set);
	t = set;
}

#endif 
