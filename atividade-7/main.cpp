#include <string>
#include <iostream>
using namespace std;

#include "BusinessTraveler.h"

int main()
{
	BusinessTraveler a("TESTE 71");
	a.print();
	a.set("Teste 72");
	a.print();
	BusinessTraveler b, c;
	b = c = a;
	a.print();
	b.print();
	c.print();
}

