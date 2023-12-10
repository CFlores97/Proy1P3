#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;
class Figura
{
public:
	virtual double area();
	virtual double perimetro();
	virtual void dibujar();
};

