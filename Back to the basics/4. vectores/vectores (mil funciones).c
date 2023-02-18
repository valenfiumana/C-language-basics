#include <stdio.h>
#include <stdlib.h>
#define N 4

/* INGRESAR VECTOR*/
void ingreso(int array[]){
    for(int i=0; i<N; i++){
        printf("Introduce la componente %i del vector \n", i);
        scanf("%i", &array[i]);
    }
}


/* IMPRIMIR VECTOR*/
void imprimir(int array[]){
    printf("[ ");
    for(int i=0; i<N; i++){
        printf("%i  ", array[i]);
    }
    printf("]\n");
}
/* SUMAR VECTOR*/
int sumar(int array[]){
    int suma = 0;
    for(int i=0; i<N; i++){
        suma+=array[i];
    }
    return suma;
}

/* PROMEDIO VECTOR*/
float promediar(int array[]){
    return sumar(array)/N;
}

/* NUMERO MAXIMO */
void maximo(int array[]){
    int maximo = 0;
    for(int i=0; i<N; i++){
        if(array[i]>maximo){
            maximo = array[i];
        }
    }
    printf("\n El numero maximo del vector es %i ", maximo);
}

/* ORDENAR VECTOR: BUBBLE SORT ASCENDENTE */
int ordenarAscendente(int array[]){
    for(int i=0; i<N-1; i++){ //N-1 porque después hacemos j+1
        for(int j=0; j<N-1-i; j++){
            if(array[j]>array[j+1]){
            // [48, 37, ... ]
            // array[j] = 48
            // array[j+1] = 37
                int temp = array[j]; // Guardo el 48
                array[j]=array[j+1]; // [37, 37, ...]
                array[j+1]=temp; // [37, 48, ...]
            }
        }
    }
    return array;

}

/* ORDENAR VECTOR: BUBBLE SORT DESCENDENTE */
void ordenarDescendente(int array[]){
	for (int i=0; i<N-1; i++) {
		for (int j=0; j<N-i-1; j++) {
			if (array[j] < array[j+1]){
        // [48, 37, ... ]
        // array[j] = 48
        // array[j+1] = 37
				int temp = array[j]; // Guardo el 48
				array[j] = array[j + 1]; // [37, 37, ...]
				array[j + 1] = temp; // [37, 48, ...]
			}
		}
	}
	printf("\n El vector ordenado descendente es: ");
	imprimir(array);
}

/* BUSQUEDA BINARIA */
int busquedaBinaria(int vector[]){
    int buscado;
    printf("Ingrese el numero que desea buscar: ");
    scanf("%d", &buscado);

    int bajo = 0;
    int alto = N - 1;
    int centro = (bajo+alto)/2;

    while (bajo <= alto) {
       if (vector[centro] == buscado) {
         printf("%d esta presente en el indice %d.\n", buscado, centro);
         break;
      }
      else if (vector[centro] < buscado)
         bajo = centro + 1;
      else
         alto = centro - 1;
        centro = (bajo + alto)/2;
   }

   if (bajo > alto)
      printf("No encontrado! %d no esta presente en el vector\n", buscado);
   return 0;
}

int main()
{
    int array[N];
    ingreso(array);
    imprimir(array);
    printf("\n La suma de componentes del array es %i y su promedio %.2f \n", sumar(array), promediar(array));
    maximo(array);
    printf("\n El vector ordenado ascendente es: ");
    imprimir(ordenarAscendente(array));
    ordenarDescendente(array);
    busquedaBinaria(ordenarAscendente(array));
}
