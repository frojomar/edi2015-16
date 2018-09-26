/*
 * Solicitudes.cpp
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include "Solicitudes.h"


Solicitudes::Solicitudes() {//reserva memoria para la cola de punteros a Solicitud
	montonSolicitudes=new Cola<Solicitud *>();
}

void Solicitudes::anadirSolicitud(int codtit){//crea una solicitud con codigo 'codtit' y la encola
	Solicitud *s=new Solicitud(codtit);
	montonSolicitudes->encolar(s);
}

Solicitud* Solicitudes::primera(){//nos devuelve la primera Solicitud si la cola no esta vacia
	Solicitud* s;
	if(!montonSolicitudes->vacia())
		montonSolicitudes->primero(s);
	return s;
}
void Solicitudes::eliminarSolicitud(){//elimina la primera solicitud de la cola
	Solicitud* s;
	if(!montonSolicitudes->vacia()){
		montonSolicitudes->primero(s);
		montonSolicitudes->desencolar();
		delete s;
	}
}
bool Solicitudes::vacia(){//nos dice si la cola de solicitudes esta vacia llamando al 'vacia' de la cola
	return montonSolicitudes->vacia();
}
void Solicitudes::mostrar(){
	Cola <Solicitud *> *c= new Cola <Solicitud*>;
	Solicitud *s;
												//hace un bucle que saca la primera solicitud, la muestra y la mete en una cola auxiliar
	while(!montonSolicitudes->vacia()){
		montonSolicitudes->primero(s);
		montonSolicitudes->desencolar();
		s->mostrar();
		c->encolar(s);
	}
	while(!c->vacia()){							//cuando hemos mostrados todas las solicitudes, las saca de la cola auxiliar y las vuelve a meter
		c->primero(s);								//a la cola original
		c->desencolar();
		montonSolicitudes->encolar(s);
	}

}
void Solicitudes::operator=(Solicitudes s){
	Solicitud *sol;
	int cod=0;

	if(this->vacia()){				//copia en nuestra cola las solicitudes de la otra si la nuestra no esta vacia
		while(!s.vacia()){
			sol=s.primera();
			cod=sol->getCodtit();
			this->anadirSolicitud(cod);
		}

	}
}

Solicitudes::~Solicitudes() {
	Solicitud *s;
	while (!montonSolicitudes->vacia()) {	//va sacando los punteros uno a uno de la cola y liberando la memoria asociada de cada uno de ellos
		montonSolicitudes->primero(s);
		delete s;
		montonSolicitudes->desencolar();
	}
	delete montonSolicitudes;
}

