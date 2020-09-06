#include <iostream>
#include "ponto2D.h"
#include <math.h>

using namespace std;
//Constructor Default
Ponto::Ponto(double x, double y)
{
	cout << "construtor padrao";
	_x = x;
	_y = y;
	_id++;
}
//Construtor de copia
Ponto::Ponto(const Ponto &Point) 
{
	cout << "Construtor de copia";
	this->_x = Point.getX();
	this->_y = Point.getY();
	_id++;
}
//Destructor
Ponto::~Ponto() {
	cout << ">>Destrutor chamado..Destruindo ponto..<<" << _id << endl;
	_id--;
}

int Ponto::_id = 0; // atribuidor do valor para o static contador do numero de pontos criado

//Basic getters
int  Ponto::getNextId ()const
{
	return _id;
}
double inline Ponto::getX () const
{
	return _x;
}
double inline Ponto::getY () const
{
	return _y;
}

//Other methods
void Ponto::print () const// Imprimir coordenadas X e Y
{
	cout << "Ponto X:: " << _x << " Ponto Y:: " << _y << endl;
}

double Ponto::distToOrig()// Distancia do ponto chamada a origem  0 0 
{
	return (sqrt(pow(_x, 2) + pow(_y, 2)));
}
double Ponto::distTo(const Ponto &p2) //Distancia do ponto chamado ao ponto de referencia
{
	return (sqrt(pow((_x -p2._x), 2) + pow((_y - p2._y), 2)));
}
void Ponto::sumOf(const Ponto &p2) // soma ao ponto chamado o valor do ponto p2
{
	_x += p2._x;
	_y += p2._y;
}
Ponto Ponto::sumOf_(const Ponto &p2) //Retorna um objeto com a soma dos pontos chamado e do ponto p2
{
	Ponto soma;
	soma._x = _x + p2._x;
	soma._y = _y + p2._y;
	return soma;
}