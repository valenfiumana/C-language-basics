//4.3. Ingresar datos a un vector finalizando con un número negativo o cero, informar el producto.
//4.5. Ingresar un vector de 10 números y luego mostrar los que están en las posiciones impares.
//4.6. Ingresar números en un vector hasta que el valor ingresado sea cero (que no se debe almacenar).

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/* INGRESAR FINALIZANDO CON CERO*/
int ingresoHasta (int array[]){
    int num = 1, cant=0;
    printf("Ingrese componentes para vector y finalice con cero o negativos");
    while(num>0){
        for(int i=0; i<MAX; i++){
            printf("\nIntroduce la componente %i del vector \n", i);
            scanf("%i", &num);
            if(num<=0){
                break;
            }
            array[i]=num;
            cant++;
        }
    }
    return cant;
}

/*IMPRIMIR*/
void imprimir(int array[], int N){
    printf("[ ");
    for(int i=0; i<N; i++){
        printf("%i ", array[i]);
    }
    printf("]\n");
}

/*PRODUCTO*/
void producto(int array[], int N){
    int producto = 1;
    for(int i=0; i<N; i++){
        producto*=array[i];
    }
    printf("El producto del vector es %i", producto);
}

/* POSICIONES IMPARES */
void posicionesImpares(int array[], int N){
    printf("\nLos numeros en posiciones impares son: ");
    for(int i=1; i<N; i=i+2){
        printf("\n- %i en la posicion %i", array[i], i);
    }
}

int main()
{
    int array[MAX];
    int N = ingresoHasta(array);
    imprimir(array, N);
    producto(array, N);
    posicionesImpares(array, N);
    return 0;
}
