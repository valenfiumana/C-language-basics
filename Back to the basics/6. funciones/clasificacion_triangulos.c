//6.6. Realizar un programa que lea los lados a, b, c de un triángulo y luego:
//a) Realizar una función que informe si conforman triangulo1
//b) Realizar una función que lo clasifique en isósceles, equilátero o escaleno.

#include <stdio.h>
#include <stdlib.h>
void claseTriangulo(float ladoA, float ladoB, float ladoC){
    if(ladoA==ladoB && ladoB==ladoC){
        printf("equilatero)");
    }
    else if (ladoA==ladoB && ladoA!=ladoC){
        printf("isoceles)");
    }
    else if (ladoC==ladoB && ladoA!=ladoC){
        printf("isoceles)");
    }
    else if (ladoA!=ladoB && ladoB!=ladoC){
        printf("escaleno)");
    }
}
void esTriangulo(float ladoA, float ladoB, float ladoC){
    if(ladoA+ladoB>ladoC&&ladoA+ladoC>ladoB&&ladoB+ladoC>ladoA){
        printf("SI es un triangulo (");
        claseTriangulo(ladoA, ladoB, ladoC);
    }
    else
        printf("NO es un triangulo");
}
int main()
{
    float a, b, c;
    printf("Ingrese un lado del triangulo\n");
    scanf("%f", &a);
    printf("Ingrese otro lado del triangulo\n");
    scanf("%f", &b);
    printf("Ingrese otro lado del triangulo\n");
    scanf("%f", &c);

    esTriangulo(a, b, c);

}

