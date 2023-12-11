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
	
	string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/cuadrado.txt";
	//string fullPath = "\"C:/Users/HP/Documents/Documentos Unitec/Programacion 3/Programas Progra 3/Proy1P3/cuadrado.txt\"";

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


	size_t pos3 = line.find("[{4 * a}]");
	while (pos3 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos3, 9, to_string((int)perimetro()) + "	   "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos3 = line.find("[{4 * a}]", pos3 + to_string((int)perimetro()).length());
	}

	size_t pos4 = line.find("[{a*a}]");
	while (pos4 != string::npos) { //npos significa que no encontro el caracter, por eso es "!= npos"
		line.replace(pos4, 7, to_string((int)area()) + "	 "); //el "14" es el length de lo que vas a reemplazar ej: "[{2 * pi * r}]"
		pos4 = line.find("[{a*a}]", pos4 + to_string((int)area()).length());
	}


	cout << line << endl;

}

int Cuadrado::getA() {
	return a;
}

void Cuadrado::setA(int a) {
	this->a = a;
}
