#include <stdlib.h>
#include <stdio.h>

int main(){
	int i,j,k,tam,auxiliar;
	int *A;
	
	printf("Ingrese el tamanio: ");
	scanf("%d", &tam);
	
	A = (int *)(malloc(sizeof(int)*tam));
	
	for( i=0; i<tam ; i++){
		printf("Ingrese los elementos: ");
		scanf("%d", &A[i+1]);
	}
	
	printf("Los elementos del arreglo son:\n");
	for(int j=1; j<=tam; j++)
		printf("%d\n", A[j]);
	
	// Ordenamieto por shell
	
	k = tam/2;
	
	while(k>0){
		for(i=k;i<tam; i++){
			j = i;
			auxiliar = A[i];
			while((j>=k)&&(A[j-k]>auxiliar)){
				A[j] = A[j-k];
				j = j-k;
			}
			A[j] = auxiliar;
		}
		k/=2;
	}
	
	// Imprimiendo arreglo ordenado
	printf("Arreglo ordenado: \n");
	for(i=0;i<=tam;i++){
		printf("%d\n", A[i]);
	}
	
	return 0;
}