#include <iostream>
#include "matrix.h"
#include <fstream>

using namespace std;

//contrutor default - cria uma matriz vazia com nRows = nCols = 0 
template<class T>
Matrix<T>::Matrix()
{
	nRows = 0;
	nCols = 0;
	m = NULL;
}

template<class T>
Matrix<T>::Matrix(int rows, int cols, const T& value)
{
	if ((rows > 0) && (cols > 0)) {
		nRows = rows;
		nCols = cols;

		m = new T*[nRows];
		for (int i = 0; i < nRows; i++)
			m[i] = new T[nCols];
		for (int i = 0; i < nRows; i++) {
			for (int j = 0; j < nCols; j++)
				m[i][j] = value;
		}
	}
	else {

			throw "Parametros incorretos para criar uma matriz" ;

		}

	
}
template<class T>
Matrix<T>::Matrix(std::ifstream &myFile)
{
	if (myFile.fail() == 1)
	{
		cout << " Arquivo fonte de texto nao encontrado \n Favor verificar a existencia do arquivo myfile.txt no diretorio de origem\n" << endl;
	}
	else
	{
		myFile >> nRows;
		myFile >> nCols;

		m = new T*[nRows];
		for (int i = 0; i < nRows; i++)
			m[i] = new T[nCols];

		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				myFile >> m[i][j];
	}
}
template<class T>
Matrix<T>::Matrix(const Matrix &that)
{
	this->nRows = that.nRows;
	this->nCols = that.nCols;
	this->m = new T*[nRows];

	for (int i = 0; i < this->nRows; i++)
		this->m[i] = new T[this->nCols];
	for (int i = 0; i < this->nRows; i++) {
		for (int j = 0; j < this->nCols; j++)
			this->m[i][j] = that.m[i][j];
	}
}

template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < nRows; i++)
		delete[] m[i];
	delete[] m;
}

template<class T>
int Matrix<T>::rows() const
{
	return nRows;
}

template<class T>
int Matrix<T>::cols() const
{
	return nCols;
}

template<class T>
T Matrix<T>::get(int ls, int cs) const
{
	if ((ls > 0) && (cs > 0))
		if ((ls <= nRows) && (cs <= nCols))
			return m[ls - 1][cs - 1];

		else
			throw "- Posicao invalida - ";
	
}

template<class T>
void Matrix<T>::transpose()
{
	//Cria uma nova matriz com numero de linhas e colunsa trocadas
	//copia os elementos da matriz X para a nova matriz
	//troca os ponteiros duplos para que o destruir do objeto desaloque
	//as memorias de matrizes nao utilizadas
	Matrix<(this->m)> Y(nCols, nRows);

	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			Y.m[j][i] = m[i][j];
	}
	T **temp;
	// Reapontamento dos apontadores da matriz
	temp = m;
	m = Y.m;
	Y.m = temp;
	// Troca do numero de linhas e colunas da matriz transposta
	nCols = Y.nCols;
	nRows = Y.nRows;
}

// imprime o conteudo da matriz
template<class T>
void Matrix<T>::print() const
{
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++)
			cout << m[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
}

//NOVOS METODOS
template<class T>
void Matrix<T>::unit()
{
	if (nRows == nCols) {
		this->zeros();
		for (int i = 0; i < nRows; i++)
			this->m[i][i] = 1.0;
	}
}
template<class T>
void Matrix<T>::zeros()
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m[i][j] = 0.0;
}
template<class T>
void Matrix<T>::ones()
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m[i][j] = 1.0;
}

