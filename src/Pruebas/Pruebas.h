/*
 * Pruebas.h
 *	CONJUNTO DE CABECERAS DE TODAS LAS PRUEBAS
 *  Created on: 19/04/2016
 *      Author: FRANCISCO JAVIER ROJO MARTÍN   DNI:76042262-F
 */

#ifndef PRUEBAS_H_
#define PRUEBAS_H_
#include <iostream>
#include "../Solicitud.h"
#include "../Solicitudes.h"
#include "../Estudiante.h"
#include "../Estudiantes.h"
#include "../ListaEstudiantes.h"
#include "../Titulacion.h"
#include "../Titulaciones.h"
#include "../ColeccionEstudiantes.h"
#include "../ElZarzal.h"
using namespace std;

////////////////////////
////IMPORTANTE/////////
//////////////////////
//EN CADA .CPP EXISTE, ADEMAS, UN INT MAIN COMENTADO, QUE NOS PERMITE QUE SI, POR CUALQUIER RAZON, QUEREMOS SACAR UNA CLASE
//PARA OTRO PROYECTO Y SUS PRUEBAS, SI QUEREMOS EJECUTAR ESTAS ULTIMAS SIN QUE EXISTA ESTE .H PODEMOS DESCOMENTAR ESE MAIN,
//COMENTAR EL DEL PROYECTO, Y EJECUTAR LAS PRUEBAS DE ESA LIBRERIA DE FORMA TOTALMENTE INDEPENDIENTE. ADEMAS, HABRIA QUE
//DESCOMENTAR EL INCLUDE AL .H DE LA CLASE Y COMENTAR EL INCLUDE A PRUEBAS.H
//////////////////////

/////////////////////
////LOS METODOS MOSTRAR DE CADA CLASE LOS SUPONGO CORRECTOS, ES DECIR, NO LOS PRUEBO, PUES NO SON MAS QUE COUT O PEQUEÑOS
////BUCLES QUE MUESTRAN DISTINTAS TITULACIONES O ESTUDIANTES
////////////////////

////////////////////
////COMO SE PUEDE VER, NO HE HECHO PRUEBAS DE 'COMPARAESTUDIANTE.H', DE 'UIFILES' NI DE 'COLECCIONESTUDIANTES' PUES SON LIBRERIAS Y CLASES
////ENTREGADAS POR LOS PROFESORES QUE SOLO HAN RECIBIDOC CAMBIOS MENORES EN ALGUNOS ELEMENTOS COMO LO QUE MUESTRAS, PERO SUSTANCIALMENTE LOS ALGORITMOS
////SEGUIDOS PARA LA IMPLEMENTACION DE ESTOS SON LOS MISMOS QUE CON LOS QUE CONTABAN CUANDO SE NOS FUERON ENTREGADAS
////////////////////


//PRUEBAS DE SOLICITUD;
void pr_Solicitud();//modulo donde se prueban todos los constructores
void pr_set_getCodtit();//modulo donde se prueban todos los set y get de la clase
void pruebas_Solicitud();//modulo principal de las pruebas de esta clase

//PRUEBAS DE SOLICITUDES;
void pr_anadirSolicitud();//modulo donde se prueban todos los constructores
void pr_eliminarSolicitud();
void pr_vacia_solicitudes();
void pr_primera();
void pr_Solicitudes();
void pruebas_Solicitudes();//modulo principal de las pruebas de esta clase

//PRUEBAS DE ESTUDIANTE
void pr_Estudiante();//modulo donde se prueban todos los constructores
void pr_set_get_Estudiante();//modulo donde se prueban todos los set y get de la clase
void pr_tieneSolicitudes();
void pr_primeraSolicitud();
void pruebas_Estudiante();//modulo principal de las pruebas de esta clase

//PRUEBAS DE ESTUDIANTES
void pr_Estudiantes();//modulo donde se prueban todos los constructores
void pr_vacia();
void pr_insertar();
void pr_sacarPrimero();
void pruebas_Estudiantes();//modulo principal de las pruebas de esta clase

//PRUEBAS DE LISTAESTUDIANTES
void pr_ListaEstudiantes();//modulo donde se prueban todos los constructores
void pr_SacarPrimero();
void pr_SacarUltimo();
void pr_InsertarPos();
void pr_notaMinima();
void pr_cuantos();
void pr_buscarEstudiante();
void pruebas_ListaEstudiantes();//modulo principal de las pruebas de esta clase

//PRUEBAS TITULACION
void pr_Titulacion();//modulo donde se prueban todos los constructores
void pr_get_Titulacion();//modulo donde se prueban todos los set y get de la clase
void pr_plazasLlenas();
void pr_actualizarNotaCorte();
void pr_cumpleNota();
void pr_insertarEspera();
void pr_insertarAdmitido();
void pr_obtenerSobrante();
void pr_buscarEstudiante();
void pr_admitidos_a_arbol();
void pr_espera_a_arbol();
void pr_busquedaXraiz();
void pruebas_Titulacion();//modulo principal de las pruebas de esta clase

//PRUEBAS TITULACIONES
void pr_Titulaciones();//modulo donde se prueban todos los constructores
void pr_insertar2();
void pr_seleccionarTitulacion();
void pr_infoTitulacion();
void pr_buscarEstudiante2();
void pr_notascorte();
void pr_matricula();
void pr_busquedaXraiz3();
void pruebas_Titulaciones();//modulo principal de las pruebas de esta clase

//PRUEBAS GESTORESTUDIANTES
void pr_cuantos2();
void pr_obtenerAleatorio();
void pr_obtenerEstMayorNota();
void pruebas_GestorEstudiantes();

//PRUEBAS EL ZARZAL
void pr_ElZarzal();//modulo donde se prueban todos los constructores
void pr_asignar();
void pr_preinscripcion();
void pr_consultarTitulacion();
void pr_consultarEstudiante();
void pr_notasCorte();
void pr_matricula2();
void pr_busquedaXraiz2();
void pruebas_ElZarzal();//modulo principal de las pruebas de esta clase




#endif /* PRUEBAS_H_ */
