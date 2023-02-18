//3.4 Ingresar números enteros, finalizando cuando la suma supere 50. Informar la cantidad de datos ingresados y la cantidad de números que son múltiplos de 3.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, ingresados = 0, multiplos = 0, suma=0;
    printf("Ingresa numeros enteros. Finaliza cuando la suma supere 50\n");
    do{
        scanf("%i", &num);
        ingresados++;
        suma+=num;
        if(num%3==0){
            multiplos++;
        }
    }
    while(suma<=50);

    printf("Se ingresaron %i numeros y %i eran multiplos de 3", ingresados, multiplos);
    return 0;
}
