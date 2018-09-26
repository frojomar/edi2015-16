/*
 * comparausuario.h
 *
 *  Created on: 20 de abr. de 2016
 *      Author: jarico
 */

#ifndef COMPARAESTUDIANTE_H_
#define COMPARAESTUDIANTE_H_

#include "Estudiante.h"
#include <string>
using namespace std;

class ComparaPtrEstudiante {
public:

	int operator()(const Estudiante *e1, const Estudiante *e2) const {
		int flag = 1;
		if (e1->getDni() == e2->getDni())
			flag = 0;
		else {
			if (e1->getApellido1() < e2->getApellido1())
				flag = -1;
			else {
				if (e1->getApellido1() == e2->getApellido1()) {
					if (e1->getApellido2() < e2->getApellido2())
						flag = -1;
					else
						if (e1->getApellido2() == e2->getApellido2())
							if (e1->getNombre() < e2->getNombre())
								flag = -1;
				}
			}
		}
		return flag;
	}

};
#endif /* COMPARAESTUDIANTE_H_ */
