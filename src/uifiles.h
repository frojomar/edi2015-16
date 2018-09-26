//============================================================================
// Name        : user uifiles.h
// Author      : Profesores de la asignatura EDI, Modificaciones por FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
// Version     : Curso 15/16
// Copyright   : Your copyright notice
// Description : Definición de la clase user interface
//============================================================================

#ifndef UIFILES_H_
#define UIFILES_H_
#include "ElZarzal.h"
#include "Pruebas/Pruebas.h"
#include <cstring>

/**
 * Clase de manejo del menú de la Universidad de El Zarzal
 */

class UIFILES{

private:

	ElZarzal *z; //tan solo contara con un puntero a una clase El Zarzal

	void pruebas();//PRUEBAS
	void preinscripcion();//FUNCION 1
	void consultarTitulacion();//FUNCION 2
	void consultarEstudiante();//FUNCION 3
	void matricula();//FUNCION 4
	void proceso_matricula();//FUNCION 5
	void consultarTitulacionMatricula();//FUNCION 6
	void busquedaXraiz();//FUNCION 7
	void notasCorte();//FUNCION 8
	int  menu     ();//menu desde donde se muestran las opciones y se lee la opcion introducida por consola
	void ejecutar ();//menu desde el que se compara la opcion introducida con las posibles y se nos manda a la funcion adecuada

public:
   
	 UIFILES();		//solo tenemos como publicos estos dos metods, pues una vez creemos e inicialicemos una instancia de la interfaz
	 	 	 	 	 //el propio constructor nos mandara al menu de ejecucion, del que saldremos cuando pulsemos finalizar
	 	 	 	 	 //es ahi cuando volveremos al main donde se ejecutara el segundo metodo publico, el destructor.
	 ~UIFILES();
	 
};

#endif /* UIFILES_H_ */
