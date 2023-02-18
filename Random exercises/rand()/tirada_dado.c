//Simular la tirada de un dado hasta que la suma de las tiradas sea mayor o igual que 100.

#include <stdio.h>
#include <stdlib.h> //para usar rand() y srand()
#include <time.h> //para usar time()

int main()
{
    int suma=0, dado;
    srand(time(0));
    do{
        dado = rand() % (6 - 1+1)+1;
        printf("%i\n", dado);
        suma+=dado;
    }
    while(suma<100);
    printf("Suma tiradas: %i", suma);
    return 0;
}
