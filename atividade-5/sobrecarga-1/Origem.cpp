#include<iostream> 

class Ponto2D{
    
    int x,y;
    
    public:
        Ponto(int xx=0, int yy=0):x(xx),y(yy){ };
        Ponto& operator-- ();
        Ponto operator+ (const Ponto& ) const;
        ~Ponto(){}; 
};

int main() {

    Ponto a(1,4), b(3,2), c;
    c = a + b;               // soma as coordenadas dos pontos a e b 
    --c;                    // decrementa em uma unidade as coordenadas de c
}