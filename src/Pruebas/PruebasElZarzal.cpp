/*
 * PruebasElZarzal.cpp
 *
 *  Created on: 04/04/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */
#include <iostream>
#include "Pruebas.h"
//#include "../ElZarzal.h"
using namespace std;

/////////////////////////////////////////
///*************************************
/*******************************
 * NOTA::	no he realizado pruebas de proceso_matricula, pues se tratan de unas pruebas de costosa implementacion, ademas de que requieren
 * 	de una cantidad de tiempo desproporcionada para el tiempo relativo a la Fase 03 de este proyecto
 */
/****************************
////*/////////////////////////////////////



void pr_ElZarzal(){
	cout<<"	--Inicio pruebas de los constructores de ElZarzal"<<endl;
	ElZarzal z1(1);//constructor creado para las pruebas, que tan solo reserva memoria en este caso
	ElZarzal z;
	//lo unico que hace es reservar memoria para la lista de punteros a titulaciones e insertar de el fichero, igual con el monton de estudiantes;
	cout<<"	--Fin pruebas de los constructores de ElZarzal"<<endl;
}

void pr_asignar(){
	cout<<"	--Inicio pruebas del asignar de ElZarzal"<<endl;
	cout<<"		El modulo asignar no lo podemos probar desde aqui, pues se trata de un metodo privado"<<endl;
	/*
	ElZarzal z1(-1);//crea El Zarzal con los datos
	Solicitudes *sol;

	sol=new Solicitudes();
	sol->anadirSolicitud(01);
	Estudiante *e1=new Estudiante("e1","__","__","__",9,sol);

	sol=new Solicitudes();
	sol->anadirSolicitud(01);
	Estudiante *e2=new Estudiante("e2","__","__","__",8,sol);

	sol=new Solicitudes();
	sol->anadirSolicitud(01);
	Estudiante *e3=new Estudiante("e3","__","__","__",7,sol);

	sol=new Solicitudes();
	sol->anadirSolicitud(01);
	Estudiante *e4=new Estudiante("e4","__","__","__",6,sol);

	sol=new Solicitudes();
	sol->anadirSolicitud(02);
	Estudiante *e5=new Estudiante("e5","__","__","__",5,sol);

	z1.asignar(e2);
	z1.asignar(e3);
	z1.asignar(e1);
	z1.asignar(e4);
	z1.asignar(e5);

	cout<<"En Titulacion T1 deben aparecer e1,e2,e3 admitidos (en ese orden), y e4 en espera"<<endl;
	cout<<"En Titulacion T2 debe aparecer e5 admitido"<<endl;
	cout<<"En Titulacion T3 no debe aparecer nadie"<<endl;

	z1.mostrar2();
*/
	cout<<"	--Fin pruebas del asignar de ElZarzal"<<endl;
}

void pr_preinscripcion(){
	cout<<"	--Inicio pruebas del preinscripcion de ElZarzal"<<endl;
	ElZarzal z1(0);//crea El Zarzal con una lista predefinida
	ElZarzal z2(-1);//creo El Zarzal con otra lista predefinida

	z1.preinscripcion();
	z2.preinscripcion();

	cout<<"*****PRIMERA PRUEBA*****"<<endl;
	cout<<"Segun el metodo a probar, la lista de alumnos de cada titulacion tras preinscribir seria la siguiente:"<<endl;
	cout<<"Esta lista ademas COINCIDE con la que debia salir (se puede comprobar lo que deberia salir en los comentarios al final de PruebasElZarzal.cpp)"<<endl;
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	z1.mostrar2(); //ver al final los resultados que deben salir
	cout<<endl;
	cout<<endl;

	cout<<"*****SEGUNDA PRUEBA*****"<<endl;
	cout<<"Segun el metodo a probar, la lista de alumnos de cada titulacion tras preinscribir seria la siguiente:"<<endl;
	cout<<"Esta lista ademas COINCIDE con la que debia salir (se puede comprobar lo que deberia salir en los comentarios al final de PruebasElZarzal.cpp)"<<endl;
	cout<<"Este Ejemplo se trata del proporcionado en las diapositivas del Proyecto"<<endl;
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	z2.mostrar2();//ver al final los resultados que deben salir, ademas de en unas presentaciones usadas en los laboratorios

	cout<<"	--Fin pruebas del preinscripcion de ElZarzal"<<endl;
}

