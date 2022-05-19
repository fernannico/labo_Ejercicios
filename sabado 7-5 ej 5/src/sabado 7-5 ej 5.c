/*
Ejercicio 5 (RELACIONES):
Establecer las relaciones entre datos
Usuario (nombre)
Posteo(comentario)
Hashtag(descripcion)

Hardcodear datos para las 3 entidades

Listados
Por cada usuario su comentario junto al hashtag
El porcentaje que representa cada hashtag sobre el total de posteos
E/los hashtags menos utilizado
El nombre de los usuarios que usaron el hashtag #VIVALAFRA

 */

#include <stdio.h>
#include <stdlib.h>
#define size 4

typedef struct
{
	char nombre[20];
	int idUsuario;
}eUsuario;

typedef struct
{
	int idPosteo;
	char comentario[100];

	int idUsuario;
}ePosteo;

typedef struct
{
	int idHashtag;
	char descripcion[20];
}eHashtag;

typedef struct
{
	int idPosteo;
	int idHashtag;
}eRelacion;

//Hardcodear datos para las 3 entidades

int main(void)
{
	setbuf(stdin, NULL);

	//eUsuario usuarioHarcodeo[size] = {{"nico", 123}, {"ivan", 456}, {"ailin", 789}, {"edith", 147}};

	ePosteo posteosHarcodeo[size] = {{321, "batata", 123}, {654, "banana", 456}, {987, "barbacoa", 789}, {741, "bondiola", 147}};

	eHashtag hashtagHarcodeo[size] = {{159, "#dieta"}, {357, "#Vegano"}, {157, "#Crossfit"}, {359, "#carnivoro"}};

	eRelacion relacionHarcodeo[size] = {{321, 159}, {654, 357}, {157, 987}, {359, 741}};

	/** el programa es DE POSTEO A RELACION Y DE RELACION A HASHTAG*/

	/*Listados
		Por cada usuario su comentario junto al hashtag
		El porcentaje que representa cada hashtag sobre el total de posteos
		E/los hashtags menos utilizado
		El nombre de los usuarios que usaron el hashtag #VIVALAFRA
	*/
	for(int i = 0; i < size; i++)
	{
		if(posteosHarcodeo[i].idPosteo == 987)
		{
			for(int j = 0; j< size; j++)
			{
				if(relacionHarcodeo[j].idPosteo == posteosHarcodeo[i].idPosteo)
				{
					for(int k = 0; k < size; k++)
					{
						if(hashtagHarcodeo[k].idHashtag == relacionHarcodeo[j].idHashtag)
						{
							printf("%s", hashtagHarcodeo[k].descripcion);
						}
					}
				}
			}
		}
	}

	return EXIT_SUCCESS;
}









