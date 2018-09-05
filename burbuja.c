/*****************BURBUJA SIMPLE**************************
LORETTO ESTRADA GALILEA AMÉRICA
PEREZ GARCIA ATZIRI***/
#include <stdio.h>
#include <stdlib.h>


void Burbuja(int *A, int n){
	int aux;//Se declara variable auxiliar para hacer el cambio
	for(int i = 0; i<n-1; i++){//Se realiza n-1 veces el proceso para ordenar todos los numeros
		for(int j=0; j<n-1; j++){
			if(*(A+j) > *(A+j+1)){//Compración si el primero número es mayor al siguiente
				aux = *(A+j);//Se asigna el valor del numero mayor de ambos a aux
				*(A+j) = *(A+j+1);//Se hace el intercambio
				*(A+j+1) = aux;//Se establece el numero mayor en la poscion +1 
			}
		}
	}
	for (int j = 0; j < n; ++j)
	{
		printf("%d\n", A[j]);
	}
}
int main(){
	int l=0; //Variable que guardar la longitud del arreglo
	int *array;//Espacio en memoria donde se guardan los números a ordenar
	printf("Ingrese longitud del arreglo: ");
	scanf("%d", &l); //Se guarda el valor de la longitud
	array =(int*)(malloc(sizeof(int)*l)); //se pide espacio en memoria para guardar los numeros a ordenar
	for(int i=0; i<l; i++){//Se guardan los elementos pedidos en la entrada en cada espacio de memoria pedido anteriormente
		printf("Ingrese elemento[%d]: ",i);
		scanf("%d", array+i);
		}
	for (int j = 0; j < l; ++j)//Imprimir arreglo
	{
		printf("%d\n", array[j]);
	}
	printf("*********************\n");
	Burbuja(array, l);
	return 0;
}