#ifndef _HORISTA
#define _HORISTA

#include "professor.h"

using namespace std;

class ProfHorista: public Professor {
        double nrNorasTrabalhadas;
        double valorHora;
    public:
        ProfHorista(string n, double nht, double vh);
        double getSalario();
        virtual ~ProfHorista() {};
};

#endif // _HORISTA