#include <stdio.h>
void ingresar(int M[][3], int fil, int col){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            printf("Ingrese el valor %i %i\n", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

void mostrar(int M[][3], int fil, int col){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            printf("%d  ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int M[2][3];
    ingresar(M, 2, 3);
    mostrar(M, 2, 3);
    return 0;
}
