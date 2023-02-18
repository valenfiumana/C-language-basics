#include <stdio.h>
#include <stdlib.h> //para rand() y srand(seed)
#include <time.h> //para time()

int main()
{
    //sin modificar el rango maximo
    int N, a;
    N = RAND_MAX;
    a = rand();
    printf("N = %i y a = %i \n", N, a);

    //uso el resto para cambiar el maximo
    int numero = rand() % 11; //entre 0 y 10
    N=10;
    numero = rand() % (N+1); //entre 0 y N
    printf("\n\nNumero entre 0 y N (10): %i \n", numero);

    //cambio tambien el minimo
    int num, maximo=20, minimo=10;
    numero = rand() % (maximo-minimo+1) + minimo; //entre minimo y maximo. Estoy calculando cuantos numeros hay entre los extremos y sumandole el minimo.
    printf("\n\nNumero entre un minimo(10) y un maximo(20): %i \n", numero);

    //para cambiar la seed de rand() uso srand() y time()
    srand(time(0));
    printf("\n\nEntre 0 y 4 usando srand(time(0)):\n");
    for(int i=0; i<10; i++){
        a = rand();
        int b = a % 5;
        printf("a = %i y b = %i\n", a, b);
    }

    //rango de 0 a 0.750
    printf("\n\nEntre 0 y 0.750:\n");
    for(int i=0; i<10; i++){
        printf("%1.3f \n", (float)(rand()%76)/100); //
    }

    return 0;
}
