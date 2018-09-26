/*
 * PruebasTitulaciones.cpp
 *
 *  Created on: 04/04/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */
#include <iostream>
#include "Pruebas.h"
//#include "../Titulaciones.h"
using namespace std;

void pr_Titulaciones(){
	cout<<"	--Inicio pruebas del constructor de Titulaciones"<<endl;
	Titulaciones etit1(1);//constructor creado para las pruebas, que tan solo reserva memoria en este caso
	Titulaciones tit;
	//lo unico que hace es reservar memoria para la lista de punteros a titulaciones e insertar de el fichero;
	cout<<"	--Fin pruebas del contructor de Titulaciones"<<endl;
}

void pr_insertar2(){
	cout<<"	--Inicio pruebas del insertar de Titulaciones"<<endl;
	Titulaciones tit(1);
	Titulacion *t1=new Titulacion(01, "Titulacion de Prueba 1", 14);
	Titulacion *t2=new Titulacion(02, "Titulacion de Prueba 2", 44);

	tit.insertar(t1);
	tit.insertar(t2);

	cout<<"Deben aparecer la Titulacion de Prueba 1 y la Titulacion de Prueba 2, en ese orden:"<<endl;
	tit.mostrar();

	cout<<"	--Fin pruebas del insertar de Titulaciones"<<endl;
}

void pr_seleccionarTitulacion(){
	cout<<"	--Inicio pruebas del seleccionarTitulacion de Titulaciones"<<endl;
	Titulaciones tit(0);//carga la lista de titulaciones con unas titulaciones predecifinidas
	Titulacion *t1=new Titulacion(01, "Grado en Ingenieria Informática en Ingeniería del Software", 45);
	Titulacion *t2=new Titulacion(03, "Grado en Ingenieria de Sonido e Imagen en Telecomunicacion", 30);
	Titulacion *taux;

	tit.seleccionarTitulacion(01,taux);

	if(taux!=t1)
		cout<<"		Error para la prueba 1."<<endl;

	tit.seleccionarTitulacion(03,taux);

	if(taux!=t2)
		cout<<"		Error para la prueba 2."<<endl;

	tit.seleccionarTitulacion(02,taux);

	if(taux==t1 || taux==t2)
		cout<<"		Error para la prueba 3."<<endl;

	cout<<"	--Fin pruebas del seleccionarTitulacion de Titulaciones"<<endl;
}

void pr_infoTitulacion(){
	cout<<"	--Inicio pruebas del infoTitulacion de Titulaciones"<<endl;
	Titulaciones tit(0);//carga la lista de titulaciones con unas titulaciones predecifinidas


	cout<<"Debe mostrar la siguiente info: Codigo 01, Nombre:Grado en Ingenieria Informática en Ingeniería del Software, Plazas:45, Admitidos: ,Espera:  "<<endl;
	tit.infoTitulacion(01);

	cout<<"Debe mostrar la siguiente info: Codigo 03, Nombre:Grado en Ingenieria de Sonido e Imagen en Telecomunicacion, Plazas:30, Admitidos: ,Espera:  "<<endl;
	tit.infoTitulacion(03);


	cout<<"	--Fin pruebas del infoTitulacion de Titulaciones"<<endl;
}

void pr_buscarEstudiante2(){
	cout<<"	--Inicio pruebas del buscarEstudiante de Titulaciones"<<endl;
	Titulaciones tit(1);
	Titulacion *t1=new Titulacion(01, "Grado en Ingenieria Informática en Ingeniería del Software", 45);
	Titulacion *t2=new Titulacion(03, "Grado en Ingenieria de Sonido e Imagen en Telecomunicacion", 30);

	Estudiante *e1=new Estudiante("e1", "__", "__", "345A", 6);
	Estudiante *e2=new Estudiante("e2", "__", "__", "441N", 8);
	Estudiante *e3=new Estudiante("e3", "__", "__", "111N", 8);
	Estudiante *e4=new Estudiante("e4", "__", "__", "333N", 8);
	Estudiante *e5=new Estudiante("e5", "__", "__", "666N", 8);

		t1->insertarEspera(e3);
		t1->insertarAdmitido(e5);
		t1->insertarAdmitido(e4);
		t2->insertarAdmitido(e1);
		t2->insertarEspera(e2);

		tit.insertar(t1);
		tit.insertar(t2);

		cout<<"Debe mostrar al estudiante e1:"<<endl;
		tit.buscarEstudiante("345A");

		cout<<"Debe mostrar al estudiante e2:"<<endl;
		tit.buscarEstudiante("441N");

		cout<<"Debe mostrar al estudiante e3:"<<endl;
		tit.buscarEstudiante("111N");

		cout<<"Debe mostrar al estudiante e4:"<<endl;
		tit.buscarEstudiante("333N");

		cout<<"Debe mostrar al estudiante e5:"<<endl;
		tit.buscarEstudiante("666N");

		cout<<"Debe decir que no lo ha encontrado:"<<endl;
		tit.buscarEstudiante("cc");

	cout<<"	--Fin pruebas del buscarEstudiante de Titulaciones"<<endl;
}

