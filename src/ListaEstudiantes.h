/*
 * ListaEstudiantes.h
 *
 *  Created on: 14/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#ifndef LISTAESTUDIANTES_H_
#define LISTAESTUDIANTES_H_
#include "EstructurasDatos/listapi.h"
#include "EstructurasDatos/pila.h"
#include "Estudiante.h"

class ListaEstudiantes {
	ListaPI<Estudiante *> *EstTit;
public:

	//***********************************
	////*******CONSTRUCTORES.
	//***********************************

	/*
	* PRE: instancia creada,
	* POST:reserva memoria para la Lista de Punteros a Estudiantes
	* COMPLEJIDAD O(1)
	*/
	ListaEstudiantes();


	//***********************************
	////*******OTROS METODOS.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST: nos devuelve como parametro de salida un puntero al estudiante que se encuentra en la primera posicion y saca el puntero a su vez de la lista
	* COMPLEJIDAD O(1)
	*/
	void SacarPrimero(Estudiante *&e);

	/*
	* PRE: instancia creada e inicializada
	* POST:nos devuelve como parametro de salida un puntero al estudiante que se encuentra en la ultima posicion y saca el puntero a su vez de la lista
	* COMPLEJIDAD O(1)
	*/
	void SacarUltimo(Estudiante *&e);

	/*
	* PRE: instancia creada e inicializada
	* POST:inserta al estudiante en la posicion correspondiente segun su nota (nota+alta primero, nota+baja ultimo)
	* COMPLEJIDAD O(n)
	*/
	bool InsertarPos(Estudiante *e);

	/*
	* PRE: instancia creada e inicializada
	* POST:nos devuelve la nota del estudiante que ocupa la ultima posicion en la lista
	* COMPLEJIDAD O(n)
	*/
	float notaMinima();

	/*
	* PRE: instancia creada e inicializada
	* POST:nos dice cuantos estudiantes hay en la lista
	* COMPLEJIDAD O(n)
	*/
	int cuantos();

	/*
	* PRE: instancia creada e inicializada
	* POST:nos devuelve como salida un puntero al estudiante cuyo DNI coincide con el dado como entrada, indicandonos bool==true si se ha encontrado y ese puntero, por tanto, es valido
	* COMPLEJIDAD O(n)
	*/
	bool buscarEstudiante(string dni, Estudiante *&e);


	//***********************************
	////*******MOSTRAR.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST:muestra la informacion de todos los estudiantes que se encuentran en la lista
	* COMPLEJIDAD O(n)
	*/
	void mostrar();

	~ListaEstudiantes();
};

#endif /* LISTAESTUDIANTES_H_ */
