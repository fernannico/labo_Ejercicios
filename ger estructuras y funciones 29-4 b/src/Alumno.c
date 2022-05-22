#include <string.h>
#include "Alumno.h"

void InicializarListaAlumnos(eAlumno listaAlumnos[])/** puedo poner un size pero no va a ser el tamaño del vector sino la cantidad de E q voy a iniciailzar, asiq no hace falta*/
{
	/*listaAlumnos = {{10,"Pedro",7.5, OCUPADO},{99, "Ana", 9, OCUPADO},{14,"Luis",5, OCUPADO}};
	 * esto de nuevo, no me deja hacerlo (tira error) porq es un vector asignandole otro vector y eso no se puede.*/
	 /** lo que tengo que hacer es crear un nuevo vector auxiliar	*/
	eAlumno harcodeos[10] = {{10,"german",7.5, OCUPADO},{99, "Analia", 9, OCUPADO},{14,"eze",5, OCUPADO}, {10,"nico",7.5, OCUPADO}, {10,"FAbio",7.5, OCUPADO}};
	/**ahora tengo que reemplazar listaAlumnos por el auxiliar, copiarlo. Pero no puedo asignar un vector a otro vector. Tampoco puedo usar strcmp porq es una array.
	 * TENGO QUE USAR UN FOR PARA HACER QUE ESE VECTOR SE ASIGNE A EL OTRO, ELEMENTO POR ELEMENTO */
	for(int i = 0; i < 10; i++)
	{
		listaAlumnos[i] = harcodeos[i];/**ESTA ES LA MANERA DE ASIGNAR UN VECTOR A OTRO VECTOR*/
	}
}

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

	miAlumno.estado = OCUPADO;/** ahi lo encapsule a que cada vez que ingrese un alumno, ya lo muestre como ocupado*/

	return miAlumno;
}

void MostrarUnAlumno(eAlumno miAlumno)
{

	printf("%4d %10s %4.2f\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio);
}

void CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos)/** comentario fina: no esta tan bien en verdad la fx. Funciona pero muy cargada y es void. Quiero reducirla y que me devuelva algo*/
{
	int flag;/**tengo un problema donde puede ser que ya haya ocupado todos las posiciones y aun asi me va a dejar seguir ingresando alumnos, entonces tengo que decir CUANDO se ocupo tod0*/
	flag = 0;
	int i;/**tengo que declarar la i afuera del for para que sea una variable general y la pueda usar en el if(i == size)*/
	for(i=0; i<sizeAlumnos; i++)/** rrecorro el vector y antes de cargar los datos del alumno, pregunto si el estado de ese alumno esta libre */
	{
		if(listaAlumnos[i].estado == LIBRE)/** aca me va a cargar mientras haya uno libre. Pero tengo que decir algo cuando no hay mas espacio*/
		{
			listaAlumnos[i] = PedirUnAlumno();/**el for con PedirUnAlumno devolvia un alumno con datos y lo cargaba en una posicion
											especifica del vetor.*/
			listaAlumnos[i].estado = OCUPADO;/**medio como una bandera. Si no pongo esto, siempre va a cargar al indice 0, porq no estoy cambiando el estado*/
			flag = 1;
			break;/**Si no pongo esto, me cambia a TODOS como ocupados. Necesito que PARE una vez encontro a alguien libre. CIERRO EL BUCLE FOR!!!!*/
		}
	}
	if(flag == 0)/** si es = 0 significa que nunca entro al if porque estaba tod0 ocupado. Es decir que iteró todas las posiciones, llegó al final del for
				pero nunca cambio el estado	 */
	{
		printf("no hay espacio");
	}
	/**LA OTRA FORMA DE SABER SI SE OCUPARON TODOS LOS ESPACIOS DEL VECTOR: cuando i coincide con el size quiere decir q el for llego al final del array por
	 * lo que no hay mas espacios. o sea

		if(i == sizeAlumnos)
		{
			printf("no hay espacio");
		}

	 * */
}

