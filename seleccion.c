/*****************SELECCION**************************
LORETTO ESTRADA GALILEA AMÉRICA
PEREZ GARCIA ATZIRI***/
#include <stdio.h>
#include <stdlib.h>


void Seleccion(int *A, int n){
	int min = 0, aux = 0; // se declara la variable usada para determinar el numero minimo, y el auxiliar para realizar el intercambio
	for(int i = 0; i<n; i++){ //Se realiza este proceso n veces para sacar el minimo n veces y acomodarlo en el lufar correcto
		min = i;//Se establce la premisa inicial que el primer numero es el mínimo del arreglo
		for (int j = i+1; j < n; ++j)//Se busca el minimo de todo el cjto de numeros. Se empieza de s de +1 debido a que ocmo el primer numero es el minimo (segun premisa anterior) o es necesario incluir este numero.
		{
			if(*(A+j) < *(A+min))//Si el numero en el apuntador es menor al que se tenia considerado como mínimo:
				min = j;//Se establece el nuevo Minimo
		}
		aux = *(A+min);//Se realiza el intercambio sabiendo ya que min va al principio del arreglo.
		*(A+min) = *(A+i); //intercambian lugares, ahora el que es minimo toma el lugar del que se creia minimo anteriorimente. 
		*(A+i) =  aux;//El minimo anterior toma el lugar en el que estaba el minimo nuevo.
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
	Seleccion(array, l);
	return 0;
}