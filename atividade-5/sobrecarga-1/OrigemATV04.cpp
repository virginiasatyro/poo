// Ponto2D.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "ponto2D.h"


using namespace std;

int main()// Programa teste
{
	//Criacao de 4 objetos
	Ponto A, C, D (11.02,13.65);
	Ponto B(3.65, 5.33);
	Ponto E(D);
	Ponto F = E;
	//Teste para avaliar que o contador _id esta correto, valor de 4 objetos do tipo ponto foram criados
	cout << "Total de pontos criados:: " << A.getNextId()<<endl;
	//Teste da função print() e da inicialização do objeto por default
	cout << "imprime ponto A:" << endl;
	A.print();
	//Avaliar a inicialização do objeto por passagem de argumentos
	cout << "imprime ponto B:" << endl;
	B.print();
	cout << "imprime ponto E = D:" << endl;
	E.print();
	cout << "imprime ponto F = D:" << endl;
	F.print();

	//Teste da função sumOf
	A.sumOf(B);
	cout << "imprime soma de A= A+B:" << endl;
	A.print();
	//Teste da função sumOf_
	C = A.sumOf_(B);
	cout << "imprime soma C= A+B:" << endl;
	C.print();
	// Teste da função distToOrig
	double x = B.distToOrig();
	cout << "Distancia do ponto B a origem 0,0: " << x << endl;

	x = B.distTo(D);
	cout << "Distancia do ponto B ao ponto D: " << x << endl;
	//Demonstração que o _id pode ser acessado por qualquer objeto da mesma classe e o valor esta correto
	cout << "Total de pontos criados:: " << D.getNextId() << endl;

}
