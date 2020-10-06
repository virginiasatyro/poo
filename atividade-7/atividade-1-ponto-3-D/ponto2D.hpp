#include<iostream>

using namespace std;

class Ponto2D{
    
     public:
        // construtor
        Ponto2D(int xx = 0.0, int yy = 0.0):x(xx),y(yy){ };
        // operator <<
        friend ostream& operator<< (ostream &op, const Ponto2D &p);
        // operator =
        Ponto2D& operator= (const Ponto2D &p);
        // destrutor
        ~Ponto2D(){};
        // getters
        double get_x(void) const { return x; }
        double get_y(void) const { return y; }
        // setter
        void set (double nx, double ny) { x=nx; y=ny; }
    
    private:                
        double x;
        double y;
};

ostream& operator<< (ostream &op, const Ponto2D &p){
            op << endl;
            op << "x = " << p.x << endl;
            op << "y = " << p.y << endl;
            return op;
}

Ponto2D& Ponto2D::operator= (const Ponto2D &p){
    x = p.x;
    y = p.y;
    return *this;
}
