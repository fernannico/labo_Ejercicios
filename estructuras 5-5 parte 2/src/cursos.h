/*
 * cursos.h
 *
 *  Created on: 21 may. 2022
 *      Author: Ailin Pc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CURSOS_H_
#define CURSOS_H_
#define TAMC 3

typedef struct
{
	int idCurso;
	char descripcion[20];
	int duracion;
}eCurso;

void MostrarCursos(eCurso listaCursos[], int sizeCursos);

#endif /* CURSOS_H_ */
