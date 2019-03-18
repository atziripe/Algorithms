/*********** SHELL ***********
LORETTO ESTRADA GALILEA AMÉRICA 
PEREZ GARCIA ATZIRI*/
/***********LIBRERIAS********************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h> // Biblioteca para 'TRUNC'
#include <string.h>
#include "tiempo.h"

/*********************************Funcion Shell******************************/
//Toma como entrada el arreglo donde es encuentran los números a ordenar y la longitud
void Shell(int* A, int n){
	int i,j,k,auxiliar; // Declarando variables auxiliares, iteradores
	k = (n/2, -1); // Definiendo el tamaño del paso
	
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
		k=(k/2,-1); // Definiendo un nuevo tamaño de paso.
	}
	//for(int i = 0; i <n; i++)
	//	printf("%d\n",*(A+i));
	
}
/*********************************Funcion PRINCIPAL******************************/
//Toma como entrada la longitud del arreglo.
int main(int argc, char const *argv[]){
	int *array;//Espacio en memoria donde se guardan los números a ordenar
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n;
	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
	}
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo (llamada a la función que contiene el algoritmo)
	//******************************************************************	
	array =(int*)(malloc(sizeof(int)*n)); //se pide espacio en memoria para guardar los numeros a ordenar
	for(int i=0; i<n; i++){//Se guardan los elementos pedidos en la entrada en cada espacio de memoria pedido anteriormente
	scanf("%d", array+i);
	}
	Shell(array, n);
	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************

	//Terminar programa normalmente	
	exit (0);	

}