//6.1. Tabular (mostrar en forma de tabla) las funciones seno, coseno y tangente para los ángulos: pi/6, pi/3, pi/2, es decir 30, 60 y 90 grados.

#include <stdio.h>
#include <stdlib.h>
#include"math.h"
#define PI 3.14159

int main()
{
    float r;

    printf("- - - - - - - - - - - - - - - - - - - -\n");
    printf("\n Ang \t  Sen \t  Cos \t  Tan \n");
    printf("- - - - - - - - - - - - - - - - - - - -\n");

    for(int i=0; i<=90; i+=30){
     r = i * PI / 180;
     printf("\n%3d \t %5.2f \t %5.2f \t %5.2f\n", i, sin(r), cos(r), tan(r));
    }




    return 0;
}
