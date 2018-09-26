/*
 * PruebasTitulacion.cpp
 *
 *  Created on: 04/04/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */
#include <iostream>
#include "Pruebas.h"
//#include "../Titulacion.h"
using namespace std;


void pr_Titulacion(){
	cout<<"	--Inicio pruebas del los constructores de Titulacion"<<endl;

	Titulacion t1,t2(03,"Titulacion de Prueba 1", 15); //t3(t2);

	cout<<"Los datos deben ser: Codigo 0 , Nombre:  , Plazas: 0, NotaCorte:0, Admitidos:  , Espera:  "<<endl;
	t1.mostrar();
	cout<<"Los datos deben ser: Codigo 03 , Nombre:Titulacion de Prueba 1, Plazas: 15, NotaCorte:0, Admitidos:  , Espera:  "<<endl;
	t2.mostrar();
	cout<<"Los datos deben ser: Codigo 03 , Nombre:Titulacion de Prueba 1, Plazas: 15, NotaCorte:0, Admitidos:  , Espera:  "<<endl;
	//t3.mostrar();

	cout<<"	--Fin pruebas de los constructores de Titulacion"<<endl;
}

void pr_get_Titulacion(){
	cout<<"	--Inicio pruebas de los get de de Titulacion"<<endl;

	Titulacion t1,t2(03,"Titulacion de Prueba 1", 15);

	if(t1.getCodigo()!=0)
		cout<<"		Error para la prueba 1."<<endl;

	if(t2.getCodigo()!=03)
		cout<<"		Error para la prueba 2."<<endl;

	if(t1.getNombre()!=" ")
		cout<<"		Error para la prueba 3."<<endl;

	if(t2.getNombre()!="Titulacion de Prueba 1")
		cout<<"		Error para la prueba 4."<<endl;

	if(t1.getNota_corte()!=0)
		cout<<"		Error para la prueba 5."<<endl;

	if(t2.getNota_corte()!=0)
		cout<<"		Error para la prueba 6."<<endl;

	cout<<"	--Fin pruebas de los get de Titulacion"<<endl;
}

void pr_plazasLlenas(){
	cout<<"	--Inicio pruebas del plazasllenas de Titulacion"<<endl;

	Titulacion t1,t2(03,"Titulacion de Prueba 1", 15);

	if(!t1.plazasLlenas())
		cout<<"		Error para la prueba 1."<<endl;

	if(t2.plazasLlenas())
		cout<<"		Error para la prueba 1."<<endl;

	cout<<"	--Fin pruebas del plazasllenas de Titulacion"<<endl;
}

void pr_insertarEspera(){
	cout<<"	--Inicio pruebas del insertarEspera de Titulacion"<<endl;
	Titulacion t2(03,"Titulacion de Prueba 1", 15);
	Estudiante *e1=new Estudiante("e1", "__", "__", "_______", 6);
	Estudiante *e2=new Estudiante("e2", "__", "__", "_______", 8);
	Estudiante *e3=new Estudiante("e3", "__", "__", "_______", 1);

	t2.insertarEspera(e1);
	cout<<"En espera debe aparecer e1"<<endl;
	t2.mostrar();

	t2.insertarEspera(e2);
	t2.insertarEspera(e3);
	cout<<"En espera deben aparecer en este orden: e2, e1, e3"<<endl;
	t2.mostrar();

	cout<<"	--Fin pruebas del insertarEspera de Titulacion"<<endl;
}

void pr_insertarAdmitido(){
	cout<<"	--Inicio pruebas del insertarAdmitido de Titulacion"<<endl;

	Titulacion t2(03,"Titulacion de Prueba 1", 15);
	Estudiante *e1=new Estudiante("e1", "__", "__", "_______", 6);
	Estudiante *e2=new Estudiante("e2", "__", "__", "_______", 8);
	Estudiante *e3=new Estudiante("e3", "__", "__", "_______", 1);

	t2.insertarAdmitido(e1);
	cout<<"En admitidos debe aparecer e1"<<endl;
	t2.mostrar();

	t2.insertarAdmitido(e2);
	t2.insertarAdmitido(e3);
	cout<<"En admitidos deben aparecer en este orden: e2, e1, e3"<<endl;
	t2.mostrar();

	cout<<"	--Fin pruebas del insertarAdmitido de Titulacion"<<endl;
}

