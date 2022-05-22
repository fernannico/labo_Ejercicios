#include "Alumno.h"

void InicializarListaAlumnos(eAlumno listaAlumnos[])
{
	eAlumno harcodeos[10] = {{10,"german",7.5, 2, OCUPADO},{99, "Analia", 9, 3, OCUPADO},{14,"eze",5, 3, OCUPADO}, {10,"nico",7.5, 1, OCUPADO}, {10,"FAbio",7.5, 2, OCUPADO}};
	for(int i = 0; i < 10; i++)
	{
		listaAlumnos[i] = harcodeos[i];
	}
} /**ahora hay que ponerle los cursos en el harcodeo*/

/**																							FUNCIONES GERMAN*/
/*eAlumno PedirUnAlumno()
{
	eAlumno miAlumno;

	printf("Ingrese el legajo: ");
	scanf("%d", &miAlumno.legajo);
	printf("Ingrese el nombre: ");
	fflush(stdin);
	gets(miAlumno.nombre);
	printf("Ingrese el promedio: ");
	scanf("%f", &miAlumno.promedio);

	scanf("%d", &miAlumno.idCurso);

	miAlumno.estado = OCUPADO;

	return miAlumno;
}*/												/**PASADO A NEXO*/

void MostrarUnAlumno(eAlumno miAlumno)
{

	printf("%4d %10s %4.2f %4d\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio, miAlumno.idCurso);
}

/*
void CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos)
{
	int flag;
	flag = 0;
	int i;
	for(i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].estado == LIBRE)
		{
			listaAlumnos[i] = PedirUnAlumno();
			listaAlumnos[i].estado = OCUPADO;
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		printf("no hay espacio");
	}
}*/									/**USAMOS LA MEJORADA Q ESTA EN NEXO*/

int BuscarEspacioLibre(eAlumno listaAlumnos[], int sizeAlumnos)
{
	int index;
	index = -1;
	for(int i = 0; i < sizeAlumnos; i++)
	{
		if(listaAlumnos[i].estado == LIBRE)
		{
			index = i;
			break;
		}
	}

	return index;
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

void OrdenarListaDeAlumnosPorNombreMayorAMenor(eAlumno listaAlumnos[], int sizeAlumnos)
{
	eAlumno auxiliarAlumno;
	for(int i = 0; i < sizeAlumnos-1; i++)
	{
		for(int j = i+1; j<sizeAlumnos; j++)
		{
			if(strcmp(listaAlumnos[i].nombre,listaAlumnos[j].nombre)<0)
			{
				auxiliarAlumno = listaAlumnos[i];
				listaAlumnos[i] = listaAlumnos[j];
				listaAlumnos[j] = auxiliarAlumno;
			}
		}
	}
}

void OrdenarListaDeAlumnosPorNombreMenorAMayor(eAlumno listaAlumnos[], int sizeAlumnos)
{
	eAlumno auxiliarAlumno;
	for(int i = 0; i < sizeAlumnos-1; i++)
	{
		for(int j = i+1; j<sizeAlumnos; j++)
		{
			if(strcmp(listaAlumnos[i].nombre,listaAlumnos[j].nombre)>0)
			{
				auxiliarAlumno = listaAlumnos[i];
				listaAlumnos[i] = listaAlumnos[j];
				listaAlumnos[j] = auxiliarAlumno;
			}
		}
	}
}

/**  																						FUNCIONES PROPIAS*/

void OrdenarMayorAMenorNota(eAlumno vectorControl[], int size)
{
	eAlumno auxiliarEntero;
	for(int i = 0; i < (size - 1); i++)
	{
		for(int j = i+1; j < size; j++ )
		{
			if(vectorControl[i].promedio < vectorControl[j].promedio)
			{
				auxiliarEntero = vectorControl[i];
				vectorControl[i] = vectorControl[j];
				vectorControl[j] = auxiliarEntero;
			}
		}
	}
}

void OrdenarMayorAMenorNotaYNombreAscendente(eAlumno vectorControl[], int size)
{
	eAlumno auxiliarEntero;

	for(int i = 0; i < (size - 1); i++)
	{
		for(int j = i+1; j < size; j++ )
		{
			if(vectorControl[i].promedio < vectorControl[j].promedio)
			{
				auxiliarEntero = vectorControl[i];
				vectorControl[i] = vectorControl[j];
				vectorControl[j] = auxiliarEntero;
			}else{
				if(vectorControl[i].promedio == vectorControl[j].promedio)
				{
					if(strcmp(vectorControl[i].nombre, vectorControl[j].nombre) > 0)
					{
						auxiliarEntero = vectorControl[i];
						vectorControl[i] = vectorControl[j];
						vectorControl[j] = auxiliarEntero;
					}
				}
			}
		}
	}
}

void MostrarListaAprobados(eAlumno vectorControl[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(vectorControl[i].promedio >= 7)
		{
			MostrarUnAlumno(vectorControl[i]);
		}
	}
}

void MostrarListaAprobadosaaa(eAlumno vectorControl[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(vectorControl[i].promedio >= 7)
		{
			if(strcmp(vectorControl[i].nombre, "aaa") == 0)
			{
				MostrarUnAlumno(vectorControl[i]);
			}
		}
	}
}

void MostrarListaAprobadosA0(eAlumno vectorControl[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(vectorControl[i].promedio >= 7)
		{
			if(vectorControl[i].nombre[0] == 'A')
			{
				MostrarUnAlumno(vectorControl[i]);
			}
		}
	}
}

int ModificarAlumno(eAlumno vectorControl[], int size)
{
	int legajo;
	int modifico;

	modifico = -1;

	printf("ingrese legajo a modificar: ");
	scanf("%d", &legajo);

	for(int i = 0; i < size; i++)
	{
		if(vectorControl[i].estado == OCUPADO && vectorControl[i].legajo == legajo)
		{
			/**ENCONTRE EL LEGAJO*/
			printf("ingrese el nuevo promedio: ");
			scanf("%f", &vectorControl[i].promedio);
			break;
		}
	}
	return modifico;
}


int EliminarAlumno(eAlumno vectorControl[], int size)
{
	int retorno;
	int legajo;

	retorno = -1;

	printf("ingrese legajo a eliminar: ");
	scanf("%d", &legajo);

	for(int i = 0; i < size; i++)
	{
		if(vectorControl[i].estado == OCUPADO && vectorControl[i].legajo == legajo)
		{
			vectorControl[i].estado = LIBRE;
			retorno = 1;
			break;
		}
	}

	return retorno;
}





