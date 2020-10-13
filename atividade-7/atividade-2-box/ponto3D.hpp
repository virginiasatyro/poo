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
        Ponto3D& operator= (const Ponto2D &p)
        {
            Ponto2D::set(p.get_x(), p.get_y());
            return *this;
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