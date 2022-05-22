#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define T 8

typedef struct
{
	int legajo;//PK
	char nombre[20];
	float promedio;
	int idCurso; /**ahora los alumnos tienen curso, pero no tienen nada guardado de cursos; ¡¡hay que cargar cursos en los alumnos!!*/
	int estado;
}eAlumno;

//eAlumno PedirUnAlumno();

void InicializarListaAlumnos(eAlumno listaAlumnos[]);

void MostrarUnAlumno(eAlumno miAlumno);//POR VALOR

//void CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos);//POR REFERENCIA

int BuscarEspacioLibre(eAlumno listaAlumnos[], int sizeAlumnos);

int ModificarAlumno(eAlumno vectorControl[], int size);

int EliminarAlumno(eAlumno vectorControl[], int size/*, int legajo*/);


void MostrarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos);
//zzz --> aaa
void OrdenarListaDeAlumnosPorNombreMayorAMenor(eAlumno listaAlumnos[], int sizeAlumnos);

//aaa --> zzz
void OrdenarListaDeAlumnosPorNombreMenorAMayor(eAlumno listaAlumnos[], int sizeAlumnos);

void OrdenarMayorAMenorNota(eAlumno vectorControl[], int size);

void OrdenarMayorAMenorNotaYNombreAscendente(eAlumno vectorControl[], int size);

void MostrarListaAprobados(eAlumno vectorControl[], int size);

void MostrarListaAprobadosaaa(eAlumno vectorControl[], int size);

void MostrarListaAprobadosA0(eAlumno vectorControl[], int size);


