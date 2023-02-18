//4.4. Ingresar números enteros positivos estrictamente crecientes (validarlo).
// Finalizar cuando un valor supere 50. Informar la cantidad de datos ingresados y luego los números múltiplos de 3.
#include <stdio.h>
#include <stdlib.h>

/* INGRESO CRECIENTE */
int ingresoCreciente(int array[]){
    int num, suma=0, cant=1;
    printf("Ingrese componentes del vector en orden creciente: \n");
    scanf("%i", &array[0]);
    suma+=array[0];
    for(int i=1; i<20; i++){
        if(suma<50){
           do{
            scanf("%i", &num);
            if(num>array[i-1]){
                array[i]=num;
                suma+=num;
                cant++;
            }
        }
        while(num<array[i-1]);
        }
    }
    return cant;
}

/* IMPRIMIR */
void imprimir(int array[], int N){
    printf("[ ");
    for(int i=0; i<N; i++){
        printf("%i ", array[i]);
    }
    printf("] \n");
}

/* MULTIPLOS DE 3 */
void multiplos(int array[], int N){
    int multiplos = 0;
    printf("Los multiplos de 3 son: [ ");
    for(int i=0; i<N; i++){
        if(array[i]%3==0){
            multiplos++;
            printf("%i ", array[i]);
        }
    }
    printf("]\n");
    printf("Es decir, hay %i multiplos de 3\n", multiplos);
}

int main()
{
    int array[20];
    int N = ingresoCreciente(array);
    imprimir(array, N);
    multiplos(array, N);
    return 0;
}
