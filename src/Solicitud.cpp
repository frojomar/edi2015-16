/*
 * Solicitud.cpp
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include "Solicitud.h"

Solicitud::Solicitud() {//inicializa el atributo a 0
	codtit=0;
}

Solicitud::Solicitud(int cod){//inicializa el atributo con el valor de cod
	codtit=cod;
}

void Solicitud::setCodtit(int cod){//pone en el atributo el valor que contiene cod
	codtit=cod;
}

int Solicitud::getCodtit()const{//nos devuelve el valor del codtit
	return codtit;
}

void Solicitud::mostrar(){//nos muestra el codigo de la solicitud
	cout<<codtit<<" ";
}

Solicitud::~Solicitud() {
//no hace nada, pues no tiene memoria que liberar
}

