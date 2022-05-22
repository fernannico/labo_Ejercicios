/*
 * nexo.c
 *
 *  Created on: 21 may. 2022
 *      Author: Ailin Pc
 */

#include "nexo.h"

eAlumno PedirUnAlumno(eAlumno listaCursos[], int sizeCursos)
{
	eAlumno miAlumno;

	printf("Ingrese el legajo: ");
	scanf("%d", &miAlumno.legajo);
	printf("Ingrese el nombre: ");
	fflush(stdin);
	gets(miAlumno.nombre);
	printf("Ingrese el promedio: ");
	scanf("%f", &miAlumno.promedio);

										/**AGREGAR QUE CURSO*/
	MostrarCursos(listaCursos, sizeCursos);
	scanf("%d", &miAlumno.idCurso);

	miAlumno.estado = OCUPADO;

	return miAlumno;
}

/*void CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos, eCurso listaCursos[], int sizeCursos)
{
	int flag;
	flag = 0;
	int i;
	for(i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].estado == LIBRE)
		{
			listaAlumnos[i] = PedirUnAlumno(listaCursos, sizeCursos);
			listaAlumnos[i].estado = OCUPADO;
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		printf("no hay espacio");
	}
}*/

int CargarListaDeAlumnosMejorada(eAlumno listaAlumnos[], int sizeAlumnos, eCurso listaCursos[], int sizeCursos)
{
	int index;

	index = BuscarEspacioLibre(listaAlumnos, sizeAlumnos);

	if(index != -1)
	{
		listaAlumnos[index] = PedirUnAlumno(listaCursos, sizeCursos);
	}

	return index;
}
