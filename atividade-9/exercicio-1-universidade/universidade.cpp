#include "universidade.h"

/*
class Universidade {
    private:
        vector<Professor> professores;

    public:
        Universidade();
        ~Universidade();
        void addProfessor(); // adiciona professor a lista de professores
        double totalPago();  // retorna valor pago mensalmente aos professores da Universidade
};*/

Universidade::Universidade()
{
    addProfessor("Professor Horista 1", 40, 100);
    addProfessor("Professor Horista", 30, 100);
    addProfessor("Professor Integral", 5000);
}

Universidade::~Universidade()
{

}

void Universidade::addProfessor(string n, double nht, double vh)
{
    ProfHorista professor(n, nht, vh);
    professores.push_back(&professor);
    totalPago(professor.getSalario());
}

void Universidade::addProfessor(string n, double sm)
{
    ProfIntegral professor(n, sm);
    professores.push_back(&professor);
    totalPago(professor.getSalario());
}

void Universidade::totalPago(double valor)
{
    total_pago += valor;
}

double Universidade::getTotalPago()
{
    return total_pago;
}