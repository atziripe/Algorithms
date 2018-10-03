/*****************BUSQUEDA SECUENCIAL**************************
LORETTO ESTRADA GALILEA AMERICA
PEREZ GARCIA ATZIRI***/

/***********LIBRERIAS*******************/
#include <stdio.h>
#include <stdlib.h>
#include "BusBin.h"


/***********FUNCION ARBOL DE BUSQUEDA BINARIA********************/
/* La funcion recibe como parametros el arbol binario donde se encuentran ordenados todos los elementos, 
el tamaño a buscar y la altura del arbol. 
Regresa el 1 o 0 dependiendo si se encuentra o no el elemento*/
int Buscar_ABB(DicBin a,Elem k, int altura) 
{
  int alt = 0;
  if (!vacio(a))
    {
      while (!vacio(a) && raiz(a)!=k){
          if (k < raiz(a)){
              a=izquierdo(a);
          }
          if (raiz(a) < k){
              a=derecho(a);
          }
        alt++;
      }      
      if(!vacio(a) && raiz(a)==k)
        return 1;                             
    }
    return 0;
  }

/******FUNCION PRINCIPAL****************/
int main(int argc, char *argv[]){
  int n = 0, num=0, res = 0, high = 0;
  DicBin arbolito = vacio();
  Elem *array;
  if (argc<2) {
    printf("Indique la longitud del arreglo - \tEjemplo: [user@equipo]$ %s 4\n\n",argv[0]);
    exit(-1);
  }  
  n=atoi(argv[1]);
  if (argc!=3) {
   printf("\nIndique el numero a Buscar - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
    exit(-1);
  }
  num=atoi(argv[2]);
  array = (int*)malloc(sizeof(int)*n);
  for(int i=0; i<n; ++i){
    scanf("%d", array+i);
    if (*(array+i))
    arbolito = InsOrd (*(array+i), arbolito);
  }
  high=altura(arbolito);
  res = Buscar_ABB(arbolito, num,(high-1));
  if(res == 1)
    printf("El numero si está :)\n");
  else if(res==0)
    printf("El número no está :(\n");
  return 0;
}