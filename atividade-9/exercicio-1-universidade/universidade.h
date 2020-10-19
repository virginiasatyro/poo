#ifndef _UNIVERSIDADE
#define _UNIVERSIDADE

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "professor.h"
#include "horista.h"
#include "integral.h"

using namespace std;

class Universidade {
    private:
        vector<Professor*> professores;
        double total_pago;

    public:
        Universidade();
        ~Universidade();
        void addProfessor(string n, double, double); // adiciona professor horista
        void addProfessor(string n, double); // adiciona professor integral
        void totalPago(double);  // retorna valor pago mensalmente aos professores da Universidade
        double getTotalPago();
};

#endif //_UNIVERSIDADE