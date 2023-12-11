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
	//string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/paralelogramo.txt";
	string fullPath = "\"C:/Users/HP/Documents/Documentos Unitec/Programacion 3/Programas Progra 3/Proy1P3/paralelogramo.txt\"";

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

	size_t pos1 = line.find("[{b}]");

	while (pos1 != string::npos) {
		line.replace(pos1, 5, to_string(b) + "    ");
		pos1 = line.find("[{b}]", pos1 + to_string(b).length());
	}

	size_t pos2 = line.find("[{h}]");

	while (pos2 != string::npos) {
		line.replace(pos2, 5, to_string(h) + "    ");
		pos2 = line.find("[{h}]", pos2 + to_string(h).length());
	}

	size_t pos3 = line.find("{a}");

	while (pos3 != string::npos) {
		line.replace(pos3, 3, to_string(a) + "  ");
		pos3 = line.find("{a}", pos3 + to_string(a).length());
	}

	size_t pos4 = line.find("{b}");

	while (pos4 != string::npos) {
		line.replace(pos4, 3, to_string(b) + "  ");
		pos4 = line.find("{b}", pos4 + to_string(b).length());
	}

	size_t pos5 = line.find("{h}");

	while (pos5 != string::npos) {
		line.replace(pos5, 3, to_string(h) + "  ");
		pos5 = line.find("{h}", pos5 + to_string(h).length());
	}

	size_t pos6 = line.find("[{a+b}]");
	while (pos6 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos6, 7, to_string(a+b) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos6 = line.find("[{a+b}]", pos6 + to_string((a+b)).length());
	}

	size_t pos7 = line.find("[{2*a+b}]");
	while (pos7 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos7, 9, to_string((int)perimetro()) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos7 = line.find("[{2*a+b}]", pos7 + to_string((int)perimetro()).length());
	}

	size_t pos8 = line.find("[{b*h}]");
	while (pos8 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos8, 7, to_string((int)area()) + "	    "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos8 = line.find("[{b*h}]", pos8 + to_string((int)area()).length());
	}


	cout << line << endl;
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
