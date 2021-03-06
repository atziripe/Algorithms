/*****************BURBUJA SIMPLE**************************
LORETTO ESTRADA GALILEA AMÉRICA
PEREZ GARCIA ATZIRI***/
/***********LIBRERIAS********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

/*********************************Funcion Burbuja******************************/
//Toma como entrada el arreglo donde es encuentran los números a ordenar y la longitud 
void Burbuja(int *A, int n){
	int aux;//Se declara variable auxiliar para hacer el cambio
	for(int i = 0; i<n-2; i++){//Se realiza n-1 veces el proceso para ordenar todos los numeros
		for(int j=0; j<n-2; j++){
			if(*(A+j) > *(A+j+1)){//Compración si el primero número es mayor al siguiente
				aux = *(A+j);//Se asigna el valor del numero mayor de ambos a aux
				*(A+j) = *(A+j+1);//Se hace el intercambio
				*(A+j+1) = aux;//Se establece el numero mayor en la poscion +1 
			}
		}
	}
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
	//Algoritmo
	//******************************************************************	
	array =(int*)(malloc(sizeof(int)*n)); //se pide espacio en memoria para guardar los numeros a ordenar
	for(int i=0; i<n; i++){//Se guardan los elementos pedidos en la entrada en cada espacio de memoria pedido anteriormente
	scanf("%d", array+i);
	}
	Burbuja(array, n);
		//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("num. problema | real (tiempo total) | Procesamiento CPU | E/S\n");
	printf("%.10f s | %.10f s | %.10f s", wtime1 - wtime0, utime1 - utime0, stime1 - stime0);
	printf("\n");
	


	//Terminar programa normalmente	
	exit (0);	

}
