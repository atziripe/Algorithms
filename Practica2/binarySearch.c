/*****************BUSQUEDA BINARIA**************************
LORETTO ESTRADA GALILEA AMERICA
PEREZ GARCIA ATZIRI***/

/***********LIBRERIAS********************/
#include <stdio.h>  
#include <stdlib.h>

/***********FUNCION BUSQUEDA BINARIA********************/
/* La funcion recibe como parametros el arreglo, el tamaño de este y el dato a buscar.
 Regresa el mensaje de si se encuentra el dato, o en caso contrario si este no se encuentra. */
void binarySearch(int *A, int n, int buscar){
	int final, medio, inicio = 0; // Variables para realizar la busqueda.
	final = n-1;
	int bandera = '0';
	
	while(inicio<=final){
		medio = (inicio + final)/2;
		if(buscar == *(A+medio)){
			bandera = '1';
			break;
		} else{
			if(*(A+medio)>buscar){
				final = medio - 1;
			}
			else{
			inicio = medio + 1;
			}
		}
	}
	if(bandera == '0')
		printf("Numero no encontrado.\n");
	else
		printf("Numero encontrado");
		// printf("El numero se encuentra en la posicion: %d\n", medio+1);
}

/***********FUNCION PRINCIPAL***************/
/* Toma como entrada la longitud del arreglo. */
int main(int argc, char const *argv[]){ 
	int *Arreglo; // Se declara el contenedor de elemento.
	int i, tam, buscar;

	if(argc!=2){
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamanio del algoritmo
	else{
		tam=atoi(argv[1]);
	}
	
	// Dato a buscar
	if(argc!=3){
		printf("\nIndique numero a buscar - \nEjemplo: [user@equipo]$ %s %s 1000 %s \n",argv[0],argv[1]);
		exit(-1);
	}
	buscar=atoi(argv[2]);
	
	//scanf("%d", &tam);
	//scanf("%d", &buscar);
	
	Arreglo = (int*)malloc(sizeof(int)*tam);
	
	// printf("Ingrese los elementos:\n");
	for(i=0; i<tam; i++){
		scanf("%d", Arreglo+i);
	}
	
	binarySearch(Arreglo,tam, buscar);
	
	return 0; 
}
