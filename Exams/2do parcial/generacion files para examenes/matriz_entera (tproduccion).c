#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//IMPRIMIR MATRIZ
void mostrar(float M[15][8]){
    for(int i=0; i<15; i++){
        printf("\n\t");
        for(int j=0; j<8; j++){
            printf("  %.2f\t", M[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    float M[15][8], c, c1;

    FILE *fp = fopen("tproduccion.dat", "wb");
    if(fp==NULL){
        perror("Error al abrir");
        return -1;
    }

    srand(time(0));
    for(int i=0; i<15; i++){
        for(int j=0; j<8; j++){
            M[i][j] = (float)(rand()%(2500-1300+1)+1200)/100;
        }
    }

    c = fwrite(M, sizeof(M), 1, fp);
    if(c!=1){
        perror("Error al leer");
        return -1;
    }

    mostrar(M);

    c1=fclose(fp);
    if(c1!=0){
        perror("Error al cerrar");
        return -1;
    }

    return 0;
}
