//2.4. Ingresar un n�mero e informar si es m�ltiplo de 7.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    printf("Ingrese un numero: \n");
    scanf("%i", &num);

    if(num%7==0){
        printf("%i es multiplo de 7 \n", num);
    }
    else{
        printf("%i no es multiplo de 7 \n", num);
    }
    return 0;
}
