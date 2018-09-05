#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	int i,j,k,n,auxiliar;
	int *A;
	
	printf("Ingrese el tamanio: ");
	scanf("%d", &n);
	
	A = (int *)(malloc(sizeof(int)*n));
	
	printf("Ingrese los elementos: ");
	for( i=0; i<n ; i++)	
		scanf("%d", &A[i]);
	
	printf("Los elementos del arreglo son:\n");
	for(j=0; j<n; j++)
		printf("%d\n", A[j]);
	
	// Ordenamieto por shell
	
	k = trunc(n/2);
	
	while(k>0){
		for(i=k;i<n; i++){
			j = i;
			auxiliar = A[i];
			while((j>=k)&&(A[j-k]>auxiliar)){
				A[j] = A[j-k];
				j = j-k;
			}
			A[j] = auxiliar;
		}
		k=trunc(k/2);
	}
	
	// Imprimiendo arreglo ordenado
	printf("Arreglo ordenado: \n");
	for(i=0;i<n;i++){
		printf("%d\n", A[i]);
	}
	
	return 0;
}
