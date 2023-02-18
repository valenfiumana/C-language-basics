//Llenar matriz de un valor constante (ej. 5)
#include <stdio.h>

int main()
{
    int M[2][3];
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            M[i][j]=5;
        }
    }
    return 0;
}
