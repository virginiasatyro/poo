#include <iostream>
#include "matrix.h"
#include <fstream>

using namespace std;

//contrutor default - cria uma matriz vazia com nRows = nCols = 0  
Matrix::Matrix() 
{
	nRows = 0;
	nCols = 0;
	m = NULL;
}

Matrix::Matrix(int rows, int cols, const double &value) 
{
	nRows = rows;
	nCols = cols;
	m = new double*[nRows];
	for (int i = 0; i < nRows; i++)
		m[i] = new double[nCols];
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			m[i][j] = value;
	}
}

Matrix::Matrix(std:: ifstream &myFile)
{
	myFile.open("myfile.doc");

	if (myFile.fail() == 1) 
	{
		cout << " Arquivo fonte de texto nao encontrado \n Favor verificar a existencia do arquivo myfile.txt no diretorio de origem\n" << endl;
	}
	else 
	{
	double value = 0.0;

		myFile >> nRows;
		myFile >> nCols;
		//cout << "n:" << nRows << " - " << nCols << endl;

		m = new double*[nRows];
		for (int i = 0; i < nRows; i++)
			m[i] = new double[nCols];

		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				myFile >> m[i][j];	
		
	}
	myFile.close();
}

Matrix::Matrix(const Matrix &that)
{
	this->nRows = that.nRows;
	this->nCols = that.nCols;
	this->m = new double*[nRows];

	for (int i = 0; i < this->nRows; i++)
		this->m[i] = new double[this->nCols];
	for (int i = 0; i < this->nRows; i++) {
		for (int j = 0; j < this->nCols; j++)
			this->m[i][j] = that.get(i,j);
	}
}

// destrutor
Matrix::~Matrix()
{
	for (int i = 0; i < nRows; i++)
		delete[] m[i];
	delete [] m;
}
// obtem o numero de linhas
int Matrix::getRows() const 
{
	return nRows;
}
// obtem o numero de colunas
int Matrix::getCols() const 
{
	return nCols;
}

double Matrix:: get(int ls, int cs) const
{
	if (ls < nRows)
		if (cs < nCols)
			return m[ls-1][cs-1];
}
// torna a matriz transposta
void Matrix::transpose() 
{
	//Cria uma nova matriz com numero de linhas e colunsa trocadas
	//copia os elementos da matriz X para a nova matriz
	//troca os ponteiros duplos para que o destruir do objeto desaloque
	//as memorias de matrizes nao utilizadas
	Matrix Y(nCols, nRows);

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			Y.m[j][i] = m[i][j];
	}
	
	double **temp;
	// Reapontamento dos apontadores da matriz
	temp = m;
	m = Y.m;
	Y.m = temp;
	// Troca do numero de linhas e colunas da matriz transposta
	nCols = Y.nCols;
	nRows = Y.nRows;
}

// imprime o conteudo da matriz
void Matrix::print() const 
{
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			cout << m[i][j]<< " ";
		cout << "\n";
	}
	cout << endl;
}

//NOVOS METODOS

void Matrix::unit()
{
	if (nRows == nCols) {
		this->zeros();
		for (int i = 0; i < nRows; i++)
			this->m[i][i] = 1.0;
	}	
}

void Matrix::zeros() 
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m[i][j] = 0.0;
}

void Matrix::ones()
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m[i][j] = 1.0;
}
