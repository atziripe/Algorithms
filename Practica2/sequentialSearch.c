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
	int j, bandera = 0;
	
	for(j=0; j<n; j++){
		if(buscar == *(A+j)){
			bandera = '1';
		}
	}
	
	if(bandera == 1){
		printf("Numero encontrado.\n");
		// printf("El elemento esta en la posicion: %d \n", j+1);
	} else
		printf("Numero no encontrado.\n");
}

/***********FUNCION PRINCIPAL***************/
/* Toma como entrada la longitud del arreglo y el elemento a buscar. */
int main(int argc, char const *argv[]){ 
	int *Arreglo; // Se declara el contenedor de elemento.
	int tam, i, j; // Se declaran variables auxiliares para realizar el cambio.
	int busq;
|	if(argc!=2){
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamanio del algoritmo
	else{
		tam=atoi(argv[1]);
	}
	
	// Dato a buscar
	if(argc!=3){
		printf("\nIndique numero a buscar - \nEjemplo: [user@equipo]$ %s %s 1000 \n",argv[0],argv[1]);
		exit(-1);
	}
	busq=atoi(argv[3]);
	// scanf("%d", &busq);
	
	Arreglo = (int*)malloc(sizeof(int)*tam);
	
	// printf("Ingrese los elementos:\n");
	for(i=0; i<tam; i++){
		scanf("%d", (Arreglo+i));
	}
	
	sequentialSearch(Arreglo,tam,busq);
	
	return 0;
}
