// Listado con secuencia numerica de 7000 valores. Se desea obtener e imprimir:
// 1. producto de todos los valores positivos menores a 80
// 2. cant negativos
// 3. suma de los multiplos de 7
// 4. valor maximo dentro de los menores a 1000
// 5. cantidad de valores menores al promedio de todo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void producto(int vector[], int n){
    int prod = 1;
    for(int i=0; i<n; i++){
        if(vector[i]<800){
            prod = prod * vector[i];
        }
    }
    printf("El producto es %d \n", prod);
}

void cantNegativos(int vector[], int n){
    int cant = 0;
    for(int i=0; i<n; i++){
        if(vector[i]<0){
            cant++;
        }
    }
    printf("Los negativos son %d \n", cant);
}

void sumaMultiplos7(int vector[], int n){
    int suma = 0;
    for(int i=0; i<n; i++){
        if(vector[i]%7==0){
            suma+=suma;
        }
    }
    printf("La suma de multiplos de 7 es %d \n", suma);
}

void maximoMenores100(int vector[], int n){
    int max = 0;
    for(int i=0; i<n; i++){
        if(vector[i]<700 && vector[i]>max){
            max=vector[i];
        }
    }
    printf("El maximo de los menores de 700 es %d \n", max);
}

int promedio(int vector[], int n){
    int suma = 0;
    for(int i=0; i<n; i++){
        suma+=vector[i];
    }
    int promedio = suma/n;
    return promedio;
}

int main()
{
    int vector[N];
    srand(time(0));

    for(int i=0; i<N; i++){
        int a = rand();
        vector[i] = a % 800;
    }

    for(int i=0; i<N; i++){
        printf("%d ", vector[i]);
    }

    producto(vector, N);
    cantNegativos(vector, N);
    sumaMultiplos7(vector, N);
    maximoMenores100(vector, N);

    return 0;
}
