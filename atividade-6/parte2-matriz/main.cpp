// Programa cliente para testar a classe Matrix

#include <cstdlib> // system()
#include <iostream>
using namespace std;

#include "matrix.h"

void clearscreen() {
if (system( "clear" )) system( "cls" );
}

int main(){
    
    cout << "\n ---------------Testando construtores -------------- \n" << endl;
    Matrix<double> m1;
    cout << "Matrix<int> m1" << endl;
    cout << "-> Matriz de dimensao " << m1.rows() << " x " << m1.cols() << endl;
    cout << "m1 = " << m1 << endl;

    Matrix<float> m2(5, 5, 7.5);
    cout << "Matrix<float> m2(5, 5, 7.5)" << endl;
    cout << "-> Matriz de dimensao " << m2.rows() << " x " << m2.cols() << endl;
    cout << "m2 = " << m2 << endl;

    cout << "\nPressione qualquer tecla para continuar...";
    getchar();
    clearscreen();
    
    Matrix<float> m3(m2);
    cout << "Matrix<float> m3(m2)" << endl;
    cout << "-> Matriz de dimensao " << m3.rows() << " x " << m3.cols() << endl;
    cout << "m3 = " << m3 << endl;

    
    Matrix<double> m4(2, 3, 6);
    cout << "Matrix<double> m4(2, 3)" << endl;
    cout << "-> Matriz de dimensao " << m4.rows() << " x " << m4.cols() << endl;
    cout << "m4 = " << m4 << endl;
    
    cout << "\nPressione qualquer tecla para continuar...";
    getchar();
    clearscreen();
    
    cout << "\n ---------------Testando Inicializacoes -------------- \n" << endl;
    
    Matrix<float> m6(3, 4, 2.3);
    cout << "Matrix<float> m6(3, 4, 2.3)" << endl;
    cout << "-> Matriz de dimensao " << m6.rows() << " x " << m6.cols() << endl;
    cout << "m6 = " << m6;
    m6.zeros();
    cout << "m6.zeros() :: Matriz Zeros" << endl;
    cout << "m6 = " << m6 << endl;
   
    cout << "\nPressione qualquer tecla para continuar...";
    getchar();
    clearscreen();
    
    cout << "\n --------------- Testando Sobrecarga de Operadores-------------------------- \n" << endl;

    m6(1, 1) = 7; m6(1, 3) = -3; m6(2, 1) = 3.6; m6(2, 2) = -2; m6(3, 1) = 4;
    cout << "-> Sobrecarga do Operador ( )" << endl;
    cout << "m6(1, 1) = 7; m6(1, 3) = -3; m6(2, 1) = 3.6; m6(2, 2) = -2; m6(3, 1) = 4;" << endl;
    cout << "m6 = " << m6 << endl;
    
}