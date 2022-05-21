/*
 * structCurso.c
 *
 *  Created on: 20 may. 2022
 *      Author: Ailin Pc
 */
#include "StructCurso.h"
#define LARGO_CADENA 20
 // > <
/*hacer funcion para harcodear datos*/
void CargaForzadaCurso(eCurso curso[], int size, int maximo)
{
	//en plural porque son varios. Los tres son arrays
	int idCursos[5] = {1, 2, 3, 4, 5};
	char descripciones[5][LARGO_CADENA] = {"matematica", "lengua", "fisica", "geografia", "programacion"};//uno para el tamaño de la cadena en si y otro la cantidad de cadenas
	int duraciones[5] = {5, 9, 3, 4, 8};

	for(int i = 0; i < maximo; i++)
	{
		curso[i].idCurso = idCursos[i];/**cuando el for en posicion 0 va a cargar en id curso y lo que se va a guardar .......51:00*/
		strcpy(curso[i].descripcion, descripciones[i]);/**no se peude .......54:00*/
		curso[i].duracion = duraciones[i];
	}
}

/**hay que hacer una fx que muestre UNO y otra fx que muestre TODOS. Eso es MODULARIZAR**/
void MostrarUnCurso(eCurso curso)/**COMO ES MOSTRAR UNO SOLO, NO SE CARGA COMO ARRAY*/
{
	printf("%d \t %s \t %d\n", curso.idCurso, curso.descripcion, curso.duracion);
}

void MostrarListaDeCursos(eCurso curso[], int size)
{
	printf("\nID\t DESCRIPCION\t DURACION\n");/**\t es el espacio de una tabulacion. Esta linea podria estar en una fx cabecera cursos*/

	for(int i = 0; i < size; i++)
	{
		MostrarUnCurso(curso[i]);
	}

}






