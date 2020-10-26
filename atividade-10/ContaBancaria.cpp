#include "ContaBancaria.h"
#include<iostream>

using namespace std;

vector<int> ContaBancaria::NumContas;

//METODOS CONTA BANCARIA

ContaBancaria::ContaBancaria(int &senha)
{
	_senha = senha;
	_saldo = 0.0;
	this->set_nConta(geradorNumContas());
}

ContaBancaria::~ContaBancaria()
{
	for (int i = 0; i < signed(ExtratoConta.size()); i++)
	{
		delete ExtratoConta[i];
	}
}
//Metodo para alterar a senha ja definida, primeiro fornecer a senha atual. depois a nova senha
bool ContaBancaria::alteraSenha(int &senha)
{
	if (_senha == senha) {
		cout << "::Digite a nova senha::" << endl;
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
	// O codigo cria um numero da conta bancaria e verifica se esse numero ja foi utilizado
	// caso o numero de conta coincida com algum numero existe o codigo ira gerar um novo numero de conta
	// e verificar novamente até encontrar um numero de conta bancario unico
	int repetido=0;
	do 
	{
		repetido = 0;
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
	throw  Erro ("::Saldo insuficiente::");
}

void ContaCorrente::deposita(double valor)
{// REALIZA O DEPOSITO E REGISTRA A OPERACAO NO VETOR DE EXTRATO E ADICIONA +1 NO NUMERO DE TRANSACOES
	this->set_Saldo(this->get_Saldo() + valor);
	ExtratoConta.resize(ExtratoConta.size() + 1);
	ExtratoConta[ExtratoConta.size() - 1] = new Extrato(this->get_Saldo(), valor, "DEPOSITO");
	nTransacoes++;
}
void ContaCorrente::tiraExtrato()
{
	cout << ":: Conta numero: " << this->get_numeroConta() << " ::" << endl;
	cout << ":: Numero de transacoes " << nTransacoes << "::" << endl;
	cout << ":: OPERACAO :: VALOR :: SALDO ::"<<endl;
	for (int i = 0; i < (signed)this->ExtratoConta.size(); i++)
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
	throw  Erro("::Saldo insuficiente Operacao cancelada::");
}
// REALIZA O DEPOSITO E REGISTRA A OPERACAO NO VETOR DE EXTRATO
void ContaPoupanca::deposita(double valor)
{
	ExtratoConta.resize(ExtratoConta.size() + 1);
	this->set_Saldo(this->get_Saldo() + valor);
	ExtratoConta[ExtratoConta.size() - 1] = new Extrato(this->get_Saldo(), valor, "DEPOSITO");
}
void ContaPoupanca::tiraExtrato()
{
	cout << ":: Conta numero: " << this->get_numeroConta() << " ::" << endl;
	cout << ":: Taxa de Rendimento: " << _TaxaRend <<"::"<< endl;
	cout << "::  OPERACAO  ::  VALOR  ::  SALDO ::" << endl;
		for (int i = 0; i < (signed)this->ExtratoConta.size(); i++)
		{
			this->ExtratoConta[i]->printDados();
		}
	cout << " " << endl;
}
// METODO VIRTUAL POLIMORFICO PARA CADA TIPO DE CLASSE DERIVADA DA CLASSE BASE ABSTRATA
double ContaPoupanca::DadoUnico()
{
	return this->_TaxaRend;
}
// METODO SETS
void ContaPoupanca::set_TaxaRend(double novaTaxa)
{
	_TaxaRend = novaTaxa;
}
