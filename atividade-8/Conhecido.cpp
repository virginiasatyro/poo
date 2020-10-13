#include "Conhecido.h"

Conhecido::Conhecido()
{
	email = "indefinido";
	Pessoa::Pessoa();
}

Conhecido::~Conhecido()
{
}

string Conhecido::get_email()
{
	return email;
}
void Conhecido::set(string &name, int &old, string &mail)
{	
	Pessoa::set(name, old);
	email = mail;
}