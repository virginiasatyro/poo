#pragma once
#ifndef CONHECIDO_H
#define CONHECIDO_H
#include "Pessoa.h"

class Conhecido :public Pessoa
{
private:
	string email;
public:
	Conhecido();
	~Conhecido();
	string get_email();
	void set(string &name, int &old, string &mail);
};

#endif