#include <stdio.h>
#define fil 2
#define col 3

void ingresar(int M[fil][col]){
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
            printf("Ingresar posicion %d %d\n", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

int main()
{
    int M[2][3], c, c1;

    FILE *fp = fopen("datosMatriz.dat", "wb");
    if(fp==NULL){
        perror("Error al abrir archivo");
        return -1;
    }

    ingresar(M);

    c = fwrite(M, sizeof(int), 6, fp);
    if(c != 6){
        perror("Error al guardar");
        return -2;
    }

    c1 = fclose(fp);
    if(c1 != 0){
        perror("Error al cerrar");
        return -3;
    }
    return 0;
}
