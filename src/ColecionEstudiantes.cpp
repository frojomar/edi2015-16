

#include <iostream>
#include <string>

#include "EstructurasDatos/arbol.h"
#include "ColeccionEstudiantes.h"
#include "Estudiante.h"
using namespace std;

/*    METODOS PRIVADOS    */

int	comparar(Estudiante *&e1, string apellido1,string apellido2, string nombre, string dni){
		int flag = 1;										//va comparando al estudiante de la misma forma que lo compara el criterio de
		if (e1->getDni() == dni)							//ordenacion del arbol.
			flag = 0;												//Nos devuelve 1 si es mayor el estudiante que buscamos, -1 si es menor, o 0
		else {														//si es igual al estudiante de la raiz
			if (apellido1 < e1->getApellido1())
				flag = -1;
			else {
				if (e1->getApellido1() == apellido1) {
					if (apellido2 < e1->getApellido2())
						flag = -1;
					else
						if (e1->getApellido2() == apellido2)
							if (nombre <e1->getNombre())
								flag = -1;
				}
			}
		}
		return flag;
}

Arbol<Estudiante *, ComparaPtrEstudiante> * GestorEstudiantes::similares(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, const string &apel) {

	Arbol<Estudiante *, ComparaPtrEstudiante> *izq;
	Arbol<Estudiante *, ComparaPtrEstudiante> *der;
	Arbol<Estudiante *, ComparaPtrEstudiante> *aux = NULL;
	Estudiante *e;
	int pos;
	string raiz;

	if (!abbu->vacio()) { //si el arbol no esta vacio...

		e=abbu->raiz();//cogemos al estudiante de la raiz
		raiz=e->getApellido1();//cogemos su primer apellido
		pos=raiz.find(apel);//buscamos la posicion donde se encuentra la raiz dada dentro de ese apellido
		if(pos==0)//si la posicion es 0, es decir, si su apellido empieza por esa raiz, decimos que lo hemos encontrado
			aux=abbu;//copiamos al arbol de salida este arbol
		else{//si no lo hemos encontrado
			izq=abbu->hijoIzq();//copiamos en izq el arbol de la rama izquierda
			der=abbu->hijoDer();//copiamos en der el arbol de la rama derecha

			if(apel<raiz){//si la letra por la que empieza la raiz dada es menor que la del apellido del estudiante del nodo...
				if(izq!=NULL)
					aux=similares(izq, apel);//buscamos por la rama izquierda para ver si encontramos algun apellido que empiece por dicha raiz
			}
			else{//si es mayor...
				if(der!=NULL)
					aux=similares(der, apel);//buscamos por la rama derecha para ver si encontramos algun apellido que empiece por dicha raiz
			}
		}
	}
	return aux;
}



void GestorEstudiantes::filtroInOrden(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, const string &apel) {

	Arbol<Estudiante *, ComparaPtrEstudiante> *izq;
	Arbol<Estudiante *, ComparaPtrEstudiante> *der;
	Estudiante *e;
	string raiz;

	if (!abbu->vacio()) {

		e=abbu->raiz();//guardamos al estudiante de la raiz..
		raiz=e->getApellido1();//y su primer apellido

		izq=abbu->hijoIzq();//copiamos en izq el arbol de la rama izquierda
		der=abbu->hijoDer();//copiamos en der el arbol de la rama derecha
		if(izq!=NULL)
			filtroInOrden(izq,apel);//si el arbol izquierdo es no nulo nos vamos por el, ya que queremos mostrarlos en orden

		if(raiz.find(apel)==0){
			e->mostrar();//si el apellido comienza por la raiz dada, mostramos al estudiante
		}

		if(der!=NULL)
			filtroInOrden(der,apel);

	}
}



void GestorEstudiantes::inOrden (Arbol<Estudiante *, ComparaPtrEstudiante> *abbu) {

	Arbol<Estudiante *, ComparaPtrEstudiante> *aux;
	string raiz;

	if (!abbu->vacio()) {

		aux = abbu->hijoIzq();//cogemos la raiz..
		if (aux != NULL) {//nos vamos todoo a la izquierda que podamos, para encontrar al menor
			inOrden(aux);
		}

		abbu->raiz()->mostrar();//empezamos a mostrar desde la izquierda hasta la derecha

		aux = abbu->hijoDer();//nos vamos avanzando hasta la derecha todoo lo que podamos
		if (aux != NULL) {
			inOrden(aux);
		}

	}
}


