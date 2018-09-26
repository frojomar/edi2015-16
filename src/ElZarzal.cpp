/*
 * ElZarzal.cpp
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include "ElZarzal.h"
//METODOS PRIVADOS/*

int toInt(string cad){
	stringstream flujo;
	int numero;
	flujo<< cad;
	flujo>> numero;
	return numero;
}

string toString (int numero){
	stringstream flujo;
	string cadena;
	flujo<< numero;
	flujo>> cadena;
	return cadena;
}

void ElZarzal::renuncia(int codtit, string apel, string apellido2, string nombre, string dni){
	Titulacion *t;
	Estudiante *e;
	bool enc;

	ListaTitulaciones->seleccionarTitulacion(codtit, t);//buscamos la titulacion con codigo 'codtit'

	enc=t->buscarAdmitidos(apel, apellido2, nombre, dni, e);//buscamos al estudiante en la lista de admitidos de la titulacion en cuestion

	if(enc){
		t->eliminarDeAdmitidos(e);//elimina el puntero que apunta a el de la titulacion en cuestion
		ListaTitulaciones->eliminarDeRestoTitulaciones(e,codtit);//elimina los punteros que apuntan a el de las otras las titulaciones
		delete e;//elimina al estudiante
		t->admitirEstMayorNota();

	}
	else{//si el estudiante no se encuentra admitido en la titulacion dada, lo indicamos
		cout<<"--El Estudiante "<<apel<<" "<<apellido2<<", "<<nombre<<" con DNI"<<dni<< " NO esta ADMITIDO en la titulacion "<<codtit<<". "<<t->getNombre()<<endl;
	}

}

void ElZarzal::seMatricula(ofstream &fsal,int codtit, string apel, string apellido2, string nombre, string dni){
	Titulacion *t;
	Estudiante *e;
	bool enc;

	ListaTitulaciones->seleccionarTitulacion(codtit, t);//buscamos la titulacion con codigo 'codtit'

	enc=t->buscarAdmitidos(apel, apellido2, nombre, dni, e);//buscamos al estudiante en la lista de admitidos de la titulacion en cuestion

	if(enc){
		e->infoAFichero(fsal);//imprimimos su info al fichero adecuado
		t->eliminarDeAdmitidos(e);//elimina el puntero que apunta a el de la titulacion en cuestion
		ListaTitulaciones->eliminarDeRestoTitulaciones(e,codtit);//elimina los punteros que apuntan a el de las otras las titulaciones
		delete e;//elimina al estudiante
	}
	else{//si el estudiante no se encuentra admitido en la titulacion dada, lo indicamos
		cout<<"--El Estudiante "<<apel<<" "<<apellido2<<", "<<nombre<<" con DNI"<<dni<< " NO esta ADMITIDO en la titulacion "<<codtit<<". "<<t->getNombre()<<endl;
	}
}

//METODOS PUBLICOS

ElZarzal::ElZarzal(int bandera){
	EstudiantesPre=new Estudiantes(bandera); //llama al constructor de la pila de preincritos con el valor de bandera dado
	ListaTitulaciones=new Titulaciones(bandera);//llama al constructor de la lista de titulaciones con el valor de bandera dado
}

ElZarzal::ElZarzal() {
	EstudiantesPre=new Estudiantes();//llama al constructor por defecto de Estudiantes
	ListaTitulaciones=new Titulaciones();//llama al constructor por defecto de Titulaciones
}
void ElZarzal::asignar(Estudiante *&e){
	Titulacion *t;
	Estudiante *eaux;
	int codigo=0;

	if(e->tieneSolicitudes() && !e->getAdmitido()){//solo realiza la asignacion si el estudiante no ha sido admitido ya (cosa que no ha pasado si esta en este proceso) y si tiene solicitudes en la cola de solicitudes
		codigo=e->primeraSolicitud();//obtenemos la primera solicitud
		ListaTitulaciones->seleccionarTitulacion(codigo,t);//seleccionamos la titulacion acorde a esta solicitud
		if(!t->plazasLlenas()){//lo insertamos directamente en admitidos si la titulacion no esta llena
			t->insertarAdmitido(e);
		}
		else{// en caso de que este llena...
			if(t->cumpleNota(e)){//si su nota es mayor que la de corte...
				t->insertarAdmitido(e);//lo insertamos en admitidos
				t->obtenerSobrante(eaux);//sacamos al que mas baja nota tiene de esta
				t->actualizarNotaCorte();//actualizamos a la nueva nota de corte, pues ahora la nota mas baja no es la misma que antes
				t->insertarEspera(eaux);//insertamos en espera al estudiante que hemos sacado de admitidos
				asignar(eaux);//llamamos a asignar con ese esudiante que hemos sacado, para que en caso de que tenga mas solicitudes, se siga procesando
			}
			else//en caso de que no cumpla la nota...
				t->insertarEspera(e);//lo insertamos en la lista de espera de esa titulacion
				asignar(e);// lo volvemos a procesar llamando a asignar de nuevo con el, para que, en caso de tener mas solicitudes, se les procesen hasta que se quede sin ninguna o entre en admitido en alguna
		}
	}
}

void ElZarzal::preinscripcion(){
	Estudiante *e;

	while(!EstudiantesPre->vacia()){//saca estudiantes de la pila de preinscritos y va llamando al metodo privado de esta clase de asignar
		EstudiantesPre->sacarPrimero(e);
		this->asignar(e);
	}
}

void ElZarzal::notasCorte(){
	ListaTitulaciones->notasCorte();//llama a la funcion de la clase Titulaciones que muestra la info de todas las titulaciones que esta alberga
}

void ElZarzal::matricula(){
	ListaTitulaciones->matricula();//llama a la funcion de la clase Titulaciones que matricula a los alumnos da cada una de las titulaciones de la universidad
	cout<<"	--Matricula llevada a cabo"<<endl;
}

void ElZarzal::consultarEstudiante(string dni){
	ListaTitulaciones->buscarEstudiante(dni);//llama al metodo de Titulaciones que busca dentro de sus titulaciones a los estudiantes por el DNI
}

void ElZarzal::busquedaXraiz(string raiz){
	ListaTitulaciones->busquedaxraiz(raiz);//llama a la funcion de la clase Titulaciones que busca en todas las titulaciones a los alumnos cuyo apellido empieze por la raiz dada
}

void ElZarzal::consultarTitulacion(int cod){
	ListaTitulaciones->infoTitulacion(cod);//llama al metodo de Titulaciones que busca la titulaciones que le estamos indicando y muestra su info
}

void ElZarzal::mostrar1(){
	EstudiantesPre->mostrar();//llama al mostrar de Estudiantes
}

void ElZarzal::mostrar2(){
	ListaTitulaciones->mostrar();//llama al mostrar de Titulaciones
}

void ElZarzal::proceso_matricula(){
	cout<<"	--Proceso de matricula iniciado"<<endl;
		ifstream fent;
		string nombreF,comando, apellido, apellido2, nombre, dni, codigo="";
		int contador, codtit;
		//antes de esto se deben definir tantos flujos de escritura como titulaciones existan
		//se deben pasar como parametro de entrada salida estos flujos tambien a traves de las llamadas a renuncia y seMatricula
		//se debe llamar a una funcion que escriba, para cada fichero, la info de su titulacion al principio
		contador=ListaTitulaciones->cuantas();

		ofstream fsal[contador];//se definen tantos flujos de salida como titulaciones haya

		for(int i=0; i<contador; i++){
			nombreF="0"+toString(i+1)+".txt";//se abren tantos como se hayan definido
			fsal[i].open(nombreF.c_str());
			if(!fsal[i].is_open())
				cout<<"ERROR AL ABRIR EL FICHERO DE ESCRITURA DE LA TITULACION"<<i+1<<endl;
		}
		for(int i=0; i<contador; i++){
			ListaTitulaciones->InfoAFicheros(fsal[i],i+1);
		}

		fent.open("matyrenuncias.txt");
		if(fent.is_open()){//abrimos el fichero
			while(!fent.eof()){//vamos leyendo cada linea de fichero de texto, separando las cadenas por cada '#'
				getline(fent,comando, '#');		//leemos el comando a hacer
				if(!fent.eof()){
					getline(fent, codigo, '#');	//leemos la titulacion sobre la que lo quiere hacer
					getline(fent,apellido, '#');//guardamos el primer apellido
					getline(fent,apellido2, '#');	//guardamos momentaneamente en dni el segundo apellido
					getline(fent,nombre, '#');	//guardamos momentaneamente en dni el nombre
					getline(fent,dni);	//guardamos en dni el dni
				}
				if(comando=="REN"){
					codtit=toInt(codigo);
					this->renuncia(codtit,apellido,apellido2,nombre,dni);
				}
				else{
					if(comando=="MAT"){
						codtit=toInt(codigo);
						this->seMatricula(fsal[codtit-1],codtit,apellido,apellido2,nombre,dni);
					}
					else{
						cout<<"--Comando erroneo en 'matryrenuncias.txt'"<<endl;
					}
				}
			}
			fent.close();
		}

		for(int i=0; i<contador; i++){
			fsal[i].close();//se cierran tantos como se hayan abierto
		}
		//ListaTitulaciones->actualizarNotasCorteArb(); En este punto se supone que deberia estar vacios los arboles
	cout<<"	--Proceso de matricula finalizando"<<endl;

}

void ElZarzal::consultarTitulacionMatricula(int cod){
	ListaTitulaciones->infoTitulacion2(cod);//llama al metodo de Titulaciones que busca la titulaciones que le estamos indicando y muestra su info tras matricula
}

ElZarzal::~ElZarzal(){
	delete EstudiantesPre;//elimina la memoria asociada al puntero a la clase Estudiantes
	delete ListaTitulaciones;//elimina la memoria asociada al puntero a la clase Titulaciones
}

