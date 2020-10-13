#include "Amigo.h"



Amigo::Amigo()
{
	Pessoa::Pessoa();
	data = "indefinido";
}

string Amigo::get_data()
{
	return data;
}
void Amigo::set(string &name, int &old, string &date)
{
	Pessoa::set(name, old);
	data = date;
}

Amigo::~Amigo()
{
}
