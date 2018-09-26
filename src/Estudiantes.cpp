/*
 * Estudiantes.cpp
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include "Estudiantes.h"
float toFloat(string cad){
	stringstream flujo;
	float numero;
	flujo<< cad;
	flujo>> numero;
	return numero;
}

Estudiantes::Estudiantes(int bandera){
	this->montonEstudiantes= new Pila<Estudiante *>();

	if(bandera==0){//crea la pila de estudiantes con estos estudiantes
		Estudiante *e;
		Solicitudes *s;

		s=new Solicitudes();
		s->anadirSolicitud(01);
		s->anadirSolicitud(03);
		s->anadirSolicitud(04);
		e = new Estudiante("LÓPEZ", "LEBRATO", "ISMAEL", "53866385C", 5.436,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		s->anadirSolicitud(06);
		e = new Estudiante("LÓPEZ", "LÓPEZ", "ISMAEL", "86438544P", 5.836,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		s->anadirSolicitud(02);
		s->anadirSolicitud(03);
		e = new Estudiante("MACARRO", "LÓPEZ", "ISMAEL", "38455686G", 7.445,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		e = new Estudiante("MAGUIÑA", "LÓPEZ", "IGNACIO", "8449434L", 6.896,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(03);
		s->anadirSolicitud(02);
		e = new Estudiante("MALPARTIDA", "LORENTE", "IGNACIO", "53986334X", 8.346,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		s->anadirSolicitud(02);
		e = new Estudiante("MANCERA", "LORO", "IGNACIO", "45969965A", 8.156,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(03);
		e = new Estudiante("MANGAS", "LUJÁN", "IGNACIO", "83396335R", 8.386,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		e = new Estudiante("MANGUT", "MACHUCA", "GUILLERMO", "83433548R", 8.946,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		e = new Estudiante("MANZANO", "MAESTRE", "GUILLERMO", "86349644F", 9.446,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		e = new Estudiante("VAQUERO", "VALBUENA", "ALBERTO", "83448443F", 9.436,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(03);
		s->anadirSolicitud(01);
		e = new Estudiante("BUENO", "BERMEJO", "REBECA", "86356334Q", 7.153,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		e = new Estudiante("RODRIGUEZ", "RAMOS", "JOSÉ", "45433334E", 6.366,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(02);
		e = new Estudiante("VÁZQUEZ", "VARGAS", "ALBERTO", "83399663K", 6.999,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(03);
		s->anadirSolicitud(01);
		e = new Estudiante("VENTURA", "VÁZQUEZ", "AIDA", "86355843P", 8.866,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(07);
		e = new Estudiante("VERDEJO", "VERDUGO", "AFRICA", "38354639Q", 8.336,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(05);
		e = new Estudiante("VICENTE", "ZAPATA", "ADRIÁN MANUEL", "45439946P",8.836,s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(04);
		s->anadirSolicitud(01);
		e = new Estudiante("BRIONES", "BENÍTEZ", "ROBERTO", "86334885H", 5.584,s);
		this->insertar(e);
	}
	if(bandera==-1){//crea la pila de estudiantes con estos estudiantes
		Estudiante *e;
		Solicitudes *s;

		s=new Solicitudes();  //alamcena las solicitudes de cada estudiante
		s->anadirSolicitud(01);
		s->anadirSolicitud(03);
		e = new Estudiante("e1", "__", "__", "_______", 6, s);//crea cada estudiante con sus datos y su Solicitudes
		this->insertar(e);	//lo inserta en la pila

		s=new Solicitudes();
		s->anadirSolicitud(02);
		e = new Estudiante("e2", "__", "__", "_______", 8, s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		s->anadirSolicitud(03);
		e = new Estudiante("e3", "__", "__", "_______", 5.5, s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(02);
		s->anadirSolicitud(03);
		e = new Estudiante("e4", "__", "__", "_______", 7, s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		e = new Estudiante("e5", "__", "__", "_______", 10, s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		s->anadirSolicitud(03);
		e = new Estudiante("e6", "__", "__", "_______", 9, s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(03);
		s->anadirSolicitud(01);
		e = new Estudiante("e7", "__", "__", "_______", 6.2, s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(02);
		s->anadirSolicitud(03);
		e = new Estudiante("e8", "__", "__", "_______", 6, s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		s->anadirSolicitud(03);
		e = new Estudiante("e9", "__", "__", "_______", 8, s);
		this->insertar(e);

		s=new Solicitudes();
		s->anadirSolicitud(01);
		s->anadirSolicitud(02);
		s->anadirSolicitud(03);
		e = new Estudiante("e10", "__", "__", "_______", 5, s);
		this->insertar(e);


	}
}

Estudiantes::Estudiantes() {//crea la pila de estudiantes preincritos a partir de 'estudiantes.txt'
	this->montonEstudiantes = new Pila<Estudiante *>();
	Estudiante *e;
	Solicitudes* s;
	string apellido1, apellido2, nombre, dni, nota, numsol, sol;
	float cont;

	ifstream fent;
	fent.open("estudiantes.txt");
	if(fent.is_open()){//abrimos el fichero
		while(!fent.eof()){
			s=new Solicitudes();				//vamos leyendo cada linea de fichero de texto, separando las cadeanas por cada '#'
			getline(fent,apellido1, '#');		//cada estudiante lo creamos con la info de una linea completa del fichero y las de solicitudes
			if(!fent.eof()){
				getline(fent,apellido2, '#');
				getline(fent,nombre, '#');
				getline(fent,dni, '#');
				getline(fent,nota, '#');
				getline(fent,numsol);
				cont=toFloat(numsol);
				for(int i=0;i<cont;i++){	//cuando sabemos cuantas solicitudes tiene, sabemos cuantas lineas debemos leer, pues cada linea
					getline(fent, sol);		//contiene una solicitud
					s->anadirSolicitud(toFloat(sol)); //vamos añadiendo cada solicitud a la cola de estas
				}
				e= new Estudiante(apellido1, apellido2, nombre, dni, toFloat(nota), s);//creamos el estudiante que alberga esas caracteristicas
				this->insertar(e);//lo insertamos en la pila de preinscritos
			}
		}
		fent.close();//cerramos el fichero
	}
}

bool Estudiantes::vacia(){
	return montonEstudiantes->estaVacia();//nos dice si la pila esta vacia o no usando el vacia de la EDL Pila
}

void Estudiantes::insertar(Estudiante *e) {
	montonEstudiantes->apilar(e); //inserta el puntero al estudiante con el apilar de la EDL Pila
}

void Estudiantes::sacarPrimero(Estudiante* &e){
	if(!this->vacia()){
	montonEstudiantes->cima(e);		//consulta la cima de la pila
	montonEstudiantes->desapilar();		//una vez tenemos un puntero al Estudiante asociado al puntero de la cima, sacamos ese puntero de la pila
	}
}

void Estudiantes::mostrar(){
	Pila<Estudiante*>* paux=new Pila<Estudiante*>();
	Estudiante* e;
	while(!montonEstudiantes->estaVacia()){		//mientras la pila no este vacia va mostrando al Estudiante al que apunta el puntero de la
		montonEstudiantes->cima(e);					//cima y lo va apilando en una pila aux al mismo tiemp oque lo desapila de la pila original
		paux->apilar(e);
		montonEstudiantes->desapilar();
	}
	while(!paux->estaVacia()){				//copiamos de la pila aux de nuevo a la pila original
		paux->cima(e);
		e->mostrar();
		montonEstudiantes->apilar(e);
		paux->desapilar();
	}
}

Estudiantes::~Estudiantes() {
	Estudiante *e;
	while (!montonEstudiantes->estaVacia()) {	//vamos sacando punteros de la pila y eliminando la memoria asociada
		montonEstudiantes->cima(e);
		delete e;
		montonEstudiantes->desapilar();
	}
	delete montonEstudiantes; 	//cuando la pila esta vacia eliminamos el puntero a esa pila
}

