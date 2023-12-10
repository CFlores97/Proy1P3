#pragma once
#include "Figura.h"
#include "Circulo.h"
#include "Cometa.h"
#include "Cuadrado.h"
#include "Paralelogramo.h"
#include "Rectangulo.h"
#include "Rombo.h"
#include "Trapecio.h"
#include "Triangulo.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
class Funciones
{
public:

	static void readTxt(string fileName);
	static void accion(int argc, char*argv[]);
};

