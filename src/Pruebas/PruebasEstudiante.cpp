/*
 * PruebasEstudiante.cpp
 *
 *  Created on: 04/04/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */
#include <iostream>
#include "Pruebas.h"
//#include "../Estudiante.h"
using namespace std;


void pr_Estudiante(){
	cout<<"	--Inicio pruebas de los constructores de Estudiante"<<endl;
	Solicitudes *sol= new Solicitudes;
	sol->anadirSolicitud(1);
	sol->anadirSolicitud(2);
	Estudiante e1, e2("Luis", "Alfonso", "Angel", "444333E", 9.99), e3("Berrio", "FLores", "Jorge", "11133E", 10, sol);

	cout<<"Los datos deben ser: Angel Luis Alfonso con DNI 444333E, nota 9.99 y cola de solicitudes vacia"<<endl;
	e2.mostrar_pruebas();
	cout<<"Los datos deben ser: Jorge Berrio Flores con DNI 11133E, nota 10 y cola de solicitudes: 1 2"<<endl;
	e3.mostrar_pruebas();
	cout<<"Los datos deben ser:  con DNI ,nota 0 y cola de solicitudes vacia"<<endl;
	e1.mostrar_pruebas();

	cout<<"	--Fin pruebas de los constructores de Estudiante"<<endl;

}

void pr_set_get_Estudiante(){
	cout<<"	--Inicio pruebas de los set y get de Estudiante"<<endl;
	Solicitudes *sol= new Solicitudes;
	sol->anadirSolicitud(1);
	sol->anadirSolicitud(2);
	Estudiante e1;
	 e1.setNombre("Raul");
	 e1.setApellido1("Martin");
	 e1.setApellido2("Guerrero");
	 e1.setDni("43AS");
	 e1.setNota(6);
	 e1.setSolicitudes(sol);

	 if(e1.getNombre()!="Raul")
		 cout<<"		Error para la prueba 2."<<endl;
	 if(e1.getApellido1()!="Martin")
		 cout<<"		Error para la prueba 3."<<endl;
	 if(e1.getApellido2()!="Guerrero")
		 cout<<"		Error para la prueba 4."<<endl;
	 if(e1.getDni()!="43AS")
		 cout<<"		Error para la prueba 5."<<endl;
	 if(e1.getNota()!=6)
			cout<<"		Error para la prueba 6."<<endl;

	cout<<"	--Fin pruebas de los set y get de Estudiante"<<endl;
}

void pr_tieneSolicitudes(){
	cout<<"	--Inicio pruebas del tieneSolicitudes de Estudiante"<<endl;
	Solicitudes *sol= new Solicitudes;
	sol->anadirSolicitud(1);
	sol->anadirSolicitud(2);
	Estudiante e1, e2("Luis", "Alfonso", "Angel", "444333E", 9.99), e3("Berrio", "FLores", "Jorge", "11133E", 10, sol);

	if(e1.tieneSolicitudes())
		cout<<"		Error para la prueba 1."<<endl;

	if(e2.tieneSolicitudes())
		cout<<"		Error para la prueba 2."<<endl;

	if(!e3.tieneSolicitudes())
		cout<<"		Error para la prueba 3."<<endl;

	cout<<"	--Fin pruebas del tieneSolicitudes de Estudiante"<<endl;
}

void pr_primeraSolicitud(){
	cout<<"	--Inicio pruebas del primeraSolicitud de Estudiante"<<endl;
	int saux;
	Solicitudes *sol= new Solicitudes;
	sol->anadirSolicitud(1);
	sol->anadirSolicitud(2);
	Estudiante e3("Berrio", "FLores", "Jorge", "11133E", 10, sol);

	saux=e3.primeraSolicitud();
	if(saux!=1)
		cout<<"		Error para la prueba 1."<<endl;

	saux=e3.primeraSolicitud();
	if(saux!=2)
		cout<<"		Error para la prueba 2."<<endl;

	cout<<"	--Fin pruebas del primeraSolicitud de Estudiante"<<endl;
}

void pruebas_Estudiante(){
	cout<<"INICIO PRUEBAS ESTUDIANTE"<<endl;
	pr_Estudiante();
	cout<<endl;
	pr_set_get_Estudiante();
	cout<<endl;
	pr_tieneSolicitudes();
	cout<<endl;
	pr_primeraSolicitud();
	cout<<endl;
	cout<<"FIN PRUEBAS ESTUDIANTE"<<endl;
}

/*
int main(){
	cout<<"INICIO PRUEBAS ESTUDIANTE"<<endl;
	pr_Estudiante();
	cout<<endl;
	pr_set_get_Estudiante();
	cout<<endl;
	pr_tieneSolicitudes();
	cout<<endl;
	pr_primeraSolicitud();
	cout<<endl;
	cout<<"FIN PRUEBAS ESTUDIANTE"<<endl;
	return 0;
}*/
