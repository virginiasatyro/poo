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
	if ((rows> 0) && (cols > 0)){
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
	else {
		if((rows==0)&&(cols==0))
		{
			nRows = 0;
			nCols = 0;
			m = NULL;
		}
		else
		{	
		cout<<"Parametros incorretos , retornando matriz 0x0"<<endl;
		nRows = 0;
		nCols = 0;
		m = NULL;

		}
		
	}
}

Matrix::Matrix(std:: ifstream &myFile)
{
	if (myFile.fail() == 1) 
	{
		cout << " Arquivo fonte de texto nao encontrado \n Favor verificar a existencia do arquivo myfile.txt no diretorio de origem\n" << endl;
	}
	else 
	{
		myFile >> nRows;
		myFile >> nCols;

		m = new double*[nRows];
		for (int i = 0; i < nRows; i++)
			m[i] = new double[nCols];

		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				myFile >> m[i][j];	
	}
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
			this->m[i][j] = that.m[i][j];
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

double Matrix::get(int ls, int cs) const
{
	if ((ls > 0) && (cs > 0)) {
		if (ls <= nRows) {
			if (cs <= nCols ) {
				return m[ls - 1][cs - 1];
			} else {
				cout << "posicao invalida - terceiro if, return -1" << endl;
				return -1;
			} 
		}
		else {
			cout << "posicao invalida - segundo if, return -1" << endl;
			return -1;
		}
	}
	else {
		cout << "posicao invalida funcao get, return -1" << endl;
		return -1;
	}
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

//Sobrecarga de operadores
Matrix Matrix::operator+ (const Matrix &Right) 
{
	if ((this->nRows==Right.nRows) && (this->nCols==Right.nCols))
	{	
		Matrix aux(this->nRows,this-> nCols);
		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				aux.m[i][j] = this->m[i][j]+ Right.m[i][j];

		return aux;
	}
	
	Matrix aux;
	return aux;
}

Matrix Matrix::operator- (const Matrix &Right)
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

Matrix& Matrix::operator=(const Matrix &Right)
{
	if(this == &n){
		return *this;
	}
	this->nRows = Right.nRows;
    	this->nCols = Right.nCols;
    	if(this->m != NULL){
        	for(int i = 0; i < nRows; i++){
 			delete[] this->m[i];
        	}
		delete[] this->m;
   	 }
   	 this->m = new double* [nRows];
   	 for(int i = 0; i < nRows; i++){
        	this->m[i] = new double[nCols];
    	}
    	for(int i = 0; i < nRows; i++){
        	for(int j = 0; j < nCols; j++){
           		 this->m[i][j] = Right.m[i][j];
        	}
    	}
    	return *this;
}

 bool Matrix:: operator== (const Matrix &Right) 
{
	 bool igualdade = false;
	 if ((this->nRows == Right.nRows) && (this->nCols == Right.nCols))
	 {
		 for (int i = 0; i < nRows; i++)
			 for (int j = 0; j < nCols; j++)
				 if (this->m[i][j]!=Right.m[i][j])
				 {
					 return igualdade;
				 }
		 return igualdade = true;
	 }
	 return igualdade;
}

 bool Matrix::operator!= (const Matrix &Right) 
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
		 return igualdade=false;
	 }
	 return igualdade;
}

Matrix Matrix::operator* (const Matrix &Right) 
{
	if (this->nCols == Right.nRows)
	{
		Matrix aux( this->nRows, Right.nCols);
		for (int i = 0; i < this->nRows; i++)
		{
			for (int j = 0; j < Right.nCols; j++)
			{
				for (int k = 0; k < this->nCols; k++)
				{
					aux.m[i][j]+= this->m[i][k] * Right.m[k][j];
				}
			}
		}
		return aux;
	}
	Matrix aux;
	return aux;
}

Matrix Matrix::operator~ () // Transposta
{
	Matrix aux(this->nCols, this->nRows);

	for (int i = 0; i < this->nRows; i++)
	{
		for (int j = 0; j < this->nCols; j++)
		{
			aux.m[j][i] = this->m[i][j];
		}
	}
	return aux;
}

double& Matrix::operator() (const int& ls, const int& cs) const
{
	return this->m[ls - 1][cs - 1];
}

Matrix& Matrix::operator -= (const Matrix &Right)
{
	if ((this->nRows == Right.nRows) && (this->nCols == Right.nCols))
	{
		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
					this->m[i][j] -= Right.m[i][j];
	}
	return *this;
}

Matrix& Matrix::operator += (const Matrix &Right)
{
	if ((this->nRows == Right.nRows) && (this->nCols == Right.nCols))
	{
		for (int i = 0; i < nRows; i++)
			for (int j = 0; j < nCols; j++)
				this->m[i][j] += Right.m[i][j];
	}
	return *this;
}
Matrix& Matrix::operator *= (const double n)
{
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			this->m[i][j] *= n;
	return *this;
}

Matrix& Matrix::operator *= (const Matrix &Right)
{
	if (this->nCols == Right.nRows){
		Matrix aux(this->nRows,Right.nCols);
		for (int i = 0; i < this->nRows; i++)
		{
			for (int j = 0; j < Right.nCols; j++)
			{
				for (int k = 0; k < this->nCols; k++)
				{
					aux.m[i][j]+= this->m[i][k] * Right.m[k][j];
				}
			}
		}	
		return *this = aux;
	}
}

istream& operator >> (istream& text, Matrix& Right) //ENTRADA
{
	for (int i = 0; i < Right.nRows; i++) {
		for (int j = 0; j < Right.nCols; j++)
			text >> Right.m[i][j];
	}
	return text;
}

ostream& operator << (ostream& text, const Matrix& Right) //SAIDA
{
	for (int i = 0; i < Right.nRows; i++) {
		for (int j = 0; j < Right.nCols; j++)
			text << Right.m[i][j] << " ";
		text << "\n";
	}
	text << "\n";
	return text;
}
