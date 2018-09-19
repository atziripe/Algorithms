/*****************BUSQUEDA SECUENCIAL**************************
LORETTO ESTRADA GALILEA AMERICA
PEREZ GARCIA ATZIRI***/

/***********LIBRERIAS********************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/********ESTRUCTURA AUXILIAR PARA LOS ARGUMENTOS********/
/* Definida para pasar los argumentos que se requieren. */
struct argumentos{
	int dato;
	int *arreglo;
	int n;
};

/********THREAD BUSQUEDA SECUENCIAL********/
/* La funcion recibe como parametro una estructura.
La estructura contiene el dato a buscar, el tamaño del arreglo y el arreglo.
Devuelve la posicion en la que se encuentra el dato a buscar, o en su defecto si es
que el dato no esta en el arreglo.*/
void *sequentialSearch(void *recibido){
	int bandera = '0'; // Para saber si el elemento se encontro.
	struct argumentos *ptr = (struct argumentos *)recibido;
	
	int *arregloRecibido = ptr -> arreglo;
	int datoABuscarRecibido =  ptr -> dato;
	int tamRecibido = ptr -> n;
	
	for(int i=0; i<tamRecibido; i++){
		if(datoABuscarRecibido == arregloRecibido[i]){
			printf("El elemento esta en la posicion: %d \n", i+1);
			bandera = '1';
		}
	}
	
	if(bandera == '0'){
		printf("El elemento no se encuentra en el arreglo");
	}
}

/******** FUNCION PRINCIPAL ********/
int main (){
	int *A;
	int datoABuscar, tam;
	
	A = (int *)malloc(sizeof(int)*tam);
	
	printf("Ingrese longitud del arreglo: ");
	scanf("%d", &tam);
	
	printf("Ingrese los elementos:\n");
	for(int i=0; i<tam; i++){
		scanf("%d", &A[i]);
	}	
	
	printf("Ingrese el dato a buscar: ");
	scanf("%d", &datoABuscar);
	
	struct argumentos args;
	args.dato = datoABuscar;
	args.arreglo = A;
	args.n = tam;
	
	pthread_t busqueda;
	
	pthread_create(&busqueda, NULL, sequentialSearch, (void *)(&args));
	
	pthread_join(busqueda, NULL);
	
	return 0;
}