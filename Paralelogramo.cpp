#include "Paralelogramo.h"

Paralelogramo::Paralelogramo(int a, int b, int h) {
	this->a = a;
	this->b = b;
	this->h = h;
}

Paralelogramo::~Paralelogramo()
{
}

double Paralelogramo::area() {
	return b * h;
}

double Paralelogramo::perimetro() {
	return 2 * (a + b);
}

void Paralelogramo::dibujar()
{
	setlocale(LC_ALL, "Spanish");
	string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/paralelogramo.txt";

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

int Paralelogramo::getA() {
	return a;
}

int Paralelogramo::getB() {
	return b;
}

int Paralelogramo::getH() {
	return h;
}

void Paralelogramo::setA(int a) {
	this->a = a;
}

void Paralelogramo::setB(int b) {
	this->b = b;
}

void Paralelogramo::setH(int h) {
	this->h = h;
}
