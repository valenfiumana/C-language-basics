//3.1. Ingresar 10 n�meros enteros e informar el promedio.
//3.2. Ingresar 10 n�meros e informar el n�mero m�ximo.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num, suma, max=0;
    printf("Ingrese diez numeros: \n");

    for(int i=0; i<10; i++){
        scanf("%f", &num);
        suma+=num;

        if(num>max)
            max = num;
    }

    printf("El promedio es de %.2f y el maximo es %.2f", suma/10, max);

    return 0;
}
