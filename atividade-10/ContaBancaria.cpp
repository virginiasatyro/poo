#include "ContaBancaria.h"
#include<iostream>
#include<conio.h>
using namespace std;

//METODOS CONTA BANCARIA

ContaBancaria::ContaBancaria(int &senha)
{
	_senha = senha;
	_saldo = 0.0;
	this->set_nConta(geradorNumContas());
}

ContaBancaria::~ContaBancaria()
{
}

bool ContaBancaria::alteraSenha(int &senha)
{
	if (_senha == senha) {
		cout << "Digite a nova senha::" << endl;
		int nova_senha;
		cin >> nova_senha;
		set_Senha(nova_senha);
		return 1;
	}
	return 0;
		
}
void ContaBancaria::set_Senha(int &senha)
{
	_senha = senha;
}
void ContaBancaria::set_Saldo(double novoSaldo)
{
	_saldo = novoSaldo;
}
void ContaBancaria::set_nConta(int Conta)
{
	_numeroConta = Conta;
}

double ContaBancaria::get_Saldo()
{
	return _saldo;
}
int ContaBancaria::get_Senha()
{
	return _senha;
}
int ContaBancaria::get_numeroConta()
{
	return _numeroConta;
}
int ContaBancaria::geradorNumContas()
{
	int NumeroConta;
	int repetido=0;
	do 
	{
		NumeroConta = 180510000+rand() % 9999;
		for (int i = 0; i<signed(NumContas.size()); i++)
		{
			if (NumeroConta == NumContas[i])
			{
				repetido = 1;
			}
		}

	} while (repetido == 1);

	return NumeroConta;
}

//METODOS CONTA CORRENTE
ContaCorrente::ContaCorrente(int &senha)
{
	this->set_Senha(senha);
	this->set_nConta(geradorNumContas());
	this->set_Saldo(0);
}

ContaCorrente::~ContaCorrente()
{
	for (int i = 0; i < signed(ExtratoConta.size()); i++)
	{
		delete ExtratoConta[i];
	}
}

void ContaCorrente::saca(double &valor)
{
	if (get_Saldo() >= valor) {
		ExtratoConta.resize(ExtratoConta.size() + 1);
		this->set_Saldo(get_Saldo() - valor);
		ExtratoConta[ExtratoConta.size() - 1] = new Extrato(this->get_Saldo(), valor, "SAQUE");
	}
	throw "::Saldo insuficiente::";
}
void ContaCorrente::deposita(double &valor)
{
	this->set_Saldo(double(this->get_Saldo() + valor));
	ExtratoConta.resize(ExtratoConta.size() + 1);
	this->set_Saldo(get_Saldo() + valor);
	ExtratoConta[ExtratoConta.size() - 1] = new Extrato(this->get_Saldo(), valor, "DEPOSITO");
}
void ContaCorrente::tiraExtrato()
{
	//
}




//METODOS CONTA POUPANCA




//METODOS EXTRATO