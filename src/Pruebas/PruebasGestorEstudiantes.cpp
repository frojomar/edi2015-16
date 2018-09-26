/*

 * PruebasGestorEstudiantes.cpp
 *
 *  Created on: 10/05/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include <iostream>
#include "Pruebas.h"
//#include "../ColeccionEstudiantes.h"
using namespace std;

void pr_cuantos2(){
	cout<<"	--Inicio pruebas del cuantos de GestorEstudiantes"<<endl;
		GestorEstudiantes abb;
		Estudiante *e1, *e2, *e3;

		e1=new Estudiante("RUIZ", "LOPEX", "ANGEL", "7623436F", 9.5);
		e2=new Estudiante("GALILEO", "SANCHEZ", "LUIS", "2543678A", 9.0);
		e3=new Estudiante("MARQUEZ", "GUERRERO", "JOSE", "1567836P", 5.0);

		if(abb.cuantos()!=0)
			cout<<"		Error para la prueba 1."<<endl;

		abb.insertar(e1);
		if(abb.cuantos()!=1)
			cout<<"		Error para la prueba 2."<<endl;

		abb.insertar(e3);
		abb.insertar(e2);
		if(abb.cuantos()!=3)
			cout<<"		Error para la prueba 3."<<endl;

		abb.eliminar(e3);
		if(abb.cuantos()!=2)
			cout<<"		Error para la prueba 4."<<endl;

	cout<<"	--Fin pruebas del cuantos de GestorEstudiantes"<<endl;
}

void pr_obtenerAleatorio(){
	cout<<"	--Inicio pruebas del obtenerAleatorio de GestorEstudiantes"<<endl;
		GestorEstudiantes abb;
		Estudiante *e1, *e2, *e3, *eaux;

		e1=new Estudiante("RUIZ", "LOPEX", "ANGEL", "7623436F", 9.5);
		e2=new Estudiante("GALILEO", "SANCHEZ", "LUIS", "2543678A", 9.0);
		e3=new Estudiante("MARQUEZ", "GUERRERO", "JOSE", "1567836P", 9.5);

		abb.insertar(e3);
		abb.insertar(e1);
		abb.insertar(e2);

		abb.obtenerAleatorio(eaux);
		if(eaux!=e3)
			cout<<"		Error para la prueba 1."<<endl;

		abb.obtenerAleatorio(eaux);
		if(eaux!=e3)
			cout<<"		Error para la prueba 2."<<endl;
		abb.eliminar(eaux);

		abb.obtenerAleatorio(eaux);
		if(eaux!=e2)
			cout<<"		Error para la prueba 3."<<endl;
		abb.eliminar(eaux);

		abb.obtenerAleatorio(eaux);
		if(eaux!=e1)
			cout<<"		Error para la prueba 4."<<endl;
		abb.eliminar(eaux);

	cout<<"	--Fin pruebas del obtenerAleatorio de GestorEstudiantes"<<endl;
}

void pr_obtenerEstMayorNota(){
	cout<<"	--Inicio pruebas del sacarEstMayorNota de GestorEstudiantes"<<endl;
		GestorEstudiantes abb;
		Estudiante *e1, *e2, *e3, *eaux;

		e1=new Estudiante("RUIZ", "LOPEX", "ANGEL", "7623436F", 9.5);
		e2=new Estudiante("GALILEO", "SANCHEZ", "LUIS", "2543678A", 9.0);
		e3=new Estudiante("MARQUEZ", "GUERRERO", "JOSE", "1567836P", 9.5);

		abb.insertar(e3);
		abb.insertar(e1);
		abb.insertar(e2);

		abb.sacarEstMayorNota(eaux);
		if(eaux!=e1 && eaux!=e3)
			cout<<"		Error para la prueba 1."<<endl;

		abb.sacarEstMayorNota(eaux);
		if(eaux!=e1 && eaux!=e3)
			cout<<"		Error para la prueba 2."<<endl;

		abb.sacarEstMayorNota(eaux);
		if(eaux!=e2)
			cout<<"		Error para la prueba 3."<<endl;

	cout<<"	--Fin pruebas del sacarEstMayorNota de GestorEstudiantes"<<endl;
}

void pruebas_GestorEstudiantes(){
	cout<<"INICIO PRUEBAS GESTOR ESTUDIANTES"<<endl;
	pr_cuantos2();
	cout<<endl;
	pr_obtenerAleatorio();
	cout<<endl;
	pr_obtenerEstMayorNota();
	cout<<endl;
	cout<<"FIN PRUEBAS GESTOR ESTUDIANTES"<<endl;
}
/*
int main(){
	cout<<"INICIO PRUEBAS GESTOR ESTUDIANTES"<<endl;
	pr_cuantos2();
	cout<<endl;
	pr_obtenerAleatorio();
	cout<<endl;
	pr_obtenerEstMayorNota();
	cout<<endl;
	cout<<"FIN PRUEBAS GESTOR ESTUDIANTES"<<endl;
	return 0;
}*/

