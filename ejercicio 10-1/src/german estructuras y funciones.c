/******************************************************************************
Ejercicio 10-1:
Dada la estructura eAlumno (legajo, nombre, nota1, nota2, promedio),
de qué manera la podría relacionar con la estructura eCurso (idCurso, descripcion, duracion),
teniendo en cuenta que un alumno puede cursar solo un curso
*******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
	int idCurso;
	char descripcion[50];
	int duracion;
}eCurso;

typedef struct
{
	int legajo;
	char nombre[20];
	int nota1;
	int nota2;
	float promedio;
	//int idCurso;
	eCurso cursoAlumno;
}eAlumno;

eCurso PedirCurso();

int main()
{
    eAlumno unAlumno;

    unAlumno.cursoAlumno = PedirCurso();//no habia puesto () a la funcion. No habia puesto el campo a la variable de tipo eAlumno
    /**recordar que a las variables de tipo estructura necesito especificar el campo tambien*/
    printf("curso: %s", unAlumno.cursoAlumno.descripcion);/**EL CAMPO cursoAlumno es otra estructura, por lo que tengo que aclarar
    															que campo quiero de esa otra estructura*/
    return 0;
}

eCurso PedirCurso()
{
	eCurso unCurso;

	unCurso.idCurso = 123;
	strcpy(unCurso.descripcion, "programacion");
	unCurso.duracion = 16;

	return unCurso;
}


