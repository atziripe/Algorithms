#include <stdio.h>
#include <stdlib.h>
#include "BusBin.h"
int
main ()
{
  DicBin a = vacio ();
  Elem *array;
  int c = 0;
  int l=0; //Variable que guardar la longitud del arreglo
  printf("Ingrese longitud del arreglo: ");
  scanf("%d", &l); //Se guarda el valor de la longitud
  array =(int*)(malloc(sizeof(int)*l)); //se pide espacio en memoria para guardar los numeros a ordenar
  for(int i=0; i<l; i++){//Se guardan los elementos pedidos en la entrada en cada espacio de memoria pedido anteriormente
    printf("Ingrese elemento[%d]: ",i);
    scanf("%d", array+i);
    if (*(array+i))
  a = InsOrd (*(array+i), a);//Se van guardando en orden dentro del arbol
    }
  for (int j = 0; j < l; ++j)//Imprimir arreglo
  {
    printf("%d\n", array[j]);
  }
  printf("*********************\n");
  ImpInorden (a);//Se imprimen en inorden
  return 0;
}
