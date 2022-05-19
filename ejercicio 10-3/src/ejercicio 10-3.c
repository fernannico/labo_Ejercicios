/*
 * Ejercicio 10-3:
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
idProducto (numerico)
descripcion (alfanumérico)
nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
tipo (numérico)
precio (numérico decimal)

Agregar la estructura etipoProducto, que definirá los siguientes campos:
idTipo (numérico)
descripcionTipo(alfanumérico)

Para esta estructura en principio trabajaremos con datos hardcodeados:
idTipo 	descripcionTipo
1000	Iphone
1001	Ipad
1002	Mac
1003	Accesorios
*/
/**ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array. Al momento de dar de alta el producto, el usuario podrá elegir el tipo de producto, de una lista que se le desplegará en pantalla.
BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo. Si modifica el tipo de producto, se utilizará el mismo criterio que para dar de alta.
LISTADO Productos.
LISTADO ordenado por precio.
LISTADO ordenado por descripción.
 * Agregar los siguientes informes:
	Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.
	El/los  productos más caros.
 * */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*define EEUU 47
#define CHINA 57
#define OTRO 67*/

#define T 4

typedef struct
{
	int idProducto;
	char descripcion[30];	//no es lo mismo q la otra descripcion, puede ser iphone X o bla... como modelos
	int nacionalidad;
	//int tipo;				NO VA PORQUE TENEMOS EL ID!!!!!!
	int idTipo;
	float precio;

	//int estado;
}eProducto;

typedef struct
{
	int idTipo;
	char descripcionTipo[30];
}eTipoProducto;

float CalcularPromedio(float acumulador, int contadorUnidades);



int main()
{
	setbuf(stdout, NULL);
	//int opcion;
	int contador;
	float acumulador;
	float promedio;

	/** hay que inicializar el prodecuto. Para eso hay que ponerle el estado*/
	eProducto producto[5] = {{1, "produto 1", 47, 1000, 15000},
							{2, "produto 2", 47, 1001, 30000},
							{3, "produto 3", 57, 1002, 45000},
							{4, "produto 4", 57, 1003, 60000.5},
							{5, "produto 5", 67, 1000, 100000.5}};
	/**el define no va la letra....? NO! porq lo definiste mal al define*/
	eTipoProducto tipo[T] = {{1000, "Iphone"}, {1001, "Ipad"}, {1002, "Mac"}, {1003, "Accesorios"}};/**sin [] no es array*/

	/**switch(opcion)
	{
		case :
		break;
		case :
		break;

	}*/												//NO SE PROGRAMA EN FUNCION DE 33:00 LO DE SWITCH ESTA MUY MAL

	/**hacer un for q pase por la estructura tipo y otro for q pase por la estructura producto
	 * lo mejor es programar all primero en el main y despues pasar a fx*/
	for(int i = 0; i < T; i++)
	{
		contador = 0;										/*53 IMPORTANTE LA UBICACION DEL CONTAOR*/
		printf("%s", tipo[i].descripcionTipo);
		acumulador = 0;

		for(int j = 0; j < 5; j++)
		{
			if(tipo[i].idTipo == producto[j].idTipo)
			{
				acumulador = acumulador + producto[j].precio;
				contador++;
			}
		}
		promedio = acumulador/contador;
																//1:00:00 importante promedio ubicacion
		printf("\n%-4s %10.2f", tipo[i].descripcionTipo, promedio);
	}

    return EXIT_SUCCESS;
}

float CalcularPromedio(float acumulador, int contadorUnidades)
{
	float promedio;

	promedio = acumulador / contadorUnidades;

	return promedio;
}




/*rever a partir de la 1:00:00*/








