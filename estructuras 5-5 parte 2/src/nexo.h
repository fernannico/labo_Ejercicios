/*
 * nexo.h
 *
 *  Created on: 21 may. 2022
 *      Author: Ailin Pc
 */

#ifndef NEXO_H_
#define NEXO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Alumno.h"
#include "cursos.h"

eAlumno PedirUnAlumno(eAlumno listaCursos[], int sizeCursos);
//void CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos, eCurso listaCursos[], int sizeCursos);
int CargarListaDeAlumnosMejorada(eAlumno listaAlumnos[], int sizeAlumnos, eCurso listaCursos[], int sizeCursos);

#endif /* NEXO_H_ */
