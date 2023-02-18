//1. Mostrar los ńumeros del 1 al 20.
//2. Mostrar los cuadrados de los numeros del 1 al 20.
//3. Mostrar los cubos de los numeros entre 1 y 20.


#include <stdio.h>

int main()
{
    printf("Numeros del 1 al 20: \n");
    int i = 1;
    do{
        printf("%i ", i);
        i++;
    }
    while(i<=20);

    printf("\n\nCuadrados de numeros del 1 al 20:\n");
    for(int i=1; i<=20; i++){
        printf("%i ", i*i);
    }

    printf("\n\nCubos de numeros del 1 al 20:\n");
    for(int i=1; i<=20; i++){
        printf("%i ", i*i*i);
    }
    return 0;
}
