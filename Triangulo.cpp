#include "Triangulo.h"

Triangulo::Triangulo(int a, int b, int c, int h) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->h = h;
}

Triangulo::~Triangulo()
{
	
}

double Triangulo::area() {
	return (b * h) / 2;
}

double Triangulo::perimetro() {
	return a + b + c;
}

void Triangulo::dibujar()
{

	
	string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/triangulo.txt";
	//string fullPath = "\"C:/Users/HP/Documents/Documentos Unitec/Programacion 3/Programas Progra 3/Proy1P3/triangulo.txt\"";

	ifstream file(fullPath);

	if (!file) {
		cerr << "no se pudo abrir el archivo " << fullPath << endl;
	}

	string line;

	//string line;

	stringstream buffer;
	buffer << file.rdbuf();
	line = buffer.str();
	file.close();


	size_t pos = line.find("[{a}]");

	while (pos != string::npos) {
		line.replace(pos, 5, to_string(a) + "  ");
		pos = line.find("[{a}]", pos + to_string(a).length());
	}

	size_t pos1 = line.find("[{b}]");

	while (pos1 != string::npos) {
		line.replace(pos1, 5, to_string(b) + "  ");
		pos1 = line.find("[{b}]", pos1 + to_string(b).length());
	}

	size_t pos2 = line.find("[{c}]");

	while (pos2 != string::npos) {
		line.replace(pos2, 5, to_string(c) + "        ");
		pos2 = line.find("[{c}]", pos2 + to_string(c).length());
	}

	size_t pos3 = line.find("[{h}]");

	while (pos3 != string::npos) {
		line.replace(pos3, 5, to_string(h) + "      ");
		pos3 = line.find("[{h}]", pos3 + to_string(h).length());
	}

	size_t pos4 = line.find("{a}");

	while (pos4 != string::npos) {
		line.replace(pos4, 3, to_string(a) + "  ");
		pos4 = line.find("{a}", pos4 + to_string(a).length());
	}

	size_t pos5 = line.find("{b}");

	while (pos5 != string::npos) {
		line.replace(pos5, 3, to_string(b) + "  ");
		pos5 = line.find("{b}", pos5 + to_string(b).length());
	}

	size_t pos6 = line.find("{c}");

	while (pos6 != string::npos) {
		line.replace(pos6, 3, to_string(c) + "  ");
		pos6 = line.find("{c}", pos6 + to_string(c).length());
	}

	size_t pos7 = line.find("{h}");

	while (pos7 != string::npos) {
		line.replace(pos7, 3, to_string(h) + "  ");
		pos7 = line.find("{h}", pos7 + to_string(h).length());
	}

	size_t pos8 = line.find("[{a + b + c}]");
	while (pos8 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos8, 13, to_string((int)perimetro()) + "	      "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos8 = line.find("[{a + b + c}]", pos8 + to_string((int)perimetro()).length());
	}

	size_t pos9 = line.find("[{b * h}]");
	while (pos9 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos9, 9, to_string(b*h) + "	  "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos9 = line.find("[{b * h}]", pos9 + to_string(b*h).length());
	}

	size_t pos10 = line.find("[{(b * h)/2}]");
	while (pos10 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos10, 13, to_string((int)area()) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos10 = line.find("[{(b * h)/2}]", pos10 + to_string((int)area()).length());
	}


	cout << line << endl;
}

int Triangulo::getA() {
	return a;
}

int Triangulo::getB() {
	return b;
}

int Triangulo::getC() {
	return c;
}

int Triangulo::getH() {
	return h;
}

void Triangulo::setA(int a) {
	this->a = a;
}

void Triangulo::setB(int b) {
	this->b = b;
}

void Triangulo::setC(int c) {
	this->c = c;
}

void Triangulo::setH(int h) {
	this->h = h;
}