void pr_consultarTitulacion(){
	cout<<"	--Inicio pruebas del consultarTitulacion de ElZarzal"<<endl;
	ElZarzal z1(0);//crea El Zarzal con una lista predefinida

	cout<<"La informacion que se debe mostrar es la de la titulacion 07. Grado en Edificacion, con datos y SIN estudiantes "<<endl;
	z1.consultarTitulacion(07);

	z1.preinscripcion();

	cout<<"La informacion que se debe mostrar es la de la titulacion 07. Grado en Edificacion, con datos y  CON estudiantes aguales a los obtenidos en los resultados de la prueba 1"<<endl;
	z1.consultarTitulacion(07);

	cout<<"	--Fin pruebas del consultarTitulacion de ElZarzal"<<endl;
}

void pr_consultarEstudiante(){
	cout<<"	--Inicio pruebas del consultarEstudiante de ElZarzal"<<endl;
	ElZarzal z1(0);//crea El Zarzal con una lista predefinida
	ElZarzal z2(1);//crea El Zarzal vacia

	cout<<"Debe mostrar que no se ha encontrado, pues se esta buscando en un El Zarzal sin estudiantes preinscritos "<<endl;
	z2.consultarEstudiante("45969965A");

	cout<<"Debe mostras que no se ha encontrado porque aun no se ha npreinscrito los estudiantes"<<endl;
	z1.consultarEstudiante("45969965A");

	z1.preinscripcion();

	cout<<"Debe mostrar la informacion de IGNACIO MANCERA LORO, con DNI 45969965A, ADMITIDO EN Ing. del Software"<<endl;
	z1.consultarEstudiante("45969965A");

	cout<<"Debe mostrar la informacion de BRIONES BENÍTEZ, ROBERTO, con DNI 86334885H, ADMITIDO EN Ing. Civil"<<endl;
	z1.consultarEstudiante("86334885H");

	cout<<"Debe mostrar la informacion de MANZANO MAESTRE, GUILLERMO, con DNI 86349644F, ADMITIDO EN Ing. del Software"<<endl;
	z1.consultarEstudiante("86349644F");

	cout<<"	--Fin pruebas del consultarEstudiante de ElZarzal"<<endl;
}

void pr_notasCorte(){
	cout<<"	--Inicio pruebas del notasCorte de ElZarzal"<<endl;
	ElZarzal z1(0);//crea El Zarzal con una lista predefinida
	ElZarzal z2(1);//crea El Zarzal vacia

	cout<<"No debe mostrar nada, pues estamos ejecutandolo sobre un El Zarzal vacio:"<<endl;
	z2.notasCorte();
	cout<<"		--(Si se ha mostrado algo antes de esto algo va mal!!)--"<<endl;

	cout<<"Debe mostrar todas las notas de corte 0:"<<endl;
	z1.notasCorte();

	cout<<"Debe mostrar las siguientes notas de corte:"<<endl;
	cout<<"		Grado en Edificación    8.336"<<endl;
	cout<<"		Grado en Ingenieria Civil Transportes y Servicios Urbanos    0"<<endl;
	cout<<"		Grado en Ingenieria Civil Hidrologia    8.836"<<endl;
	cout<<"		Grado en Ingenieria Civil Construcciones Civiles    5.584"<<endl;
	cout<<"		Grado en Ingenieria de Sonido e Imagen en Telecomunicacion    7.153"<<endl;
	cout<<"		Grado en Ingenieria Informática en Ingeniería del Computadores    6.999"<<endl;
	cout<<"		Grado en Ingenieria Informática en Ingeniería del Software    7.445"<<endl;
	z1.preinscripcion();
	z1.notasCorte();

	cout<<"	--Fin pruebas del notasCorte de ElZarzal"<<endl;
}

void pr_matricula2(){
	cout<<"	--Iicio pruebas del matricula de El Zarzal"<<endl;
		//no merece la pena llevar a cabo pruebas de este metodo, pues se trata de una llamada al 'matricula' de Titulaciones, ya probado
	cout<<"	--Fin pruebas del matricula de El Zarzal"<<endl;
}

void pr_busquedaXraiz2(){
	cout<<"	--Iicio pruebas del busquedaXraiz de El Zarzal"<<endl;
		//no merece la pena llevar a cabo pruebas de este metodo, pues se trata de una llamada al 'busquedaXraiz' de Titulaciones, ya probado
	cout<<"	--Fin pruebas del busquedaXraiz de El Zarzal"<<endl;
}

