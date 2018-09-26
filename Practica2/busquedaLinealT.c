/*****************BUSQUEDA SECUENCIAL**************************
LORETTO ESTRADA GALILEA AMERICA
PEREZ GARCIA ATZIRI***/

/***********LIBRERIAS********************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/********* VARIABLES GLOBALES **********/
int NumThreads;

/********ESTRUCTURA AUXILIAR PARA LOS ARGUMENTOS********/
struct argumentos{
	int id;
	int dato;
	int *arreglo;
	int n;
};

/********THREAD BUSQUEDA SECUENCIAL********/
void *sequentialSearch(void *recibido){
	int bandera = '0'; // Para saber si el elemento se encontro.
	struct argumentos *ptr = (struct argumentos *)recibido;
	
	int *arregloRecibido = ptr -> arreglo;
	int datoABuscarRecibido =  ptr -> dato;
	int tamRecibido = ptr -> n;
	int n_Thread = ptr -> id;
	
	for(int i=0; i<tamRecibido; i++){
		if(datoABuscarRecibido == arregloRecibido[i]){
			bandera = '1';
		}
	}
	
	if(bandera == '1'){
		printf("Hilo %d.\t", n_Thread);
		printf("Numero encontrado.\n");
		// printf("El elemento esta en la posicion: %d \n", i+1);
	}
	else{
		printf("Hilo %d.\t", n_Thread);
		printf("Numero no encontrado.\n");
	}
}

/******** FUNCION PRINCIPAL ********/
int main (int argc, char *argv[]){
	int *A;
	int datoABuscar, tam, i;
	
	// Conocer el numero de threads
	pthread_t *thread;
	if(argc<2){
		printf("Indique el numero de threads - \n Ejemplo: [user@equipo]$ %s 4\n\n", argv[0]);
		exit(-1);
	}
	NumThreads = atoi(argv[1]);
	thread = malloc(NumThreads*sizeof(pthread_t));
	
	// Tamanio del arreglo;
	if(argc<3){
		printf("\nIndique el tamanio de N - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
		exit(-1);
	}
	tam=atoi(argv[2]);
	
	// Dato a buscar
	if(argc!=4){
		printf("\nIndique numero a buscar - \nEjemplo: [user@equipo]$ %s %s 1000 %s \n",argv[0],argv[1],argv[2]);
		exit(-1);
	}
	datoABuscar=atoi(argv[3]);
	
	A = (int *)malloc(sizeof(int)*tam);
	
	// Guardando elementos
	for(int i=0; i<tam; i++){
		scanf("%d", A+i);
	}	
	
	struct argumentos args;
	args.id = i;
	args.dato = datoABuscar;
	args.arreglo = A;
	args.n = tam;
	
	for(i=1; i<=NumThreads; i++){
		struct argumentos args ={i,datoABuscar,A,tam};
		if(pthread_create(&thread[i], NULL, sequentialSearch, (void *)(&args)) != 0){
			perror("El thread no pudo crearse");
			exit(-1);
		}
	}
	
	sequentialSearch(0);
	
	for(i=1; i<=NumThreads; i++)
		pthread_join(thread[i], NULL);
	
	return 0;
}