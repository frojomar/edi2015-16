/*
 * recorrido.h
 *
 *  Created on: 04/03/2014
 *      Author: jarico
 *      Complementado por: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#ifndef GESTOR_USUARIOS_H_
#define GESTOR_USUARIOS_H_

#include <iostream>
#include <string>

#include "EstructurasDatos/arbol.h"
#include "Estudiante.h"
#include "comparaestudiante.h"
using namespace std;



class GestorEstudiantes {

private:

	Arbol<Estudiante *, ComparaPtrEstudiante> *abb_estudiantes;

	/*
	* PRE: instancia creada,  e inicializada
	* POST:nos devuelve el arbol cuya raiz es el primer estudiante cuyo apellido contiene la raiz apel buscada
	* COMPLEJIDAD O(log n)
	*/
	Arbol<Estudiante *, ComparaPtrEstudiante> * similares (Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, const string &apel);

	/*
	* PRE: instancia creada,  e inicializada
	* POST: nos muestra por pantalla todos los estudiantes cuyo apellido contenga la raiz apel
	* COMPLEJIDAD O(log n)
	*/
	void filtroInOrden  (Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, const string &apel);

	/*
	* PRE: instancia creada,  e inicializada
	* POST:nos muestra todoo el arbol en orden alfabetico
	* COMPLEJIDAD O(log n)
	*/
	void inOrden (Arbol<Estudiante *, ComparaPtrEstudiante> *abbu);

	/*
	* PRE: instancia creada,  e inicializada
	* POST:nos devuelve bool==true si lo ha encontrado, devolviendonos un estudiante valido por el parametro 'e'
	* COMPLEJIDAD O(log n)
	*/
	bool buscarEstudianteR(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu,string apellido, string apellido2, string nombre, string dni, Estudiante *&e);

	/*
	* PRE: instancia creada,  e inicializada
	* POST: saca del arbol y nos devuelve por 'e' al estudiante con mayor nota
	* COMPLEJIDAD O(n)
	*/
	void sacarEstMayorNotaR(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, Estudiante *&e);

	/*
	* PRE: instancia creada, e inicializada
	* POST:nos devuelve cuantos estudiantes contiene el arbol
	* COMPLEJIDAD O(n)
	*/
	int contar(Arbol<Estudiante *, ComparaPtrEstudiante> *abb);

public:

	/*
	* PRE: instancia creada,
	* POST:inicilaiza los atributos
	* COMPLEJIDAD O(1)
	*/
	GestorEstudiantes      ();

	/*
	* PRE: instancia creada,  e inicializada
	* POST:nos muestra los estudiantes cuyo apellido comienza por  la raiz contenida en 'apel'
	* COMPLEJIDAD O(1)
	*/
	void  mostrarSimilares (const string &apel);

	/*
	* PRE: instancia creada,  e inicializada
	* POST: nos muestra todos los estudiantes alfabeticamente del arbol
	* COMPLEJIDAD O(1)
	*/
	void  mostrar          ();

	/*
	* PRE: instancia creada, e inicializada
	* POST:inserta en el sitio adecuado al estudiante 'e'
	* COMPLEJIDAD O(1)
	*/
	void insertar(Estudiante *&e);

	/*
	* PRE: instancia creada,  e inicializada
	* POST:nos devuelve bool=true si lo encuentra y un estudiante valido en 'e'
	* COMPLEJIDAD O(1)
	*/
	bool buscarEstudiante(string apellido, string apellido2, string nombre, string dni, Estudiante *&e);

	/*
	* PRE: instancia creada, e inicializada
	* POST:nos devuelve en 'e' el estudiante con mayor nota
	* COMPLEJIDAD O(1)
	*/
	void sacarEstMayorNota(Estudiante *&e);

	/*
	* PRE: instancia creada, e inicializada
	* POST: nos devuelve bool=true si hay estudiantes en el arbol
	* COMPLEJIDAD O(1)
	*/
	bool tieneEstudiantes();

	/*
	* PRE: instancia creada,  e inicializada
	* POST: nos devuelve el estudiante de la raiz
	* COMPLEJIDAD O(1)
	*/
	void obtenerAleatorio(Estudiante *&e);

	/*
	* PRE: instancia creada,  e inicializada
	* POST: nos dice cuantos estudiantes contiene el arbol
	* COMPLEJIDAD O(1)
	*/
	int cuantos();

	/*
	* PRE: instancia creada,  e inicializada
	* POST:elimina el puntero al estudiante 'e' del arbol
	* COMPLEJIDAD O(1)
	*/
	void eliminar(Estudiante *&e);

	/*
	* PRE: instancia creada,  e inicializada
	* POST: destruye la instancia al arbol de estudiantes
	* COMPLEJIDAD O(1)
	*/
	~GestorEstudiantes     ();
};



#endif /* GESTOR_ESTUDIANTES_H_ */
