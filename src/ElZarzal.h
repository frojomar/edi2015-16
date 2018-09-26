/*
 * ElZarzal.h
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#ifndef ELZARZAL_H_
#define ELZARZAL_H_
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Titulaciones.h"
#include "Estudiantes.h"
#include "EstructurasDatos/pila.h"
using namespace std;

class ElZarzal {
private:
	Estudiantes* EstudiantesPre;
	Titulaciones* ListaTitulaciones;

	//***********************************
	////*******METODOS PRIVADOS.
	//***********************************

	/*
	* PRE: instancia creada, estudiante 'e' inicializado, solicitudes corresponden con carreras que existen en la universidad
	* POST:asigna un estudiante a una titulacion segun su cola de solicitudes, comprobando si debe ir a la lista de espera o de admitidos
	* COMPLEJIDAD O(1)
	*/
	void asignar(Estudiante *&e);
	/*
	* PRE:  instancia creada e inicializada, preinscripcion y matricula llevadas a cabo
	* POST:elimina al estudiante que coincide con los datos pasados de todas las titulaciones donde este, si se encuentra admitido en la titulacion con codigo 'codtit'
	* COMPLEJIDAD O(1)
	*/
	void renuncia(int codtit, string apel, string apellido2, string nombre, string dni);
	/*
	* PRE:  instancia creada e inicializada, preinscripcion y matricula llevadas a cabo
	* POST:elimina al estudiante que coincide con los datos pasados de todas las titulaciones donde este, si se encuentra admitido en la titulacion con codigo 'codtit' e imprime su info al fichero de esa titulacion
	* COMPLEJIDAD O(1)
	*/
	void seMatricula(ofstream &fsal, int codtit, string apel, string apellido2, string nombre, string dni);

public:

	//***********************************
	////*******CONSTRUCTORES.
	//***********************************

	/*
	* PRE: instancia creada
	* POST:inicializa los atributos de la instancia con unos valores especificos especialmente pensados para las pruebas
	* COMPLEJIDAD O(1)
	* //constructor que uso en las pruebas. Con bandera!=0 0 !=-1 solo reserva memoria,
	*  y con 0 o -1 se crea con una lista de titulaciones y estudiantes especificos
	*/
	ElZarzal(int bandera);

	/*
	* PRE: instancia creada
	* POST:inicializa los atributos de la instancia
	* COMPLEJIDAD O(1)
	*/
	ElZarzal();

	//***********************************
	////*******OPCIONES DEL MENU.
	//***********************************

	/*
	* PRE: instancia creada e inicializada, 'ListaTitulaciones' contiene titulaciones
	* POST: va sacando estudiantes de la pila de estudiantes preinscritos y los va mandando a asignar hasta que la pila este vacia, LOS PREINSCRIBE
	* COMPLEJIDAD O(n)
	*/
	void preinscripcion();//FUNCION 1

	/*
	* PRE: instancia creada e inicializada, matricula no llevada a cabo si queremos que nos muestre los estudiantes de sus listas
	* POST:muestra la informacion de la titulacion con codigo == 'cod' si la encuentra en la lista de titulaciones, sino, dice que no la ha encontrado
	* COMPLEJIDAD O(1)
	*/
	void consultarTitulacion(int cod);//FUNCION 2

	/*
	* PRE: instancia creada e inicializada, preincripciones llevadas a cabo, matricula no llevada a cabo
	* POST:muestra la informacion del estudiante cuyo deni coincida con el dado, y si no lo encuentra, nos lo indica
	* COMPLEJIDAD O(1)
	*/
	void consultarEstudiante(string dni);//FUNCION 3

	/*
	* PRE: instancia creada, preinscripcion llevada a cabo
	* POST:matricula a los estudiantes preinscritos anteriormente
	* COMPLEJIDAD O(1)
	*/
	void matricula();//FUNCION 4

/////////////////////////////////////////////////////
	/*
	* PRE: instancia creada, metricula llevada a cabo
	* POST:busca en las titulaciones a los estudiantes cuyo apellido comience por la raiz dada
	* COMPLEJIDAD O(1)
	*/
	void busquedaXraiz(string raiz);//FUNCION 7
//////////////////////////////////////////////////////

	/*
	* PRE: instancia creada e inicializada
	* POST:nos muestra las notas de Corte de todas las titulaciones junto al nombre de la titulacion, siendo 0 la nota si no se ha llevado a cabo 'preinscripcion'
	* COMPLEJIDAD O(1)
	*/
	void notasCorte();//FUNCION 8

	//***********************************
	////*******METODOS PARA MOSTRAR.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST:muestra la lista de EstudiantesPre
	* COMPLEJIDAD O(1)
	*/
	void mostrar1();

	/*
	* PRE: instancia creada e inicializada
	* POST:muestra como quedan todas las titulaciones con sus listas de admitidos y espera tras preinscribir (si no hemos preinscrito, estas listas estaran vacias)
	* COMPLEJIDAD O(1)
	*/
	void mostrar2();

	//***********************************
	////*******METODOS PARA FASE 03.
	//***********************************
	/*
	* PRE: instancia creada e inicializada, preinscripcion y matricula llevadas a cabo
	* POST:crea un fichero por titulacion con los estudiantes ya matriculados en cada una y elimina de todas las titulaciones a los que renuncian. Quedan en admitidos los que aun no han sido tratados.
	* COMPLEJIDAD O(n)
	*/
	void proceso_matricula();//FUNCION 5
	/*
	* PRE: instancia creada e inicializada, preinscripcion y matricula llevada a cabo
	* POST:muestra como queda una titulacion tras matricula(si no se lleva a cabo preinscripcion y matricula, el arbol de admitidos estará vacio)
	* COMPLEJIDAD O(1)
	*/
	void consultarTitulacionMatricula(int cod);//FUNCION 6

	~ElZarzal();
};

#endif /* ELZARZAL_H_ */
