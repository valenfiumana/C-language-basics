/*
7.5. Escribir un programa que realice las siguientes tareas:
a) Leer el archivo matri1.dat
b) Llamar a una función menu( ) la cual presentará un menú con cinco opciones:
1. Suma de los números positivos.
2. Suma de los números negativos.
3. Suma de una fila (el usuario ingresa el nro. de fila).
4. Suma de una columna (el usuario ingresa el nro. de columna).
5. Producto de la diagonal principal (7.3)
6. Suma diagonal secundaria (7.4)
7. Mostrar
8. Ordenar fila de menor a mayor
9. Ordenar todo de mayor a menor
0. Salir
*/

#include <stdio.h>
#include <stdlib.h>
//IMPRIMIR MATRIZ
void mostrar(int M[4][4]){
    for(int i=0; i<4; i++){
        printf("\n\t");
        for(int j=0; j<4; j++){
            printf("  %d  ", M[i][j]);
        }
        printf("\n");
    }
}
//SUMA POS
void sumaPos(int M[4][4]){
    int suma = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
           if(M[i][j]>0){
            suma+=M[i][j];
           }
        }
    }
    printf("La suma de positivos es %d\n", suma);
}

//SUMA NEG
void sumaNeg(int M[4][4]){
    int suma = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
           if(M[i][j]<0){
            suma+=M[i][j];
           }
        }
    }
    printf("La suma de negativos es %d\n", suma);
}

//SUMA FILA
void sumaFila(int M[4][4], int fila){
    int suma=0;
    for(int j=0; j<4; j++){
        suma+=M[fila][j];
    }
    printf("La suma de la fila %d es %d\n", fila, suma);
}

//SUMA COLUMNA
void sumaCol(int M[4][4], int col){
    int suma=0;
    for(int i=0; i<4; i++){
        suma+=M[i][col];
    }
    printf("La suma de la col %d es %d\n", col, suma);
}

//PRODUCTO DIAGONAL PRINCIPAL
void prodDiag(int M[4][4]){
    int prod = 1;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
           if(i==j){
            prod=prod*M[i][j];
           }
        }
    }
    printf("El producto de la diagonal principal es %d\n", prod);
}

//SUMA DIAGONAL SECUNDARIA
void sumaDiag(int M[4][4], int fil, int col){
    int suma = 0;
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
           if(i+j==col-1){
            suma+=M[i][j];
           }
        }
    }
    printf("La suma de la diagonal secundaria es %d\n", suma);
}

//FILA DE MENOR A MAYOR

//TODO MAYOR A MENOR
void ordenamayormenor(float M[4][4]){
    float aux;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int x=0; x<4;x++){
                for(int y=0; y<4; y++){
                    if(M[i][j]<M[x][y]){
                        aux=M[i][j];
                        M[i][j]=M[x][y];
                        M[x][y]=aux;
                    }
                }
            }
        }
    }

    mostrar(M);
}

void menu(int M[4][4]){
    int op, fila, col, aux2[4][4];

    do{
        printf("\n- - - - - - - MENU - - - - - - - ");
        printf("\n1. Suma de los números positivos.");
        printf("\n2. Suma de los números negativos.");
        printf("\n3. Suma de una fila");
        printf("\n4. Suma de una columna");
        printf("\n5. Producto de la diagonal principal ");
        printf("\n6. Suma diagonal secundaria");
        printf("\n7. Mostrar");
        printf("\n8. Ordenar fila de mayor a menor");
        printf("\n0. Salir\n");
        printf("Elige una opcion:\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            sumaPos(M);
            break;
        case 2:
            sumaNeg(M);
            break;
        case 3:
            printf("Ingresa una fila:\n");
            scanf("%d", &fila);
            sumaFila(M, fila);
            break;
        case 4:
            printf("Ingresa una columna:\n");
            scanf("%d", &col);
            sumaCol(M, col);
            break;
        case 5:
            prodDiag(M);
            break;
        case 6:
            sumaDiag(M, 4, 4);
            break;
        case 7:
            mostrar(M);
            break;
        case 9:
            ordenamayormenor(M);
        case 0:
            break;
        }
    }while(op!=0);
}

int main()
{
    int V[16], M[4][4], c, c1, k=0;

    FILE *fp = fopen("matrizCuad.dat", "rb");
    if(fp == NULL){
        perror("Error al abrir");
        return -1;
    }

    c = fread(V, sizeof(int), 16, fp);
    if(c != 16){
        perror("Error al leer");
        return -2;
    }

    //lleno matriz
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            M[i][j]=V[k];
            k++;
        }
    }

    //menu
    menu(M);



    c1=fclose(fp);
    if(c1 != 0){
        perror("Error al cerrar");
        return -3;
    }
    return 0;
}
