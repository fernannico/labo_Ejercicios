#include <string.h>
#include "Alumno.h"

/**																							FUNCIONES GERMAN*/
eAlumno PedirUnAlumno()
{
	eAlumno miAlumno;

	printf("Ingrese el legajo: ");
	scanf("%d", &miAlumno.legajo);
	printf("Ingrese el nombre: ");
	fflush(stdin);
	gets(miAlumno.nombre);//scanf("%[^\n]", miAlumno.nombre); ... fgets
	printf("Ingrese el promedio: ");
	scanf("%f", &miAlumno.promedio);

	return miAlumno;
}

void MostrarUnAlumno(eAlumno miAlumno)
{

	printf("%4d %10s %4.2f\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio);
}

void CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos)
{
	for(int i=0; i<sizeAlumnos; i++)
	{
		listaAlumnos[i] = PedirUnAlumno();
	}
}

void MostrarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos)
{
	for(int i=0; i<sizeAlumnos; i++)
	{
		MostrarUnAlumno(listaAlumnos[i]);
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
			//strcmp no porque eso compara strings y promedio es float
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

	//OrdenarListaDeAlumnosPorNombreMenorAMayor(vectorControl, size);
	/** no porque es primero un ordenamiento y depues lo desordeno a otro ordenamiento**/


	for(int i = 0; i < (size - 1); i++)
	{
		for(int j = i+1; j < size; j++ )
		{
			if(vectorControl[i].promedio < vectorControl[j].promedio)/**primero pregunto si los promedi0os son uno mayor q el otro. El ordenamiento
															no va xq es con el mismo for. Si el primer promedio no es meonr al 2do y son iguales*/
			{
				auxiliarEntero = vectorControl[i];
				vectorControl[i] = vectorControl[j];
				vectorControl[j] = auxiliarEntero;
				/**el if de == no va aca porque estaria diciendo que ya es menor al otro se cumpla una condicion extra.
				 * Pero no puede ser uno menor a otro y a la vez ==*/
			}else{
				if(vectorControl[i].promedio == vectorControl[j].promedio)/**pregunto si un promedio no es menor al otro y son iguales*/
				{
					if(strcmp(vectorControl[i].nombre, vectorControl[j].nombre) > 0)/**no puedo llamar a otra funcion o crear otro for xq sino
									estoy ejecutando otro for para ordenar alfabeticamente. Tengo que ordenar con los dos mismos for de arriba.
									Se compara en el burbujeo la posicion control con la posterior, no puedo poner i == i sino compara con si mismo,
									tiene que ser i con j*/
					{
						auxiliarEntero = vectorControl[i];
						vectorControl[i] = vectorControl[j];
						vectorControl[j] = auxiliarEntero;
						/**comparo los string con "string compare" y si se cumple, si llegue a este if, es porque los promedios son igaules.
						 * Y si son iguales, que se ordenen por nombre. Como estoy en este if de solo notas iguales, solo se ordenan los que
						 * son de notas iguales. O SEA QUE NO SE PISAN LOS ORDENAMIENTOS, SINO LO COPMPLEMENTA. ESTO PORQ ES UN SI, SINO, SI.
						 * ordeno por nombre si no se cumplio el criterio de arriba (109)*/
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
			if(strcmp(vectorControl[i].nombre, "aaa") == 0)/**como necesito comparar toda la cadena necesito un strcmp, en cambio si quiero comparar
																una sola letra no lo necesito y solo va con ==*/
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
			//if(strcmp(vectorControl[0].nombre, 'A') == 0)
			/**strcmp MAL porque no quiero comparar toda la cadena, sino 1 letra de la cadena.
			 * El primer indice tiene que ser i porque estoy consutlando por el alumno de la iteracion,
			 * el 2do indice hace referencia a una posicion dentro de la cadea*/
			if(vectorControl[i].nombre[0] == 'A')
			{
				MostrarUnAlumno(vectorControl[i]);
			}
		}
	}
}

