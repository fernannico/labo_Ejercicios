#include <stdio.h>

typedef struct
{
	int legajo;
	char nombre[20];
	float promedio;
}eAlumno;

eAlumno PedirUnAlumno();


void MostrarUnAlumno(eAlumno miAlumno);//POR VALOR
void CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos);//POR REFERENCIA
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
