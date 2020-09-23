#ifndef MATRIX_H
#define MATRIX_H
// matrix.h (header file)
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//template <class T>
//ostream& operator<<(ostream&, const Matrix<T>&);

template<class T> 
class Matrix
{
private:
	T** m; // m é um array 2D a ser implementado como um pointer de pointers
	int nRows;  // numero de linhas
	int nCols;  //  numero de colunas

public:

	// Construtores
	Matrix();
	Matrix(int rows, int cols,const T& value=0);
	Matrix(std::ifstream &myFile);
	Matrix(const Matrix &that);
	//
	// destrutor
	~Matrix();

	// basic getters
	int getRows() const;
	int getCols() const;
	T get(int ls, int cs) const;
	//Funções
	void transpose();
	void print() const;
	void unit();
	void zeros();
	void ones();
	//Sobrecarga de operando
	Matrix operator + (const Matrix &Right);
	Matrix operator - (const Matrix &Right);
	Matrix& operator =(const Matrix &Right);
	bool operator == (const Matrix &Right);
	bool operator != (const Matrix &Right);
	T& operator() (const int &ls, const int &cs) const;
	Matrix operator * (const Matrix &Right);
	Matrix operator ~();
	Matrix& operator -= (const Matrix &Right);
	Matrix& operator += (const Matrix &Right);
	Matrix& operator *= (const double n);
	Matrix& operator *= (const Matrix &Right);
	/* OPERACOES  << >>  */
	/* OPERACOES  << >>  */

	friend std::istream& operator >> (std::istream& text, Matrix& Right);
	friend std::ostream& operator << (std::ostream& text, const Matrix& Right);


};

#endif //MATRIX_H