/**tratamos que la fx anterior se comunique con el exterior para decir qe paso adentro.
 * neceito una fx que me diga QUE POSICION DEL ARRAY ESTA LIBRE. El int que devuelve es la posicion del espacio libre*/
int BuscarEspacioLibre(eAlumno listaAlumnos[], int sizeAlumnos)
{
	int index;
	index = -1; /**ESTO QUIERE DECIR QUE POR DEFAULT NO HAY ESPACIO HASTA Q SE DEMUESTRE LO CONTRARIO (cuando tengo uno libre)*/
	for(int i = 0; i < sizeAlumnos; i++)/**busca qué espacio esta libre en el array asiq hay que hacer un for con los alumnos */
	{
		if(listaAlumnos[i].estado == LIBRE)
		{
			index = i;/**la fx busca donde hay un indice disponible para guardar un dato y en caso que este lleno me devuelve -1*/
			break;/**rompo xq sino sigo buscando por lo q cargo desde el ultimo hacia el primero*/
		}
	}

	return index;
}					//ya en tp

int CargarListaDeAlumnosMejorada(eAlumno listaAlumnos[], int sizeAlumnos)
{
	int index;

	index = BuscarEspacioLibre(listaAlumnos, sizeAlumnos); /** una vez tengo el espacio libre, le tengo que decir que me lo cargue. Asiq:*/

	if(index != -1)/** distinto a -1 porq -1 quiere decir que no hay espacio!! si hay, que haga algo*/
	{
		listaAlumnos[index] = PedirUnAlumno(); 	/** a pedir alumno le agrego que cada vez que se ingrese un alumno, decir que el espacio este ahora ocupado*/
	}

	return index;/**EN VEZ DE DEVOLVER EL INDEX SE PODRIA PREGUNTAR EN EL IF "estas seguro que queres impactar los cambios?" y si pone que no, no se carga el alumno
	por lo que tengo que devolver otro estado, no puedo devolver -1 o cualquier otro valor, tengo q manejar otros valores y despues preguntar por afuera de la fx*/
}


void MostrarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos)
{
	for(int i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].estado == OCUPADO)/**Siempre muestro TOD0 el array, pero lo que quiero es mostrar solo los cargados,  sin esto mostraria la basura en los indices q no se agregó nada todavia*/
		{
			MostrarUnAlumno(listaAlumnos[i]);
		}
	}
			/** se puede hacer "si estan todos los alumnos libres, con un flag hago que devuelva "no hay alumnos para mostrar" ". Por lo que podemos pasar las funciones void a que devuelvan un entero
			 * para que no sean void. Entonces segun el caso, podemos devolver un estado al main para hacer un mensaje en cada uno de los casos."*/
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

