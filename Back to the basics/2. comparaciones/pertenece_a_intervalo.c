//2.3. Ingresar un número e informar si pertenece al intervalo -2< x < 4.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    printf("Ingrese un numero\n");
    scanf("%i", &num);

    if(num>-2 && num<4){
        printf(" -2 < %i < 4 ", num);
    }
    else{
        printf(" %i no pertenece al intervalo -2 < x < 4 ", num);
    }
}
