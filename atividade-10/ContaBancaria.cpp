#include "ContaBancaria.h"
#include<iostream>

using namespace std;

vector<int> ContaCorrente::NumContas;

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

//METODOS SETS
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
// METODOS GETS
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
//DEMAIS METODOS
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
ContaCorrente::ContaCorrente(int &senha):ContaBancaria(senha)
{
	this->set_Senha(senha);
	this->set_nConta(geradorNumContas());
	this->set_Saldo(0);
	nTransacoes = 0;
}

ContaCorrente::~ContaCorrente()
{
	for (int i = 0; i < signed(ExtratoConta.size()); i++)
	{
		delete ExtratoConta[i];
	}
}
// FUNCOES VIRTUAIS SENDO DEFINIDAS
void ContaCorrente::saca(double &valor)
{
	if (get_Saldo() >= valor) {
		ExtratoConta.resize(ExtratoConta.size() + 1);
		this->set_Saldo(get_Saldo() - valor);
		ExtratoConta[ExtratoConta.size() - 1] = new Extrato(this->get_Saldo(), valor, "SAQUE");
		nTransacoes++;
	}
	throw "::Saldo insuficiente::";
}

void ContaCorrente::deposita(double valor)
{
	this->set_Saldo(double(this->get_Saldo() + valor));
	ExtratoConta.resize(ExtratoConta.size() + 1);
	this->set_Saldo(get_Saldo() + valor);
	ExtratoConta[ExtratoConta.size() - 1] = new Extrato(this->get_Saldo(), valor, "DEPOSITO");
	nTransacoes++;
}
void ContaCorrente::tiraExtrato()
{
	for (int i = 0; i < (signed)this->ExtratoConta.size() - 1; i++)
	{
		this->ExtratoConta[i]->printDados();
	}
}
double ContaCorrente::DadoUnico()
{
	return this->nTransacoes;
}


//METODOS CONTA POUPANCA
ContaPoupanca::ContaPoupanca(int &senha) :ContaBancaria(senha)
{
	this->set_Senha(senha);
	this->set_nConta(geradorNumContas());
	this->set_Saldo(0);
	this->set_TaxaRend(0.99); //Preset padrao da taxa do banco, pode ser alterada por funcao
}
ContaPoupanca::~ContaPoupanca()
{
	for (int i = 0; i < signed(ExtratoConta.size()); i++)
	{
		delete ExtratoConta[i];
	}
}
// FUNCOES VIRTUAIS SENDO DEFINIDAS
void ContaPoupanca::saca(double &valor)
{
	if (get_Saldo() >= valor) {
		ExtratoConta.resize(ExtratoConta.size() + 1);
		this->set_Saldo(get_Saldo() - valor);
		ExtratoConta[ExtratoConta.size() - 1] = new Extrato(this->get_Saldo(), valor, "SAQUE");
	}
	throw "::Saldo insuficiente::";
}

void ContaPoupanca::deposita(double valor)
{
	//this->set_Saldo(double(this->get_Saldo() + valor));
	ExtratoConta.resize(ExtratoConta.size() + 1);
	this->set_Saldo(this->get_Saldo() + valor);
	ExtratoConta[ExtratoConta.size() - 1] = new Extrato(this->get_Saldo(), valor, "DEPOSITO");
}
void ContaPoupanca::tiraExtrato()
{
	cout << " Taxa de Rendimento: " << _TaxaRend <<"::"<< endl;
		for (int i = 0; i < (signed)this->ExtratoConta.size() - 1; i++)
		{
			this->ExtratoConta[i]->printDados();
		}
}


double ContaPoupanca::DadoUnico()
{
	return this->_TaxaRend;
}
// METODO SETS
void ContaPoupanca::set_TaxaRend(double novaTaxa)
{
	_TaxaRend = novaTaxa;
}
