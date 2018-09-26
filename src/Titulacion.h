/*
 * Titulacion.h
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#ifndef TITULACION_H_
#define TITULACION_H_
#include <cstring>
#include <iostream>
#include "ListaEstudiantes.h"
#include "ColeccionEstudiantes.h"

using namespace std;

class Titulacion {
private:
	int codigo;
	string nombre;
	float nota_corte;
	int plazas;
	ListaEstudiantes *admitidos;
	ListaEstudiantes *espera;

	GestorEstudiantes *arbAdm;
	GestorEstudiantes *arbEsp;

public:

	//***********************************
	////*******CONSTRUCTORES.
	//***********************************

	/*
	* PRE: instancia creada,
	* POST:inicializa los atributos de la instancia con los valores por defecto
	* COMPLEJIDAD O(1)
	*/
	Titulacion();

	/*
	* PRE: instancia creada,
	* POST:inicializa los atributos de la instancia con los valores de codigo, nombre y plazas indicados por los parametros de entrada
	* COMPLEJIDAD O(1)
	*/
	Titulacion(int _codigo, string _nombre, int _plazas);

	/*
	* PRE: instancia creada,
	* POST:inicializa los atributos de la instancia con los valores de la titulacion t, haciendo una copia del valor de sus atributos
	* COMPLEJIDAD O(1)
	*/
	Titulacion(const Titulacion &t);

	//***********************************
	////*******METODOS SELECTORES (GET).
	//***********************************

	/*
	* PRE:	instancia creada e inicializada
	* POST: devuelve el valor almacenado en el atributo Codigo
	* COMPLEJIDAD O(1)
	*/
	int getCodigo()const;

	/*
	* PRE:	instancia creada e inicializada
	* POST: devuelve el valor almacenado en el atributo Nota_corte
	* COMPLEJIDAD O(1)
	*/
	float getNota_corte()const;

	/*
	* PRE:	instancia creada e inicializada
	* POST: devuelve el valor almacenado en el atributo Nombre
	* COMPLEJIDAD O(1)
	*/
	string getNombre()const;

	/*
	* PRE:	instancia creada e inicializada
	* POST: cambia el valor de la nota de corte a nota
	* COMPLEJIDAD O(1)
	*/
	void setNota_Corte(float nota);

	//***********************************
	////*******OTROS METODOS.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST: nos devuelve si estan las plazas llenas o no de esta titulacion, es decir, si el numero de plazas es igual al de estudiantes admitidos
	* COMPLEJIDAD O(1)
	*/
	bool plazasLlenas();

	/*
	* PRE: instancia creada e inicializada
	* POST: cambia el valor de 'notaCorte' al de la nota del ultimo estudiante admitido
	* COMPLEJIDAD O(1)
	*/
	void actualizarNotaCorte();

	/*
	* PRE: instancia creada e inicializada, e inicializado
	* POST: nos dice si la nota del estudiante dado es mayor que la de corte (si puede entrar en admitidos, por tanto)
	* COMPLEJIDAD O(1)
	*/
	bool cumpleNota(Estudiante *e);

	/*
	* PRE: instancia creada e inicializada, e inicializado
	* POST: inserta al estudiante en la lista de Espera, indicando que no esta admitido ademas
	* COMPLEJIDAD O(1)
	*/
	void insertarEspera(Estudiante *e);

	/*
	* PRE: instancia creada e inicializada, e inicializado
	* POST: inserta al estudiante en la lista de Admitidos, indicando que esta admitido ademas
	* COMPLEJIDAD O(1)
	*/
	void insertarAdmitido(Estudiante *e);

	/*
	* PRE: instancia creada e inicializada
	* POST: nos debuelve el estudiante sobrante, es decir, al de menor nota de la lista de Admitidos
	* COMPLEJIDAD O(1)
	*/
	void obtenerSobrante(Estudiante *&e);

	/*
	* PRE: instancia creada e inicializada, preincscripcion llevada a cabo, matricula no llevada a cabo
	* POST: nos devuelve al estudiante cuyo dni coincide con el dado si bool==true y nos indica si esta admitido en esta titulacion o no
	* COMPLEJIDAD O(1)
	*/
	bool buscarEstudiante(string dni, Estudiante *&e, bool &admitido);

////////////////////////////////////////////////////////////
	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo
	* POST: copia los estudiantes admitidos al Arbol de Estudiantes admitidos, la lista de admitidos queda vacia
	* COMPLEJIDAD O(n)
	*/
	void Admitidos_a_Arbol();

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo
	* POST: copia los estudiantes en espera al Arbol de Estudiantes en espera, la lista de en espera queda vacia
	* COMPLEJIDAD O(n)
	*/
	void Espera_a_Arbol();

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo, matricula llevada a cabo
	* POST: nos devuelve todos los estudiantes de la titulacion con apellido que empiece por el apellido dado
	* COMPLEJIDAD O(1)
	*/
	void busquedaxraiz(string apellido);
////////////////////////////////////////////////////////////
	/*
	* PRE: instancia creada e inicializada
	* POST:muestra la info de la titulacion por pantalla (el valor de cada uno de sus atributos, asi como los estudiantes admitidos y en espera)
	* COMPLEJIDAD O(1)
	*/
	void mostrar();

	//***********************************
	////*******METODOS PARA FASE 03.
	//***********************************

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo, matricula llevada a cabo
	* POST: imprime la info de la titulacion al fichero vinculado al fsal pasado como parametro
	* COMPLEJIDAD O(1)
	*/
	void InfoAFichero(ofstream &fsal);

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo, matricula llevada a cabo
	* POST: nos devuelve bool=true si lo ha encontrado y 'e' es un estudiante valido
	* COMPLEJIDAD O(1)
	*/
	bool buscarAdmitidos(string apellido, string apellido2, string nombre, string dni, Estudiante *&e);

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo, matricula llevada a cabo
	* POST: saca de el arbol de espera al estudiante con mayor nota y lo inserta en el de admitidos
	* COMPLEJIDAD O(1)
	*/
	void admitirEstMayorNota();

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo, matricula llevada a cabo
	* POST: elimina del arbol de admitidos el puntero al estudiante 'e'
	* COMPLEJIDAD O(1)
	*/
	void eliminarDeAdmitidos(Estudiante *&e);

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo, matricula llevada a cabo
	* POST: elimina de el arbol de espera el puntero al estudiante 'e'
	* COMPLEJIDAD O(1)
	*/
	void eliminarDeEspera(Estudiante *&e);

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo, matricula llevada a cabo
	* POST: nos muestra la info de la titulacion con los estudiantes admitidos ordenados alfabeticamente
	* COMPLEJIDAD O(1)
	*/
	void mostrar2();

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo, matricula llevada a cabo
	* POST: nos devuelve el estudiante raiz de el arbol de admitidos
	* COMPLEJIDAD O(1)
	*/
	bool EstAleatorioAdm(Estudiante *&e);

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo, matricula llevada a cabo
	* POST: nos devuelve el estudiante raiz de el arbol de espera
	* COMPLEJIDAD O(1)
	*/
	bool EstAleatorioEsp(Estudiante *&e);

	/*
	* PRE: instancia creada e inicializada
	* POST: elimina la instancia
	* COMPLEJIDAD O(1)
	*/
	~Titulacion();
};

#endif /* TITULACION_H_ */
