//Crear una matriz M de 12 filas y 5 columnas a partir del archivo matriz.dat
//  1. MostrarMatriz(M).
//  2. BuscarValor(M,Num): Ingrese un n ́umero por pantalla(Num) si est ́a muestre en que fila y columna y devuelva 1 , sino devuelva 0 .
//  3. BuscarValor(M,Num) Dado un n ́umero al azar(Num)igual que anterior, es lamisma funci ́on, cambia de donde sale Num.
//  4. MENORenfila(M,fils,cols), devuelve la fila donde se encuentra el n ́umero de menor magnitud, y filas y columnas son las filas y columnas definidas para M.
//  5. MAYORencol(M,fils,cols) devuelve la columna donde est ́a el numero de mayor magnitud y donde fils y cols son las filas y columnas definidas para M.
//  6. PROMEDIOcol(M,fils,cols,valor) devuelve el promedio de una columna(valor)donde fils y cols son las filas y columnas definidas para M.
//  7. PROMEDIOfil(M,fils,cols, valor) devuelve el promedio de una fila dada(valor), donde fils y cols son las filas y columnas definidas para M.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//IMPRIMIR MATRIZ
void mostrar(int M[12][5]){
    for(int i=0; i<12; i++){
        printf("\n\t");
        for(int j=0; j<5; j++){
            printf("  %6d  ", M[i][j]);
        }
        printf("\n");
    }
}

//BUSCAR VALOR
int buscarValor(int M[12][5], int num){
    for(int i=0; i<12; i++){
        for(int j=0; j<5; j++){
            if(num == M[i][j]){
                printf("El numero %d esta en fila %d y columna %d\n", num, i, j);
                return 1;
            }
        }
    }
    return 0;
}

//FILA CON MENOR NUMERO
int menorEnMatriz(int M[12][5], int fils, int cols){
    int min = 0, fila;
    for(int i=0; i<fils; i++){
        for(int j=0; j<cols; j++){
            if(M[i][j] < min){
                min = M[i][j];
                fila = i;
            }
        }
    }
    return fila;
}

//COLUMNA CON MAYOR NUMERO
int mayorEnMatriz(int M[12][5], int fils, int cols){
    int max = 0, col;
    for(int i=0; i<fils; i++){
        for(int j=0; j<cols; j++){
            if(M[i][j] > max){
                max = M[i][j];
                col = j;
            }
        }
    }
    return col;
}


//PROMEDIO DE COLUMNA INGRESADA
float promedioCol(int M[12][5], int fils, int col){
    int suma = 0;
    for(int i=0; i<fils; i++){
        suma+=M[i][col];
    }
    return suma/fils;
}

//PROMEDIO DE FILA INGRESADA
float promedioFila(int M[12][5], int cols, int fila){
    int suma = 0;
    for(int j=0; j<cols; j++){
        suma+=M[fila][j];
    }
    return suma/cols;
}

//TRANSPUESTA
void transpuesta(int M[12][5], int col, int fil){
    for(int i = 0;i < col;i++){
      printf("\n\t\t");
      for(int j = 0;j < fil;j++){
          printf("  %6d  ", M[j][i]);
        }
    printf("\n");
  }
  printf("\n\n\n");
}

void menu(int M[12][5]){
    int op, num, fila, col;

    do{
        printf("\n\n- - - - - MENU - - - - ");
        printf("\n1. Mostrar");
        printf("\n2. Buscar valor ingresado");
        printf("\n3.Buscar valor random");
        printf("\n4.Menor (indicar fila)");
        printf("\n5.Mayor (indicar columna)");
        printf("\n6.Promedio columna");
        printf("\n7.Promedio fila");
        printf("\n8.Transpuesta");
        printf("\n0. Salir");
        printf("\nElige una opcion: \n");
        scanf("%d", &op);

        switch(op){
        case 1:
            mostrar(M);
            break;
        case 2:
            printf("\nIngrese valor para buscar:\n");
            scanf("%d", &num);
            if(!buscarValor(M, num)){
                printf("El numero %d no esta en la matriz", num);
            }
            break;
        case 3:
            srand(time(0));
            int random = rand() % 100;
            if(!buscarValor(M, random)){
                printf("El numero %d no esta en la matriz", random);
            }
            break;
        case 4:
            printf("El menor numero esta en la fila %d\n", menorEnMatriz(M, 12, 5));
            break;
        case 5:
            printf("El mayor numero esta en la columna %d\n", mayorEnMatriz(M, 12, 5));
            break;
        case 6:
            printf("\nIngrese columna para saber su promedio:\n");
            scanf("%d", &col);
            printf("El promedio de la columna %d es %.2f\n", col, promedioCol(M, 12, col));
            break;
        case 7:
            printf("\nIngrese fila para saber su promedio:\n");
            scanf("%d", &fila);
            printf("El promedio de la fila %d es %.2f\n", fila, promedioFila(M, 5, fila));
            break;
        case 8:
            transpuesta(M, 12, 5);
            break;
        case 0:
            break;

        }
    }while(op!=0);
}

int main()
{
    int V[60], M[12][5], c, c1, k=0;

    FILE *fp;
    fp = fopen("matriz.dat", "rb");
    if(fp == NULL){
        perror("Error al abrir");
        return -1;
    }

    c = fread(V, sizeof(int), 60, fp);
    if(c != 60){
        perror("Error al leer");
        return -2;
    }
    else{
        //leno matriz con datos archivo
        for(int i=0; i<12; i++){
            for(int j=0; j<5; j++){
                M[i][j]=V[k];
                k++;
            }
        }

        //menu
        menu(M);
    }



    c1 = fclose(fp);
    if(c1 != 0){
        perror("Error al cerrar");
        return -1;
    }

    return 0;
}
