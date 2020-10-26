#include <iostream>
#include "ContaBancaria.h"
#include <vector>

using namespace std;

int main()
{
	//Vetor para alocação dinamica de ContasBancarias
	vector<ContaBancaria*> ContasBanco;
	int nContas;

	cout << "::Ola, quantas contas bancarias deseja criar conosco?::" << endl;
	cin >> nContas;
	cout << "::Hum, entendi, voce deseja criar "<<nContas<<" novas contas. Vamos comecar:"<<endl;
	//Definir o tamanho do vetor pelo numero de contas totais
	ContasBanco.resize(nContas);
//CRIA CONTAS
	cout << "::Trabalhamos com dois tipos de contas, corrente e poupanca:" << endl;
	cout << "::Digite 1 para Corrente e 2 para Poupanca, e a cada conta digita a senha tbm =]::" << endl;
	int ContasCriadas = 0;
	while (ContasCriadas < nContas)
	{
		cout << "::Qual o tipo da conta " << ContasCriadas << "?" << endl;
		int Tipo, senha;
		cin >> Tipo;
		if (Tipo == 1) // Cria conta Corrente
		{
			cout << "::Qual a senha para esta conta corrente?::" << endl;
			cin >> senha;
			ContasBanco[ContasCriadas] = new ContaCorrente(senha);
			ContasCriadas++;
		}
		else if (Tipo == 2) // Cria conta Poupanca
		{
			cout << "::Qual a senha para esta conta poupanca?::" << endl;
			cin >> senha;
			ContasBanco[ContasCriadas] = new ContaPoupanca(senha);
			ContasCriadas++;
		}
		else
		{
			cout << " Valor invalido, essa opcao nao existe. Vamos tentar de novo::" << endl;
		}
	}

// TESTE DE IMPRESSAO DA TAXA DE RENDIMENTO VIA RTTI
	cout << "::Taxa de rendimento para cada conta::" << endl;
	for (int i = 0; i < (signed)ContasBanco.size(); i++)
	{
		ContaPoupanca *OK = dynamic_cast<ContaPoupanca*>(ContasBanco[i]);
		if (OK)
		{
			cout << "Conta Poupanca numero: " << ContasBanco[i]->get_numeroConta();
			cout << "Taxa:"<<ContasBanco[i]->DadoUnico() << endl;
		}

	}

// REALIZANDO DEPOSITOS
double deposito;
//DEPOSITANDO UM VALOR ALEATORIO EM CADA CONTA
for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	deposito = rand() % 600;
	ContasBanco[i]->deposita(deposito);
}
//DEPOSITANDO UM VALOR DE 250 REAIS SOMENTE NAS CONTAS CORRENTE

for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	ContaCorrente *OK = dynamic_cast<ContaCorrente*>(ContasBanco[i]);
	if (OK)
	{
		ContasBanco[i]->deposita(250);
	}
}

//DEPOSITANDO UM VALOR DE 1000 REAIS SOMENTE NAS CONTAS POUPANCA

for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	ContaPoupanca *OK = dynamic_cast<ContaPoupanca*>(ContasBanco[i]);
	if (OK)
	{
		ContasBanco[i]->deposita(1000);
	}
}

// REALIZANDO SAQUES
// VALOR DE SAQUES ALEATORIOS
double saque;
for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	saque = rand() % 1000;
	//PODEM OCORRER VALORES DE SAQUE MAIORES DO QUE O VALOR  DISPONIVEL NA CONTA, PARA ISSO USAMOS O TRY ANDA CATCH
	
	// Implementar Try and catch
	// Vou dormir 
	
	
	
	
	
	
	ContasBanco[i]->saca(saque);
}

// TAXA DE RENDIMENTO DAS CONTAS CORRENTES VIA RTTI
for (int i = 0; i < (signed)ContasBanco.size(); i++)
	{
		ContaPoupanca *OK = dynamic_cast<ContaPoupanca*>(ContasBanco[i]);
		if (OK)
		{
			cout << "Conta Poupanca numero: " << ContasBanco[i]->get_numeroConta();
			cout << "Taxa:" << ContasBanco[i]->DadoUnico() << endl;
		}
	}

// NUMERO DE TRANSACOES DAS CONTAS CORRENTES VI RTTI

for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	ContaCorrente *OK = dynamic_cast<ContaCorrente*>(ContasBanco[i]);
	if (OK)
	{
		cout << "Conta Corrente numero: " << ContasBanco[i]->get_numeroConta();
		cout << "Numero de transacoes:" << ContasBanco[i]->DadoUnico() << endl;
	}
}

// IMPRESSAO DO EXTRATO - CRIAMOS POR NOSSA INTERPRETACAO E PARA GANHAR PONTOS EXTRA
// A CLASSE EXTRATO QUE ARMAZENA O TIPO DA OPERACAO FINANCEIRA, VALOR SACADO OU RETIRADO, E O VALOR DE DINHEIRO NA CONTA
// QUE SE APROXIMA DO EXTRATO QUE RETIRAMOS NUM BANCO
//Podemos imprimir também somente os dados de conta poupanca ou da corrente se for solicitado via RTTI
for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	ContasBanco[i]->tiraExtrato();
}

// O banco fechou, vamos deletar tudo, apagando contas e dinheiro também
// DELETANDO MEMORIA ALOCADA
for (int i = 0; i < (signed) ContasBanco.size() - 1; i++)
{
	delete ContasBanco[i];
}
//FIM Boas Ferias
return 0;
}
