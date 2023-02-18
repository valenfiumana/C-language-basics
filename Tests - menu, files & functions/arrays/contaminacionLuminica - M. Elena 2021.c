// Programa que:
//1. Ingresar todos los valores medidos por teclado (50 valores)
//2. Menú repetitivo:
//  A. Mostrar todos los valores mostrando a qué numero de medicion corresponden (1 a 50)
//  B. Mostrar mínimo nivel de contamiación (y a qué numero corresponde)
//  c. Cantidad de mediciones en las que la contaminaciión está dentro del margen del promedio (10 a 25 mg/Kg)
//  D. Informar si hay al menos dos mediciones iguales adyacentes
//  E. Mostrar numeros de medición y valor que superen en hasta un 20% al minimo del conjunto
//  F. Mostrar promedio de las 10 primeras mediciones, luego de las otras 10 y así (5 promedios). Guardarlos en archivo "resumen.dat"
//  G. Abandonar

#include <stdio.h>
#include <stdlib.h>
#define N 50

void mostrar(int vector[]){
    for(int i=0; i<N; i++){
        printf("Medicion %d: %d\n", i+1, vector[i]);
    }
}

void minimo(int vector[]){
    int min = 90000, medicion;
    for(int i=0; i<N; i++){
        if(vector[i]<min){
            min = vector[i];
            medicion = i;
        }
    }
    printf("El minimo es %d y es la medicion %d\n", vector[medicion], medicion+1);
}

void adyacentes(int vector[]){
    int verdad = 0;
    for(int i=0; i<N; i++){
        if(vector[i]==vector[i+1]){
            verdad = 1;
        }
    }
    if(verdad==1){
        printf("Hay al menos dos numeros adyacentes\n");
    }
    else{
        printf("No hay numeros adyacentes\n");
    }

}

void hasta20Minimo(int vector[]){
    int min = 90000, medicion;
    for(int i=0; i<N; i++){
        if(vector[i]<min){
            min = vector[i];
        }
    }
    int tope = min + (min*20/100);
    for(int i=0; i<N; i++){
        if(vector[i]<tope){
            printf("medicion %d: %d\n", i+1, vector[i]);
        }
    }
}

int promedio(int vector[], int inicio, int fin){
    int suma = 0, promedio;
    for(int i=inicio; i<fin; i++){
        suma+=vector[i];
    }
    promedio=suma/fin;
    return promedio;
}

int main()
{
    int v[50], o, prom[4];

    printf("Ingresar todos los valores medidos: \n");
    for(int i=0; i<N; i++){
        scanf("%d", &v[i]);
    }

    do{
        printf("\n\n\n- - - - - - - - - - - - - MENU - - - - - - - - - - - - - ");
        printf("\n1. Mostrar todo");
        printf("\n2. Minimo");
        printf("\n3. ");
        printf("\n4. Informar si hay al menos dos numeros adyacentes");
        printf("\n5. Mostrar los que superen hasta 20 porciento al minimo");
        printf("\n6. Mostrar promedio de a 10 mediciones y guardarlos en archivo");
        printf("\n0. Salir");
        printf("\n\nSeleccione una opcion:\n");
        scanf("%d", &o);

        switch(o){
        case 1:
            mostrar(v);
            break;
        case 2:
            minimo(v);
            break;
        case 3:
            adyacentes(v);
            break;
        case 4:
            hasta20Minimo(v);
            break;
        case 5:
            prom[0] = promedio(v, 0, 10);
            prom[1] = promedio(v, 11, 20);
            prom[2] = promedio(v, 21, 30);
            prom[3] = promedio(v, 31, 40);
            prom[4] = promedio(v, 41, 50);
            break;
        case 0:
            break;
        }

    }
    while(o!=0);
    return 0;
}
