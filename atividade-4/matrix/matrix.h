#ifndef MATRIX_H
#define MATRIX_H
// matrix.h (header file)
#include <iostream>
#include <fstream>
#include <string>


class Matrix {
private:

	double** m; // m é um array 2D a ser implementado como um pointer de pointers
	int nRows;  // numero de linhas
	int nCols;  //  numero de colunas

public:

	// Construtores
	Matrix();
	//NOVO CODIGO
	Matrix(int rows, int cols, const double &value = 0.0);
	Matrix(std::ifstream &myFile);
	Matrix(const Matrix &that);
	//
	// destrutor
	~Matrix();

	// basic getters
	int getRows() const;
	int getCols() const;
	//Nova função
	double get(int ls, int cs) const;
	//

	// other methods
	void transpose();
	void print() const;
	//NOVOS METODOS
	void unit();
	void zeros();
	void ones();

};
#endif //MATRIX_H
