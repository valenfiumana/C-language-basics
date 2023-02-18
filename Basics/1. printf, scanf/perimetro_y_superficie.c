//1.3. Dado el radio de una circunferencia, informar su perímetro y superficie.
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main()
{
    float radio;
    printf("Ingrese radio de circunferencia: \n");
    scanf("%f", &radio);

    printf("\nLa superficie (PI * r2) de la circunferencia es %.2f \n", radio * radio * PI);
    printf("\nEl perimetro (PI * d) es %.2f \n", (radio + radio) * PI);
    return 0;
}
