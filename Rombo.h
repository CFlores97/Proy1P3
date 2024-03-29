#pragma once
#include "Figura.h"
class Rombo : public Figura
{
	int a, d, D;
public:
	Rombo(int, int, int);
	~Rombo();

	//polimorfos
	virtual double area() override;
	virtual double perimetro() override;
	virtual void dibujar() override;

	//getters
	int getA();
	int getD();
	int getDMayus();

	//setters
	void setA(int);
	void setD(int);
	void setDMayus(int);
	

};

