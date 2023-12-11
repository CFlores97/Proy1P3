#include "Trapecio.h"

Trapecio::Trapecio(int a, int b, int c, int h, int B) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->h = h;
	this->B = B;
}

Trapecio::~Trapecio()
{
	
}

double Trapecio::area() {
	return ((B + b) * h) / 2;
}

double Trapecio::perimetro() {
	return B + b + a + c;
}

void Trapecio::dibujar()
{
	
	string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/trapecio.txt";
	//string fullPath = "\"C:/Users/HP/Documents/Documentos Unitec/Programacion 3/Programas Progra 3/Proy1P3/trapecio.txt\"";

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

	size_t pos5 = line.find("[{c}]");

	while (pos5 != string::npos) {
		line.replace(pos5, 5, to_string(c) + "    ");
		pos5 = line.find("[{c}]", pos5 + to_string(c).length());
	}

	size_t pos6 = line.find("{c}");

	while (pos6 != string::npos) {
		line.replace(pos6, 3, to_string(c) + "  ");
		pos6 = line.find("{c}", pos6 + to_string(c).length());
	}

	size_t pos7 = line.find("[{h}]");

	while (pos7 != string::npos) {
		line.replace(pos7, 5, to_string(h) + "    ");
		pos7 = line.find("[{h}]", pos7 + to_string(h).length());
	}

	size_t pos8 = line.find("{h}");

	while (pos8 != string::npos) {
		line.replace(pos8, 3, to_string(h) + "  ");
		pos8 = line.find("{h}", pos8 + to_string(h).length());
	}

	size_t pos9 = line.find("[{B}]");

	while (pos9 != string::npos) {
		line.replace(pos9, 5, to_string(B) + "    ");
		pos9 = line.find("[{B}]", pos9 + to_string(B).length());
	}

	size_t pos10 = line.find("{B}");

	while (pos10 != string::npos) {
		line.replace(pos10, 3, to_string(B) + "  ");
		pos10 = line.find("{B}", pos10 + to_string(B).length());
	}

	size_t pos11 = line.find("[{B + b + a + c}]");
	while (pos11 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos11, 17, to_string((int)perimetro()) + "               "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos11 = line.find("[{B + b + a + c}]", pos11 + to_string((int)perimetro()).length());
	}

	size_t pos12 = line.find("[{B + b}]");
	while (pos12 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos12, 9, to_string(B+b) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos12 = line.find("[{B + b}]", pos12 + to_string(B+b).length());
	}

	size_t pos13 = line.find("[{((B+b)*h)/2}]");
	while (pos13 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos13, 15, to_string((int)area()) + "	           "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos13 = line.find("[{((B+b)*h)/2}]", pos13 + to_string((int)area()).length());
	}

	cout << line << endl;
}

int Trapecio::getA() {
	return a;
}

int Trapecio::getB() {
	return b;
}

int Trapecio::getC() {
	return c;
}

int Trapecio::getH() {
	return h;
}

int Trapecio::getBMayus() {
	return B;
}

void Trapecio::setA(int a) {
	this->a = a;
}

void Trapecio::setB(int b) {
	this->b = b;
}

void Trapecio::setC(int c) {
	this->c = c;
}

void Trapecio::setH(int h) {
	this->h = h;
}

void Trapecio::setBMayus(int B) {
	this->B = B;
}
