#pragma once
#ifndef AMIGO_H
#define AMIGO_H
#include "Pessoa.h"
using namespace std;

class Amigo :public Pessoa
{
private:
	string data;
public:
	Amigo();
	~Amigo();
	string get_data();
	void set(string &name, int &old, string &date);
};

#endif