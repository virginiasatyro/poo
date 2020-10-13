#pragma once
#ifndef PESSOA_H
#define PESSOA_H

#include<iostream>
#include <string>
using namespace std;

class Pessoa
{
private:
	string nome;
	int idade;
public:
	Pessoa(string &name, int &old);
	Pessoa();
	~Pessoa();
	//Get e sets
	string get_nome();
	int get_idade();
	void set_nome(string &name);
	void set_idade(int &old);
	void virtual set(string &name, int &old);
	
};

#endif // !1