//7.2. Escribir un programa que lea por teclado los datos de una matriz de números enteros de 4 filas y 4 columnas y luego los grabe en el archivo matri1.dat

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M[4][4], c, c1, V[16], k=0;

    FILE *fp = fopen("matrizCuad.dat", "wb");
    if(fp == NULL){
        perror("Error al abrir");
        return -1;
    }

    printf("Complete la matriz: \n");
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("Fila %d Columna %d : \n", i, j);
            scanf("%d", &M[i][j]);
            V[k] = M[i][j];
            k++;
        }
    }

    c = fwrite(V, sizeof(int), 16, fp);
    if(c != 16){
        perror("Error al escribir");
        return -2;
    }


    c1 = fclose(fp);
    if(c1!=0){
        perror("Error al cerrar");
        return -3;
    }
    return 0;
}
