#ifndef _INTEGRAL
#define _INTEGRAL

#include "professor.h"

using namespace std;

class ProfIntegral: public Professor {
        double salarioMensal;
    public:
       ProfIntegral(string n, double sm);
       double getSalario();
       virtual ~ProfIntegral(){};
};

#endif // _INTEGRAL