#include<stdio.h>
#include<stdlib.h>

int main(){
	int *Arreglo;
	int tam, i, j, auxiliar;
	
	printf("Ingrese el tamanio: ");
	scanf("%d", &tam);
	
	Arreglo = (int*)malloc(sizeof(int)*tam);
	
	printf("Ingrese los elementos:\n");
	for(i=0; i<tam; i++){
		scanf("%d", &Arreglo[i]);
	}
	
	printf("Los elementos del arreglo son:\n");
	for(j=0; j<tam; j++)
		printf("%d \n", Arreglo[j]);
	
	// Ordenamiento insercion
	for(i=0; i<tam ; i++){
		j = i;
		auxiliar = Arreglo[i];
		while((j>0)&&(auxiliar<Arreglo[j-1])){
			Arreglo[j] = Arreglo[j-1];
			j--;
		}
		Arreglo[j] = auxiliar;
	}
	
	// Imprimiendo arreglos
	printf("Elementos ordenados: \n");
	for(i=0; i<tam; i++)
		printf("%i\n", Arreglo[i]);
	
	return 0;
}