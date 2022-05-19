#include <stdlib.h>
#include "Alumno.h"
#define T 8

int main(void) {
	setbuf(stdout, NULL);

	eAlumno listaAlumnos[T];// = {{10,"Pedro",7.5, OCUPADO},{99, "Ana", 9, OCUPADO},{14,"Luis",5, OCUPADO}};
	/**esta lista no aparece si pongo mostrar de una en el tablero porque luego vamos a inicializar a todos en libre*/
	int opcion;

	int retorno;
/** en verdad solo con 1 2 y 3 no es tan ajustado con la realidad. Esto debiera ser cargar los alumno de a uno, al cargar q se vuelva
 * a mostrar el menu y distintos alumnos van a querer hacer diferentes cosas. En la fila de atencion, muchos alumnos van a buscar hacer
 * diferentes cosas con el sistema ENTONCES hay que cambiar la carga de alumnos a una especie de pseudoaleatoria */
	for(int i = 0; i < T; i++)
	{
		listaAlumnos[i].estado = LIBRE;/** ASI HAGO QUE TODOS LOS ALUMNOS ESTEN INICIALIZADOS EN LIBRE (0)*/
	}	//ESTO DIRECTO A FUNCION "InicializarEstadoLibres"! LLamar una sola vez para que se inicialicen todos en 0 de estado libre
	/**este for que cumple la funcion de pasar todos a libre, hace que lo harcodeado no tenga efecto porq automaticamente se pasan a libre
	 * por lo que cuando haga la prueba, cuando quiera testear, van a estar pisados como libre a pesar de que esten harcodeados OCUPADOS
	 *
	 * ENTONCES tengo que hacer el harcodeo de datos PERO DESPUES DE LA ASIGNACION DE LIBRE de todos los datos del array. Asi tengo los primers
	 * 5 10 o lo q sea ya asignados. PERO NO SE PUEDE HACER:

	 eAlumno listaAlumnos[T];
	 listaAlumnos[T] = {{10,"Pedro",7.5, OCUPADO},{99, "Ana", 9, OCUPADO},{14,"Luis",5, OCUPADO}};

	 porque NO SE PUEDE ASIGNAR UN VECTOR A OTRO VECTOR;

	 entonces tenemos q hacer una fx que se encargue de inicializar con datos la lista de alumnos.

	 * */

	InicializarListaAlumnos(listaAlumnos);/**ahora tengo 5 harcodeados y 3 mas para argegar*/
	/** AHORA TENGO EL PROBLEMA QUE SI CARGO UNO, ORDENO Y CARGO OTRO, EL NUEVO APARECE ARRIBA DE TODOS y no es por si es mayor o menor nombre, es por el burbujeo
	 * asiq TENGO QUE PONER EN EL BURBUJEO QUE ME ORDENE SOLO LOS OCUPADOS*/

	do
	{
		printf("\n1.Cargar\n"
				"2.Mostrar\n"
				"3.Ordenar\n"
				"4. Modificaciones \n"
				"5. Bajas\n"
				"10.Salir\n"
				"Elija una opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				retorno = CargarListaDeAlumnosMejorada(listaAlumnos, T);/***esta fx ahoira devuelve algo por lo que lo tiene que recibir una variable*/

				switch (retorno)
				{
					case -1:
						printf("\n no hay mas espacio\n");
					break;
					default:/**no voy a poner TODAS LAS OPCIONES POSIBLES DEL SIZE! porq si bien ahora son 3, pueden ser 100 casos, asiq hago un default*/
						printf("\nse cargo exitosamente el alumno!\n");
					break;
				}/** de esta manera la fx no tiene nada que ver con los mensajes de lo que pudo haber llegado a pasar dentro de la funcion, sino que lo hace el main
				pasamos de una fx q no devuelve nada a que devuelva algo y las opciones de mensaje lo hacemos en el main segun lo q devolvio.*/
			break;
			case 2:
				MostrarListaDeAlumnos(listaAlumnos, T);
			break;
			case 3:
				OrdenarListaDeAlumnosPorNombreMayorAMenor(listaAlumnos, T);
			break;
			case 4:
				retorno = ModificarAlumno(listaAlumnos, T);/* lo indicado es mostrarle la lista antes de decirle que ingrese el legajo porq no sabe q hay
				 *el usuario puede saber los legajos? NO! Tengo que mostrarle la lista de alumnos! ademas poniendo solo el numero de legajo no me dice a quien encontro,
				 * que nota tenia, que promedio, no me dice nada. Si modifico no avisa, no avisa nada, eso agregar!*/
				switch (retorno)
				{
					case -1:
						printf("\n no existe ese legajo\n");
					break;
					default:/**no voy a poner TODAS LAS OPCIONES POSIBLES DEL SIZE! porq si bien ahora son 3, pueden ser 100 casos, asiq hago un default*/
						printf("\nse modifico exitosamente el promedio!\n");
					break;
				}
			break;
			case 5:
				retorno = EliminarAlumno(listaAlumnos, T);
				/**DE NUEVO. VER QUE CUANDO APRETO 5 DE UNA, NO ME APARECE LA LISTA DE ALUMNOS CON LEGAJO. ESO LE TENGO QUE MOSTRAR*/
				switch (retorno)
				{
					case -1:
						printf("\n no existe ese legajo\n");
					break;
					default:
						printf("\nAlumno eliminado!\n");
					break;
				}
			break;
		}
	}while(opcion!=10);

	return EXIT_SUCCESS;
}
