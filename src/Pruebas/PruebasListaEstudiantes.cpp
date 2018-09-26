/*
 * PruebasListaEstudiantes.cpp
 *
 *  Created on: 04/04/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */
#include <iostream>
#include "Pruebas.h"
//#include "../ListaEstudiantes.h"
using namespace std;

void pr_ListaEstudiantes(){
	cout<<"	--Inicio pruebas del constructor de ListaEstudiantes"<<endl;
		ListaEstudiantes lest;
		//lo unico que hace es reservar memoria para la lista de punteros a estudiantes;
	cout<<"	--Fin pruebas del constructor de ListaEstudiantes"<<endl;
}

void pr_InsertarPos(){
	cout<<"	--Inicio pruebas del InsertarPos de ListaEstudiantes"<<endl;
		ListaEstudiantes lest1;
		Estudiante *e1=new Estudiante("e1","","","",3);
		Estudiante *e2=new Estudiante("e2","","","",7);
		Estudiante *e3=new Estudiante("e3","","","",5);


		lest1.InsertarPos(e2);
		lest1.InsertarPos(e1);
		cout<<"		Debe mostrarse primero e2:"<<endl;
		lest1.mostrar();

		lest1.InsertarPos(e3);
		cout<<"		Debe mostrarse en el medio e3:"<<endl;
		lest1.mostrar();

	cout<<"	--Fin pruebas del InsertarPos de ListaEstudiantes"<<endl;
}

void pr_SacarPrimero(){
	cout<<"	--Inicio pruebas del SacarPrimero de ListaEstudiantes"<<endl;
	ListaEstudiantes lest1;
	Estudiante *e1=new Estudiante("e1","","","",3);
	Estudiante *e2=new Estudiante("e2","","","",7);
	Estudiante *e3=new Estudiante("e3","","","",5);
	Estudiante *eaux;


	lest1.InsertarPos(e2);
	lest1.InsertarPos(e1);
	lest1.InsertarPos(e3);

	lest1.SacarPrimero(eaux);
	if(eaux!=e2)
		cout<<"		Error para la prueba 1."<<endl;
	delete eaux;

	lest1.SacarPrimero(eaux);
	if(eaux!=e3)
		cout<<"		Error para la prueba 2."<<endl;

	cout<<"	--Fin pruebas del SacarPrimero de ListaEstudiantes"<<endl;
}

void pr_SacarUltimo(){
	cout<<"	--Inicio pruebas del SacarUltimo de ListaEstudiantes"<<endl;
	ListaEstudiantes lest1;
	Estudiante *e1=new Estudiante("e1","","","",3);
	Estudiante *e2=new Estudiante("e2","","","",7);
	Estudiante *e3=new Estudiante("e3","","","",5);
	Estudiante *eaux;


	lest1.InsertarPos(e2);
	lest1.InsertarPos(e1);
	lest1.InsertarPos(e3);

	lest1.SacarUltimo(eaux);
	if(eaux!=e1)
		cout<<"		Error para la prueba 1."<<endl;
	delete eaux;

	lest1.SacarUltimo(eaux);
	if(eaux!=e3)
		cout<<"		Error para la prueba 2."<<endl;

	cout<<"	--Fin pruebas del SacarUltimo de ListaEstudiantes"<<endl;
}

void pr_notaMinima(){
	cout<<"	--Inicio pruebas del notaMinima de ListaEstudiantes"<<endl;
	ListaEstudiantes lest1;
	Estudiante *e1=new Estudiante("e1","","","",3);
	Estudiante *e2=new Estudiante("e2","","","",7);
	Estudiante *e3=new Estudiante("e3","","","",5);
	Estudiante *eaux;

	lest1.InsertarPos(e2);
	lest1.InsertarPos(e1);
	lest1.InsertarPos(e3);

	if ((lest1.notaMinima())!=3)
		cout<<"		Error para la prueba 1."<<endl;

	lest1.SacarUltimo(eaux);
	delete eaux;
	if ((lest1.notaMinima())!=5)
			cout<<"		Error para la prueba 1."<<endl;

	cout<<"	--Fin pruebas del notaMinima de ListaEstudiantes"<<endl;
}

void pr_cuantos(){
	cout<<"	--Inicio pruebas del cuantos de ListaEstudiantes"<<endl;
	ListaEstudiantes lest1;
	Estudiante *e1=new Estudiante("e1","","","",3);
	Estudiante *e2=new Estudiante("e2","","","",7);
	Estudiante *e3=new Estudiante("e3","","","",5);


	lest1.InsertarPos(e2);
	lest1.InsertarPos(e1);

	if(lest1.cuantos()!=2)
		cout<<"		Error para la prueba 1."<<endl;

	lest1.InsertarPos(e3);

	if(lest1.cuantos()!=3)
		cout<<"		Error para la prueba 2."<<endl;

	cout<<"	--Fin pruebas del cuantos de ListaEstudiantes"<<endl;
}

void pr_buscarEstudiante(){
	cout<<"	--Inicio pruebas del buscarEstudiante de ListaEstudiantes"<<endl;
	ListaEstudiantes lest1;
	Estudiante *e1=new Estudiante("e1","","","76a",3);
	Estudiante *e2=new Estudiante("e2","","","66a",7);
	Estudiante *e3=new Estudiante("e3","","","45b",5);
	Estudiante *eaux;
	string dni="66a";
	bool enc;

	lest1.InsertarPos(e2);
	lest1.InsertarPos(e1);
	lest1.InsertarPos(e3);

	enc=lest1.buscarEstudiante(dni, eaux);
	if(!enc || (eaux!=e2))
		cout<<"		Error para la prueba 1."<<endl;

	dni="11c";
	enc=lest1.buscarEstudiante(dni, eaux);
	if(enc)
			cout<<"		Error para la prueba 2."<<endl;

	cout<<"	--Fin pruebas del buscarEstudiante de ListaEstudiantes"<<endl;
}

void pruebas_ListaEstudiantes(){
	cout<<"INICIO PRUEBAS LISTAESTUDIANTES"<<endl;
	pr_ListaEstudiantes();
	cout<<endl;
	pr_InsertarPos();
	cout<<endl;
	pr_SacarUltimo();
	cout<<endl;
	pr_SacarPrimero();
	cout<<endl;
	pr_notaMinima();
	cout<<endl;
	pr_cuantos();
	cout<<endl;
	pr_buscarEstudiante();
	cout<<endl;
	cout<<"FIN PRUEBAS LISTAESTUDIANTES"<<endl;
}

/*
int main(){
	cout<<"INICIO PRUEBAS LISTAESTUDIANTES"<<endl;
	pr_ListaEstudiantes();
	cout<<endl;
	pr_SacarPrimero();
	cout<<endl;
	pr_SacarUltimo();
	cout<<endl;
	pr_InsertarPos();
	cout<<endl;
	pr_notaMinima();
	cout<<endl;
	pr_cuantos();
	cout<<endl;
	pr_buscarEstudiante();
	cout<<endl;
	cout<<"FIN PRUEBAS LISTAESTUDIANTES"<<endl;
	return 0;
}
 */


