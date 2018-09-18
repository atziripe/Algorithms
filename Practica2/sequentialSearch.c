#include <stdio.h>  
#include <stdlib.h>

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
	
	for(j=0; j<tam; j++){
		if(busq == Arreglo[j]){
			printf("El elemento esta en la posicion: %d \n", j+1);
		}
	}
	
	return 0;
}