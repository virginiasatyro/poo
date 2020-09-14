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
	
	


	File.close();
	return 0;
}
