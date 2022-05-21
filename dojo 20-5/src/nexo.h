/*
 * nexo.h
 *
 *  Created on: 20 may. 2022
 *      Author: Ailin Pc
 */
#include "StructCurso.h"
#include "funciones.h"

#ifndef NEXO_H_
#define NEXO_H_

void CargarListaDeAlumnosConCurso(eAlumno listaAlumnos[], int sizeAlumnos, eCurso curso[], int size);//POR REFERENCIA
void MostrarUnAlumno(eAlumno miAlumno/*, eCurso miCurso)*/);
void MostrarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos/*, eCurso miCurso[]*/);

eAlumno PedirUnAlumnoConCurso(eCurso curso[], int size);
void alumnosAprobados(eAlumno listaAlumnos[], int sizeAlumnos);


#endif /* NEXO_H_ */
