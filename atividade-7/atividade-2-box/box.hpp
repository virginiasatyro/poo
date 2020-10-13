#include "ponto3D.hpp"

class Box
{
    public:
        // inicializa box a partir das coordenadas dos seus vértices
        Box(Ponto3D, Ponto3D, Ponto3D, Ponto3D, Ponto3D, Ponto3D, Ponto3D, Ponto3D);
        {
            
        }

        // destrutor
        ~Box();

        // -
        double area();
        double volume();

        // setters
        void set_largura(double l)
        {
            _largura = l;
        }

        void set_altura(double a)
        {
            _altura = a;
        }

        void set_profundidade(double p)
        {
            _profundidade = p;
        }

        // getters
        double get_largura()
        {
            return _largura;
        }

        double get_altura()
        {
            return _altura;
        }

        double get_profundidade()
        {
            return _profundidade;
        }

    private:
        double _largura;
        double _altura;
        double _profundidade;

        Ponto3D *p0, *p1, *p2, *p3, *p4, *p5, *p6, *p7;
};