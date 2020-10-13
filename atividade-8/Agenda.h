#pragma once
#include<vector>
#include "Pessoa.h"
#include "Amigo.h"
#include "Conhecido.h"
#include <stdlib.h>

class Agenda
{
private:
	static int num_Amigos;
	static int num_Conhecidos;
	vector<Pessoa> Contato;
	
public:
	Agenda(int pessoas);
	~Agenda();

	int get_num_Amigos();
	int get_num_Conhecidos();
	void addInformacoes();
	void imprimeAniversarios();
	void imprimeEmail();
};

int Agenda::num_Amigos = 0;
int Agenda::num_Conhecidos = 0;