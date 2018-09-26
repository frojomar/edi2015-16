/*
 * PruebasSolicitud.cpp
 *
 *  Created on: 04/04/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include <iostream>
//#include "../Solicitud.h"
#include "Pruebas.h"
using namespace std;

void pr_Solicitud(){
	cout<<"	--Inicio pruebas de los constructores de Solicitud"<<endl;

	Solicitud s;
	if(s.getCodtit()!=0)
		cout<<"		Error para constructor por defecto"<<endl;
	Solicitud s2(1);
	if(s2.getCodtit()!=1)
		cout<<"		Error para constructor parametrizado"<<endl;

	cout<<"	--Fin pruebas de los contructores de Solicitud"<<endl;
}

void pr_set_getCodtit(){
	cout<<"	--Inicio pruebas de los get_setCodtit de Solicitud"<<endl;

	Solicitud s1(1);
	if(s1.getCodtit()!=1)
		cout<<"		Error para metodo getCodtit(1)"<<endl;
	Solicitud s2(2);
	if(s2.getCodtit()!=2)
		cout<<"		Error para metodo getCodtit(2)"<<endl;
	Solicitud s3(3);
	if(s3.getCodtit()!=3)
		cout<<"		Error para metodo getCodtit(3)"<<endl;

	s1.setCodtit(4);
	if(s1.getCodtit()!=4)
		cout<<"		Error para metodo setCodtit(4)"<<endl;
	s2.setCodtit(5);
	if(s2.getCodtit()!=5)
		cout<<"		Error para metodo setCodtit(5)"<<endl;
	s3.setCodtit(6);
	if(s3.getCodtit()!=6)
		cout<<"		Error para metodo setCodtit(6)"<<endl;

	cout<<"	--Fin pruebas de los get_setCodtit de Solicitud"<<endl;
}

void pruebas_Solicitud(){
	cout<<"INICIO PRUEBAS SOLICITUD"<<endl;
	pr_Solicitud();
	cout<<endl;
	pr_set_getCodtit();
	cout<<"FIN PRUEBAS SOLICITUD"<<endl;
}

/*
int main(){
	cout<<"INICIO PRUEBAS SOLICITUD"<<endl;
	pr_Solicitud();
	cout<<endl;
	pr_set_getCodtit();
	cout<<"FIN PRUEBAS SOLICITUD"<<endl;
	return 0;
}
*/

