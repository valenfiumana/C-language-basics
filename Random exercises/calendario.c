/// En el calendario gregoriano, un año normal consta de 365 días. Debido a que la duración real de un año sideral (el tiempo necesario para que la Tierra gire una vez alrededor del Sol) es en realidad 365.2425 días,
/// un "año bisiesto" de 366 días se utiliza una vez cada cuatro años para eliminar el error causado por tres años normales (pero cortos).
/// Cualquier año divisible por 4 es un año bisiesto: por ejemplo, 1988, 1992 y 1996 son años bisiestos. Sin embargo, hay un pequeño error de cálculo que debe tenerse en cuenta.
/// Para eliminar este error, el calendario gregoriano estipula que un año que es divisible por 100 (por ejemplo, 1900) es un año bisiesto solo si también es divisible por 400.
/// Haga un algortimo que dado un año devuelva la cantidad de días que tuvo ese año.


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool esBisiesto(int year){
    if(year%100==0){
        if(year%400==0){
            return true;
        }
    }
    else if(year%4==0){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int year;
    printf("Ingrese el año a analizar: \n");
    scanf("%d", &year);
    if(esBisiesto(year)==true){
        printf("\n%i es bisiesto", year);
    }
    else{
        printf("\n%i NO es bisiesto\n", year);
    }
    return 0;
}
