/*****************BURBUJA OPTIMIZADA**************************
LORETTO ESTRADA GALILEA AMÉRICA
PEREZ GARCIA ATZIRI***/
/***********LIBRERIAS********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

/*********************************Funcion BurbujaOpt******************************/
//Toma como entrada el arreglo donde es encuentran los números a ordenar y la longitud de este.
void BurbujaOpt(int *A, int n){
	int aux, i, cambios;//Se declaran variables auxiliares para hacer el cambio
	cambios = 1;
	i = 0;
	while(i<n && cambios!=0){//Se realiza n-1 veces el proceso para ordenar todos los numeros
		cambios= 0;
		for(int j=0; j<n-2; j++){
			if(*(A+i) < *(A+j)){//Compración si el primero número es mayor al siguiente
				aux = *(A+i);//Se asigna el valor del numero mayor de ambos a aux
				*(A+i) = *(A+j);//Se hace el intercambio
				*(A+j) = aux;//Se establece el numero mayor en la poscion +1 
				cambios = 1;
			}
		}
		i++;
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
	BurbujaOpt(array, n);
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