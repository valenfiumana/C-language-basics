//Llenar matriz de un valor ingresado por usuario

#include <stdio.h>

int main()
{
    int M[2][3];

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("Ingrese el valor %i %i\n", i, j);
            scanf("%d", &M[i][j]);
        }
    }

    return 0;
}
