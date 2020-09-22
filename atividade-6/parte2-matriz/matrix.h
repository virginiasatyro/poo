// matrix.h

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

template <class TValor> class Matrix;

template <class TValor> 
ostream& operator<<(ostream&, const Matrix<TValor>&);

template <class TValor>
class Matrix {
    
    private:
        ... 
        
    public:
        //Construtores 
        Matrix();
        Matrix(int linhas, int colunas);
        Matrix(int linhas, int colunas, const TValor& valor);
        Matrix(const Matrix &matriz);
        // Destrutor
        ~Matrix();
        
        TValor& operator()(const int, const int) const; 
        ...

};
