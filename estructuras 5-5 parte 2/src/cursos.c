/*
 * cursos.c
 *
 *  Created on: 21 may. 2022
 *      Author: Ailin Pc
 */

#include "cursos.h"

void MostrarCursos(eCurso listaCursos[], int sizeCursos)
{
	for(int i = 0; i < sizeCursos; i++)
	{
		printf("%d\t %s \t\n", listaCursos[i].idCurso, listaCursos[i].descripcion);
	}
}
