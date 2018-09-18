#include <stdio.h>  
#include <stdlib.h>

int main(){ 
	int *Arreglo; // Se declara el contenedor de elemento.
	int tam, i, j, auxiliar; // Se declaran variables auxiliares para realizar el cambio.
	int final, medio, inicio = 0; // Variables para realizar la busqueda.
	int buscar;
	
	printf("Ingrese el tamanio: ");
	scanf("%d", &tam);
	
	printf("Ingrese el num a buscar: ");
	scanf("%d", &buscar);
	
	Arreglo = (int*)malloc(sizeof(int)*tam);
	
	printf("Ingrese los elementos:\n");
	for(i=0; i<tam; i++){
		scanf("%d", &Arreglo[i]);
	}
	
	final = tam-1;
	
	while(inicio<=final){
		medio = (inicio + final)/2;
		
		if(buscar == Arreglo[medio]){
			printf("El numero se encuentra en la posicion: %d", medio);
		} else{
			if(Arreglo[medio]>buscar){
				final = medio - 1;
			}
			else{
			inicio = medio + 1;
			}
		}
	}
	
	return 0; 
}