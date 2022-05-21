/*
 * StructCurso.h
 *
 *  Created on: 20 may. 2022
 *      Author: Ailin Pc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 6
#define LIBRE 0
#define OCUPADO 1

#ifndef STRUCTCURSO_H_
#define STRUCTCURSO_H_

typedef struct
{
	int idCurso;
	char descripcion[20];
	int duracion;
}eCurso;/*CADA ESTRUCTURA TIENE QUE TENER SU PROPIO .C Y .H. Cada estructura tiene que tener sus funciones propias de las estructuras*/

/**el array del curso es importante porq es lo que vamos a agarrar para cargar datos. Size dice que son varios cursos, asiq ya no es 1 curso,
 *  asiq es vector, un puntero. No se puede cargar un vector por valor. Entonces cargamos en la direccion de memoria.
 *  el maximo seria la cantidad de valores que quiero harcodear del array (ej si son 200 scopes, solo cargar 5)*/
void CargaForzadaCurso(eCurso curso[], int size, int maximo);

void MostrarListaDeCursos(eCurso curso[], int size);
void MostrarUnCurso(eCurso curso);
#endif /* STRUCTCURSO_H_ */
