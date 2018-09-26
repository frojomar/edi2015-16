/*
 * Solicitud.h
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#ifndef SOLICITUD_H_
#define SOLICITUD_H_
#include <iostream>
using namespace std;

class Solicitud {
private:
	int codtit;

public:

	//***********************************
	////*******CONSTRUCTORES.
	//***********************************

	/*
	* PRE: instancia creada,
	* POST:inicializa los atributos de la instancia con los valores por defecto
	* COMPLEJIDAD O(1)
	*/
	Solicitud();

	/*
	* PRE: instancia creada,
	* POST:inicializa los atributos de la instancia con el valor de codtit indicado por cod
	* COMPLEJIDAD O(1)
	*/
	Solicitud(int cod);

	//**********************************************************
	////*******METODOS SELECTORES (GET) Y MODIFICADORES (SET).
	//**********************************************************

	/*
	* PRE:	instancia creada e inicializada
	* POST: modifica el valor almacenado en el atributo Codtit
	* COMPLEJIDAD O(1)
	*/
	void setCodtit(int cod);

	/*
	* PRE:	instancia creada e inicializada
	* POST: devuelve el valor almacenado en el atributo Codtit
	* COMPLEJIDAD O(1)
	*/
	int getCodtit()const;

	//***********************************
	////*******MOSTRAR.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST:muestra el codigo de la solicitud
	* COMPLEJIDAD O(1)
	*/
	void mostrar();

	~Solicitud();
};

#endif /* SOLICITUD_H_ */
