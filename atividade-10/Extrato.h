#ifndef EXTRATO_H
#define EXTRATO_H

#include <ctime>
#include <string>

using namespace std;

class Extrato
{
public:
	Extrato(double valorNaConta, double &Movimentacao, string  TypeMove);
	~Extrato();

private:
	double _valorNaConta;
	double _Movimentacao;
	string _TipoMovimentacao;
};

#endif