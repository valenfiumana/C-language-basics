//Un juego de tiro al blanco de 3 regiones 0(el blanco)la m�s cercana y 2 la m�s lejana.
//Si se tiran 20 veces, hacer un c�digo que lo simule y diga cu�ntas veces dio en el blanco.

#include <stdio.h>
#include <stdlib.h> //para rand() y srand()
#include <time.h> //para time()

int main()
{
    int blanco=0, tiro;
    srand(time(0));
    printf("Preparen arcos... A tirar!\n");
    for(int i=0; i<20; i++){
        tiro = rand() % (2+1);
        printf("%d \n", tiro);
        if(tiro == 0){
            blanco++;
        }
    }
    printf("\n Se tiro al blanco %i veces \n", blanco);
    return 0;
}
