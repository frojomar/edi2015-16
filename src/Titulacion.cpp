/*
 * Titulacion.cpp
 *
 *  Created on: 07/03/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#include "Titulacion.h"

string aString (int numero){
	stringstream flujo;
	string cadena;
	flujo<< numero;
	flujo>> cadena;
	return cadena;
}

Titulacion::Titulacion() {//inicializa los atributos a 0 o " "
	codigo=0;
	nombre=" ";
	nota_corte=0;
	plazas=0;
	admitidos=new ListaEstudiantes ;
	espera=new ListaEstudiantes;
	arbAdm=new GestorEstudiantes;
	arbEsp=new GestorEstudiantes;
}

Titulacion::Titulacion(int _codigo, string _nombre, int _plazas){//inicializa los atributos con los datos dados
	codigo= _codigo;
	nombre= _nombre;
	nota_corte=0;
	plazas= _plazas;
	admitidos=new ListaEstudiantes();
	espera=new ListaEstudiantes() ;
	arbAdm=new GestorEstudiantes;
	arbEsp=new GestorEstudiantes;
}

Titulacion::Titulacion(const Titulacion &t){//copia el valor de los parametros de t en los de la Titulacion que se esta inicializando
	codigo= t.codigo;
	nombre= t.nombre;
	nota_corte= t.nota_corte;
	plazas= t.plazas;
	admitidos= t.admitidos;
	espera= t.espera;
	arbAdm=t.arbAdm;
	arbEsp=t.arbEsp;
}

int Titulacion::getCodigo()const{
	return codigo;
}
float Titulacion::getNota_corte()const{
	return nota_corte;
}
string Titulacion::getNombre()const{
	return nombre;
}

void Titulacion::setNota_Corte(float nota){
	nota_corte=nota;
}

bool Titulacion::plazasLlenas(){
	return (admitidos->cuantos()==plazas);//llama a 'cuantos' de ListaEstudiantes para saber cuantos estudiantes hay en Admitidos
}
void Titulacion::actualizarNotaCorte(){
	nota_corte=admitidos->notaMinima();//llama a 'notaMinima' de listaEstudiantes, que nos devuelve la nota minima de los Admitidos
}

bool Titulacion::cumpleNota(Estudiante *e){
	return e->getNota()>nota_corte; //por la forma en que se ha diseñado el InsertarPos de ListaEstudiantes es > y no >=
}

void Titulacion::insertarEspera(Estudiante *e){
	espera->InsertarPos(e);//llamamos al 'insertarPos' desde la lista de Espera
	e->setAdmitido(false);
}
void Titulacion::insertarAdmitido(Estudiante *e){
	admitidos->InsertarPos(e);//llamamos al 'insertarPos' desde la lista de Admitido
	actualizarNotaCorte();//como el que hemos insertado puede tener la nota mas baja de todos los Admitidos, debemos actualizar la nota de corte
	e->setAdmitido(true);
}
void Titulacion::obtenerSobrante(Estudiante *&e){
	admitidos->SacarUltimo(e);//saca de la lista de admitidos al de menor nota y nos lo devuelve como salida
	e->setAdmitido(false);//cambiamos su estado a no admitido, ya que no se encuentra en la lista de admitidos de esta titulacion
}

bool Titulacion::buscarEstudiante(string dni, Estudiante *&e,bool &admitido){
	bool encontrado=false;
	admitido=false;
														//busca al estudiante tanto en la lista de admitidos como en la de espera, indicandonos
	encontrado=admitidos->buscarEstudiante(dni, e);		//gracias a admitidos en cual de las dos listas se encuentra
	if(encontrado)
		admitido=true;
	else{
		encontrado=espera->buscarEstudiante(dni, e);
	}
	return encontrado;
}

void Titulacion::Admitidos_a_Arbol(){
	Estudiante *e;

	while(admitidos->cuantos()>0){//mientras no este vacia la lista de estudiantes admitidos...
		admitidos->SacarPrimero(e);//sacamos el primero de la lista...
		arbAdm->insertar(e);//lo insertamos en el arbol
	}
}

void Titulacion::Espera_a_Arbol(){
	Estudiante *e;

	while(espera->cuantos()>0){//mientras no este vacia la lista de estudiantes en espera...
		espera->SacarPrimero(e);//sacamos el primero de la lista...
		arbEsp->insertar(e);//y lo metemos en el arbol
	}
}

void Titulacion::busquedaxraiz(string apellido){

	cout<<"Buscando en Admitidos de: "<<this->getNombre()<<endl;//buscamos las coincidencias en el arbol de admitidos
	arbAdm->mostrarSimilares(apellido);
	cout<<"Buscando en Espera de: "<<this->getNombre()<<endl;//buscamos las coincidencias en el arbol de en espera
	arbEsp->mostrarSimilares(apellido);
}


void Titulacion::mostrar(){
	cout<<"INFO TITULACION:"<<endl;				//nos muestra el valor de todos sus atributos
	cout<<"	Codigo: "<<codigo<<"."<<endl;
	cout<<"	Nombre: "<<nombre<<"."<<endl;
	cout<<"	Plazas: "<<plazas<<"."<<endl;
	cout<<"	Nota de Corte: "<<nota_corte<<"."<<endl;
	cout<<"	Admitidos: "<<endl; admitidos->mostrar(); cout<<endl;
	cout<<"		Total de alumnos Admitidos: "<<admitidos->cuantos()<<endl;
	cout<<"	Espera: "<<endl; espera->mostrar(); cout<<endl;
	cout<<"		Total de alumnos Espera : "<<espera->cuantos()<<endl;
}

void Titulacion::InfoAFichero(ofstream &fsal){
	fsal<<codigo<<" "<<nombre<<" "<<plazas<<endl;
}

bool Titulacion::buscarAdmitidos(string apellido, string apellido2, string nombre, string dni, Estudiante *&e){
	return arbAdm->buscarEstudiante(apellido, apellido2, nombre, dni, e);
}
bool Titulacion::EstAleatorioAdm(Estudiante *&e){
	bool tiene=false;

	if(arbAdm->tieneEstudiantes()){//si el arbol tiene estudiantes..
		tiene=true;//decimos que tiene
		arbAdm->obtenerAleatorio(e);//sacamos el estudiante de la raiz
	}
	return tiene;
}

bool Titulacion::EstAleatorioEsp(Estudiante *&e){
	bool tiene=false;

	if(arbEsp->tieneEstudiantes()){//si el arbol tiene estudiantes..
		tiene=true;//decimos que tiene
		arbEsp->obtenerAleatorio(e);//sacamos el estudiante de la raiz
	}
	return tiene;
}

void Titulacion::admitirEstMayorNota(){
	Estudiante *e;
	if(arbEsp->cuantos()>0){//si tiene estudiantes
	arbEsp->sacarEstMayorNota(e);//sacamos al de mayor nota de espera
	arbAdm->insertar(e);//y lo admitimos
	this->setNota_Corte(e->getNota());//cambiamos la nota de conte a la de este estudiante nuevo admitido
	}
}

void Titulacion::eliminarDeAdmitidos(Estudiante *&e){
	arbAdm->eliminar(e);
}

void Titulacion::eliminarDeEspera(Estudiante *&e){
	arbEsp->eliminar(e);
}



void Titulacion::mostrar2(){
	cout<<"INFO TITULACION:"<<endl;				//nos muestra el valor de todos sus atributos
	cout<<"	Codigo: "<<codigo<<"."<<endl;
	cout<<"	Nombre: "<<nombre<<"."<<endl;
	cout<<"	Plazas: "<<plazas<<"."<<endl;
	cout<<"	Nota de Corte: "<<nota_corte<<"."<<endl;
	cout<<"	Admitidos: "<<endl; arbAdm->mostrar(); cout<<endl;
	cout<<"		Total de alumnos Admitidos: "<<arbAdm->cuantos()<<endl;
	//cout<<"	Espera: "<<endl; arbEsp->mostrar(); cout<<endl;
	//cout<<"		Total de alumnos Espera: "<<arbEsp->cuantos()<<endl;
}

Titulacion::~Titulacion() {
	delete admitidos;//llama al destructor de ListaEstudiantes
	//delete espera; //Este se encuentra comentado, ya que si se ejecuta se producen errores, ya que, una vez que liberamos la memoria a la
						//que apuntan los punteros de estudiantes de la lista de admitidos, puede haber, en otras titulaciones, punteros que
						//apuntasen a esa memoria que a sido liberada, y que, por tanto, al intertar volver a liberarla, el compilador nos dara
						//un error indicandonos que estamos intentando acceder a memoria cuyo acceso no podemos llevar a cabo
	////AUN ASI, SE SUPONE QUE EL PROGRAMA NO DEBERIA ENCONTRAR MAS QUE UNAS LISTAS VACIAS AL LLAMAR AL DESTRUCTOR DE ESTAS, PUES CUANDO EJECUTEMOS
	////EL COMANDO DE MATRICULA, LOS PUNTEROS DE LAS LISTAS DEJARAN DE ESTAR EN ESTAS PARA ESTAR EN LOS ARBOLES, POR LO QUE SERA EN LOS ARBOLES
	////DONDE REALMENTE NOS DEBE RESULTAR RELEVANTE LA LIBERACION DE MEMORIA ASOCIADA A LOS PUNTEROS A ESTUDIANTES
	delete arbAdm;
	delete arbEsp;

}

