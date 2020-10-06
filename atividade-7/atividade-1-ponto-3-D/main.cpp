#include "ponto2D.hpp"

// a ser implementada

class Ponto3D: public Ponto2D{
    
    public:
        // construtor
        Ponto3D(double xx = 0, double yy = 0, double zz=0) : 
            Ponto2D(xx, yy), z(zz)
        {

        }

        // operator <<
        friend ostream& operator<< (ostream &op, const Ponto3D &p)
        {
            op << endl;
            op << "x = " << p.get_x() << endl;
            op << "y = " << p.get_y() << endl;
            op << "z = " << p.z << endl;
            return op;
        }

        // operator =
        Ponto3D& operator= (const Ponto3D &p)
        {
            //z = p.z;
            //return *this;
        }

        // setter
        void set(double nx  = 0, double ny = 0, double nz = 0)
        {
            Ponto2D::set(nx, ny);
            z = nz;
        }

        // getter
        double get_z()
        {
            return z;
        }
            
    private:
        double z;
};    

// código para teste da classe Ponto3D
    
int main()
{
    Ponto2D p1(3,4), p2;
    p2.set(2,1.5);
    cout << p1 << endl;
    cout << p2 << endl;

    p2 = p1;
    cout << p2 << endl;


    Ponto3D p3(2,4.5,5), p4;
    p4.set(1,0.3,12);
    cout << p3 << endl;
    cout << p4 << endl;

   /* p4 = p3;
    cout << p4 << endl;

    p4 = p1;
    cout << p4 << endl;*/

    return 0;
}    
    
    

