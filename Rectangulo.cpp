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
	
	string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/rectangulo.txt";
	//string fullPath = "\"C:/Users/HP/Documents/Documentos Unitec/Programacion 3/Programas Progra 3/Proy1P3/rectangulo.txt\"";

	ifstream file(fullPath);

	if (!file) {
		cerr << "no se pudo abrir el archivo " << fullPath << endl;
	}

	string line;

	stringstream buffer;
	buffer << file.rdbuf();
	line = buffer.str();
	file.close();


	size_t pos = line.find("[{a}]");

	while (pos != string::npos) {
		line.replace(pos, 5, to_string(a) + "    ");
		pos = line.find("[{a}]", pos + to_string(a).length());
	}

	size_t pos2 = line.find("{a}");

	while (pos2 != string::npos) {
		line.replace(pos2, 3, to_string(a) + "  ");
		pos2 = line.find("{a}", pos2 + to_string(a).length());
	}

	size_t pos3 = line.find("[{b}]");

	while (pos3 != string::npos) {
		line.replace(pos3, 5, to_string(b) + "    ");
		pos3 = line.find("[{b}]", pos3 + to_string(b).length());
	}

	size_t pos4 = line.find("{b}");

	while (pos4 != string::npos) {
		line.replace(pos4, 3, to_string(b) + "  ");
		pos4 = line.find("{a}", pos4 + to_string(b).length());
	}

	size_t pos5 = line.find("[{a+b}]");
	while (pos5 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos5, 7, to_string(a+b) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos5 = line.find("[{a+b}]", pos5 + to_string(a+b).length());
	}

	size_t pos6 = line.find("[{2*a+b}]");
	while (pos6 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos6, 9, to_string((int)perimetro()) + "	   "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos6 = line.find("[{a*a}]", pos6 + to_string((int)perimetro()).length());
	}

	size_t pos7 = line.find("[{b*a}]");
	while (pos7 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos7, 9, to_string((int)area()) + "	  "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos7 = line.find("[{a*a}]", pos7 + to_string((int)area()).length());
	}

	cout << line << endl;
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
