// main.cpp
#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    ifstream in("myFile.txt");
    Matrix Y;
    Matrix X(3,1), A(3,3), C(3,3);
    Matrix Z(3,2,7.0);
    Matrix W(in);
    
    // operadores a serem implementados em sua classe:
    
    A(2, 1) = 10;        // altera o valor de uma posição de A - OK
    C = A + A;          // Soma - OK
    C -= A;             // Subtração - OK   
    A = C - A;          // Subtração - OK
    A += A;             // Soma -OK
    A = ~C;             // A é igual a transposta de C - OK
    X *= 2;             // multiplicação por uma constante - OK
    //C = A*X;            // multiplicação de matrizes
    C *= X;             // multiplicação de matrizes - OK
    if (A == C)         // verifica a igualdade entre A e C - OK  
    if(X != Y)          // verifica a desigualdade entre A e C - OK
    cout << Z << endl;  // impressão de matrizes - OK
    cin >> W;           // leitura de dados para dentro da matriz Y - OK
    W.print();

    return 0;
}