void pruebas_ElZarzal(){
	cout<<"INICIO PRUEBAS ELZARZAL"<<endl;
	pr_ElZarzal();
	cout<<endl;
	pr_asignar();
	cout<<endl;
	pr_preinscripcion();
	cout<<endl;
	pr_consultarTitulacion();
	cout<<endl;
	pr_consultarEstudiante();
	cout<<endl;
	pr_notasCorte();
	cout<<endl;
	pr_matricula2();
	cout<<endl;
	pr_busquedaXraiz();
	cout<<endl;
	cout<<"FIN PRUEBAS ELZARZAL"<<endl;
}
/*
int main(){
	cout<<"INICIO PRUEBAS ELZARZAL"<<endl;
	pr_ElZarzal();
	cout<<endl;
	pr_asignar();
	cout<<endl;
	pr_preinscripcion();
	cout<<endl;
	pr_consultarTitulacion();
	cout<<endl;
	pr_consultarEstudiante();
	cout<<endl;
	pr_notasCorte();
	cout<<endl;
	pr_matricula2();
	cout<<endl;
	pr_busquedaXraiz();
	cout<<endl;
	cout<<"FIN PRUEBAS ELZARZAL"<<endl;
	return 0;
}
 */
//************************************************
//resultados para la PRUEBA 1 DE PREINSCRIPCION
//************************************************
/*
INFO TITULACION:
	Codigo: 7.
	Nombre: Grado en Edificación.
	Plazas: 3.
	Nota de Corte: 8.336.
	Admitidos:
VERDEJO VERDUGO, AFRICA     38354639Q     8.336.


	Espera:

INFO TITULACION:
	Codigo: 6.
	Nombre: Grado en Ingenieria Civil Transportes y Servicios Urbanos.
	Plazas: 2.
	Nota de Corte: 0.
	Admitidos:

	Espera:

INFO TITULACION:
	Codigo: 5.
	Nombre: Grado en Ingenieria Civil Hidrologia.
	Plazas: 3.
	Nota de Corte: 8.836.
	Admitidos:
VICENTE ZAPATA, ADRIÁN MANUEL     45439946P     8.836.


	Espera:

INFO TITULACION:
	Codigo: 4.
	Nombre: Grado en Ingenieria Civil Construcciones Civiles.
	Plazas: 2.
	Nota de Corte: 5.584.
	Admitidos:
BRIONES BENÍTEZ, ROBERTO     86334885H     5.584.


	Espera:

INFO TITULACION:
	Codigo: 3.
	Nombre: Grado en Ingenieria de Sonido e Imagen en Telecomunicacion.
	Plazas: 7.
	Nota de Corte: 7.153.
	Admitidos:
VENTURA VÁZQUEZ, AIDA     86355843P     8.866.

MANGAS LUJÁN, IGNACIO     83396335R     8.386.

MALPARTIDA LORENTE, IGNACIO     53986334X     8.346.

BUENO BERMEJO, REBECA     86356334Q     7.153.


	Espera:

INFO TITULACION:
	Codigo: 2.
	Nombre: Grado en Ingenieria Informática en Ingeniería del Computadores.
	Plazas: 6.
	Nota de Corte: 6.999.
	Admitidos:
VÁZQUEZ VARGAS, ALBERTO     83399663K     6.999.


	Espera:

INFO TITULACION:
	Codigo: 1.
	Nombre: Grado en Ingenieria Informática en Ingeniería del Software.
	Plazas: 5.
	Nota de Corte: 7.445.
	Admitidos:
MANZANO MAESTRE, GUILLERMO     86349644F     9.446.

VAQUERO VALBUENA, ALBERTO     83448443F     9.436.

MANGUT MACHUCA, GUILLERMO     83433548R     8.946.

MANCERA LORO, IGNACIO     45969965A     8.156.

MACARRO LÓPEZ, ISMAEL     38455686G     7.445.


	Espera:
MAGUIÑA LÓPEZ, IGNACIO     8449434L     6.896.

RODRIGUEZ RAMOS, JOSÉ     45433334E     6.366.

LÓPEZ LÓPEZ, ISMAEL     86438544P     5.836.

LÓPEZ LEBRATO, ISMAEL     53866385C     5.436.

 */
//*************************************************************
//*********************************************************
//*****************************************************
//************************************************
//resultados para la PRUEBA 2 DE PREINSCRIPCION
//************************************************
/*INFO TITULACION:
	Codigo: 3.
	Nombre: T3.
	Plazas: 3.
	Nota de Corte: 5.
	Admitidos:
e7 __, __     _______     6.2.

e8 __, __     _______     6.

e10 __, __     _______     5.


	Espera:

INFO TITULACION:
	Codigo: 2.
	Nombre: T2.
	Plazas: 2.
	Nota de Corte: 7.
	Admitidos:
e2 __, __     _______     8.

e4 __, __     _______     7.


	Espera:
e8 __, __     _______     6.

e10 __, __     _______     5.


INFO TITULACION:
	Codigo: 1.
	Nombre: T1.
	Plazas: 3.
	Nota de Corte: 8.
	Admitidos:
e5 __, __     _______     10.

e6 __, __     _______     9.

e9 __, __     _______     8.


	Espera:
e1 __, __     _______     6.

e3 __, __     _______     5.5.

e10 __, __     _______     5.

*/
