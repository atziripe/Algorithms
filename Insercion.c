/************ INSERCION ***********
 PÉREZ GARCÍA ATZIRI
 LORETTO ESTRADA GALILEA AMÉRICA
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	int *Arreglo; // Se declara el contenedor de elemento.
	int n, i, j, auxiliar; // Se declaran variables auxiliares para realizar el cambio.
	
	// printf("Ingrese el tamanio: ");
	scanf("%d", &n);
	
	Arreglo = (int*)malloc(sizeof(int)*n); // Reservando el espacio de memoria para el prog
	
	// printf("Ingrese los elementos:\n");
	for(i=0; i<n; i++){
		scanf("%d", &Arreglo[i]);
	}
	
	// Ordenamiento insercion
	for(i=0; i<n ; i++){ // Ordenar los n elementos
		j = i; // los iteradores i y j se igualan
		auxiliar = Arreglo[i]; // Auxiliar toma el valor de la posicion i del arreglo
		while((j>0)&&(auxiliar<Arreglo[j-1])){
			Arreglo[j] = Arreglo[j-1]; // Se le asigna el  valor de la posicion anterior
			j--; // Disminuye el iterador j.
		}
		Arreglo[j] = auxiliar; // se asigna el valor de la posicion j del arreglo a auxiliar
	}
	
	// Imprimiendo arreglos
	// printf("Elementos ordenados: \n");
	for(i=0; i<n; i++)
		printf("%i\n", Arreglo[i]);
	
	return 0;
}