//Sobrecarga de operadores
template<class T>
Matrix<T> Matrix<T>::operator+ (const Matrix &Right)
{
	if ((this->nRows == Right.nRows) && (this->nCols == Right.nCols))
	{
		Matrix aux(this->nRows, this->nCols);
		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				aux.m[i][j] = this->m[i][j] + Right.m[i][j];

		return aux;
	}

	Matrix aux;
	return aux;
}
template<class T>
Matrix<T> Matrix<T>::operator- (const Matrix &Right)
{
	if ((this->nRows == Right.nRows) && (this->nCols == Right.nCols))
	{
		Matrix aux(nRows, nCols);
		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				aux.m[i][j] = this->m[i][j] - Right.m[i][j];
		return aux;
	}
	Matrix aux;
	return aux;
}
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix &Right)
{
	if (this == &Right) {
		return *this;
	}
	this->nRows = Right.nRows;
	this->nCols = Right.nCols;
	if (this->m != NULL) {
		for (int i = 0; i < nRows; i++) {
			delete[] this->m[i];
		}
		delete[] this->m;
	}
	this->m = new T*[nRows];
	for (int i = 0; i < nRows; i++) {
		this->m[i] = new T[nCols];
	}
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			this->m[i][j] = Right.m[i][j];
		}
	}
	return *this;
}
template<class T>
bool Matrix<T>:: operator== (const Matrix &Right)
{
	bool igualdade = false;
	if ((this->nRows == Right.nRows) && (this->nCols == Right.nCols))
	{
		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				if (this->m[i][j] != Right.m[i][j])
				{
					return igualdade;
				}
		return igualdade = true;
	}
	return igualdade;
}
template<class T>
bool Matrix<T>::operator!= (const Matrix &Right)
{
	bool igualdade = true;
	if ((this->nRows == Right.nRows) && (this->nCols == Right.nCols))
	{
		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				if (this->m[i][j] != Right.m[i][j])
				{
					return igualdade;
				}
		return igualdade = false;
	}
	return igualdade;
}
template<class T>
Matrix<T> Matrix<T>::operator* (const Matrix &Right)
{
	if (this->nCols == Right.nRows)
	{
		Matrix aux(this->nRows, Right.nCols);
		for (int i = 0; i < this->nRows; i++)
		{
			for (int j = 0; j < Right.nCols; j++)
			{
				for (int k = 0; k < this->nCols; k++)
				{
					aux.m[i][j] += this->m[i][k] * Right.m[k][j];
				}
			}
		}
		return aux;
	}
	else
	     throw " -operacao invalidade entre as matrizes- ";
}
template<class T>
Matrix<T> Matrix<T>::operator~ () // Transposta
{
	Matrix<T> aux(this->nCols, this->nRows);

	for (int i = 0; i < this->nRows; i++)
	{
		for (int j = 0; j < this->nCols; j++)
		{
			aux.m[j][i] = this->m[i][j];
		}
	}
	return aux;
}

template<class T>
T& Matrix<T>::operator() (const int& ls, const int& cs) const
{
	if ((ls > 0) && (cs > 0))
		if ((ls <= nRows) && (cs <= nCols))
			return *this->m[ls - 1][cs - 1];
	else
		throw "- Posicao invalida - ";
}

template<class T>
Matrix<T>& Matrix<T>::operator -= (const Matrix &Right)
{
	if ((this->nRows == Right.nRows) && (this->nCols == Right.nCols))
	{
		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				this->m[i][j] -= Right.m[i][j];
	return *this;
	}
	else
		throw "Operacao impossivel para matrizes de diferentes dimensoes- ";
}

template<class T>
Matrix<T>& Matrix<T>::operator += (const Matrix &Right)
{
	if ((this->nRows == Right.nRows) && (this->nCols == Right.nCols))
	{
		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				this->m[i][j] += Right.m[i][j];
	return *this;
	}
	else
		throw " -Operacao impossivel para matrizes de diferentes dimensoes- ";
}

template<class T>
Matrix<T>& Matrix<T>::operator *= (const double n)
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			this->m[i][j] *= n;
	return *this;
}
template<class T>
Matrix<T>& Matrix<T>::operator *= (const Matrix &Right)
{
	if (this->nCols == Right.nRows) {
		Matrix aux(this->nRows, Right.nCols);
		for (int i = 0; i < this->nRows; i++)
		{
			for (int j = 0; j < Right.nCols; j++)
			{
				for (int k = 0; k < this->nCols; k++)
				{
					aux.m[i][j] += this->m[i][k] * Right.m[k][j];
				}
			}
		}
		return *this = aux;
	}
	else
		throw " -Operacao impossivel para matrizes de diferentes dimensoes- ";
}
template<class T>
istream& operator >> (istream& text, Matrix<T>& Right) //ENTRADA
{
	for (int i = 0; i < Right.nRows; i++) {
		for (int j = 0; j < Right.nCols; j++)
			text >> Right.m[i][j];
	}
	return text;
}

template<class T>
ostream& operator << (ostream& text, const Matrix<T>& Right) //SAIDA
{
	for (int i = 0; i < Right.nRows; i++) {
		for (int j = 0; j < Right.nCols; j++)
			text << Right.m[i][j] << " ";
		text << "\n";
	}
	text << "\n";
	return text;
}

