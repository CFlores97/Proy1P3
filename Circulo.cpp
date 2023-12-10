#include "Circulo.h"

#include <cmath>
#include <iomanip>


Circulo::Circulo(int r) {
	this->r = r;
}

Circulo::~Circulo() {
	delete this;
}

double Circulo::area() {
	return 3.1416 * (r * r);
}

double Circulo::perimetro() {
	return 2 * 3.1416 * r;
}

void Circulo::dibujar() {

	string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/circulo.txt";

	ifstream file(fullPath);

	if (!file) {
		cerr << "no se pudo abrir el archivo " << fullPath << endl;
	}

	string line;

	while (getline(file, line)) {
		cout << line << endl;
	}

	file.close();
}


int Circulo::getR() {
	return r;
}

void Circulo::setR(int r) {
	this->r = r;
}
