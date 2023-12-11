#include "Circulo.h"

#include <cmath>
#include <iomanip>
#include <locale.h>


Circulo::Circulo(int r) {
	this->r = r;
}

Circulo::~Circulo() {
	//delete this;
}

double Circulo::area() {
	return 3.1416 * (r * r);
}

double Circulo::perimetro() {
	return 2 * 3.1416 * r;
}

void Circulo::dibujar() {
	setlocale(LC_CTYPE, "Spanish");

	//string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/circulo.txt";
	string fullPath = "\"C:/Users/HP/Documents/Documentos Unitec/Programacion 3/Programas Progra 3/Proy1P3/circulo.txt\"";

	ifstream file(fullPath);

	if (!file) {
		cerr << "no se pudo abrir el archivo " << fullPath << endl;
	}

	string line;

	stringstream buffer;
	buffer << file.rdbuf();
	line = buffer.str();
	file.close();


	size_t pos = line.find("[{r}]");

	while (pos != string::npos) {
		line.replace(pos, 5, to_string(r) + "    ");
		pos = line.find("[{r}]", pos + to_string(r).length());
	}

	size_t pos2 = line.find("{r}");

	while (pos2 != string::npos) {
		line.replace(pos2, 3, to_string(r) + "  ");
		pos2 = line.find("{r}", pos2 + to_string(r).length());
	}


	size_t pos3 = line.find("[{2 * pi * r}]");
	while (pos3 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos3, 14, to_string((int)perimetro()) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos3 = line.find("[{2 * pi * r}]", pos3 + to_string((int)perimetro()).length());
	}

	size_t pos4 = line.find("[{pi * (r * r)}]");
	while (pos4 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos4, 16, to_string((int)area()) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos4 = line.find("[{pi * (r * r)}]", pos4 + to_string((int)area()).length());
	}

	cout << line << endl;
	
}


int Circulo::getR() {
	return r;
}

void Circulo::setR(int r) {
	this->r = r;
}
