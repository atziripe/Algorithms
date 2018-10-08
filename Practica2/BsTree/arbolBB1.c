/*****************BUSQUEDA SECUENCIAL**************************
LORETTO ESTRADA GALILEA AMERICA
PEREZ GARCIA ATZIRI***/

/***********LIBRERIAS*******************/
#include <stdio.h>
#include <stdlib.h>
#include "BusBin.h"
#include "tiempo.h"
#include "pruebas.h"


/***********FUNCION ARBOL DE BUSQUEDA BINARIA********************/
/* La funcion recibe como parametros el arbol binario donde se encuentran ordenados todos los elementos, 
el tamaño a buscar y la altura del arbol. 
Regresa el 1 o 0 dependiendo si se encuentra o no el elemento*/
void Buscar_ABB(DicBin a, int k) 
{
  if (!esvacio(a))
    {
      while (!esvacio(a) && raiz(a)!=k){
          if (k < raiz(a)){
              a=izquierdo(a);;
          }
          if (raiz(a) < k){
              a=derecho(a);
          }
      }      
      if(!esvacio(a) && raiz(a)==k)
        printf("Numero encontrado :)\n");  
      else 
        printf("Numero no encontrado :(\n");                        
    }
}

/******FUNCION PRINCIPAL****************/
int main(int argc, char *argv[]){
  int *array;
  DicBin arbol = vacio();
  double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
  uswtime(&utime0, &stime0, &wtime0);//Iniciar el conteo del tiempo para las evaluaciones de rendimiento  
  for(int k; k<20; k++){
    array = (int*)malloc(sizeof(int)*tamanios[k]);
    for(int j=0; j<tamanios[k]; ++j){
      scanf("%d", (array+j));
      if(*(array+j))
        arbol=InsOrd(*(array+j), arbol);
    }
    for(int i = 0; i < 20; i++){   
      Buscar_ABB(arbol,numeros[i]);
      uswtime(&utime1, &stime1, &wtime1);//Evaluar los tiempos de ejecución 
      //Cálculo del tiempo de ejecución del programa
      printf("busqueda | N | total | CPU | EyS | CPU/Wall\n");
      printf("%d | %d | %.10f s | %.10f s | %.10f s | %.10f\n",numeros[i], tamanios[k], wtime1 - wtime0, utime1 - utime0, stime1 - stime0,100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
      printf("*****************************************************************************************\n"); 
   }
    free(array);
    free(arbol);
 }
    return 0;
}
