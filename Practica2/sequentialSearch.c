/*****************BUSQUEDA SECUENCIAL**************************
LORETTO ESTRADA GALILEA AMERICA
PEREZ GARCIA ATZIRI***/

/***********LIBRERIAS********************/
#include <stdio.h>  
#include <stdlib.h>

/***********FUNCION BUSQUEDA SECUANCIAL*************/
/* La funcion recibe como parametros el arreglo, el tamaño de este y el dato a buscar.
 Regresa la posicion donde se encuentra el dato, o en caso contrario si este no se encuentra. */
void sequentialSearch(int *A, int n, int buscar){
	int j;
	
	for(j=0; j<n; j++){
		if(buscar == *(A+j)){
			printf("El elemento esta en la posicion: %d \n", j+1);
		}
	}
	
}

/***********FUNCION PRINCIPAL***************/
/* Toma como entrada la longitud del arreglo y el elemento a buscar. */
int main(){ 
	int *Arreglo; // Se declara el contenedor de elemento.
	int tam, i, j; // Se declaran variables auxiliares para realizar el cambio.
	int busq;
	
	printf("Ingrese el tamanio: ");
	scanf("%d", &tam);
	
	printf("Ingrese el num a buscar: ");
	scanf("%d", &busq);
	
	Arreglo = (int*)malloc(sizeof(int)*tam);
	
	printf("Ingrese los elementos:\n");
	for(i=0; i<tam; i++){
		scanf("%d", &Arreglo[i]);
	}
	
	sequentialSearch(Arreglo,tam,busq);
	
	return 0;
}
