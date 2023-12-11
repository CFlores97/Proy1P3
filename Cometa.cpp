#include "Cometa.h"

Cometa::Cometa(int a, int b, int d, int D) {
	this->a = a;
	this->b = b;
	this->d = d;
	this->D = D;
}

Cometa::~Cometa()
{
}

double Cometa::area() {
	return (D * d) / 2;
}

double Cometa::perimetro() {
	return 2 * (b + a);
}

void Cometa::dibujar()
{
	setlocale(LC_ALL, "Spanish");
	//string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/cometa.txt";
	string fullPath = "\"C:/Users/HP/Documents/Documentos Unitec/Programacion 3/Programas Progra 3/Proy1P3/cometa.txt\"";

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
		pos4 = line.find("{b}", pos4 + to_string(b).length());
	}

	size_t pos5 = line.find("[{d}]");

	while (pos5 != string::npos) {
		line.replace(pos5, 5, to_string(d) + "    ");
		pos5 = line.find("[{d}]", pos5 + to_string(d).length());
	}

	size_t pos6 = line.find("{d}");

	while (pos6 != string::npos) {
		line.replace(pos6, 3, to_string(d) + "  ");
		pos6 = line.find("{d}", pos6 + to_string(d).length());
	}

	size_t pos7 = line.find("[{D}]");

	while (pos7 != string::npos) {
		line.replace(pos7, 5, to_string(D) + "    ");
		pos7 = line.find("[{D}]", pos7 + to_string(D).length());
	}

	size_t pos8 = line.find("{D}");

	while (pos8 != string::npos) {
		line.replace(pos8, 3, to_string(D) + "  ");
		pos8 = line.find("{D}", pos8 + to_string(D).length());
	}

	size_t pos9 = line.find("[{a+b}]");
	while (pos9 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos9, 7, to_string(a+b) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos9 = line.find("[{a+b}]", pos9 + to_string(a+b).length());
	}

	size_t pos10 = line.find("[{2*a+b}]");
	while (pos10 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos10, 9, to_string((int)perimetro()) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos10 = line.find("[{2*a+b}]", pos10 + to_string((int)perimetro()).length());
	}

	size_t pos11 = line.find("[{D * d}]");
	while (pos11 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos11, 9, to_string(D * d) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos11 = line.find("[{D * d}]", pos11 + to_string(D * d).length());
	}

	size_t pos12 = line.find("[{(D * d)/2}]");
	while (pos12 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos12, 13, to_string((int)area()) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos12 = line.find("[{(D * d)/2}]", pos12 + to_string((int)area()).length());
	}

	cout << line << endl;
}

int Cometa::getA() {
	return a;
}

int Cometa::getB() {
	return b;
}

int Cometa::getD() {
	return d;
}

int Cometa::getDMayus() {
	return D;
}

void Cometa::setA(int a) {
	this->a = a;
}

void Cometa::setB(int b) {
	this->b = b;
}

void Cometa::setD(int d) {
	this->d = d;
}

void Cometa::setDMayus(int D) {
	this->D = D;
}
