/*
 * Estudiante.cpp
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include "Estudiante.h"

string goString(int numero) {
	stringstream flujo;
	string cadena;
	flujo << numero;
	flujo >> cadena;
	return cadena;
}

Estudiante::Estudiante() {//inicializa los atributos con los valores a 0 o ""
	apellido1="";
	apellido2="";
	nombre="";
	dni="";
	nota=0;
	montonSolicitudes=new Solicitudes;//reserva memoria, creando una cola vacia
	admitido=false;
}

Estudiante::Estudiante(string _apellido1, string _apellido2, string _nombre, string _dni, float _nota){//inicializa los atributos dados como entrada
	apellido1=_apellido1;
	apellido2=_apellido2;
	nombre=_nombre;
	dni=_dni;
	nota=_nota;
	montonSolicitudes=new Solicitudes;
	admitido=false;
}

Estudiante::Estudiante(string _apellido1, string _apellido2, string _nombre, string _dni, float _nota, Solicitudes* _montonSolicitudes){//inicializa los atributos dados como entrada y con cola de solicitudes
	apellido1=_apellido1;
	apellido2=_apellido2;
	nombre=_nombre;
	dni=_dni;
	nota=_nota;
	montonSolicitudes= _montonSolicitudes;
	admitido=false;
}

Estudiante::Estudiante(const Estudiante &e){//copia el valor de los parametros de e en los del EStudiante que se esta inicializando
	apellido1=e.getApellido1();
	apellido2=e.getApellido2();
	nombre=e.getNombre();
	dni=e.getDni();
	nota=e.getNota();
	montonSolicitudes=e.montonSolicitudes;
	admitido=e.admitido;
}

string Estudiante::getApellido1()const{
	return apellido1;
}
string Estudiante::getApellido2()const{
	return apellido2;
}
string Estudiante::getNombre()const{
	return nombre;
}
string Estudiante::getDni()const{
	return dni;
}
float Estudiante::getNota()const{
	return nota;
}
bool Estudiante::getAdmitido()const{
	return admitido;
}
void Estudiante::setApellido1(string _apellido1){
	apellido1=_apellido1;
}
void Estudiante::setApellido2(string _apellido2){
	apellido2=_apellido2;
}
void Estudiante::setNombre(string _nombre){
	nombre=_nombre;
}
void Estudiante::setDni(string _dni){
	dni=_dni;
}
void Estudiante::setNota(float _nota){
	nota=_nota;
}
void Estudiante::setSolicitudes(Solicitudes *_montonSolicitudes){
	montonSolicitudes=_montonSolicitudes;
}
void Estudiante::setAdmitido(bool _admitido){
	admitido=_admitido;
}

void Estudiante::mostrar(){//muestra todos los datos excepto la cola de solicitudes
	cout<<apellido1<<" "<<apellido2<<", "<<nombre<<"     "<<dni<<"     "<<nota<<".";
	cout<<endl;
	cout<<endl;
}

void Estudiante::mostrar_pruebas(){//muestra todos los datos y ademas llama al mostrar de Solicitudes para tambien mostrar las solicitudes, cosa muy util en las pruebas para hacer las trazas de pr_preinscripcion
	cout<<apellido1<<" "<<apellido2<<", "<<nombre<<"     "<<dni<<"     "<<nota<<"   Solicitudes: ";
	montonSolicitudes->mostrar();
	cout<<endl;
	cout<<endl;
}

bool Estudiante::tieneSolicitudes(){
	return !montonSolicitudes->vacia();//comprueba si Solicitudes esta vacia con su metodo
}

int Estudiante::primeraSolicitud(){
	Solicitud *s;
	int cod=0;

	s=montonSolicitudes->primera();			//obtenemos la primera solicitud de Solicitudes
	cod=s->getCodtit();		//obtenemos el codigo de dicha solicitud
	montonSolicitudes->eliminarSolicitud();//sacamos esa solicitud de la cola de solicitudes que representa Solicitudes
	return cod;//nos devuelve el codigo
}

void Estudiante::infoAFichero(ofstream &fsal){
	fsal<<apellido1<<" "<<apellido2<<" "<<nombre<<" "<<dni<<" "<<nota<<endl;
}

Estudiante::~Estudiante() {
	delete montonSolicitudes;//llama al destructor de Solicitudes
}

