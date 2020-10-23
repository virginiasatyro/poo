#include "Extrato.h"
#include <string>
using namespace std;


Extrato::Extrato(double valorNaConta, double &Movimentacao, string TypeMove)
{
	_valorNaConta=valorNaConta;
	_Movimentacao=Movimentacao;
	_TipoMovimentacao=TypeMove;
}


Extrato::~Extrato()
{
}
