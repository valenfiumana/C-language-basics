#include <stdio.h>
#include <stdlib.h>
//IMPRIMIR MATRIZ
void mostrar(int M[3][3]){
    for(int i=0; i<3; i++){
        printf("\n\t");
        for(int j=0; j<3; j++){
            printf("  %d  ", M[i][j]);
        }
        printf("\n");
    }
}

int estaLleno(int M[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(M[i][j]==0){
                return 0;
            }
        }
        printf("\n");
    }
    return 1;
}

int hizoTateti(int M[3][3]){
    int j=0;
    for(int i=0; i<3; i++){
        //fila
        if(M[i][j]==M[i][j+1]M[i][j+2]){
            return 1;
        }
        //columna
        if(M[j][i]==M[j+1][i]==M[j+2][i]){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int M[3][3], fil, col;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            M[i][j]=0;
        }
    }
    mostrar(M);

    do{
        //jugador 1
        do{
        printf("Jugador 1, ingrese fila:\n");
        scanf("%d", &fil);
        printf("Jugador 1, ingrese columna:\n");
        scanf("%d", &col);
        }while(M[fil][col]!=0);
        M[fil][col] = 1;
        mostrar(M);

        //jugador 2
        do{
            printf("Jugador 2, ingrese fila:\n");
            scanf("%d", &fil);
            printf("Jugador 2, ingrese columna:\n");
            scanf("%d", &col);
        }while(M[fil][col]!=0);
        M[fil][col] = 2;
        mostrar(M);
    } while (!estaLleno(M));

    return 0;
}
