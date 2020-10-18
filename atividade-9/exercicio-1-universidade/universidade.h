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
        vector<ProfHorista> prof_horista;
        vector<ProfIntegral> prof_integral;
        double total_pago;

    public:
        Universidade();
        ~Universidade();
        void addProfessorHorista(string n, double nht, double vh); // adiciona professor a lista de professores
        void addProfessorIntegral(string n, double sm);
        void totalPago(double);  // retorna valor pago mensalmente aos professores da Universidade
        double getTotalPago();
};

#endif //_UNIVERSIDADE