#include <stdio.h>
#include <string.h>
#define T 6
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int legajo;
	char nombre[20];
	float promedio;
	int estado;
	int idCurso;
	//si agrego otro dato que seria id de curso, tengo que modificar los datos de la carga
}eAlumno;


void OrdenarListaDeAlumnosPorNombre(eAlumno listaAlumnos[], int sizeAlumnos);
void alumnosAprobados(eAlumno listaAlumnos[], int sizeAlumnos);
void ordenarPorNota(eAlumno listaAlumnos[], int sizeAlumnos);
void inicializarAlumno(eAlumno listaAlumnos[], int sizeAlumnos);
