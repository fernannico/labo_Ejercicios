#include "nexo.h"


int main(void) {
	setbuf(stdout, NULL);

	eAlumno listaAlumnos[T];//={{10,"Pedro",7.5},{99, "Ana", 9},{14,"Luis",5},{11,"Juan",8},{12, "Martin", 7.5},{13,"Mariano",5}};
	int opcion;
	eCurso ListaDeCursos[5];
	CargaForzadaCurso(ListaDeCursos, 5, 5);

	inicializarAlumno(listaAlumnos,T);

	do
	{
		printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Mostrar Alumnos Aprobados\n5.Ordenar Por Nota\n10.Salir\nElija una opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				CargarListaDeAlumnosConCurso(listaAlumnos, T, ListaDeCursos, 5);
				printf("------------------------------------------------\n");
			break;
			case 2:
				MostrarListaDeAlumnos(listaAlumnos, T);

				printf("------------------------------------------------\n");
			break;
			case 3:
				OrdenarListaDeAlumnosPorNombre(listaAlumnos, T);
				printf("------------------------------------------------\n");
			break;
			case 4:
			    alumnosAprobados(listaAlumnos,T);
			    printf("------------------------------------------------\n");
			break;
			case 5:
			    ordenarPorNota(listaAlumnos,T);
			    printf("------------------------------------------------\n");
			break;

		}
	}while(opcion!=10);

	return EXIT_SUCCESS;
}
