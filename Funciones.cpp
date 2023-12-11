#include "Funciones.h"
#include <windows.h>

void Funciones::readTxt(string fileName)
{
	
	string fullPath = "C:/Users/carlo/Desktop/Proyecto1P3/Proyecto1P3_CarlosFlores_DanielElvir/" + fileName + ".txt";
	//string fullPath = "C:\\Users\\HP\\Documents\\Documentos Unitec\\Programacion 3\\Programas Progra 3\\Proy1P3\\" + fileName + ".txt";

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

void Funciones::accion(int argc, char* argv[])
{
	Circulo* circ;
	Triangulo* tri;
	Cometa* com;
	Cuadrado* cuad;
	Paralelogramo* par;
	Rectangulo* rec;
	Rombo* rom;
	Trapecio* trap;

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	
	if (argc == 1) {

		cout << "Uso: Proyecto1P3_CarlosFlores_DanielElvir.exe ACCION [VARIABLES]" << endl <<
			"     Calculos de perimetro y area de Figuras Planas." << endl <<
			"     Donde: " << endl << "          ACCION: " <<
			endl << "                  ayuda                    |  Informacion sobre el uso del programa." << endl <<
			endl << "                         triangulo         | VARIABLES: a b c h" <<
			endl << "                         paralelogramo     | VARIABLES: a b h" <<
			endl << "                         rectangulo        | VARIABLES: a b" <<
			endl << "                         cuadrado          | VARIABLES: a" <<
			endl << "                         rombo             | VARIABLES: a d D" <<
			endl << "                         cometa            | VARIABLES: a b d D" <<
			endl << "                         trapecio          | VARIABLES: a b c h B" <<
			endl << "                         circulo           | VARIABLES: r" <<
			endl << endl;
	}

	string firstParam = argv[1];
	if (argc > 1 && firstParam == "triangulo") {
		int a = stoi(argv[2]);
		int b = stoi(argv[3]);
		int c = stoi(argv[4]);
		int h = stoi(argv[5]);

		tri = new Triangulo(a, b, c, h);
		tri->dibujar();
	}
	else if (argc > 1 && firstParam == "paralelogramo") {
		int a = stoi(argv[2]);
		int b = stoi(argv[3]);
		int h = stoi(argv[4]);

		par = new Paralelogramo(a, b, h);
		par->dibujar();
	}
	else if (argc > 1 && firstParam == "rectangulo") {
		int a = stoi(argv[2]);
		int b = stoi(argv[3]);

		rec = new Rectangulo(a, b);

		rec->dibujar();
	}
	else if (argc > 1 && firstParam == "cuadrado") {
		int a = stoi(argv[2]);

		cuad = new Cuadrado(a);

		cuad->dibujar();
	}
	else if (argc > 1 && firstParam == "rombo") {
		int a = stoi(argv[2]);
		int d = stoi(argv[3]);
		int D = stoi(argv[4]);

		rom = new Rombo(a, d, D);

		rom->dibujar();
	}
	else if (argc > 1 && firstParam == "cometa") {
		int a = stoi(argv[2]);
		int b = stoi(argv[3]);
		int d = stoi(argv[4]);
		int D = stoi(argv[5]);

		com = new Cometa(a, b, d, D);
		com->dibujar();
	}
	else if (argc > 1 && firstParam == "trapecio") {
		int a = stoi(argv[2]);
		int b = stoi(argv[3]);
		int c = stoi(argv[4]);
		int h = stoi(argv[5]);
		int B = stoi(argv[6]);

		trap = new Trapecio(a, b, c, h, B);

		trap->dibujar();
	}
	else if (argc > 1 && firstParam == "circulo") {
		int radius = stoi(argv[2]);
		circ = new Circulo(radius);
		circ->dibujar();
	}

} 
