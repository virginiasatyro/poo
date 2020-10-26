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
	virtual void deposita(double valor) = 0;
	virtual void tiraExtrato()=0;
	virtual double DadoUnico() = 0;
	//Por estarmos implementando a um vetor de extrato para ambas as classes poupanca e corrente
	//Criamos esse metodo virtual para imprimir dados unicos de cada classe, para que nao fosse impresso o 
	//extrato toda vez que se consultasse a taxa de rendimento ou o numero de transacoes, tornando o
	//programa mais proximo da realidade 

	//O conteudo cobrado neste TP nessa aplicado na funcao abaixo -Polimorfismo e RTTI


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
protected:
	static vector<int> NumContas;
	vector<Extrato*> ExtratoConta;
};

class ContaCorrente : public ContaBancaria
{
public:
	ContaCorrente(int &senha);
	~ContaCorrente();

	void saca(double &valor) override;
	void deposita(double valor) override;
	void tiraExtrato() override;
	double DadoUnico() override;

private:
	int nTransacoes;
};

class ContaPoupanca :public ContaBancaria
{
public:
	ContaPoupanca(int &senha);
	~ContaPoupanca();

	void saca(double &valor) override;
	void deposita(double valor) override;
	void tiraExtrato() override;
	double DadoUnico() override;

	void set_TaxaRend(double novaTaxa);

private:
	double _TaxaRend;
};

#endif
