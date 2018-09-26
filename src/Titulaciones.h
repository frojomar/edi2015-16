/*
 * Titulaciones.h
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#ifndef TITULACIONES_H_
#define TITULACIONES_H_
#include "EstructurasDatos/listapi.h"
#include <fstream>
#include <sstream>
#include "Titulacion.h"

class Titulaciones {
private:
	ListaPI<Titulacion *> *montonTitulaciones;
public:

	//***********************************
	////*******CONSTRUCTORES.
	//***********************************

	/*
	* PRE: instancia creada, 'titulaciones.txt' existe en la carpeta del proyecto
	* POST:inicializa los atributos de la instancia con los datos tomados de 'titulaciones.txt'
	* COMPLEJIDAD O(n)
	*/
	Titulaciones();

	/*
	* PRE: instancia creada
	* POST:inicializa los atributos de la instancia con unos valores especificos especialmente pensados para las pruebas
	* COMPLEJIDAD O(1)
	* //constructor que uso en las pruebas. Con bandera!=0 0 !=-1 solo reserva memoria,
	*  y con 0 o -1 se crea con una lista de titulaciones especifica
	*/
	Titulaciones(int bandera);//constructor creado para las pruebas, que tan solo reserva memoria o crea unas titulaciones especificas si bandera=0 o -1



	//***********************************
	////*******PARA LAS OPCIONES DEL MENU.
	//***********************************

	/*
	* PRE: instancia creada e inicializada, el codigo dado debe coincidir con alguna titulacion para saber que albergara t
	* POST: busca en la lista la titulacion cuyo ccodigo coincide con el dado y nos devuelve un puntero a esta
	* COMPLEJIDAD O(n)
	*/
	void seleccionarTitulacion(int cod, Titulacion *&t);//FUNCION 1

	/*
	* PRE: instancia creada e inicializada, matricula no llevada a cabo si queremos que nos muestre las listas con los estudiantes en ellas, preinscricion lelvada a cabo
	* POST: busca en la lista la titulacion cuyo ccodigo coincide con el dado y, si la encuentra, muestra la info de esta, sino, nos lo indica
	* COMPLEJIDAD O(n)
	*/
	void infoTitulacion(int cod);//FUNCION 2

	/*
	* PRE: instancia creada e inicializada, matricula no llevada a cabo, preinscripcion llevada a cabo
	* POST: busca en las titulaciones al estudiante cuyo dni coincida con el dado, diciendonos que no lo ha encontrado si no lo encuentra
	* COMPLEJIDAD O(n)
	*/
	void buscarEstudiante(string dni);//FUNCION 3

//////////////////////////////////////////////////////
	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo, matricula llevada a cabo
	* POST: busca en las titulaciones todos aquellos estudiantes cuyo apellido empiece por la raiz dada
	* COMPLEJIDAD O(n)
	*/
	void busquedaxraiz(string apellido);//FUNCION 4
////////////////////////////////////////////////////////

	/*
	* PRE: instancia creada e inicializada, preinscripcion llevada a cabo
	* POST: matricula a los estudiantes de todas las titulaciones
	* COMPLEJIDAD O(n)
	*/
	void matricula();//FUNCION 5

	/*
	* PRE: instancia creada e inicializada
	* POST: nos muestra las notas de Corte de todas las titulaciones junto al nombre de la titulacion, siendo 0 la nota si no contienen estudiantes en admitidos
	* COMPLEJIDAD O(n)
	*/
	void notasCorte();//FUNCION 6

	//***********************************
	////*******OTROS METODOS.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST: inserta un puntero a una titulacion dentro de la lista de punteros a titulaciones
	* COMPLEJIDAD O(1)
	*/
	void insertar(Titulacion *t);

	/*
	* PRE: instancia creada e inicializada
	* POST:muestra como quedan todas las titulaciones con sus listas de admitidos y espera tras preinscribir (si no hemos preinscrito, estas listas estaran vacias)
	* COMPLEJIDAD O(n)
	*/
	void mostrar();

	//***********************************
	////*******METODOS PARA FASE 03.
	//***********************************

	/*
	* PRE: instancia creada e inicializada
	* POST: nos devuelve el numero de titulacion que hay en la lista
	* COMPLEJIDAD O(1)
	*/
	int cuantas();

	/*
	* PRE: instancia creada e inicializada, matricula llevada a cabo
	* POST: vimprimer en el fichero correspondiente a fsal la info de la titulacion 'codtit'
	* COMPLEJIDAD O(1)
	*/
	void InfoAFicheros(ofstream &fsal, int codtit);

	/*
	* PRE: instancia creada e inicializada, matricula llevada a cabo
	* POST: elimina los punteros de los arboles de espera a estudiante 'e', excepto de la titulacion con codigo 'codtit'
	* COMPLEJIDAD O(1)
	*/
	void eliminarDeRestoTitulaciones(Estudiante *&e,int codtit);

	/*
	* PRE: instancia creada e inicializada, matricula llevada a cabo
	* POST: nos muestra la info de la titulacion con codigo 'codtit' con el arbol de admitidos
	* COMPLEJIDAD O(1)
	*/
	void infoTitulacion2(int cod);

	~Titulaciones();
};

#endif /* TITULACIONES_H_ */
