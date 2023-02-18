#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//IMPRIMIR MATRIZ
void mostrar(int M[25][16]){
    for(int i=0; i<25; i++){
        printf("\n\t");
        for(int j=0; j<16; j++){
            printf("  %d  ", M[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int M[25][16], c, c1, k=7;

    FILE * fp = fopen("monitoreos.dat", "wb");
    if(fp == NULL){
        perror("Error al abrir");
        return -1;
    }

    srand(time(0));
    for(int i=0; i<25; i++){
        for(int j=0; j<16; j++){
            if(i==0 && j!=0){
                M[i][j] = k;
                k++;
            }
            else if(j==0){
                M[i][j] = i;
            }
            else{
                M[i][j] = rand() % 30;
            }
        }
    }

    mostrar(M);

    c = fwrite(M, sizeof(M), 1, fp);
    if(c != 1){
        perror("Error al escribir");
        return -1;
    }

    c1 = fclose(fp);
    if(c1 != 0){
        perror("Error al escribir");
        return -1;
    }
    return 0;
}
