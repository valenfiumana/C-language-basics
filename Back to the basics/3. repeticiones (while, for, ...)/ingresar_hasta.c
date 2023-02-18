//3.3 Ingresar números finalizando con un número negativo o cero, informar el producto.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, producto = 1;
    printf("Ingresa numeros y finaliza con negativo o cero \n");
    scanf("%i", &num);

    while(num>0){
        producto=producto*num;
        printf("Ingresa numeros y finaliza con negativo o cero \n");
        scanf("%i", &num);
    }

    printf("El producto de los numeros ingresados es %i", producto);
}
