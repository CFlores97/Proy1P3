#pragma once
#include "Figura.h"
class Cometa : public Figura
{
	int a, b, d, D;
public:
	Cometa(int, int, int, int);
	~Cometa();

	//polimorfos
	virtual double area() override;
	virtual double perimetro() override;
	virtual void dibujar() override;

	//getters
	int getA();
	int getB();
	int getD();
	int getDMayus();

	//setters
	void setA(int);
	void setB(int);
	void setD(int);
	void setDMayus(int);
};

