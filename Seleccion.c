/******** Seleccion ********/
/*
	Loretto Estrada Galilea América
	Pérez García Atziri
*/

#include <stdio.h>
#include <stdlib.h>

void Seleccion(int *Arreglo, int n){
	int i, j; // Variables de contadores
	int auxiliar, minimo; // Variable para el cambio
	
	for(i=0; i=n-1; i++){
		minimo=i; // Asignando quien es el minimo
		for(j=i+1; j=n; j++){
			if(Arreglo[j]<Arreglo[minimo]) // comparando cada elemento con el minimo
			{
				minimo=j;
			}
		}
		// Haciendo el cambio de posicion de los numeros
		auxiliar = Arreglo[i];
		Arreglo[i] = Arreglo[minimo];
		Arreglo[minimo] = auxiliar;
	}	
	
	// Imprimiendo arreglo ordenado
	printf("Arreglo ordenado: \n");
	for(i=0;i<n;i++){
		printf("%i\n", Arreglo[i]);
	}
}

int main(){
	int i,j,n;
	int *Arreglo;
	
	// Pidiendo datos
	printf("Ingrese longitud: ");
	scanf("%d", &n);
	
	Arreglo = (int *)(malloc(sizeof(int)*n));
	
	printf("Ingrese los elementos:\n");
	for( i=0; i<n ; i++)	
		scanf("%d", &Arreglo[i]);
	
	// Mostrando datos
	printf("Los elementos del arreglo son:\n");
	for(j=0; j<n; j++)
		printf("%d\n", Arreglo[j]);
	
	// Ordenamiento por Seleccion
	Seleccion(Arreglo,n);
	
	return 0;
}