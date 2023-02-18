/// En el calendario gregoriano, un a�o normal consta de 365 d�as. Debido a que la duraci�n real de un a�o sideral (el tiempo necesario para que la Tierra gire una vez alrededor del Sol) es en realidad 365.2425 d�as,
/// un "a�o bisiesto" de 366 d�as se utiliza una vez cada cuatro a�os para eliminar el error causado por tres a�os normales (pero cortos).
/// Cualquier a�o divisible por 4 es un a�o bisiesto: por ejemplo, 1988, 1992 y 1996 son a�os bisiestos. Sin embargo, hay un peque�o error de c�lculo que debe tenerse en cuenta.
/// Para eliminar este error, el calendario gregoriano estipula que un a�o que es divisible por 100 (por ejemplo, 1900) es un a�o bisiesto solo si tambi�n es divisible por 400.
/// Haga un algortimo que dado un a�o devuelva la cantidad de d�as que tuvo ese a�o.


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
    printf("Ingrese el a�o a analizar: \n");
    scanf("%d", &year);
    if(esBisiesto(year)==true){
        printf("\n%i es bisiesto", year);
    }
    else{
        printf("\n%i NO es bisiesto\n", year);
    }
    return 0;
}
