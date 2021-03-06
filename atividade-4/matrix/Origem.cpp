// main.cpp
#include <iostream>
#include "matrix.h"

using namespace std;


int main()
{
	//Abertura de arquivo de recurso
	ifstream File;
	File.open("myFile.txt");

	//Teste dos diferentes tipos de construtores
	Matrix Z(File);
	Matrix Y(3, 2, 7.1);
	Matrix X(4, 4, 4); // Matrix quadrada para transformar em identidade
	Matrix W;
	Matrix K(1, 2);
	
	//Impressao das matrizes para avaliar o construtores de cada tipo
	std::cout << "Y:: " << std::endl;
	Y.print();
	std::cout << "Numero de linhas de Y:: " << Y.getRows();
	std::cout << "Numero de colunas de Y:: " << Y.getCols();

	std::cout << endl<<"Z:: " << std::endl;
	Z.print();
	std::cout << "Numero de linhas de Z:: " << Z.getRows();
	std::cout << "Numero de colunas de Z:: " << Z.getCols();

	std::cout << endl << "X:: " << std::endl;
	X.print();
	std::cout << "Numero de linhas de X:: " << X.getRows();
	std::cout << "Numero de colunas de X:: " << X.getCols();
	
	std::cout << endl << "W:: " << std::endl;
	W.print();
	std::cout << "Numero de linhas de W:: " << W.getRows();
	std::cout << "Numero de colunas de W:: " << W.getCols();
	
	std::cout << endl << "K:: " << std::endl;
	K.print();
	std::cout << "Numero de linhas de K:: " << X.getRows();
	std::cout << "Numero de colunas de K:: " << X.getCols();
	
	//Teste de funções
	std::cout << "Transposta de Y:: " << std::endl;
	Y.transpose();
	Y.print();
	std::cout << "Numero de linhas de Y:: " << Y.getRows();
	std::cout << "Numero de colunas de Y:: " << Y.getCols();

	//Teste de novas funções
	cout << "Matriz X em identidade:" << endl;
	X.unit();
	std::cout << endl << "X:: " << std::endl;
	X.print();

	//Teste incoerencia: transformar matriz nao quadrada em identidade
	Y.unit();
	std::cout << endl << "Y:: " << std::endl;
	Y.print();

	//Teste da função zeros();
	cout << "Transformar matriz Z uma matriz de 0" << endl;
	Z.zeros();
	std::cout << endl << "Z:: " << std::endl;
	Z.print();

	//Teste da função ones();

	cout << "Transformar matriz Z uma matriz de 1" << endl;
	Z.zeros();
	std::cout << endl << "Z:: " << std::endl;
	Z.print();

	//Teste da função get(int ls, int cs) const;

	cout << "Obter o valor da posição de uma matriz M(linha,coluna) por meio da funcao get,passando como parametro a liha e coluna desejada:" << endl;
	cout << "Teste: Valor da posicao Y(1,1)" <<  Y.get(1, 1) << endl;

	cout << "Teste: Valor da posicao Y(5,5), OBS( Matriz esta do tamanho 2x3: "<<endl;
	cout << Y.get(5, 5) << endl;


	File.close();
	return 0;
}
