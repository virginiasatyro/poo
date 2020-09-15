#include <iostream>
#include "ponto2D.h"


using namespace std;

int main() {

    Ponto a(1,4), b(3,2), c;
    c = a + b;               // soma as coordenadas dos pontos a e b 
    c.print();
    --c;                    // decrementa em uma unidade as coordenadas de c
    c.print();
}
