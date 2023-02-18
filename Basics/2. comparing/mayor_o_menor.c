//2.1. Ingresar 2 números, si a < b informar a*b, en caso contrario a/b.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;

    printf("Ingresa un numero: \n");
    scanf("%i", &a);

    printf("Ingresa un numero: \n");
    scanf("%i", &b);

    if(a<b){
        printf("\n %i * %i = %i", a, b, a*b);
    }
    else{
        printf("\n %i / %i = %i", a, b, a/b);
    }
    return 0;
}
