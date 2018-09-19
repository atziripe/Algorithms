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

/********THREAD BUSQUEDA BINARIA********/
/**/
void *binarySearch(void *recibido){
	int bandera = '0'; // Para saber si el elemento se encontro.
	struct argumentos *ptr = (struct argumentos *)recibido;
	
	// tomando datos de la estructura.
	int *arregloRecibido = ptr -> arreglo;
	int datoABuscarRecibido =  ptr -> dato;
	int tamRecibido = ptr -> n;
	
	int final, medio, inicio = 0; // Variables para realizar la busqueda.
	final = tamRecibido-1;
	
	// Busqueda
	while(inicio<=final){
		medio = (inicio + final)/2;
		if(datoABuscarRecibido == *(arregloRecibido+medio)){
			bandera = '1';
			break;
		} else{
			if(*(arregloRecibido+medio)>datoABuscarRecibido){
				final = medio - 1;
			}
			else{
			inicio = medio + 1;
			}
		}
	}
	
	if(bandera == '0')
		printf("El numero no esta en el arreglo.");
	else
		printf("El numero se encuentra en la posicion: %d", medio+1);

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
	
	// creando thread
	pthread_t busqueda;
	
	pthread_create(&busqueda, NULL, binarySearch, (void *)(&args));
	
	pthread_join(busqueda, NULL);
	
	return 0;
}