/*
 * nexo.c
 *
 *  Created on: 20 may. 2022
 *      Author: Ailin Pc
 */
#include "nexo.h"

eAlumno PedirUnAlumnoConCurso(eCurso curso[], int size)
{
	eAlumno miAlumno;

	printf("Ingrese el legajo: ");
	scanf("%d", &miAlumno.legajo);
	printf("Ingrese el nombre: ");
	fflush(stdin);
	//fflush(stdin);
	scanf("%[^\n]",miAlumno.nombre);
	printf("Ingrese el promedio: ");
	scanf("%f", &miAlumno.promedio);

	MostrarListaDeCursos(curso, size);/**problema de que tengo que recibir curso, por lo q incluyo la biblioteca. Encima ahora tengo que recibir como parametro los cursos
	 	 	 	 	 	 	 	 	 	 curso va sin [ xq ya fueron presentadas arriba de la forma que son, y despues adentro de la fx ya solo las puedo llamar por su nombre**/
	printf("ingrese el id del curso: ");
	scanf("%d", &miAlumno.idCurso);/**cuando le pedimos que ingrese el curso, como sabe la persona de los cursos existentes? hay que mostrarlos antes*/

	return miAlumno;
}


void CargarListaDeAlumnosConCurso(eAlumno listaAlumnos[], int sizeAlumnos, eCurso curso[], int size)
{
	for(int i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].estado == LIBRE)
		{
		    listaAlumnos[i] = PedirUnAlumnoConCurso(curso, size);
		    listaAlumnos[i].estado = OCUPADO;
		    break;
		}
	}
}

void MostrarUnAlumno(eAlumno miAlumno)
{
	printf("%4d %10s %4.2f %d \n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio, miAlumno.idCurso);
}

void MostrarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos)
{
	for(int i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].estado == OCUPADO)
		{
			MostrarUnAlumno(listaAlumnos[i]);
		}
	}
}
void alumnosAprobados(eAlumno listaAlumnos[], int sizeAlumnos)
{

	for(int i=0; i<sizeAlumnos; i++)
	{
	    if(listaAlumnos[i].estado == OCUPADO && listaAlumnos[i].promedio>=7)
	    {
	        MostrarUnAlumno(listaAlumnos[i]);
	    }
	}
}
