#include "nexo.h"

int main(void) {
	setbuf(stdout, NULL);

	eAlumno listaAlumnos[T];// = {{10,"Pedro",7.5, OCUPADO},{99, "Ana", 9, OCUPADO},{14,"Luis",5, OCUPADO}};
	eCurso listaCursos[TAMC] = {{1, "java Script", 5}, {2, "Python", 8}, {3, "Angular", 7}};/**una vez tengo los cursos tengo que hacer la relacion cursos con alumnos*/
	int opcion;

	int retorno;

	for(int i = 0; i < T; i++)
	{
		listaAlumnos[i].estado = LIBRE;
	}

	InicializarListaAlumnos(listaAlumnos);

	do
	{
		printf("\n1. Cargar\n"
				"2. Mostrar\n"
				"3. Ordenar\n"
				"4. Modificaciones \n"
				"5. Bajas\n"
				"6. Mostrar curso de alumnos\n"
				"7. por curso, los alumnos que hay\n"
				"10.Salir\n"
				"Elija una opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				retorno = CargarListaDeAlumnosMejorada(listaAlumnos, T, listaCursos, TAMC);

				switch (retorno)
				{
					case -1:
						printf("\n no hay mas espacio\n");
					break;
					default:
						printf("\nse cargo exitosamente el alumno!\n");
					break;
				}
			break;
			case 2:
				MostrarListaDeAlumnos(listaAlumnos, T);
			break;
			case 3:
				OrdenarListaDeAlumnosPorNombreMayorAMenor(listaAlumnos, T);
			break;
			case 4:
				retorno = ModificarAlumno(listaAlumnos, T);
				switch (retorno)
				{
					case -1:
						printf("\n no existe ese legajo\n");
					break;
					default:
						printf("\nse modifico exitosamente el promedio!\n");
					break;
				}
			break;
			case 5:
				MostrarListaDeAlumnos(listaAlumnos, T);
				retorno = EliminarAlumno(listaAlumnos, T);
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
			case 6:
				for(int i = 0; i < T; i++)/**ALUUMNOS*/
				{
					for(int k = 0; k < TAMC; k++)/**CURSOS*/ /**ESTO TIENE QUE ESTAR EN OTRA FUNCION (BuscarCurso)!!!!! NO PONER DOS FOR JUNTOS EN UNA MISMA FUNCION*/
					{
						if( listaAlumnos[i].estado == OCUPADO && listaAlumnos[i].idCurso == listaCursos[k].idCurso)/**MATCH de la FK de alumnos con la PK de cursos*/
						{
							printf("%4d %10s %2.2f %10s \n", listaAlumnos[i].legajo, listaAlumnos[i].nombre, listaAlumnos[i].promedio, listaCursos[k].descripcion);
							break;/**	ES IMPORTANTE ESTE BREAK! POQRUE SI NO LO PONGO, UNA VEZ ENCUENTRA EL CURSO EN EL QUE ESTA, IGUAL VA A SEGUIR BUSCANDO, CUANDO
										LA RESPUESTA YA LA TENGO. IMPORTANTE SI TENGO 200 CURSOS.

										BREAK PARA RELACION 1 A 1*/																										/***/
						}
					}
				}
			break;
			case 7:/**POR CADA CURSO LOS ALUMNOS, SERIA AL REVES*/
				/**ENTONCES SERIA COMO ANTES PERO AL REVES LOS FOR*/
				for(int i = 0; i < TAMC; i++)/**POR CADA CURSO PREGUNTO POR LOS ALUMNOS*/
				{
					printf("%s: \n", listaCursos[i].descripcion);
					for(int k = 0; k < T; k++)
					{
						/**PREGUNTO SI HAY MATCH ENTRE UNA LISTA Y OTRA, SI EL ALUMNO ESTA DISPONIBLE, Y MOSTRAR*/
						if(listaAlumnos[k].estado == OCUPADO && listaCursos[i].idCurso == listaAlumnos[k].idCurso)/**busco la PK contra la FK; poregunto si la PK es igual a la FK */
						{
							printf("\t%4d %10s\n", /*listaCursos[i].descripcion, */
									listaAlumnos[k].legajo,
									listaAlumnos[k].nombre);
							/**ACA NO SE APLICA EL BREAK PORQ POR CADA CURSO TENGO VARIOS ALUMNOS, ENTONCES SI PONGO EL BREAK, SOLO ME VA A IMPRIMIR EL PRIMER ALUMNO!!!!
							 * PERO ESTO ES UNA RELACION DE 1 A MUCHOS
							 *
							 * NO VA BREAK EN 1 A MUCHOS*/
						}
					}/**si al momento de harcodear o pedir que ingrese un curso, y se ingresa/harcodea un curso que no existe, el alumno no va a aparecer porq nunca habria un match*/
				}
				break;
		}
	}while(opcion!=10);

	return EXIT_SUCCESS;
}
