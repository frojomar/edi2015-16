/*
 * Estudiantes.h
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#ifndef ESTUDIANTES_H_
#define ESTUDIANTES_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "EstructurasDatos/pila.h"
#include "Estudiante.h"
using namespace std;

class Estudiantes {
private:
	Pila <Estudiante *> *montonEstudiantes;
public:

	//***********************************
	////*******CONSTRUCTORES.
	//***********************************

	/*
	* PRE: instancia creada
	* POST:inicializa los atributos de la instancia con unos valores especificos especialmente pensados para las pruebas
	* COMPLEJIDAD O(1)
	* //constructor que uso en las pruebas. Con bandera!=0 0 !=-1 solo reserva memoria,
	*  y con 0 o -1 se crea con una pila de punteros a estudiantes especifica
	*/
	Estudiantes(int bandera);//constructor creado para las pruebas, que tan solo reserva memoria ocrea unos alumnos especificos si bandera=0 o -1

	/*
	* PRE: instancia creada, 'titulaciones.txt' existe en la carpeta del proyecto
	* POST:inicializa los atributos de la instancia con los datos tomados de 'titulaciones.txt'
	* COMPLEJIDAD O(n)
	*/
	Estudiantes();

	//***********************************
	////*******OTROS METODOS.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST: nos devuelve 'true' si la pila de punteros a estudiantes esta vacia
	* COMPLEJIDAD O(1)
	*/
	bool vacia();

	/*
	* PRE: instancia creada e inicializada
	* POST: inserta un puntero a un estudiante en la pila
	* COMPLEJIDAD O(1)
	*/
	void insertar(Estudiante *e);

	/*
	* PRE: instancia creada e inicializada
	* POST: saca de la pila y nos devuelve como parametro de salida un puntero a un estudiante de la pila, el que se encuentra en la cima
	* COMPLEJIDAD O(1)
	*/
	void sacarPrimero(Estudiante *&e);

	//***********************************
	////*******MOSTRAR.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST:muestra la informacion de todos los estudiantes que han realizado una preisncripcion en la universidad
	* COMPLEJIDAD O(n)
	*/
	void mostrar();

	~Estudiantes();
};

#endif /* ESTUDIANTES_H_ */
