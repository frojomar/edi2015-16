/*
 * ListaEstudiantes.cpp
 *
 *  Created on: 14/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include "ListaEstudiantes.h"

ListaEstudiantes::ListaEstudiantes() {
	EstTit=new ListaPI<Estudiante *>();
}

void ListaEstudiantes::SacarPrimero(Estudiante *&e){
	if(!EstTit->estaVacia()){  //si la lista no esta vacia...
		EstTit->moverInicio();//nos movemos al inicio
		EstTit->consultar(e);//copiamos al puntero de salida la informacion de esa posicion
		EstTit->borrar();//eliminamos el puntero que albergaba dicha posicion
	}
}

void ListaEstudiantes::SacarUltimo(Estudiante *&e){
	if(!EstTit->estaVacia()){//el procedimiento a seguir es el mismo que en 'SacarPrimero' pero, en lugar de mover a inici, movemos al final
		EstTit->moverFinal();
		EstTit->consultar(e);
		EstTit->borrar();
	}
}

bool ListaEstudiantes::InsertarPos(Estudiante *e){
	bool insertado=false;
	Estudiante *eaux;									//el algoritmo empleado en este metodo es...

	if(!EstTit->estaVacia()){//si la lista no esta vacia...
		EstTit->moverInicio();							//nos posicionamos en el principio de la lista (nota+alta)
		while(!EstTit->finLista() && !insertado){	//vamos avanzando hasta llegar al final o lograr insertar
			EstTit->consultar(eaux);
			if(e->getNota()>eaux->getNota()){//vamos consultando la nota de los estudiantes asociados a los punteros de cada nodo
				EstTit->insertar(e);		//cuando encontremos un estudiante con nota menor que el estudiante a insertar...
				insertado=true;		//es hay donde debemos insertar el puntero a nuestro nuevo estudiante
			}
			EstTit->avanzar();
		}
		if(!insertado){//si hemos llegado al final sin poder encontrar alguien con nota menor...
			EstTit->insertar(e); //insertamos al nuevo estudiante en el fin de la lista
			insertado=true;
		}
	}
	else{//en caso de que la lista este vacia...
		EstTit->insertar(e);//es tan sencillo como insertarlo sin ningun tipo de comparacion ni nada similar
		insertado=true;
	}
	return insertado;
}

float ListaEstudiantes::notaMinima(){
	Estudiante *e;
	float minima=0;
	if(!EstTit->estaVacia()){
		EstTit->moverInicio();				//teniendo en cuenta que la lista esta ordenada descendientemente, podriamos movernos al final de...
		EstTit->consultar(e);				//la lista y consultar la nota, sabiendo que esta seria la minima
		minima=e->getNota();
		EstTit->avanzar();					//Pero este algoritmo esta pensado para que, si alguna vez, queremos que la lista deje de estar...
		while(!EstTit->finLista()){			//ordenada, podamos seguirlo usando para obtener la notaMinima
			EstTit->consultar(e);
			if(minima>e->getNota())			//Consiste en ir avanzando desde el principio, consultando la nota de los estudiantes para compararla...
				minima=e->getNota();		//con la minima de hasta aquel momento, de modo que cuando lleguemos al final hayamos pasado por todas...
			EstTit->avanzar();				//las notas, teniendo por tanto, sin lugar a dudas, la nota minima
		}
	}
	return minima;
}

int ListaEstudiantes::cuantos(){
	int cuantos=0;

	EstTit->moverInicio();			//se mueve al inicio y va contando por cuantas posiciones pasa hasta llegar al fin lista
	while(!EstTit->finLista()){
		cuantos++;
		EstTit->avanzar();
	}
	return cuantos;	//de esta forma devolvemos cuantos nodos hay (cuantos estudiantes hay)
}

bool ListaEstudiantes::buscarEstudiante(string dni, Estudiante *&e){
	bool encontrado=false;

	EstTit->moverInicio();							//se mueve al inicio de la lista y va comparando el DNI de cada estudiante hasta que...
	while(!EstTit->finLista() && !encontrado){		//encuentra al estudiante o llega a fin lista.
		EstTit->consultar(e);
		if(dni==e->getDni())						//En caso de encontrarlo, el bool==true nos indica que el puntero que hay en *e es...
			encontrado=true;						//ciertamente el estudiante buscado
		EstTit->avanzar();
	}
	return encontrado;
}
/*
bool ListaEstudiantes::busquedaxraiz(string nombre){
	Estudiante *e;
	string cad1;
	bool encontrado=false;

	EstTit->moverInicio();
	while(!EstTit->finLista()){
		EstTit->consultar(e);
		cad1=e->getNombre();
		if(cad1.find(nombre)==0){
			encontrado=true;
			e->mostrar();
		}
		EstTit->avanzar();
	}
	return encontrado;
}*/

void ListaEstudiantes::mostrar(){
	Estudiante *e;

	EstTit->moverInicio();			//nos movemos al inicio de la lista...
	while(!EstTit->finLista()){// y, hasta que lleguemos al final,...
		EstTit->consultar(e);
		e->mostrar();			//iremos consultando y llamando al mostrar de Estudiante
		EstTit->avanzar();
	}
}

ListaEstudiantes::~ListaEstudiantes() {
	Estudiante *e;
	EstTit->moverInicio();				//vamos consultando los punteros de la lista
	while(!EstTit->finLista()){		//eliminamos la memoria asociada a dichos punteros y sacamos el puntero de la lista...
		EstTit->consultar(e);	//hasta que quedamos la lista vacia...
		delete e;
		EstTit->borrar();
	}
	delete EstTit;	//que es cuando eliminaremos el puntero a dicha lista
}

