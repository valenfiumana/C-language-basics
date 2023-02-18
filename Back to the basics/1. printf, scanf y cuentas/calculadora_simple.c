//1.4. Ingresar tres números, informar su suma y producto.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;

    printf("Ingresa el primer numero: \n");
    scanf("%i", &a);

    printf("Ingresa el segundo numero: \n");
    scanf("%i", &b);

    printf("Ingresa el tercer numero: \n");
    scanf("%i", &c);

    //SUMA
    printf("\n %i + %i + %i = %i \n", a, b, c, a+b+c);

    //PRODUCTO
    printf("\n %i * %i * %i = %i \n", a, b, c, a*b*c);

    return 0;
}
