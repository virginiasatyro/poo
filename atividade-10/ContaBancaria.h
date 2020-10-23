#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H
#include <vector>
#include "Extrato.h"
using namespace std;

class ContaBancaria
{
public:
	ContaBancaria(int &senha);
	~ContaBancaria();
	virtual void saca(double &valor)=0;
	virtual void deposita(double &valor) = 0;
	virtual void tiraExtrato()=0;

	//metodos getters e setters
	bool alteraSenha(int &senha);
	void set_Senha(int &senha);
	void set_Saldo(double novoSaldo);
	double get_Saldo();
	void set_nConta(int Conta);
	int get_Senha();
	int get_numeroConta();
	int geradorNumContas();

private:
	int _senha, _numeroConta;
	double _saldo;
	static vector<int> NumContas;
};

class ContaCorrente : public ContaBancaria
{
public:
	ContaCorrente(int &senha);
	~ContaCorrente();

	void saca(double &valor) override;
	void deposita(double &valor) override;
	void tiraExtrato() override;

private:
	vector<Extrato*> ExtratoConta;
};

class ContaPoupanca :public ContaBancaria
{
public:
	ContaPoupanca(int &senha);
	~ContaPoupanca();

	void saca(double &valor) override;
	void deposita(double &valor) override;
	void tiraExtrato() override;

private:
	double _TaxaRend;
};

#endif