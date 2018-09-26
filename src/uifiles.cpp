//============================================================================
// Name        : user interface.cpp
// Author      : Profesores de la asignatura EDI, Modificaciones por FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
// Version     : Curso 14/15
// Copyright   : Your copyright notice
// Description : Implementación de la clase user interface
//============================================================================


#include <iostream>
#include "uifiles.h"

using namespace std;


//PUBLIC
UIFILES::UIFILES() {

	z= new ElZarzal();//se inicializa la instancia

	this->pruebas();//se ejecutan las pruebas

	this->ejecutar();//se ejecuta el programa principal


}

UIFILES::~UIFILES() {
	delete z;//se llama al destructor de El Zarzal
}

/// PRIVATE

void UIFILES::pruebas(){//llamada ordenada al conjunto de pruebas
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"----------------------------INICIO DE LAS PRUEBAS--------------------"<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;
	pruebas_Solicitud();
	cout<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;
	pruebas_Solicitudes();
	cout<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;
	pruebas_Estudiante();
	cout<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;
	pruebas_Estudiantes();
	cout<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;
	pruebas_ListaEstudiantes();
	cout<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;
	pruebas_GestorEstudiantes();
	cout<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;
	pruebas_Titulacion();
	cout<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;
	pruebas_Titulaciones();
	cout<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl;
	pruebas_ElZarzal();
	cout<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"-----------------------------FIN DE LAS PRUEBAS----------------------"<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
}

void UIFILES::preinscripcion(){//se llama al metodo preinscripcion de El Zarzal
	z->preinscripcion();
}

void UIFILES::consultarTitulacion(){
	int codigo;

	cout<<"Inserte el codigo de la titulacion a mostrar:"<<endl;//nos pide el codigo de la titulacion a buscar y llama a El Zarzal, que nos la mostrara
	cin>>codigo;
	z->consultarTitulacion(codigo);
}

void UIFILES::consultarEstudiante(){//nos pide el dni del estudiante a buscar y llama a El Zarzal, que nos mostrara su informacion
	string cadena;

	cout<<"Inserte el DNI del estudiante que desea consultar:"<<endl;
	cin>>cadena;
	z->consultarEstudiante(cadena);
}

void UIFILES::matricula(){//lleva a cabo la matricula de los estudiantes
	z->matricula();
}
void UIFILES::proceso_matricula(){
	z->proceso_matricula();
}
void UIFILES::consultarTitulacionMatricula(){
	int codigo;

	cout<<"Inserte el codigo de la titulacion a mostrar:"<<endl;//nos pide el codigo de la titulacion a buscar y llama a El Zarzal, que nos la mostrara
	cin>>codigo;
	z->consultarTitulacionMatricula(codigo);
}

void UIFILES::busquedaXraiz(){//busca a los estudiantes cuyo apellido empieza por la raiz dada
	string cadena;

	cout<<"Inserte el Apellido del estudiante (o Estudiantes) a buscar:"<<endl;
	cin>>cadena;
	z->busquedaXraiz(cadena);
}

void UIFILES::notasCorte(){//nos muestra las notas de corte de todas las asignaturas
	z->notasCorte();
}

void UIFILES::ejecutar() {

	int       opcion;
	bool      salir = false;

	do {
		opcion = menu();

		switch(opcion){						//compara nuestra opcion con las posibles

		case 1:
			this->preinscripcion();
			break;

		case 2:
			this->consultarTitulacion();
			break;

		case 3:
			this->consultarEstudiante();
			break;
			
		case 4:
			this->matricula();
			break;

		case 5:
			this->proceso_matricula();
			break;

		case 6:
			this->consultarTitulacionMatricula();
			break;

		case 7:
		    this->busquedaXraiz();
			break;

		case 8:
			this->notasCorte();
			break;	
			
		case 9:
			salir=true;
			break;

		default:
			cout << "ERROR: opcion de menu no valida" << endl;//nunca vamos a entrar aqui, pues ya se comprueba en menu que sea un numero dentro de los posibles
			break;
		}

	} while (!salir);
	cout<<" --Saliendo de la aplicacion"<<endl;
}


int UIFILES::menu(){

	int opcion;

	do {
		cout << endl;
		cout << "__________________ MENU PRINCIPAL ________________" << endl << endl;		//nos muestra el menu y nos permite elegir una opcion
		cout << "   1. Asignacion "                              << endl;
		cout << "   2. Consulta de una titulacion"             << endl;
		cout << "   3. Consulta de un Estudiante"                     << endl;
		cout << "   4. Matricula"										<< endl;
		cout << "   5. Proceso de Matricula"										<< endl;
		cout << "   6. Consultar titulacion (tras matricularse)"										<< endl;
		cout << "   7. Comienza por"			<< endl;
		cout << "   8. Notas de corte"			<< endl;
		cout << "   9. Finalizar."                                                          << endl << endl;
		cout << "Opcion elegida:  ";cin>> opcion;
		cout<<"----------------------------------------------------------------------"<<endl;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 9));

	return opcion;
}