void pr_obtenerSobrante(){
	cout<<"	--Inicio pruebas del obtenerSobrante de Titulacion"<<endl;

	Titulacion t2(03,"Titulacion de Prueba 1", 15);
	Estudiante *e2=new Estudiante("e2", "__", "__", "_______", 8);
	Estudiante *e3=new Estudiante("e3", "__", "__", "_______", 1);
	Estudiante *eaux;

	t2.insertarAdmitido(e2);
	t2.insertarAdmitido(e3);
	cout<<"En admitidos deben aparecer en este orden: e2, e1, e3"<<endl;
	t2.mostrar();

	t2.obtenerSobrante(eaux);
	t2.insertarEspera(eaux);
	cout<<"En admitidos deben aparecer en este orden: e2, e1 y e3 debe estar en espera"<<endl;
	t2.mostrar();

	cout<<"	--Fin pruebas del obtenerSobrante de Titulacion"<<endl;
}

void pr_actualizarNotaCorte(){
	cout<<"	--Inicio pruebas del actualizarNotaCorte de Titulacion"<<endl;

	Titulacion t2(03,"Titulacion de Prueba 1", 15);
	Estudiante *e1=new Estudiante("e1", "__", "__", "_______", 6);
	Estudiante *e2=new Estudiante("e2", "__", "__", "_______", 8);
	Estudiante *e3=new Estudiante("e3", "__", "__", "_______", 1);
	Estudiante *eaux;

	if(t2.getNota_corte()!=0)
		cout<<"		Error para la prueba 1."<<endl;

	t2.insertarAdmitido(e2);
	t2.insertarAdmitido(e3);
	t2.actualizarNotaCorte();

	if(t2.getNota_corte()!=1)
		cout<<"		Error para la prueba 2."<<endl;

	t2.insertarAdmitido(e1);
	t2.obtenerSobrante(eaux);
	t2.actualizarNotaCorte();

	if(t2.getNota_corte()!=6)
		cout<<"		Error para la prueba 3."<<endl;

	t2.insertarEspera(eaux);
	t2.actualizarNotaCorte();

	if(t2.getNota_corte()!=6)
		cout<<"		Error para la prueba 4."<<endl;


	cout<<"	--Fin pruebas del actualizarNotaCorte de Titulacion"<<endl;
}

void pr_cumpleNota(){
	cout<<"	--Inicio pruebas del cumpleNota de Titulacion"<<endl;

	Titulacion t2(03,"Titulacion de Prueba 1", 15);
	Estudiante *e1=new Estudiante("e1", "__", "__", "_______", 6);
	Estudiante *e2=new Estudiante("e2", "__", "__", "_______", 8);
	Estudiante *e3=new Estudiante("e3", "__", "__", "_______", 1);

	t2.insertarAdmitido(e1);
	t2.actualizarNotaCorte();

	if(t2.cumpleNota(e3))
		cout<<"		Error para la prueba 1."<<endl;

	if(!t2.cumpleNota(e2))
		cout<<"		Error para la prueba 2."<<endl;


	cout<<"	--Fin pruebas del cumpleNota de Titulacion"<<endl;
}

void pr_buscarEstudiante3(){
	cout<<"	--Inicio pruebas del buscarEstudiante de Titulacion"<<endl;

	Titulacion t2(03,"Titulacion de Prueba 1", 15);
	Estudiante *e1=new Estudiante("e1", "__", "__", "665A", 6);
	Estudiante *e2=new Estudiante("e2", "__", "__", "441N", 8);
	Estudiante *eaux;
	bool adm;

	if(t2.buscarEstudiante("665A", eaux, adm))
		cout<<"		Error para la prueba 1."<<endl;

	t2.insertarAdmitido(e1);
	t2.insertarEspera(e2);

	if(!t2.buscarEstudiante("665A", eaux, adm))
		cout<<"		Error para la prueba 2a."<<endl;
	if(!adm)
		cout<<"		Error para la prueba 2b."<<endl;
	if(eaux!=e1)
		cout<<"		Error para la prueba 2c."<<endl;

	if(t2.buscarEstudiante("111A", eaux, adm))
		cout<<"		Error para la prueba 3."<<endl;

	cout<<"	--Fin pruebas del buscarEstudiante de Titulacion"<<endl;
}

