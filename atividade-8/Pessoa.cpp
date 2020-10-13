#include "Pessoa.h"
#include <string>
using namespace std;



Pessoa::Pessoa(string &name, int &old)
{
	nome = name;
	idade = old;
}

Pessoa::Pessoa()
{
	nome ="indefinido";
	idade = 0;
}

Pessoa::~Pessoa()
{
}

string Pessoa::get_nome()
{
	return nome;
}
int Pessoa::get_idade()
{
	return idade;
}

void Pessoa::set_nome(string &name) 
{
	nome = name;
}

void Pessoa::set_idade(int &old)
{
	idade = old;
}

void Pessoa::set(string &name, int &old)
{
	nome = name;
	idade = old;
}