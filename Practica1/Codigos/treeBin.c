/*********** SHELL ***********
LORETTO ESTRADA GALILEA AMÉRICA 
PEREZ GARCIA ATZIRI*/
/***********LIBRERIAS********************/
#include <stdio.h>
#include <stdlib.h>
#include "BusBin.h"
#include <string.h>
#include "tiempo.h"

/*********************************Funcion PRINCIPAL******************************/
//Toma como entrada la longitud del arreglo.
int main(int argc, char const *argv[]){
  DicBin a = vacio ();
  Elem *array;
  double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
  int n;
  //******************************************************************  
  //Recepción y decodificación de argumentos
  //******************************************************************  

  //Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
  if (argc!=2) 
  {
    printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
    exit(1);
  } 
  //Tomar el segundo argumento como tamaño del algoritmo
  else
  {
    n=atoi(argv[1]);
  }
  //******************************************************************  
  //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
  //******************************************************************  
  uswtime(&utime0, &stime0, &wtime0);
  //******************************************************************
  
  //******************************************************************  
  //Algoritmo (llamada a la función que contiene el algoritmo)
  //******************************************************************  
  array =(int*)(malloc(sizeof(int)*argc)); //se pide espacio en memoria para guardar los numeros a ordenar
  for(int i=0; i<argc; i++){//Se guardan los elementos pedidos en la entrada en cada espacio de memoria pedido anteriormente
    scanf("%d", array+i);
    if (*(array+i))
    a = InsOrd (*(array+i), a);//Se van guardando en orden dentro del arbol
    }
  //******************************************************************
    //Evaluar los tiempos de ejecución 
  //******************************************************************
  uswtime(&utime1, &stime1, &wtime1);
  
  //Cálculo del tiempo de ejecución del programa
  printf("\n");
  printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
  printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
  printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
  printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
  printf("\n");
  
  //Mostrar los tiempos en formato exponecial
  printf("\n");
  printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
  printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
  printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
  printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
  printf("\n");
  //******************************************************************

  //Terminar programa normalmente 
  exit (0); 
  return 0;
}
