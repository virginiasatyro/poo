#include "professor.h"

/*
class Professor{
        string nome;
    public:
        Professor(string n);
        string getName() const;
        virtual double getSalario() = 0;
        virtual ~Professor();
};
*/

Professor::Professor(string n)
{
    nome = n;
}

string Professor::getName() const
{
    return nome;
}