void pr_notascorte(){
	cout<<"	--Inicio pruebas del notascorte de Titulaciones"<<endl;
	Titulaciones tit(1);
	Titulacion *t1=new Titulacion(01, "Grado en Ingenieria Informática en Ingeniería del Software", 45);
	Titulacion *t2=new Titulacion(03, "Grado en Ingenieria de Sonido e Imagen en Telecomunicacion", 30);

	Estudiante *e1=new Estudiante("e1", "__", "__", "345A", 6);
	Estudiante *e2=new Estudiante("e2", "__", "__", "441N", 10);
	Estudiante *e3=new Estudiante("e3", "__", "__", "111N", 4);
	Estudiante *e4=new Estudiante("e4", "__", "__", "333N", 2);
	Estudiante *e5=new Estudiante("e5", "__", "__", "666N", 1.5);

		t1->insertarEspera(e3);
		t1->insertarAdmitido(e5);
		t1->insertarAdmitido(e4);
		t2->insertarAdmitido(e1);
		t2->insertarEspera(e2);

		tit.insertar(t1);
		tit.insertar(t2);

		cout<<"Debe mostrar la nota de corte: 01->1.5  , 02->6"<<endl;
		tit.notasCorte();

	cout<<"	--Fin pruebas del notascorte de Titulaciones"<<endl;
}

void pr_matricula(){
	cout<<"	--Inicio pruebas del matricula de Titulaciones"<<endl;
	Titulaciones tit(1);
	Titulacion *t1=new Titulacion(01, "Grado en Ingenieria Informática en Ingeniería del Software", 45);
	Titulacion *t2=new Titulacion(03, "Grado en Ingenieria de Sonido e Imagen en Telecomunicacion", 30);
	Estudiante *e1=new Estudiante("ROJO", "__", "__", "6678A", 6);
	Estudiante *e2=new Estudiante("CARRERO", "__", "__", "2356B", 8);
	Estudiante *e3=new Estudiante("CARRASCO", "__", "__", "3467C", 1);
	Estudiante *e4=new Estudiante("ROMERO", "__", "__", "3467C", 1);
	Estudiante *e5=new Estudiante("SOTOMONTE", "__", "__", "3467C", 1);

	cout<<"Como Titulaciones no contiene ninguna titulacion, no debe encontrar a nadie"<<endl;
	tit.busquedaxraiz("RO");
	tit.busquedaxraiz("C");
	tit.busquedaxraiz("SOTO");
	tit.busquedaxraiz("MONTE");

	t1->insertarAdmitido(e1);
	t1->insertarAdmitido(e3);
	t1->insertarEspera(e2);

	t2->insertarEspera(e5);
	t2->insertarAdmitido(e4);

	tit.insertar(t1);
	tit.insertar(t2);

	cout<<"Como no se ha llevado a cabo el proceso de matriculacion, no debe encontrar a nadie"<<endl;
	tit.busquedaxraiz("RO");
	tit.busquedaxraiz("C");
	tit.busquedaxraiz("SOTO");
	tit.busquedaxraiz("MONTE");

	tit.matricula();

	cout<<"Nos debe encontrar en admitidos de Software a ROJO y en admitidos de Teleco a ROMERO por la raiz RO"<<endl;
		tit.busquedaxraiz("RO");
	cout<<"Nos debe encontrar en admitidos a CARRASCo y en espera a CARRERO de Software por la raiz C"<<endl;
		tit.busquedaxraiz("C");
	cout<<"Nos debe encontrar en SOTOMONTE en espera en Teleco por la raiz SOTO"<<endl;
		tit.busquedaxraiz("SOTO");
	cout<<"No nos debe encontrar a nadie por la raiz MONTE"<<endl;
		tit.busquedaxraiz("MONTE");

	cout<<"	--Fin pruebas del matricula de Titulaciones"<<endl;
}

void pr_busquedaXraiz3(){
	cout<<"	--Inicio pruebas del busquedaXraiz de Titulaciones"<<endl;
		///probado al probar 'matricula'
	cout<<"	--Fin pruebas del busquedaXraiz de Titulaciones"<<endl;
}

void pruebas_Titulaciones(){
	cout<<"INICIO PRUEBAS TITULACIONES"<<endl;
	pr_Titulaciones();
	cout<<endl;
	pr_insertar2();
	cout<<endl;
	pr_seleccionarTitulacion();
	cout<<endl;
	pr_infoTitulacion();
	cout<<endl;
	pr_buscarEstudiante2();
	cout<<endl;
	pr_notascorte();
	cout<<endl;
	pr_matricula();
	cout<<endl;
	pr_busquedaXraiz3();
	cout<<endl;
	cout<<"FIN PRUEBAS TITULACIONES"<<endl;
}
/*
int main(){
	cout<<"INICIO PRUEBAS TITULACIONES"<<endl;
	pr_Titulaciones();
	cout<<endl;
	pr_insertar2();
	cout<<endl;
	pr_seleccionarTitulacion();
	cout<<endl;
	pr_infoTitulacion();
	cout<<endl;
	pr_buscarEstudiante2();
	cout<<endl;
	pr_notascorte();
	cout<<endl;
	pr_matricula();
	cout<<endl;
	pr_busquedaXraiz();
	cout<<endl;
	cout<<"FIN PRUEBAS TITULACIONES"<<endl;
	return 0;
}*/

