#pragma once
#ifndef BOX_H
#define BOX_H

#include <iostream>
#include "ponto3d.h"
#include <vector>

using namespace std;

class Box { //Paralelepipedo RETANGULAR
private:
	double altura, largura, profundidade;
public:
	
	Box (double x = 0.0, double y = 0.0, double z = 0.0);
	Box(const Ponto3D &a, const Ponto3D &b, const Ponto3D &c, const Ponto3D &d, const Ponto3D &e, const Ponto3D &f, const Ponto3D &g, const Ponto3D &h);
	~Box() {};
	Box& operator=(const Box &Right);
	double area();
	double volume();
};

Box::Box(double x, double y, double z) {
	largura = x;
	profundidade = y;
	altura = z;
}

Box::Box(const Ponto3D &a, const Ponto3D &b, const Ponto3D &c, const Ponto3D &d, const Ponto3D &e, const Ponto3D &f, const Ponto3D &g, const Ponto3D &h) {
	//considerando o paralelepipedo retangular sendo ortogonal ao plano xy
	//os pontos de "a" à "h" possuirão coordenadas repetidas em diferentes pontos, encontrar a diferença entre esses pontos
	// é o que determinará as distancias de altura, largura e profundidade
	//Como a ordem dos pontos no plano 3D nao é predeterminada será necessario avaliar 
	//um ponto em relação a outros 4 pontos fornecidos em busca da distancia correta.
	//Vou colocar os pontos de "a" à "h" num vetor para facilitar a busca e analise de dados
	
	// OBS:: Com 3 pontos distintos no espaço tridimensional ja é possivel determinar uma figura
	// para esse tipo de analise de figura no espaço, para avaliar mais possibilidades de erro seria
	//necessario criar mais funçoes de analise de pontos validos, que nao vem ao caso


	//Passando os pontos para o vetor
	vector < Ponto3D> Pontos;
	Pontos.push_back(a); //ponto 1
	Pontos.push_back(b); //ponto 2
	Pontos.push_back(c); //ponto 3
	Pontos.push_back(d); //ponto 4
	Pontos.push_back(e); //ponto 5
	Pontos.push_back(f); //ponto 6
	Pontos.push_back(g); //ponto 7
	Pontos.push_back(h); //ponto 8
	//Agora é possivel usar um laço de repeticao para avaliar todos os pontos

	int Interacao = 0; // Variavel criada para avaliar as diferentes possibilidades
	// da distancia durante os laços de repetição abaixo, se ocorrer mais de um valor para
	//a distancia seja ela altura, largura ou profundidade é um sinal que existe um erro
	// e que os pontos fornecidos nao pertencem a um paralelepipedo retangular
	
	// Comparando as coordendas X , largura
	largura = 0;
	for (int i = 0; i < Pontos.size()-1; i++)
	{
		if (abs((Pontos[i].get_x() - Pontos[i + 1].get_x())) > largura) 
		{
			largura = abs((Pontos[i].get_x() - Pontos[i + 1].get_x()));
			Interacao++;
		}
	}
	if (Interacao > 1 || largura == 0)
	{
		throw "::PONTOS INVALIDOS::";
	}
	// Comparando as coordendas Y , Profundidade
	profundidade = 0;
	Interacao = 0; 
	for (int i = 0; i < Pontos.size() - 1; i++)
	{
		if (abs((Pontos[i].get_y() - Pontos[i + 1].get_y())) > profundidade)
		{
			profundidade = abs((Pontos[i].get_y() - Pontos[i + 1].get_y()));
			Interacao++;
		}	
	}
	if (Interacao > 1 || profundidade == 0)
	{
		throw "::PONTOS INVALIDOS::";
	}
	// Comparando as coordenadas Z, altura
	altura = 0;
	Interacao = 0;
	for (int i = 0; i < Pontos.size() - 1; i++)
	{
		if (abs((Pontos[i].get_z() - Pontos[i + 1].get_z())) > altura) 
		{
			altura = abs((Pontos[i].get_z() - Pontos[i + 1].get_z()));
			Interacao++;
		}
	}
	if (Interacao > 1 || altura == 0)
	{
		throw "::PONTOS INVALIDOS::";
	}
}

Box& Box::operator=(const Box &Right)
{
	this->altura = Right.altura;
	this->largura = Right.largura;
	this->profundidade = Right.profundidade;
	return *this;
}

double Box::area() {
	return largura * profundidade;
}

double Box::volume() {
	return this->area()*altura;
}
#endif