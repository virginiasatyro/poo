/*1.2. O código a seguir implementa uma classe template de um lista duplamente encadeada. 
Veja que os métodos erase(Node *it) e erase(const T& value) podem gerar situações de 
erro (exceção) no código. No momento, caso um erro ocorra, eles enviam uma mensagem de 
erro na saída padrão, cerr(...) .
•Modifique esses métodos para que eles passem a lançar erros usando a cláusula throw.

•Modifique também o código cliente main(...) para que os erros possam ser tratados 
devidamente com as cláusulas try and catch(...)

Observação: nenhum novo método precisa ser criado.*/


#include <iostream>
#include <cstdlib> // system()
using namespace std;
#include "List.h"

void clearscreen() {
	if (system("clear")) system("cls");
}

int main(int argc, char *argv[])
{

	// Cria Lista
	List<int> A;
	cout << "Criacao da Lista A:" << endl;
	cout << "-> Lista A: " << A << endl;
	//Insere elementos no Final da lista
	A.push_back(3);
	A.push_back(4);
	A.push_back(5);
	A.push_back(6);
	A.push_back(6);
	A.push_back(1);
	A.push_back(2);
	
	cout << "A.push_back(3), A.push_back(4), A.push_back(5), A.push_back(6), A.push_back(6), A.push_back(1), A.push_back(2)" << endl;
	cout << "-> Lista A " << A << endl;

	//Insere elementos no Inicio da lista
	A.push_front(8);
	A.push_front(9);
	A.push_front(4);
	A.push_front(9);
	cout << "A.push_front(8), A.push_front(9), A.push_front(4), A.push_front(9)" << endl;
	cout << "-> Lista A " << A << endl;

	
	// remove os elementos de valor igual a 6 existentes na lista
	try 
	{
		A.erase(25);// antes era 6
		cout << "A.erase(12)" << endl;
		cout << "-> Lista A " << A << endl;
	}
	catch ( const char* error)
	{
			cout << "Erro: " << error << endl;
			//Uma possibilidade correção seria inserir um elemento a lista
			// para continuar a execução do programa
			cout << " Deseja inserir um elemento na Lista (s/n):";
			char op;
			cin >> op;
			//caso o usuario aceite inserir, a lista deixara de ser nula e o pograma continuara
			//a execução retornando a função onde foi gerado o THROW.
			if (op == 's') {
				int T;
				cin >> T;
				A.push_back(T);
			}
			//caso nao, o programa sai do catch e retorna as execuções sequenciais apos o throw, se possivel
	}
	// retorna o tamanho da lista
	int tam;
	tam = A.size();
	cout << "tam = A.size" << endl;
	cout << "-> tamanho da Lista A = " << tam << endl << endl;

	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	clearscreen();

	
}