/*
 * Titulaciones.cpp
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include "Titulaciones.h"

int aInt(string cad){
	stringstream flujo;
	int numero;
	flujo<< cad;
	flujo>> numero;
	return numero;
}

Titulaciones::Titulaciones(int bandera){
	this->montonTitulaciones= new ListaPI<Titulacion *>();

	if(bandera==0){//crea la lista de titulaciones con estas siete titulaciones
		Titulacion *t;

		t=new Titulacion(01, "Grado en Ingenieria Informática en Ingeniería del Software", 5);
		montonTitulaciones->insertar(t);

		t=new Titulacion(02, "Grado en Ingenieria Informática en Ingeniería del Computadores", 6);
		montonTitulaciones->insertar(t);

		t=new Titulacion(03, "Grado en Ingenieria de Sonido e Imagen en Telecomunicacion", 7);
		montonTitulaciones->insertar(t);

		t=new Titulacion(04, "Grado en Ingenieria Civil Construcciones Civiles", 2);
		montonTitulaciones->insertar(t);

		t=new Titulacion(05, "Grado en Ingenieria Civil Hidrologia", 3);
		montonTitulaciones->insertar(t);

		t=new Titulacion(06, "Grado en Ingenieria Civil Transportes y Servicios Urbanos", 2);
		montonTitulaciones->insertar(t);

		t=new Titulacion(07, "Grado en Edificación",3);
		montonTitulaciones->insertar(t);
	}

	if(bandera==-1){//crea la lista de titulaciones con estas tres titulaciones
		Titulacion *t;

		t=new Titulacion(01, "T1", 3);
		montonTitulaciones->insertar(t);

		t=new Titulacion(02, "T2", 2);
		montonTitulaciones->insertar(t);

		t=new Titulacion(03, "T3", 3);
		montonTitulaciones->insertar(t);
	}
}

Titulaciones::Titulaciones() {//crea la lista con las titulaciones que se encuentran en 'titulaciones.txt'
	ifstream fent;
	string cod, nombre, plazas;
	this->montonTitulaciones = new ListaPI<Titulacion *>();
	Titulacion *t;
	fent.open("titulaciones.txt");//abrimos el fichero
	if(fent.is_open()){
		while(!fent.eof()){					//vamos leyendo cada linea de fichero de texto, separando las cadeanas por cada '#'
			getline(fent,cod,'#');			//cada titulacion la creamos con la info de una linea completa del fichero
			if(!fent.eof()){
				getline(fent,nombre,'#');
				getline(fent,plazas);

			t= new Titulacion(aInt(cod),nombre,aInt(plazas)); //vamos insertando las titulaciones creadas con 'insertar'
			this->insertar(t);
			}
		}
		fent.close();//cerramos el fichero
	}
}

void Titulaciones::insertar(Titulacion *t){
	montonTitulaciones->moverFinal();//insertamos las titulaciones al final de la lista segun van "llegando"
	montonTitulaciones->avanzar();
	montonTitulaciones->insertar(t);
}

void Titulaciones::seleccionarTitulacion(int cod, Titulacion *&t){
	bool encontrado=false;

	montonTitulaciones->moverInicio();
	while(!montonTitulaciones->finLista() && !encontrado){//buscamos desde el inicio de la lista hasta el final o hasta encontrarla
		montonTitulaciones->consultar(t);
		if(t->getCodigo()==cod)
			encontrado=true;//si la encontramos lo indicamos y salimos, para mantener en t esa titulacion y no la siguiente
		montonTitulaciones->avanzar();
	}
	if(!encontrado){//si hemos salido por llegar al final de la lista y no por encontrarla indicamos que ha habido un problema
		cout<<"PROBLEMA DETECTADO: CODIGO DE TITULACION NO VALIDO"<<endl;//pues en las precondiciones se indica que el codigo debe coincidir con alguna titulacion existente
	}

}

void Titulaciones::infoTitulacion(int cod){//FUNCION 2
	Titulacion *t;
	bool encontrado=false;

	montonTitulaciones->moverInicio();						//el procedimiento a seguir es el mismo que en 'seleccionarTitulacion', con la diferencia
	while(!montonTitulaciones->finLista() && !encontrado){	//de que aqui no devolvemos la titulacion, sino que mostramos su info al encontrarla
		montonTitulaciones->consultar(t);
		if(t->getCodigo()==cod){
			t->mostrar();
			encontrado=true;
		}
		montonTitulaciones->avanzar();
	}
	if(!encontrado){//si no la hemos encontrado se indica
		cout<<" --Titulacion no encontrada"<<endl;
	}
}

void Titulaciones::buscarEstudiante(string dni){//FUNCION 3
	Estudiante *e;
	Titulacion *t;
	bool encontrado=false;				//el procedimiento a seguir es el siguiente
	bool admitido=false;

	montonTitulaciones->moverInicio();
	while(!montonTitulaciones->finLista() && !encontrado){//primero lo buscamos para ver si lo encontramos
		montonTitulaciones->consultar(t);
		encontrado=t->buscarEstudiante(dni, e, admitido);
		if(encontrado)
			e->mostrar();
		montonTitulaciones->avanzar();
	}									//si lo encontramos en una titulacion, sea la que sea, hemos mostrado su info y ya pasamos a buscarlo en todas
	if(encontrado){
		cout<< "--Admitido en:"<<endl;//buscamos en todas las titulaciones, y aquellas en las que sea encontrado, si admitido==true, se muestra el nombre de esta

		montonTitulaciones->moverInicio();
		while(!montonTitulaciones->finLista()){
			montonTitulaciones->consultar(t);
			encontrado=t->buscarEstudiante(dni, e, admitido);
			if(encontrado && admitido)
				cout<<"    "<<t->getNombre()<<endl;
			montonTitulaciones->avanzar();
		}

		cout<< "--En espera en:"<<endl;//lo mismo que antes, pero ahora se muestra el nombre cuando encontrado==true y admitido==false

		montonTitulaciones->moverInicio();
		while(!montonTitulaciones->finLista()){
			montonTitulaciones->consultar(t);
			encontrado=t->buscarEstudiante(dni, e, admitido);
			if(encontrado && !admitido)
				cout<<"    "<<t->getNombre()<<endl;
			montonTitulaciones->avanzar();
		}
	}
	else{
		cout<<"	---Estudiante no encontrado"<<endl;//si no lo hemos encontrado lo indicamos
	}
}

void Titulaciones::busquedaxraiz(string apellido){//FUNCION 4
	Titulacion *t;

	montonTitulaciones->moverInicio();//nos movemos al inicio de la lista de titulaciones
	while(!montonTitulaciones->finLista()){//mientras no estemos en el fin (hayamos pasado por todas las listas), por cada titulacion...
		montonTitulaciones->consultar(t);//obtenemos la titulacion
		t->busquedaxraiz(apellido);//buscamos a los estudiantes "coincidentes" en la titulacion en cuestion
		cout<<endl;
		montonTitulaciones->avanzar();
	}
}

void Titulaciones::matricula(){//FUNCION 5
	Titulacion *t;

	montonTitulaciones->moverInicio();//nos movemos al inicio de la lista de titulaciones
	while(!montonTitulaciones->finLista()){//mientras no estemos en el fin (hayamos pasado por todas las listas), por cada titulacion...
		montonTitulaciones->consultar(t);//obtenemos la titulacion
		t->Admitidos_a_Arbol();//volcamos la lista de admitidos al arbol de admitidos
		t->Espera_a_Arbol();//volcamos la lista de en espera al arbol de en espera
		montonTitulaciones->avanzar();
	}
}

void Titulaciones::notasCorte(){//FUNCION 6
	Titulacion *t;

	montonTitulaciones->moverInicio();
	while(!montonTitulaciones->finLista()){//recorremos la lista mostrando el nombre de cada titulacion y su nota de corte
		montonTitulaciones->consultar(t);
		cout<<t->getNombre()<<"    "<<t->getNota_corte()<<endl;
		montonTitulaciones->avanzar();
	}
}

//FUNCION 7

void Titulaciones::mostrar(){
	Titulacion *t;

	montonTitulaciones->moverInicio();
	while(!montonTitulaciones->finLista()){//recorremos toda la lista mostrando la info de cada titulacion
		montonTitulaciones->consultar(t);
		t->mostrar();
		cout<<endl;
		montonTitulaciones->avanzar();
	}
}

int Titulaciones::cuantas(){
	int cont=0;

	montonTitulaciones->moverInicio();
	while(!montonTitulaciones->finLista()){//recorremos toda la lista sumando
		cont++;
		montonTitulaciones->avanzar();
	}

	return cont;
}

void Titulaciones::InfoAFicheros(ofstream &fsal, int codtit){
	Titulacion *t;

	montonTitulaciones->moverInicio();
	while(!montonTitulaciones->finLista()){//recorremos toda la lista imprimiendo para cada titulacion si info al fichero mediante el metodo..
		montonTitulaciones->consultar(t);
		if(t->getCodigo()==codtit)
			t->InfoAFichero(fsal);//..adecuado de Titulacion
		montonTitulaciones->avanzar();
	}

}

void Titulaciones::eliminarDeRestoTitulaciones(Estudiante *&e,int codtit){
	Titulacion *t;

	montonTitulaciones->moverInicio();
	while(!montonTitulaciones->finLista()){//vamos moviendonos por la lista
		montonTitulaciones->consultar(t);
		if(t->getCodigo()!=codtit){//cuando encontramos una cuyo codigo no coincida con 'codtit'..
			t->eliminarDeAdmitidos(e);//podriamos comprobar si pertenece el estudiante para no llamar a eliminar si no esta, pero esto ya nos obligaria a recorrer el arbol, por lo que nos quedariamos en las mismas
			t->eliminarDeEspera(e);//eliminamos al estudiante de espera
		}
		montonTitulaciones->avanzar();
	}
}

void Titulaciones::infoTitulacion2(int cod){
	Titulacion *t;
	bool encontrado=false;

	montonTitulaciones->moverInicio();						//el procedimiento a seguir es el mismo que en 'seleccionarTitulacion', con la diferencia
	while(!montonTitulaciones->finLista() && !encontrado){	//de que aqui no devolvemos la titulacion, sino que mostramos su info al encontrarla
		montonTitulaciones->consultar(t);
		if(t->getCodigo()==cod){
			t->mostrar2();
			encontrado=true;
		}
		montonTitulaciones->avanzar();
	}
	if(!encontrado){//si no la hemos encontrado se indica
		cout<<" --Titulacion no encontrada"<<endl;
	}
}

Titulaciones::~Titulaciones() {

	Titulacion *t;
	Estudiante *e;

	montonTitulaciones->moverInicio();
	while (!montonTitulaciones->finLista()) {	//para cada titulacion...
		montonTitulaciones->consultar(t);
			t->Admitidos_a_Arbol();	//volcamos todos los estudiantes a los arboles (por si acaso no se ha llevado a cabo matricula)
			t->Espera_a_Arbol();
			while(t->EstAleatorioAdm(e)){	//mientras el arbol contenga estudiantes, sacamos uno aleatorio
				t->eliminarDeAdmitidos(e);
				this->eliminarDeRestoTitulaciones(e, t->getCodigo());
				delete e;	//eliminamos el estudiante como tal
			}
		montonTitulaciones->avanzar();
		//no eliminamos aqui la titulacion, pues nos quedarian aun estudiantes en espera de esta titulacion que nos podria dar problemas eliminar, pues pueden estar admitidos en otra titulacion aun no procesada
	}

	//eliminamos los estudiantes que no estan admitidos en ninguna titulacion, y, que por tanto, han quedado en las listas de espera.
	montonTitulaciones->moverInicio();
	while (!montonTitulaciones->finLista()) {	//para cada titulacion...
		montonTitulaciones->consultar(t);
			while(t->EstAleatorioEsp(e)){	//mientras el arbol contenga estudiantes, sacamos uno aleatorio
				this->eliminarDeRestoTitulaciones(e,-1); //le pasamos -1 porque sabemos que ninguna titulacion tendra este codigo, por lo que pasara por el arbol de espera de todas, eliminando los punteros a este estudiante de aquellas en las que se encuentre
				delete e;	//eliminamos el estudiante como tal
			}
		montonTitulaciones->avanzar();
		//ahora ya elimino los que no estaban admitidos en ninguna titulacion
	}

	//una vez hemos quedado las listas de admitidos y de espera de todas las titulaciones vacia eliminamos las titulaciones
	montonTitulaciones->moverInicio();
	while (!montonTitulaciones->finLista()) {//vamos sacando punteros de la lista y eliminando la memoria asociada
		montonTitulaciones->consultar(t);
		delete t;//con esto llamamos al destructor de Titulacion
		montonTitulaciones->borrar();
	}
	delete montonTitulaciones;
}

