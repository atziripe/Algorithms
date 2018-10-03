/*****************BUSQUEDA SECUENCIAL**************************
LORETTO ESTRADA GALILEA AMERICA
PEREZ GARCIA ATZIRI***/

/***********LIBRERIAS*******************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "BusBin.h"

/********* VARIABLES GLOBALES **********/
int NumThreads;

/********ESTRUCTURA AUXILIAR PARA LOS ARGUMENTOS********/
/* Definida para pasar los argumentos que se requieren. */
typedef struct argumentos{
  int id;
  int dato;
  int *arreglo;
  int n;
} *datos;

/***********FUNCION ARBOL DE BUSQUEDA BINARIA********************/
/* La funcion recibe como parametros el arbol binario donde se encuentran ordenados todos los elementos, 
el tamaño a buscar y la altura del arbol. 
Regresa el 1 o 0 dependiendo si se encuentra o no el elemento*/
void* Buscar_ABB(void *recibido){
  //variables de ayuda para reparticion de threads
  int inicio = 0, fin = 0;
  DicBin arbolito = vacio();
  int altcont = 0, alt = 0 ;
  
  datos ptr = (datos)recibido;
  
  int *ArrayRecibido;
  Elem datoABuscarRecibido = (Elem)ptr -> dato;
  int tamRecibido = ptr -> n;
  int n_Thread = ptr -> id;

  inicio=(n_Thread*tamRecibido)/NumThreads;
  if(n_Thread==NumThreads-1)  
    fin=tamRecibido;
  else
    fin=((n_Thread+1)*tamRecibido)/NumThreads-1;

  for(int i=inicio;i<=fin;i++)
    arbolito = InsOrd (*(ArrayRecibido+i), arbolito);
  alt = altura(arbolito);

  if (!vacio(arbolito)){
    while (!vacio(arbolito) && raiz(arbolito)!=datoABuscarRecibido && altcont<alt){
      if (datoABuscarRecibido < raiz(arbolito)){
        arbolito=izquierdo(arbolito);
      }
      if (raiz(arbolito) < datoABuscarRecibido){
        arbolito=derecho(arbolito);
      }
      alt++;
    }      
    if(!vacio(arbolito) && raiz(arbolito)==datoABuscarRecibido)
      printf("Numero encontrado :)\n");  
    else 
      printf("Numero no encontrado :(\n");   
  }
}                     

/******FUNCION PRINCIPAL****************/
int main(int argc, char *argv[]){
  int N = 0, num=0, res = 0, i = 0;
  DicBin arbolito = vacio();
  Elem *array;

  pthread_t *thread;
  if (argc<2) {
    printf("Indique el numero de threads - \tEjemplo: [user@equipo]$ %s 4\n\n",argv[0]);
    exit(-1);
  }  
  NumThreads=atoi(argv[1]);
  if (argc<3) {
   printf("\nIndique eltamaño del problema - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
    exit(-1);
  }
  N=atoi(argv[2]);
  if(argc!=4){
    printf("\nIndique el numero a buscar - \nEjemplo: [user@equipo]$ %s %s 1000 %s \n",argv[0],argv[1],argv[2]);
    exit(-1);
  }
  num=atoi(argv[3]);

  array = (int*)malloc(sizeof(int)*N);
  for(int i=0; i<N; ++i)
    scanf("%d", array+i);

  struct argumentos args;
  args.id = i;
  args.dato = num;
  args.arreglo = array;
  args.n = N;

  // creando threads
  for(i=0; i<=NumThreads; i++){
    struct argumentos args ={i,num,array,N};
    if(pthread_create(&thread[i], NULL, Buscar_ABB, (void *)(&args)) != 0){
      perror("El thread no pudo crearse");
      exit(-1);
    }
  }

  for(i=1; i<=NumThreads; i++)
    pthread_join(thread[i], NULL);

  return 0;
}