int ModificarAlumno(eAlumno vectorControl[], int size)//si bien es solo para promedio, HACER QUE LA PERSONA DECIDA q cambiar.
{/**vamos a modificar el promedio en este caso; lueggo hacer del resto.*/
	/**primero hay que buscar uno desde un parametro, ej legajo. Despues q lo encuentro preguntar que cambiar o sea dar a elegir nombre o promedio.
	 * Pero legajo no cambia porq es el q me permite identificar un alumno dentro de tod0 el dominio. Si cambio el legajo tengo q hacer cambios en todos los
	 * registros en donde se hable de ESE legajo. ej si cambio de dni, voy a tener problema con todos los registros donde esta mi dni anterior.
	 * ejemplo de legajo se aplica para materias aprobadas, seria un quilombo. Entonces, las CLAVES PRIMARIAS no se modifican*/

	/**dijimos de 1ero pedir el legajo y despues buscar el legajo. Y si existe el legajo, modificar el promedio.*/
	int legajo;
	int modifico;

	modifico = -1; /**indica que no existe el legajo por default*/

	printf("ingrese legajo a modificar: ");
	scanf("%d", &legajo);

	/**busco el legajo en el array para ver si existe*/
	for(int i = 0; i < size; i++)
	{
		if(vectorControl[i].estado == OCUPADO && vectorControl[i].legajo == legajo)/**pregunto si lista de alumnos en posiion i esta ocupado. Es importante
		por ejemplo para bajar lo de preguntar si esta disponible. Despues preguntar si el legajo disponible coincide con el legajo q ingresó el usuario.
		si sucede es xq lo encontré. Si lo encontre, interactuo con el usuario para preguntarle que modificar (ahora solo promedio).*/
		{
			/**ENCONTRE EL LEGAJO*/
			printf("ingrese el nuevo promedio: ");
			scanf("%f", &vectorControl[i].promedio);/** si llegó aca obligo a cambiar el promedio, pero tengo que preguntarle qué dato modificar.
														Que el programa pregunte si esta seguro de la modificacion.
														Mantenerlo en el bucle preguntando si quiere modificar otra cosa para el mismo alumno (ej si cambió promedio, pregunta
														si quiere cambiar materias o lo q sea)*/
			modifico = 1;/**si entra al if es porq encnotro al legajo asiq cambio la bandera*/

			//pudo haber entrado al if pero no haber modificado nada si le pregunto si esta seguro y hubiera dicho que no. HACER el caso de q cancele la modificacion. minimo 3
			//posibles estados: que no lo encuentre, que lo encuentre y modifique, que lo encuentre pero no lo modifique

			break;/** para que si ya encontro el legajo deje de buscar!!!!!! rompo el for*/
		}/**CON SWITCH PARA PONER LAS OPCIONES DE DE ELEGIR*/
	}
	return modifico;/**desde afuera de la funcion tengo que saber si encontro el legajo, si modifico o no.*/
}


int EliminarAlumno(eAlumno vectorControl[], int size, int legajo)/** LA BAJA es en si una modificacion del estado. Lo primero es preguntar si esta ocupado, si se lo encuentra se le
				modifica el estado. Existen bajas logicas y fisicas (las fisicas no importa). Lo que hacemos es marcar el estado, usar el estado de la estructura para ver si
			 	 esta activo o no. Si hay una baja, se carga primero en el que di de baja, porq cuando el for busque donde puede cargar uno nuevo, va a encontrar primero al
			 	 que esta libre. O sea si se dio de baja el [1] y a partir del [4] estan libres, se carga en el [1].
			 	 si me piden los que estan dados de baja, puedo crear otro define con bajas. entonces tenemos libres (0), ocupados (1) y bajas (-1). Pero en este caso, no
			 	 puedo reutilizar el espacio de los dados de baja.
			 	 Si el ejercicio no lo requiere, paso directamente los q se dan de baja a libres.. para no tener que poner un -1 y que no tenga que pasar los -1 a 0.
			 	 	 entonces esto de pasar a -1 no se usa? lo que hacemos llevarme al alumno que di de baja a otro vector "alumnosDeBaja". PERO ESTO POR AHORA NOOO*/
{/** el codigo es parecido a la modificacion del promedio porq a fin y al cabo es un cambio de estado de un dato del vector*/
	int retorno;

	retorno = -1; /**indica que no existe el legajo por default*/

	printf("ingrese legajo a modificar: ");
	scanf("%d", &legajo);

	/**busco el legajo en el array*/
	for(int i = 0; i < size; i++)
	{
		if(vectorControl[i].estado == OCUPADO && vectorControl[i].legajo == legajo)
		{
			/**si ENCONTRE EL LEGAJO*/
			vectorControl[i].estado = LIBRE; /** lo pongo en disponibilidad de vuelta porq los estados son libre-ocupado. DE ESTA MANERA, AL DAR DE BAJA SE PIERDE AL ALUMNO
			 	 	 	 	 	 	 	 	 	 aunq se puede hacer lo de definir otro estado y asi quedan los datos*/
			retorno = 1;
			break;/** para que si ya encontro el legajo deje de buscar*/
		}
	}

	return retorno;
}





