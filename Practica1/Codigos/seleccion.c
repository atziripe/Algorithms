/*****************SELECCION**************************
LORETTO ESTRADA GALILEA AMÉRICA
PEREZ GARCIA ATZIRI***/
/***********LIBRERIAS********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

/*********************************Funcion Seleccion******************************/
//Toma como entrada el arreglo donde es encuentran los números a ordenar y la longitud
void Seleccion(int *A, int n){
	int min = 0, aux = 0; // se declara la variable usada para determinar el numero minimo, y el auxiliar para realizar el intercambio
	for(int i = 0; i<n; i++){ //Se realiza este proceso n veces para sacar el minimo n veces y acomodarlo en el lufar correcto
		min = i;//Se establce la premisa inicial que el primer numero es el mínimo del arreglo
		for (int j = i+1; j < n; ++j)//Se busca el minimo de todo el cjto de numeros. Se empieza desde +1 debido a que ocmo el primer numero es el minimo (segun premisa anterior) no es necesario incluir este numero.
		{
			if(*(A+j) < *(A+min))//Si el numero en el apuntador es menor al que se tenia considerado como mínimo:
				min = j;//Se establece el nuevo Minimo
		}
		aux = *(A+min);//Se realiza el intercambio sabiendo ya que min va al principio del arreglo.
		*(A+min) = *(A+i); //intercambian lugares, ahora el que es minimo toma el lugar del que se creia minimo anteriorimente. 
		*(A+i) =  aux;//El minimo anterior toma el lugar en el que estaba el minimo nuevo.
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
	//Algoritmo
	//******************************************************************	
	array =(int*)(malloc(sizeof(int)*n)); //se pide espacio en memoria para guardar los numeros a ordenar
	for(int i=0; i<n; i++){//Se guardan los elementos pedidos en la entrada en cada espacio de memoria pedido anteriormente
	scanf("%d", array+i);
	}
	Seleccion(array, n);
		//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("num. problema | real (tiempo total) | Procesamiento CPU | E/S\n");
	printf("%.10f s | %.10f s | %.10f s", wtime1 - wtime0, utime1 - utime0, stime1 - stime0);
	printf("\n");
	//******************************************************************

	//Terminar programa normalmente	
	exit (0);	

}
