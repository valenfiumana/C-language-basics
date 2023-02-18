// 1.2. Dadas la base y altura de un rectángulo, imprimir su superficie.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float h, b;

    printf("Ingrese la altura del rectangulo: \n");
    scanf("%f", &h);

    printf("Ingrese la base del rectangulo: \n");
    scanf("%f", &b);

    printf("La superficie del rectangulo es %.2f", h*b);
    return 0;
}