bool GestorEstudiantes::buscarEstudianteR(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu,string apellido, string apellido2, string nombre, string dni, Estudiante *&e){
	bool enc=false;
	int bandera=0;
	Arbol<Estudiante *, ComparaPtrEstudiante> *izq;
	Arbol<Estudiante *, ComparaPtrEstudiante> *der;

	if(!abbu->vacio()){

		e=abbu->raiz();
		bandera=comparar(e,apellido,apellido2,nombre,dni);//comparamos el estudiante de la raiz con los datos dados

		if(bandera==0){//si es igual decimos que lo hemos encontrado y fin
			enc=true;
		}
		else{//sino..
			izq=abbu->hijoIzq();
			der=abbu->hijoDer();

			if(izq!=NULL && bandera==-1)//si es menor y podemos tirar por esa rama, nos vamos por la izquierda a buscarlo
				enc=buscarEstudianteR(izq,apellido,apellido2,nombre, dni, e);
			if(der!=NULL && bandera==1)//si es mayor y podemos tirar por esa rama, nos vamos por la derecha a buscarlo
				enc=buscarEstudianteR(der,apellido,apellido2,nombre,dni,e);
		}
	}
	return enc;
}

void GestorEstudiantes::sacarEstMayorNotaR(Arbol<Estudiante *, ComparaPtrEstudiante> *abbu, Estudiante *&e){
	Arbol<Estudiante *, ComparaPtrEstudiante> *izq;
	Arbol<Estudiante *, ComparaPtrEstudiante> *der;
	Estudiante *eaux;
	if(!abbu->vacio()){

		eaux=abbu->raiz();

		if((eaux->getNota())>(e->getNota())){//vamos probando uno a uno, con todos los estudiantes, cual tiene la mayor nota, comparando uno a uno
			e=eaux;
		}
		izq=abbu->hijoIzq();
		der=abbu->hijoDer();

		if(izq!=NULL)//nos movemos por todos los nodos
			sacarEstMayorNotaR(izq, e);
		if(der!=NULL)
			sacarEstMayorNotaR(der,e);
	}

}


int GestorEstudiantes::contar(Arbol<Estudiante *, ComparaPtrEstudiante> *abb) {
	Arbol<Estudiante *, ComparaPtrEstudiante> *izq;
	Arbol<Estudiante *, ComparaPtrEstudiante> *der;
	int cuantos = 0;

	if(!abb->vacio()){
		izq=abb->hijoIzq();
		der=abb->hijoDer();

		cuantos++;//por cada nodo que pasemos el contador aumentara 1

		if(izq!=NULL)//nos movemos por todos los nodos, para no dejar ninguno sin contar
			cuantos=cuantos+contar(izq);

		if(der!=NULL)
			cuantos=cuantos+contar(der);
	}

	return cuantos;

}
/*    IMPLEMENTACION    */

GestorEstudiantes::GestorEstudiantes() {

	abb_estudiantes = new Arbol<Estudiante *, ComparaPtrEstudiante>();

}

void GestorEstudiantes::mostrarSimilares(const string &apel) {

	Arbol<Estudiante *, ComparaPtrEstudiante> *abb;

	if (!abb_estudiantes->vacio()) {

		abb = this->similares(abb_estudiantes, apel);
		if (abb != NULL) {
			//cout << "Mostrando similares a: " << apel << endl;
			filtroInOrden(abb, apel);
		} else {
			//cout << "Nadie que empiece por: " << apel << endl;
		}
	}
}

void GestorEstudiantes::mostrar () {
	inOrden(abb_estudiantes);
}

void GestorEstudiantes::insertar(Estudiante *&e){
	abb_estudiantes->insertar(e);
}

bool GestorEstudiantes::buscarEstudiante(string apellido, string apellido2, string nombre, string dni, Estudiante *&e){
	Arbol<Estudiante *, ComparaPtrEstudiante> *abb;
	bool enc=false;

	if (!abb_estudiantes->vacio()) {

		//abb = this->similares(abb_estudiantes, apellido);//obtenemos un arbol donde el primer apellido de la raiz coincide con el que buscamos
		abb=abb_estudiantes;
		if (abb != NULL) {//
			enc=this->buscarEstudianteR(abb,apellido, apellido2, nombre,dni, e);//ya tenemos el arbol donde estan los apellidos igual al dado, ahora abuscar el DNI correcto
		}
		else {
			enc=false;
		}
	}
	return enc;
}
void GestorEstudiantes::sacarEstMayorNota(Estudiante *&e){

	e=abb_estudiantes->raiz();//ponemos que la mayor nota es la de la raiz,

	this->sacarEstMayorNotaR(abb_estudiantes,e);//comparamos este estudiante con los que hay en el arbol, para obtener el verdadero mayor
	abb_estudiantes->borrar(e);//una vez tengamos al estudiante, borramos el puntero a el del arbol
}
int GestorEstudiantes::cuantos(){
	return this->contar(abb_estudiantes);
}

void GestorEstudiantes::eliminar(Estudiante *&e){
	abb_estudiantes->borrar(e);
}

bool GestorEstudiantes::tieneEstudiantes(){
	return !abb_estudiantes->vacio();
}

void GestorEstudiantes::obtenerAleatorio(Estudiante *&e){
	e=abb_estudiantes->raiz();
}

GestorEstudiantes::~GestorEstudiantes() {

	delete abb_estudiantes;
}

