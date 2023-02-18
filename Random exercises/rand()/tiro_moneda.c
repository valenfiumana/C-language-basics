//Hacer un código que simule tirar una moneda 150 veces y dé las siguientes opciones:
// 1. Mostrar cantidad de caras
// 2. Mostrar cantidad de secas
// 3. Salir

#include <stdio.h>
#include <stdlib.h> // para rand() y srand()
#include <time.h> // para time()


int main()
{
    int moneda, caras=0, secas=0;
    srand(time(0));
    for(int i=0; i<150; i++){
        moneda = rand() % (1+1);
        printf("%i \n", moneda);
        if(moneda==0){
            secas++;
        }
        else{
            caras++;
        }
    }
    int o = 1;
    do{
        printf("\n\n- - - - - - - MENU - - - - - - - \n");
        printf("1. Mostrar cantidad de caras\n");
        printf("2. Mostrar cantidad de secas\n");
        printf("3. Salir\n\n");
        scanf("%i", &o);

        switch(o){
        case 1:
            printf("\nHubo %i caras\n", caras);
            break;
        case 2:
            printf("\nHubo %i secas\n", secas);
            break;
        default:
            break;
        }
    }
    while(o!=3);
    return 0;
}