void pr_admitidos_a_arbol(){
	cout<<"	--Inicio pruebas del Admitidos_a_arbol,Espera_a_arbol y BusquedaXraiz de Titulacion"<<endl;
	Titulacion t2(03,"Titulacion de Prueba 1", 15);
	Estudiante *e1=new Estudiante("ROJO", "__", "__", "6678A", 6);
	Estudiante *e2=new Estudiante("CARRERO", "__", "__", "2356B", 8);
	Estudiante *e3=new Estudiante("CARRASCO", "__", "__", "3467C", 1);

	t2.insertarAdmitido(e1);
	t2.insertarAdmitido(e3);
	t2.insertarEspera(e2);

	t2.Admitidos_a_Arbol();
	t2.Espera_a_Arbol();

	cout<<"Nos debe encontrar en admitidos a ROJO por la raiz RO"<<endl;
	cout<<"Nos debe encontrar en admitidos a CARRASCo y en espera a CARRERO por la raiz C"<<endl;
	t2.busquedaxraiz("RO");
	t2.busquedaxraiz("C");


	cout<<"	--Fin pruebas del Admitidos_a_arbol,Espera_a_arbol y BusquedaXraiz de Titulacion"<<endl;
}

void pr_espera_a_arbol(){
	cout<<"	--Inicio pruebas del Espera_a_arbol de Titulacion"<<endl;
		///probado al probar 'Admitidos_a_arbol'
	cout<<"	--Fin pruebas del Espera_a_arbol de Titulacion"<<endl;
}

void pr_busquedaXraiz(){
	cout<<"	--Iicio pruebas del BusquedaXraiz de Titulacion"<<endl;
		///probado al probar 'Admitidos_a_arbol'
	cout<<"	--Fin pruebas del BusquedaXraiz de Titulacion"<<endl;
}
//QUEDA PROBADO QUE FUNCIONAN EN LAS PRUEBAS DE ADMITIDOS_A_ARBOL

void pruebas_Titulacion(){
	cout<<"INICIO PRUEBAS TITULACION"<<endl;
	pr_Titulacion();
	cout<<endl;
	pr_get_Titulacion();
	cout<<endl;
	pr_plazasLlenas();
	cout<<endl;
	pr_insertarEspera();
	cout<<endl;
	pr_insertarAdmitido();
	cout<<endl;
	pr_obtenerSobrante();
	cout<<endl;
	pr_actualizarNotaCorte();
	cout<<endl;
	pr_cumpleNota();
	cout<<endl;
	pr_buscarEstudiante3();
	cout<<endl;
	pr_admitidos_a_arbol();
	cout<<endl;
	pr_espera_a_arbol();
	cout<<endl;
	pr_busquedaXraiz();
	cout<<endl;
	cout<<"FIN PRUEBAS TITULACION"<<endl;
}
/*
int main(){
	cout<<"INICIO PRUEBAS TITULACION"<<endl;
	pr_Titulacion();
	cout<<endl;
	pr_get_Titulacion();
	cout<<endl;
	pr_plazasLlenas();
	cout<<endl;
	pr_actualizarNotaCorte();
	cout<<endl;
	pr_cumpleNota();
	cout<<endl;
	pr_insertarEspera();
	cout<<endl;
	pr_insertarAdmitido();
	cout<<endl;
	pr_obtenerSobrante();
	cout<<endl;
	pr_buscarEstudiante();
	cout<<endl;
	pr_admitidos_a_arbol();
	cout<<endl;
	pr_espera_a_arbol();
	cout<<endl;
	pr_busquedaXraiz();
	cout<<endl;
	cout<<"FIN PRUEBAS TITULACION"<<endl;
	return 0;
}*/
