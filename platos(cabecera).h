#pragma once
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


plato::plato(string nombre=" ", short estado=0, char tipo=' ', float calorias=0, float precio=0) {


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
short plato::getestado(){

	return this->estado;

}


void plato::settipo(char tip) {

	this->tipo = tip;

}
char plato::gettipo() {

	return this->tipo;

}

void plato::setcalorias(float cal){

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