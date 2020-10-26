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
	cout << "::Taxa de rendimento para cada conta POUPANCA::" << endl;
	for (int i = 0; i < (signed)ContasBanco.size(); i++)
	{
		ContaPoupanca *OK = dynamic_cast<ContaPoupanca*>(ContasBanco[i]);
		if (OK)
		{
			cout << "::Conta Poupanca numero: " << ContasBanco[i]->get_numeroConta();
			cout << "::Taxa:"<<ContasBanco[i]->DadoUnico() << endl;
		}
	}

// REALIZANDO DEPOSITOS
//DEPOSITANDO UM VALOR ALEATORIO EM CADA CONTA
	cout << ":: REALIZANDO DEPOSITOS DE VALORES ALEATORIOS NAS CONTAS ::" << endl;
double deposito;
for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	deposito = rand() % 600;
	ContasBanco[i]->deposita(deposito);
}
//DEPOSITANDO UM VALOR DE 250 REAIS SOMENTE NAS CONTAS CORRENTE
cout << ":: REALIZANDO DEPOSITOS DE R$ 250 NAS CONTAS CORRENTE ::" << endl;

for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	ContaCorrente *OK = dynamic_cast<ContaCorrente*>(ContasBanco[i]);
	if (OK)
	{
		ContasBanco[i]->deposita(250);
	}
}
cout <<" "<< endl;
//DEPOSITANDO UM VALOR DE 1000 REAIS SOMENTE NAS CONTAS POUPANCA
cout << ":: REALIZANDO DEPOSITOS DE R$ 1000 NAS CONTAS POUPANCA::" << endl;
for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	ContaPoupanca *OK = dynamic_cast<ContaPoupanca*>(ContasBanco[i]);
	if (OK)
	{
		ContasBanco[i]->deposita(1000);
	}
}
cout << " " << endl;
cout << ":: REALIZANDO SAQUES ALEATORIOS EM CADA CONTA CRIADA::" << endl;
// REALIZANDO SAQUES
// VALOR DE SAQUES ALEATORIOS
double saque;
for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	saque = rand() % 1000;
	cout << ":: SAQUE de R$ " << saque << " na conta numero: " << ContasBanco[i]->get_numeroConta() << " :: " << endl;
	cout << ":: Saldo disponivel :R$ "<< ContasBanco[i]->get_Saldo() << " :: " << endl;
	//PODEM OCORRER VALORES DE SAQUE MAIORES DO QUE O VALOR  DISPONIVEL NA CONTA, PARA ISSO USAMOS O TRY ANDA CATCH
	try {
		ContasBanco[i]->saca(saque);
	}
	catch (Erro& ex)
	{
		ex.out();
		cout << endl;
	}

}
cout << " " << endl;
// TAXA DE RENDIMENTO DAS CONTAS CORRENTES VIA RTTI
for (int i = 0; i < (signed)ContasBanco.size(); i++)
	{
		ContaPoupanca *OK = dynamic_cast<ContaPoupanca*>(ContasBanco[i]);
		if (OK)
		{
			cout << "::Conta Poupanca numero: " << ContasBanco[i]->get_numeroConta();
			cout << "::Taxa:" << ContasBanco[i]->DadoUnico() << endl;
		}
	}

// NUMERO DE TRANSACOES DAS CONTAS CORRENTES VI RTTI
cout << " " << endl;
for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	ContaCorrente *OK = dynamic_cast<ContaCorrente*>(ContasBanco[i]);
	if (OK)
	{
		cout << "::Conta Corrente numero: " << ContasBanco[i]->get_numeroConta();
		cout << "::Numero de transacoes:" << ContasBanco[i]->DadoUnico() << endl;
	}
}
cout << " " << endl;
cout << ":: IMPRIMINDO EXTRATOS ::" << endl;
// IMPRESSAO DO EXTRATO - CRIAMOS POR NOSSA INTERPRETACAO E PARA GANHAR PONTOS EXTRA
// A CLASSE EXTRATO QUE ARMAZENA O TIPO DA OPERACAO FINANCEIRA, VALOR SACADO OU RETIRADO, E O VALOR DE DINHEIRO NA CONTA
// QUE SE APROXIMA DO EXTRATO QUE RETIRAMOS NUM BANCO
//Podemos imprimir também somente os dados de conta poupanca ou da corrente se for solicitado via RTTI
for (int i = 0; i < (signed)ContasBanco.size(); i++)
{
	ContasBanco[i]->tiraExtrato();
}
cout << " " << endl;

// O banco fechou, vamos deletar tudo, apagando contas e dinheiro também
// DELETANDO MEMORIA ALOCADA
for (int i = 0; i < (signed) ContasBanco.size(); i++)
{
	delete ContasBanco[i];
}
//FIM Boas Ferias
return 0;
}
