#include "integral.h"

/*
class ProfIntegral: public Professor {
        double salarioMensal;
    public:
       ProfIntegral(string n, double sm)
       double getSalario();
       virtual ~ProfIntegral(){}
};
*/

ProfIntegral::ProfIntegral(string n, double sm) : Professor(n)
{
    salarioMensal = sm;
}

double ProfIntegral::getSalario()
{
    return salarioMensal;
}