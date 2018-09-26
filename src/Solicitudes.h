/*
 * Solicitudes.h
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#ifndef SOLICITUDES_H_
#define SOLICITUDES_H_
#include "Solicitud.h"
#include "EstructurasDatos/Cola.h"

class Solicitudes {
private:
	Cola <Solicitud *> *montonSolicitudes;

public:

	//***********************************
	////*******CONSTRUCTOR.
	//***********************************

	/*
	* PRE: instancia creada,
	* POST:reserva memoria para la cola de punteros a Solicitud
	* COMPLEJIDAD O(1)
	*/
	Solicitudes();

	//***********************************
	////*******OTROS METODOS.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST:encola una solicitud con codigo 'codtit'
	* COMPLEJIDAD O(1)
	*/
	void anadirSolicitud(int codtit);

	/*
	* PRE: instancia creada e inicializada
	* POST:desencola la primera solicitud
	* COMPLEJIDAD O(1)
	*/
	void eliminarSolicitud();

	/*
	* PRE: instancia creada e inicializada
	* POST:nos devuelve 'true' si hay solicitudes en la cola
	* COMPLEJIDAD O(1)
	*/
	bool vacia();

	/*
	* PRE: instancia creada e inicializada
	* POST:nos devuelve un puntero a la primera solicitud de la cola, sin quitarla de esta
	* COMPLEJIDAD O(1)
	*/
	Solicitud* primera();

	/*
	* PRE: instancia creada e inicializada
	* POST:muestra el codigo de todas las solicitudes almacenadas en la cola en orden de "llegada"
	* COMPLEJIDAD O(n)
	*/
	void mostrar(); //tengo que quitarlo antes de entregar

	//***********************************
	////*******OPERADORES.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST: copia en la instancia las solicitudes que contenía s
	* COMPLEJIDAD O(n)
	*/
	void operator=(Solicitudes s);

	~Solicitudes();
};

#endif /* SOLICITUDES_H_ */
