# semana-2-progra-2
Programación II- semana 2

//main 
#include "pch.h"
#include"menu.h"
#include<iostream>
#include<conio.h>

using namespace System;
using namespace std;

void Menupantalla() {


	cout <<endl<< "\tMenu" << endl;
	cout << "1. Agregar platos" << endl;
	cout << "2. Mostrar platos" << endl;
	cout << "3. Modifico platos" << endl;
	cout << "4. Elimina platos" << endl;
	cout << "5. Reporte de platos picantes" << endl;
}
void agregar(menu *arreglodeplatos, plato *p1) {

	string nombre;
	short estado;
	char tipo;
	float calorias;
	float precio;

	cout << "nombre: ";
	cin.ignore();
	getline(cin, nombre);

	cout << "estado: ";
	cin >> estado;

	cout << "calorias: ";
	cin >> calorias;

	cout << "tipo: ";
	cin >> tipo;

	cout << "precio: ";
	cin >> precio;

	//se inicializa para un plato
	p1 = new plato(nombre, estado, tipo, calorias, precio);

	arreglodeplatos->agregarplatos(p1);

}
void mostrar(menu* arreglodeplatos, plato* p1) {

	if (arreglodeplatos->getN() > 0) {

		cout << "nombre  \t estado \t  tipo  \t calorias \t precio \n ";

		for (int i = 0; i < arreglodeplatos->getN(); i++) {

			p1 = arreglodeplatos->getplato(i);

			cout << p1->getnombre() << "\t\t";
			cout << p1->getestado() << "\t\t\t";
			cout << p1->gettipo() << "\t\t\t\t";
			cout << p1->getcalorias() << "\t\t\t";
			cout << p1->getprecio() << "\t\t\t\t";
			cout << endl;

		}

	}
}
void modificar(menu* arreglodeplatos, plato* p1) {

	string nombre;
	short estado;
	char tipo;
	float calorias;
	float precio;

	int pos;

	cout << "Modificar" << endl;

	mostrar(arreglodeplatos, p1);
	
	cout << "Indique la posición a modificar"; cin >> pos;


	p1 = arreglodeplatos->getplato(pos);

	cout << p1->getnombre() << "\t";
	cout << p1->getestado() << "\t";
	cout << p1->gettipo() << "\t";
	cout << p1->getcalorias() << "\t";
	cout << p1->getprecio() << "\t";
	cout << endl;

	cout << "Ingrese los datos a modificar: "<<endl;

	cout << "nombre: ";
	cin.ignore();
	getline(cin, nombre);

	cout << "estado: ";
	cin >> estado;

	cout << "calorias: ";
	cin >> calorias;

	cout << "tipo: ";
	cin >> tipo;

	cout << "precio: ";
	cin >> precio;

	p1->setnombre(nombre);
	p1->setestado(estado);
	p1->setcalorias(calorias);
	p1->settipo(tipo);
	p1->setprecio(precio);



}
void eliminar(menu* arreglodeplatos, plato* p1) {

	int pos;

	cout << " eliminar: " << endl;
	mostrar(arreglodeplatos,p1);
	cout << "indique la posicion a eliminar: ";
	cin >> pos;

	p1 = arreglodeplatos->getplato(pos);	

	arreglodeplatos->eliminarplato(pos);
	delete p1;

}

void reportepicantes(menu* arreglodeplatos, plato* p1) {

	if (arreglodeplatos->getN() > 0) {

		cout << "nombre  \t estado \t  tipo  \t calorias \t precio \n ";

		for (int i = 0; i < arreglodeplatos->getN(); i++) {

			p1 = arreglodeplatos->getplato(i);

			if (p1->gettipo() == 'p') {

				cout << p1->getnombre() << "\t";
				cout << p1->getestado() << "\t";
				cout << p1->gettipo() << "\t";
				cout << p1->getcalorias() << "\t";
				cout << p1->getprecio() << "\t";


			}

		}
	}
}
int main()
{

	menu* arreglodeplatos = new menu();

	plato *p1;

	int opcion;

	while (1) {

		Menupantalla();
		cin >> opcion;

		switch (opcion) {
		case 1:

		agregar(arreglodeplatos, p1);

		break;

		case 2:

		mostrar(arreglodeplatos,p1);

		break;
		case 3:

		modificar(arreglodeplatos, p1);

		break;
		case 4:

		eliminar(arreglodeplatos, p1);

		break;
		case 5:

		reportepicantes(arreglodeplatos, p1);
		break;
		default:

		break;
		}

	}

	return 0;
}

cabecera menu
#include"plato.h"

class menu {

private:
	//crear un arreglo de objetos

	plato** arreglodeplatos;

	int* N;

public:

	menu();
	~menu();

	void agregarplatos(plato *objetoplato);
	void modificarplato(plato *objetoplato, int pos);

	plato* getplato(int pos);
	void eliminarplato( int pos);
	int getN();
};

menu::menu() {

	arreglodeplatos = NULL;//no apunta a ningún sitio
	N = new int;
	*N = 0;
}

menu::~menu() {

	delete[]arreglodeplatos;//así se destruye un arreglo
	delete N;

}

void menu::agregarplatos(plato *objetoplato) {

	plato** Aux = new plato*[*N + 1];

	for (int i = 0; i < *N; i++) {

		Aux[i] = arreglodeplatos[i];

	}

	Aux[*N] = objetoplato;
	*N = *N + 1;


	if (arreglodeplatos != NULL)

		delete arreglodeplatos;
	arreglodeplatos = Aux;
}
void menu::modificarplato(plato *objetoplato, int pos) {

	arreglodeplatos[pos] = objetoplato;


}

plato* menu::getplato(int pos) {
	//
	return this->arreglodeplatos[pos];
}
void menu::eliminarplato( int pos) {

	for (int i = 0; i < *N; i++) {

		if (pos == i) {
			for (int j = i; j < *N; j++) {

				arreglodeplatos[j] = arreglodeplatos[j + 1];
			}
			*N = *N - 1;


		}


	}

}
int menu::getN() {

	return *N;
}

cabecera plato.h

#include<iostream>
#include<string>
#include<string.h>

using namespace System;
using namespace std;

class plato {

private:

	string nombre;
	short estado;
	char tipo;
	float calorias;
	float precio;

public:

	plato(string nombre, short estado, char tipo, float calorias, float precio);
	~plato();

	void setnombre(string nom);
	string getnombre();

	void setestado(short est);
	short getestado();

	void settipo(char tip);
	char gettipo();

	void setcalorias(float cal);
	float getcalorias();

	void setprecio(float pre);
	float getprecio();

};


plato::plato(string nombre = " ", short estado = 0, char tipo = ' ', float calorias = 0, float precio = 0) {


	this->nombre = nombre;
	this->estado = estado;
	this->tipo = tipo;
	this->calorias = calorias;
	this->precio = precio;

}
plato::~plato() {



}

void plato::setnombre(string nom) {

	this->nombre = nom;

}
string plato::getnombre() {

	return this->nombre;

}

void plato::setestado(short est) {

	this->estado = est;

}
short plato::getestado() {

	return this->estado;

}


void plato::settipo(char tip) {

	this->tipo = tip;

}
char plato::gettipo() {

	return this->tipo;

}

void plato::setcalorias(float cal) {

	this->calorias = cal;
}
float plato::getcalorias() {

	return this->calorias;

}

void plato::setprecio(float pre) {

	this->precio;
}

float plato::getprecio() {

	return this->precio;

}
