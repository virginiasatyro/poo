#include <iostream>
#include "Box.h"
using namespace std;

int main()
{
	
	Ponto3D p1(2, 3, 5),p2,p3,p4,p5, p6, p7, p8;
	//Paralelepipedo sem area e volume::
	p4 = p3 = p2 = p1;
	Box b1(p1,p2,p3,p4,p5,p6,p7,p8);
	cout << "::Area: " << b1.area() << "::Volume: " << b1.volume() << endl;
	//
	p1.set();// P1 na origem 0 0 0;
	p2.set(5, 0, 0);
	p3.set(5, 4, 0);
	p4.set(0, 0, 5);
	//
	Box b2(p1, p2, p3, p4, p5, p6, p7, p8);
	cout << "::Area: " << b2.area() << "::Volume: " << b2.volume() << endl;









}