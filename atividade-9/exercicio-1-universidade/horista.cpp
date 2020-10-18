#include "horista.h"

/*
class ProfHorista: public Professor {
        double nrNorasTrabalhadas;
        double valorHora;
    public:
        ProfHorista(string n, double nht, double vh);
        double getSalario();
        virtual ~ProfHorista();
};
*/

ProfHorista::ProfHorista(string n, double nht, double vh) : Professor(n)
{
    nrNorasTrabalhadas = nht;
    valorHora = vh;
}

double ProfHorista::getSalario()
{
    return nrNorasTrabalhadas * valorHora;
}