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
	//string fullPath = "\"C:/Users/HP/Documents/Documentos Unitec/Programacion 3/Programas Progra 3/Proy1P3/rombo.txt\"";

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

	size_t pos3 = line.find("[{d}]");

	while (pos3 != string::npos) {
		line.replace(pos3, 5, to_string(d) + "    ");
		pos3 = line.find("[{d}]", pos3 + to_string(d).length());
	}

	size_t pos4 = line.find("{d}");

	while (pos4 != string::npos) {
		line.replace(pos4, 3, to_string(d) + "  ");
		pos4 = line.find("{d}", pos4 + to_string(d).length());
	}

	size_t pos5 = line.find("[{D}]");

	while (pos5 != string::npos) {
		line.replace(pos5, 5, to_string(D) + "    ");
		pos5 = line.find("[{D}]", pos5 + to_string(D).length());
	}

	size_t pos6 = line.find("{D}");

	while (pos6 != string::npos) {
		line.replace(pos6, 3, to_string(D) + "  ");
		pos6 = line.find("{D}", pos6 + to_string(D).length());
	}

	size_t pos7 = line.find("[{4 * a}]");
	while (pos7 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos7, 9, to_string((int)perimetro()) + "	   "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos7 = line.find("[{4 * a}]", pos7 + to_string((int)perimetro()).length());
	}

	size_t pos8 = line.find("[{D * d}]");
	while (pos8 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos8, 9, to_string(D*d) + "	  "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos8 = line.find("[{D * d}]", pos8 + to_string(D*d).length());
	}

	size_t pos9 = line.find("[{(D * d)/2}]");
	while (pos9 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos9, 13, to_string((int)area()) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos9 = line.find("[{(D * d)/2}]", pos9 + to_string((int)area()).length());
	}

	cout << line << endl;
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
