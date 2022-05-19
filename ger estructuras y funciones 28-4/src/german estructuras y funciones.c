#include <stdlib.h>
#include "Alumno.h"

#define T 10
//listado aprobados
//listado por nota de mayor a menor y ante igualdad de promedio, por nombre
//y si solo quiero los aprobados que se llamen ana?
//listado aprobados cuyo nombre empieza con la A

int main(void) {
	setbuf(stdout, NULL);

	eAlumno listaAlumnos[T]={{1,"aaa",7},{2, "bbb", 2},{3,"ccc",5}, {4,"Add",7}, {5,"eee",2}, {6,"Aff",4},{7,"ggg",6},{8,"hhh",7},{9,"iii",7},{10,"jjj",2}};
	int opcion;
	do
	{
		printf("1.Cargar\n"
				"2.Mostrar\n"
				"3.Ordenar por nombre descendente\n"
				"4.Ordenar por nombre ascendente\n"
				"5.Ordenar por nota descendente\n"
				"6.Ordenar por nota descendente y nombre ascendente\n"
				"7.Mostrar lista de aprobados\n"
				"8.Mostrar lista de aprobados llamados aaa\n"
				"9.aprobados cuyo nombre empieza con la A\n"
				"10.Salir\n"
				"Elija una opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				CargarListaDeAlumnos(listaAlumnos, T);
			break;
			case 2:
				MostrarListaDeAlumnos(listaAlumnos, T);
			break;
			case 3:
				OrdenarListaDeAlumnosPorNombreMayorAMenor(listaAlumnos, T);
			break;
			case 4:
				OrdenarListaDeAlumnosPorNombreMenorAMayor(listaAlumnos, T);
			break;
			case 5:
				OrdenarMayorAMenorNota(listaAlumnos, T);
			break;
			case 6:
				OrdenarMayorAMenorNotaYNombreAscendente(listaAlumnos, T);
			break;
			case 7:
				MostrarListaAprobados(listaAlumnos, T);
			break;
			case 8:
				MostrarListaAprobadosaaa(listaAlumnos, T);//cambiar funcion por nombre a elegir?
			break;
			case 9:
				MostrarListaAprobadosA0(listaAlumnos, T);
			break;
		}
	}while(opcion!=10);

	return EXIT_SUCCESS;
}


