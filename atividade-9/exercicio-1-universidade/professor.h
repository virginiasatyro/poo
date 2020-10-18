#ifndef _PROFESSOR
#define _PROFESSOR

#include <string>
#include <iostream>

using namespace std;

class Professor{
        string nome;
    public:
        Professor(string n);
        string getName() const;
        virtual double getSalario() = 0;
        virtual ~Professor() { };
};

#endif // _PROFESSOR