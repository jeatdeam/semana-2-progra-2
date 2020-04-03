#pragma once


#include"platos.h"

class menu{

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
	void eliminarplato(plato *objetoplato, int pos);
	int getN();
};

menu::menu() {

	arreglodeplatos = NULL;//no apunta a ningún sitio
	N = new int;
	*N = 0;
}

menu::~menu() {

	delete []arreglodeplatos;//así se destruye un arreglo
	delete N;

}

void menu::agregarplatos(plato *objetoplato) {

	plato **Aux = new plato*[*N+1];

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
void menu::eliminarplato(plato *objetoplato, int pos) {

	for (int i = 0; i < *N; i++) {

		if (pos == i) {
			for (int j = i; j < *N; j++) {

				arreglodeplatos[j] = arreglodeplatos[j + 1];
			}
			*N = *N - 1;


		}


	}
	
}
int menu::getN(){

	return *N;
}

