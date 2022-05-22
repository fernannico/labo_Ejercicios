/*
 ============================================================================
 Name        : estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct                      //necesito q las particulares vayan antes que la anhidadas porq esto se compila en orden. Si el domicilio no esta cargado habria error
{
    int calle[20];
    int numero;
    int codigoPostal;
    char localidad;
}eDomicilio;

typedef struct
{
    int dni;
    char nombre[20];
    																		//si pido direccion, son varios datos los q conforman esa informacion. Esto no sirve
    /*int calle[20];
    int numero;
    int codigoPostal;
    char localidad;//son un monton de campos en la misma estructura*/
    eDomicilio domicilioCliente;											//VER QUE EL LLAMADO ES DEL TIPO ESTRUCTURA
}eCliente;

typedef struct
{
    char cuit[20];
    char razonSocial[50];
    //y despues tiene un domicilio asiq se repite lo de arriba
    /*int calle[20];
    int numero;
    int codigoPostal;
    char localidad;*/
    eDomicilio domicilioProveedor;
}eProveedor;

//y si tengo un empleado, para domicilio se utilizan los mismos datos dde domicilio, asiq puedo hacer una estructura para domicilio. PERO si es ANIDADA, la tengo q llevar arriba

eDomicilio PedirUnDomicilio()
{
    eDomicilio unDomicilio;

    unDomicilio.numero = 3366;
    strcpy(unDomicilio.calle, "jujuy");
    unDomicilio.codigoPostal = 1870;
    strcpy(unDomicilio.localidad, "avellaneda");

    return unDomicilio;
}

int main(void) {

    eCliente miCliente;
    eDomicilio unDomicilio;

    miCliente.dni = 2222222;
    strcpy(miCliente.nombre, "luis");                                           //esto para asignarle un nombre WTF
     /*miCliente.domicilioCliente.numero = 3366;                                //los diversos niveles de anidamiento se acceden a travez del operador punto
    strcpy(miCliente.domicilioCliente.calle, "jujuy");
    miCliente.domicilioCliente.codigoPostal = 1870;
    strcpy(miCliente.domicilioCliente.localidad, "avellaneda");*/ /**DE ESTA MANERA ESTA DEFINIDO SOBRE LA VARIABLE domicilioCliente DEL PROPIO CLIENTE ¡¡campo por campo!!

    ahora puedo hacer: un "eDomicilio unDomicilio", de etsa manera, el domicilio esta como separado de cliente, no estamos trabajadno sobre la variable domicilioCliente */
    unDomicilio.numero = 3366;
    strcpy(unDomicilio.calle, "jujuy");
    unDomicilio.codigoPostal = 1870;
    strcpy(unDomicilio.localidad, "avellaneda");
    /**para poder pasar el domicilio creado (aparte), al cliente le tengo que asignar el domicilio que acabo de crear, por lo q voy al campo del comicilio del cliente*/
    miCliente.domicilioCliente = unDomicilio;
    /**creo un clente, creo un domicilio, al cliente le doy valores (propios: dni y nombre), al domicilio tambien le doy valores (propios) y ahora quiero asignar el domicilio creado
     * al cliente. Esto lo hago asignando al atributo domicilio de mi cliente (q es una estructura toda) el domicilio cargado por campo*/

   //podemos hacer una fx ---> linea45 (que habrai que cambiar el desarrollo, lo q esta seria harcodeado)
    miCliente.domicilioCliente = PedirUnDomicilio();

    return EXIT_SUCCESS;
}
#include <stdio.h>
