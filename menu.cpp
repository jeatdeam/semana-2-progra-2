#include "stdafx.h"
#include"menu.h"
#include<iostream>
#include<conio.h>

using namespace System;
using namespace std;

void Menu() {


	cout << endl << "Menu" << endl;
	cout << "1. Agregar platos" << endl;
	cout << "2. Mostrar platos" << endl;
	cout << "3. Modifico platos" << endl;
	cout << "4. Elimina platos" << endl;
}
void agregar(menu *arreglodeplatos, plato *p1) {

	string nombre;
	short estado;
	char tipo;
	float calorias;
	float precio;

	cout << "nombre: "; cin.ignore();
	getline(cin,nombre);
	cout << "estado: "; cin >> estado;
	cout << "calorias: "; cin >> calorias;
	cout << "tipo: "; cin >> tipo;
	cout << "precio: "; cin >> precio;

	p1 = new plato(nombre,estado,tipo,calorias,precio);

	arreglodeplatos->agregarplatos(p1);

}

int main()
{

	menu* arreglodeplatos = new menu();

	plato *p1;

	int opcion;

	while (1) {

		menu();
		cin >> opcion;

		switch (opcion) {
		case 1:

			agregar(arreglodeplatos, p1);

			break;
		}



	}




    return 0;
}
