#include <stdio.h>

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
				/** para guardar a los libres y pedirlos. Las bajas fisicas no existen porq si lo pensas, no guardaria los q se fueron y
				 * si quieren volver empezarian de nuevo*/


typedef struct
{
	int legajo;
	char nombre[20];
	float promedio;

	int estado;/**Ahora quiero que la fx haga un corte al cargar un alumno y salga. lo que quero es que el progrma cargue al alumno 1 y salir y que luego sepa q la posicion
			0 ya esta cargada y que ahora tiene que cargar en la 1, luego en la 2 y asi hasta llenar el array. NECESITO DECIR QUE ESTA
			OCUPADO LOS INDICES. tengo que cambiar la estructura del alumno y poner un campo de si la posicion del vector esta ocupada o no.
			O sea trabajar con un estado. Entonces cuadno entro a la fx para cargar un nuevo alumno,la fx busca el primero que este libre (0)
			TODOS tienen que estar inicializados en 0. PERO NO SE TIENE QUE PONER EL = 0 EN EL STRUCT!!! El typedef struct NO OCUPA ESPACIO
			en memoria! hasta que no cree un alumno, no ocupa espacio en memoria. asiq no puedo decir que todos los alumnos empiezan en 0 en el struct.*/
}eAlumno;

eAlumno PedirUnAlumno();

void InicializarListaAlumnos(eAlumno listaAlumnos[]);

void MostrarUnAlumno(eAlumno miAlumno);//POR VALOR

void CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos);//POR REFERENCIA

int CargarListaDeAlumnosMejorada(eAlumno listaAlumnos[], int sizeAlumnos);

int BuscarEspacioLibre(eAlumno listaAlumnos[], int sizeAlumnos);

int ModificarAlumno(eAlumno vectorControl[], int size);

int EliminarAlumno(eAlumno vectorControl[], int size, int legajo);


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


