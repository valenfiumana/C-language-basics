//2.2. Ingresar la base y la altura de un triángulo y el diámetro de una circunferencia. Informar cuál figura es la de mayor superficie.
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main()
{
    float b, h, d, supTrian, supCirc;

    printf("Ingrese base de triangulo: \n");
    scanf("%f", &b);

    printf("Ingrese altura de triangulo: \n");
    scanf("%f", &h);

    printf("Ingrese diametro de circunferencia: \n");
    scanf("%f", &d);

    supTrian = b*h/2;
    supCirc = (d/2)*(d/2)*PI;

    if(supCirc>supTrian){
        printf("La circunferencia tiene mayor superficie");
    }
    else if(supCirc==supTrian){
        printf("Ambos tienen igual superficie");
    }
    else if(supCirc<supTrian){
        printf("El triangulo tiene mayor superficie");
    }

    return 0;
}
