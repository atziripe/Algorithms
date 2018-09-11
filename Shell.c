/*********** SHELL ***********
LORETTO ESTRADA GALILEA AMÉRICA 
PEREZ GARCIA ATZIRI
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h> // Biblioteca para 'TRUNC'

int main(){
	int i,j,k,n,auxiliar; // Declarando variables auxiliares, iteradores.
	int *A; // Declarando contenedor.
	
	// printf("Ingrese el tamanio: ");
	scanf("%d", &n); // Definiendo el tamaño del arreglo.
	
	A = (int *)(malloc(sizeof(int)*n)); // Reservando la cantidad de memoria requerida para ordenar.
	
	// printf("Ingrese los elementos: ");
	for( i=0; i<n ; i++)	// Pidiendo los elementos y 
		scanf("%d", &A[i]); // guardándolos en el arreglo.
	
	// printf("Los elementos del arreglo son:\n"); // Mostrando los elementos que ingresaron.
	for(j=0; j<n; j++)
		printf("%d\n", A[j]);
	
	// Ordenamieto por shell
	
	k = trunc(n/2, -1); // Definiendo el tamaño del paso
	
	while(k>0){
		for(i=k;i<n; i++){ // Se lleva a cabo n-1 veces el procedimiento.
			j = i; // Hacemos que i sea igual a j 
			auxiliar = A[i];
			while((j>=k)&&(A[j-k]>auxiliar)){ // Hacemos el cambio si es que se cumple la condicion.
				A[j] = A[j-k]; // Se hace el cambio.
				j = j-k; // El iterador j cambia su valor con respecto de k.
			}
			A[j] = auxiliar; // El numero mayor se establece en la posicion j.
		}
		k=trunc(k/2,-1); // Definiendo un nuevo tamaño de paso.
	}
	
	// Imprimiendo arreglo ordenado
	printf("Arreglo ordenado: \n");
	for(i=0;i<n;i++){
		printf("%d\n", A[i]);
	}
	
	return 0;
}
