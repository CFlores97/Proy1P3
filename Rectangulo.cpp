#include "Rectangulo.h"

Rectangulo::Rectangulo(int a, int b) {
	this->a = a;
	this->b = b;
}

Rectangulo::~Rectangulo()
{
}

double Rectangulo::area() {
	return b * a;
}

double Rectangulo::perimetro() {
	return 2 * (b + a);
}

void Rectangulo::dibujar()
{
	setlocale(LC_ALL, "Spanish");
	string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/rectangulo.txt";

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

int Rectangulo::getA() {
	return a;
}

int Rectangulo::getB() {
	return b;
}

void Rectangulo::setA(int a) {
	this->a = a;
}

void Rectangulo::setB(int b) {
	this->b = b;
}
