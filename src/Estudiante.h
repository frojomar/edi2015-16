/*
 * Estudiante.h
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Solicitudes.h"
using namespace std;

class Estudiante {
private:
	string apellido1;
	string apellido2;
	string nombre;
	string dni;
	float nota;
	Solicitudes *montonSolicitudes;
	bool admitido; //este atributo lo he añadido yo, pues me es util a la hora de evitar errores en el proceso de asignacion de la preinscripcion

public:

	//***********************************
	////*******CONSTRUCTORES.
	//***********************************

	/*
	* PRE: instancia creada,
	* POST:inicializa los atributos de la instancia con los valores por defecto
	* COMPLEJIDAD O(1)
	*/
	Estudiante();

	/*
	* PRE: instancia creada,
	* POST:inicializa los atributos de la instancia con los valores de apellido1, apellido2, nombre, dni y nota indicados por los parametros de entrada, y con una cola de solicitudes vacia
	* COMPLEJIDAD O(1)
	*/
	Estudiante(string _apellido1, string _apellido2, string _nombre, string _dni, float _nota);

	/*
	* PRE: instancia creada,
	* POST:inicializa los atributos de la instancia con los valores de apellido1, apellido2, nombre, dni y nota indicados por los parametros de entrada, ademas de con una cola de solicitudes dada como parametro
	* COMPLEJIDAD O(1)
	*/
	Estudiante(string _apellido1, string _apellido2, string _nombre, string _dni, float _nota, Solicitudes* _montonSolicitudes);

	/*
	* PRE: instancia creada,
	* POST:inicializa los atributos de la instancia con los valores del estudiante e, haciendo una copia del valor de sus atributos
	* COMPLEJIDAD O(1)
	*/
	Estudiante(const Estudiante &e);

	//*******************************************************
	////*******METODOS SELECTORES (GET) Y MODIFICADORES (SET).
	//*******************************************************

	/*
	* PRE:	instancia creada e inicializada
	* POST: devuelve el valor almacenado en el atributo Apellido1
	* COMPLEJIDAD O(1)
	*/
	string getApellido1()const;

	/*
	* PRE:	instancia creada e inicializada
	* POST: devuelve el valor almacenado en el atributo Apellido2
	* COMPLEJIDAD O(1)
	*/
	string getApellido2()const;

	/*
	* PRE:	instancia creada e inicializada
	* POST: devuelve el valor almacenado en el atributo Nombre
	* COMPLEJIDAD O(1)
	*/
	string getNombre()const;

	/*
	* PRE:	instancia creada e inicializada
	* POST: devuelve el valor almacenado en el atributo DNI
	* COMPLEJIDAD O(1)
	*/
	string getDni()const;

	/*
	* PRE:	instancia creada e inicializada
	* POST: devuelve el valor almacenado en el atributo Nota
	* COMPLEJIDAD O(1)
	*/
	float getNota()const;

	/*
	* PRE:	instancia creada e inicializada
	* POST: devuelve el valor almacenado en el atributo Admitido
	* COMPLEJIDAD O(1)
	*/
	bool getAdmitido()const;

	/*
	* PRE:	instancia creada e inicializada
	* POST: modifica el valor almacenado en el atributo Apellido1
	* COMPLEJIDAD O(1)
	*/
	void setApellido1(string _apellido1);

	/*
	* PRE:	instancia creada e inicializada
	* POST: modifica el valor almacenado en el atributo Apellido2
	* COMPLEJIDAD O(1)
	*/
	void setApellido2(string _apellido2);

	/*
	* PRE:	instancia creada e inicializada
	* POST: modifica el valor almacenado en el atributo Nombre
	* COMPLEJIDAD O(1)
	*/
	void setNombre(string _nombre);

	/*
	* PRE:	instancia creada e inicializada
	* POST: modifica el valor almacenado en el atributo DNI
	* COMPLEJIDAD O(1)
	*/
	void setDni(string _dni);

	/*
	* PRE:	instancia creada e inicializada
	* POST: modifica el valor almacenado en el atributo nota
	* COMPLEJIDAD O(1)
	*/
	void setNota(float _nota);

	/*
	* PRE:	instancia creada e inicializada
	* POST: modifica el valor almacenado en el atributo montonSolicitudes
	* COMPLEJIDAD O(1)
	*/
	void setSolicitudes(Solicitudes *_montonSolicitudes);

	/*
	* PRE:	instancia creada e inicializada
	* POST: modifica el valor almacenado en el atributo Admitido
	* COMPLEJIDAD O(1)
	*/
	void setAdmitido(bool _admitido);

	//***********************************
	////*******OTROS METODOS.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST: nos devuelte bool==true si el estudiante tiene solicitudes
	* COMPLEJIDAD O(1)
	*/
	bool tieneSolicitudes();

	/*
	* PRE: instancia creada e inicializada
	* POST: nos devuelve el codigo de la solicitud que se encuentra en el primer puesto en la cola
	* COMPLEJIDAD O(1)
	*/
	int primeraSolicitud();

	/*
	* PRE: instancia creada e inicializada
	* POST:
	* COMPLEJIDAD O(1)
	*/
	//bool matricularse();

	//***********************************
	////*******MOSTRAR.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST:muestra la info del estudiante en cuestion por pantalla(sin la cola de solicitudes)
	* COMPLEJIDAD O(1)
	*/
	void mostrar();

	/*
	* PRE: instancia creada e inicializada
	* POST:muestra la info del estudiante en cuestion por pantalla(con la cola de solicitudes)
	* COMPLEJIDAD O(1)
	*/
	void mostrar_pruebas();//este mostrar es para las pruebas, pues muestra la cola de solicitudes tambien

	//***********************************
	////*******METODOS PARA FASE 03.
	//***********************************
	/*
	* PRE: instancia creada e inicializada
	* POST:imprime en el fichero vinculado a fsal los datos de 'e'
	* COMPLEJIDAD O(1)
	*/
	void infoAFichero(ofstream &fsal);

	~Estudiante();
};

#endif /* ESTUDIANTE_H_ */
