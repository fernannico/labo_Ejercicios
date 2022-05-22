#include "funciones.h"

void inicializarAlumno(eAlumno listaAlumnos[], int sizeAlumnos)
{
    for(int i=0;i<sizeAlumnos;i++)
    {
        listaAlumnos[i].estado = LIBRE;
    }
}

void OrdenarListaDeAlumnosPorNombre(eAlumno listaAlumnos[], int sizeAlumnos)
{
	eAlumno auxiliarAlumno;
	for(int i = 0; i < sizeAlumnos-1; i++)
	{
		for(int j = i+1; j<sizeAlumnos; j++)
		{
			if(listaAlumnos[i].estado == OCUPADO)
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
}

/*void alumnosAprobados(eAlumno listaAlumnos[], int sizeAlumnos)
{

	for(int i=0; i<sizeAlumnos; i++)
	{
	    if(listaAlumnos[i].estado == OCUPADO && listaAlumnos[i].promedio>=7)
	    {
	        MostrarUnAlumno(listaAlumnos[i]);
	    }
	}
}*/

void ordenarPorNota(eAlumno listaAlumnos[], int sizeAlumnos)
{
    eAlumno auxiliarAlumno;

	for(int i = 0; i < sizeAlumnos-1; i++)
	{
		for(int j = i+1; j<sizeAlumnos; j++)
		{
		    if(listaAlumnos[i].estado == OCUPADO)
		    {
    		       if(listaAlumnos[i].promedio<listaAlumnos[j].promedio)
    			{
    				auxiliarAlumno = listaAlumnos[i];
    				listaAlumnos[i] = listaAlumnos[j];
    				listaAlumnos[j] = auxiliarAlumno;
    			}else{
    			    if(listaAlumnos[i].promedio == listaAlumnos[j].promedio)
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

		}
	}
}

