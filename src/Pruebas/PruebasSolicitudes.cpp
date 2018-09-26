/*
 * PruebasSolicitudes.cpp
 *
 *  Created on: 04/04/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include <iostream>
#include "Pruebas.h"
//#include "../Solicitudes.h"
using namespace std;


void pr_Solicitudes(){
	cout<<"	--Inicio pruebas del constructor de Solicitudes"<<endl;

	Solicitudes s;

	if(!s.vacia())
		cout<<"		Error para constructor por defecto"<<endl;

	cout<<"	--Fin pruebas del constructor de Solicitudes"<<endl;
}

void pr_primera(){
	cout<<"	--Inicio pruebas del primera de Solicitudes"<<endl;
	Solicitudes s;
	Solicitud *sol;

	s.anadirSolicitud(1);
	sol=s.primera();
	if((sol->getCodtit())!=1)
		cout<<"		Error para prueba 1."<<endl;

	Solicitudes s2;
	s2.anadirSolicitud(2);
	sol=s2.primera();
	if((sol->getCodtit())!=2)
		cout<<"		Error para prueba 2."<<endl;

	cout<<"	--Fin pruebas del primera de Solicitudes"<<endl;
}

void pr_anadirSolicitud(){
	cout<<"	--Inicio pruebas del anadirSolicitudes de Solicitudes"<<endl;
	Solicitudes s;
	Solicitud *sol;

	s.anadirSolicitud(1);
	sol=s.primera();
	if((sol->getCodtit())!=1)
		cout<<"		Error para prueba 1."<<endl;


	s.anadirSolicitud(2);
	sol=s.primera();
	if((sol->getCodtit())!=1)
		cout<<"		Error para prueba 2."<<endl;

	cout<<"	--Fin pruebas del anadirSolicitud de Solicitudes"<<endl;

}

void pr_vacia_solicitudes(){
	cout<<"	--Inicio pruebas del vacia de Solicitudes"<<endl;
	Solicitudes s;

	if(!s.vacia())
		cout<<"		Error para la prueba 1."<<endl;

	s.anadirSolicitud(1);
	if(s.vacia())
		cout<<"		Error para la prueba 2."<<endl;

	cout<<"	--Fin pruebas del vacia de Solicitudes"<<endl;
}

void pr_eliminarSolicitud(){
	cout<<"	--Inicio pruebas del eliminarSolicitud de Solicitudes"<<endl;

	Solicitudes s;
	s.anadirSolicitud(3);
	s.anadirSolicitud(1);

	s.eliminarSolicitud();
	s.eliminarSolicitud();
	if(!s.vacia())
		cout<<"		Error para la prueba 1."<<endl;

	s.anadirSolicitud(1);
	if(s.vacia())
		cout<<"		Error para la prueba 2."<<endl;

	cout<<"	--Fin pruebas del eliminarSolicitud de Solicitudes"<<endl;
}

void pruebas_Solicitudes(){
	cout<<"INICIO PRUEBAS SOLICITUDES"<<endl;
	pr_Solicitudes();
	cout<<endl;
	pr_primera();
	cout<<endl;
	pr_anadirSolicitud();
	cout<<endl;
	pr_vacia_solicitudes();
	cout<<endl;
	pr_eliminarSolicitud();
	cout<<endl;
	cout<<"FIN PRUEBAS SOLICITUDES"<<endl;
}

/*
int main(){
	cout<<"INICIO PRUEBAS SOLICITUD"<<endl;
	pr_Solicitudes();
	cout<<endl;
	pr_anadirSolicitud();
	cout<<endl;
	pr_eliminarSolicitud();
	cout<<endl;
	pr_vacia();
	cout<<endl;
	pr_primera();
	cout<<endl;
	pr_asignacion();
	cout<<endl;
	cout<<"FIN PRUEBAS SOLICITUD"<<endl;
	return 0;
}*/
