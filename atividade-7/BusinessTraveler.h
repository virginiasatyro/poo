#pragma once
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
	BusinessTraveler (const string &BT="1");
	~BusinessTraveler() {};
	BusinessTraveler(const BusinessTraveler &That);
	BusinessTraveler& operator= (const BusinessTraveler &Right);
	void print();

protected:
	Pager Pg;
};

BusinessTraveler::BusinessTraveler(const string &BT){
	Pg.set(BT);
}

BusinessTraveler::BusinessTraveler(const BusinessTraveler &That){
	Pager::Pager(That.Pg);
	//Traveler::Traveler(That.BT); //ERRO::como setar esse valor sem criar um novo metodo?
}

BusinessTraveler& BusinessTraveler:: operator =(const BusinessTraveler &Right)
{
	if (this == &Right) {
		return *this;
	}
	this->Pg= Right.Pg;
	return *this;
}

void BusinessTraveler::print() {
	Pg.print();
}

#endif 