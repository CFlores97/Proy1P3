#include "Cuadrado.h"

Cuadrado::Cuadrado(int a) {
	this->a = a;
}

Cuadrado::~Cuadrado()
{
}

double Cuadrado::area() {
	return a * a;
}

double Cuadrado::perimetro() {
	return 4 * a;
}

void Cuadrado::dibujar()
{
	setlocale(LC_ALL, "Spanish");
	string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/cuadrado.txt";

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

int Cuadrado::getA() {
	return a;
}

void Cuadrado::setA(int a) {
	this->a = a;
}
