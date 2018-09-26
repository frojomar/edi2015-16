/*
 * PruebasEstudiantes.cpp
 *
 *  Created on: 04/04/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */
#include <iostream>
#include "Pruebas.h"
//#include "../Estudiantes.h"
using namespace std;

void pr_Estudiantes(){
	cout<<"	--Inicio pruebas de los constructores de Estudiantes"<<endl;
	Estudiantes est1(1);//constructor creado para las pruebas, que tan solo reserva memoria en este caso
	Estudiantes est;
	//lo unico que hace es reservar memoria para la pila de punteros a estudiantes e insertar de el fichero;
	cout<<"	--Fin pruebas de los constructores de Estudiantes"<<endl;
}

void pr_insertar(){
	cout<<"	--Inicio pruebas del insertar de Estudiantes"<<endl;
	Estudiantes est1(1);//constructor creado para las pruebas, que tan solo reserva memoria
	Estudiante *e1=new Estudiante("e1","","","",3);
	Estudiante *e2=new Estudiante("e2","","","",7);
	Estudiante *e3=new Estudiante("e3","","","",5);


	est1.insertar(e2);
	est1.insertar(e1);
	cout<<"		Debe mostrarse primero e2 y luego e1:"<<endl;
	est1.mostrar();

	est1.insertar(e3);
	cout<<"		Debe mostrarse e3 como el ultimo:"<<endl;
	est1.mostrar();


	cout<<"	--Fin pruebas del insertar de Estudiantes"<<endl;
}

void pr_vacia(){
	cout<<"	--Inicio pruebas del vacia de Estudiantes"<<endl;
	Estudiantes est(1);//constructor creado para las pruebas, que tan solo reserva memoria
	Estudiante *e=new Estudiante();
	if(!est.vacia())
		cout<<"		Error para la prueba 1."<<endl;

	est.insertar(e);
	if(est.vacia())
		cout<<"		Error para la prueba 2."<<endl;

	cout<<"	--Fin pruebas del vacia de Estudiantes"<<endl;
}

void pr_sacarPrimero(){
	cout<<"	--Inicio pruebas del sacarPrimero de Estudiantes"<<endl;
	Estudiantes est1(1);//constructor creado para las pruebas, que tan solo reserva memoria
	Estudiante *e1=new Estudiante("e1","","","",3);
	Estudiante *e2=new Estudiante("e2","","","",7);
	Estudiante *e3=new Estudiante("e3","","","",5);
	Estudiante *eaux;


	est1.insertar(e2);
	est1.insertar(e3);
	est1.insertar(e1);

	est1.sacarPrimero(eaux);
	if(eaux!=e1)
		cout<<"		Error para la prueba 1."<<endl;
	delete eaux;

	est1.sacarPrimero(eaux);
	if(eaux!=e3)
		cout<<"		Error para la prueba 2."<<endl;

	cout<<"	--Fin pruebas del sacarPrimero de Estudiantes"<<endl;
}

void pruebas_Estudiantes(){
	cout<<"INICIO PRUEBAS ESTUDIANTES"<<endl;
	pr_Estudiantes();
	cout<<endl;
	pr_insertar();
	cout<<endl;
	pr_vacia();
	cout<<endl;
	pr_sacarPrimero();
	cout<<endl;
	cout<<"FIN PRUEBAS ESTUDIANTES"<<endl;
}
/*
int main(){
	cout<<"INICIO PRUEBAS ESTUDIANTES"<<endl;
	pr_Estudiantes();
	cout<<endl;
	pr_vacia();
	cout<<endl;
	pr_insertar();
	cout<<endl;
	pr_sacarPrimero();
	cout<<endl;
	cout<<"FIN PRUEBAS ESTUDIANTES"<<endl;
	return 0;
}*/
