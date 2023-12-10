#include "Rombo.h"

Rombo::Rombo(int a, int d, int D) {
	this->a = a;
	this->d = d;
	this->D = D;
}

Rombo::~Rombo()
{
}

double Rombo::area() {
	return (D * d) / 2;
}

double Rombo::perimetro() {
	return 4 * a;
}

void Rombo::dibujar()
{
	string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/rombo.txt";

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

int Rombo::getA() {
	return a;
}

int Rombo::getD() {
	return d;
}

int Rombo::getDMayus() {
	return D;
}

void Rombo::setA(int a) {
	this->a = a;
}

void Rombo::setD(int d) {
	this->d = d;
}

void Rombo::setDMayus(int D) {
	this->D = D;
}
