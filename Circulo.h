#pragma once
#include "Figura.h"
class Circulo : public Figura
{
	int r;
public:

	Circulo(int);
	~Circulo();

	//polimorfos
	virtual double area() override;
	virtual double perimetro() override;
	virtual void dibujar() override;

	//getters
	int getR();
	

	//setters
	void setR(int);
	
};

