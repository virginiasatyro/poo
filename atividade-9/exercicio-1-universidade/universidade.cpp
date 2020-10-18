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
    // insere professores - 2 horistas e 1 integral
    addProfessorHorista("horista 1", 40, 1000);
    addProfessorHorista("horista 2", 40, 800);
    addProfessorIntegral("integral 1", 7000);
}

Universidade::~Universidade()
{

}

void Universidade::addProfessorHorista(string n, double nht, double vh)
{
    ProfHorista professor(n, nht, vh);
    prof_horista.push_back(professor);
    totalPago(professor.getSalario());
}

void Universidade::addProfessorIntegral(string n, double sm)
{
    ProfIntegral professor(n, sm);
    prof_integral.push_back(professor);
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