#include "Agenda.h"

Agenda::Agenda(int pessoas)
{
	for (int i = 0; i < pessoas; i++)
	{
		if (rand() % 1 == 1)
		{
			Amigo b;
			Contato.push_back(b);
			num_Amigos++;
		}
		else
		{
			Conhecido c;
			//Pessoa *cn = &c;
			Contato.push_back(c);
			num_Conhecidos++;
		}
	}
}

Agenda::~Agenda()
{
}

int Agenda::get_num_Amigos()
{
	return num_Amigos;
}

int Agenda::get_num_Conhecidos()
{
	return num_Conhecidos;
}

void Agenda::addInformacoes()
{   //Conhecido : nome(string) idade(int), email (string)
	//Amigo : nome(string) idade(int), data(string)
	string name, derived;
	int old;
	cin >> name >> old >> derived;
	//Necessario upcasting 
	set(name, old, derived);
}

void Agenda::imprimeAniversarios()
{

}

void Agenda::imprimeEmail()
{

}
