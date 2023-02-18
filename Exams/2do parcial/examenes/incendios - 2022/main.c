/*
Se tienen datos de la cantidad de incendios entre los años 1993 y 2019 en un archivo llamado incendios.dat.
Estos datos fueron registrados de modo que los datos corresponden a causas relacionadas con:
1) Negligencia, 2) Intencionalidad , 3) Causas naturales y 4) Desconocidas.

Menú con funciones:
1. Abra el archivo incendios.dat y coloque los datos en una matriz cuyas filas representan los años y las columnas las causas.
*(se tendrá consideración adicional si realiza este punto utilizando una función)
2. Realice un menú repetitivo:
a) Mostrar Matriz
b) Promedio de causa: Dada una causa permita saber el promedio de incendios para todos los años.
c) Cantidad total de incendios por año: Ingrese un año y muestre cantidad de incendios teniendo en cuenta todas las causas.
d) Causa más importante de incendios: Ingrese un año y muestre cuál fue la causa de incendios más importantes de ese año.
e) Desestimación de causas menores a 10: Se requiere guardar una nueva matriz con aquellos valores mayores o iguales a 10,
y 0 en los otros casos. Para ello se cuenta con una función que recibe la matriz original y devuelve la matriz modificada.
Posteriormente se muestra esta nueva matriz y se guarda en un archivo umbral.dat.
*/
#include <stdio.h>
#include <stdlib.h>
//IMPRIMIR MATRIZ
void mostrar(int M[26][4]){
    for(int i=0; i<26; i++){
        printf("\n\t");
        for(int j=0; j<4; j++){
            printf("\t%d\t", M[i][j]);
        }
        printf("\n");
    }
}

//PROMEDIO COLUMNA
float promedioCausa(int M[][4], int causa){
    int suma = 0;
    for(int i=0; i<26; i++){
        suma+=M[i][causa];
    }
    return suma/26;
}

//SUMA FILA
int totalAnual(int M[][4], int anio){
    int suma = 0;
    for(int j=0; j<4; j++){
        suma+=M[anio][j];
    }
    return suma;
}

//MAX FILA
int causaImportante(int M[][4], int anio){
    int max = 0, causa;
    for(int j=0; j<4; j++){
        if(M[anio][j]>max){
            max = M[anio][j];
            causa = j;
        }
    }
    printf("\nLa causa mas importante: ");
    switch(causa){
    case 0:
        printf("negligencia\n");
        break;
    case 1:
        printf("intencionalidad");
        break;
    case 2:
        printf("causas naturales");
        break;
    case 3:
        printf("desconocida");
        break;
    }
}

//NUEVA MATRIZ
void umbralMatriz(int M[][4], int M2[][4]){
    for(int i=0; i<26; i++){
        for(int j=0; j<4; j++){
            if(M[i][j]>=10){
                M2[i][j]=M[i][j];
            }
            else{
                M2[i][j]=0;
            }
        }
    }
}

//GUARDAR MATRIZ
void guardarMatriz(int M[][4]){
    int c, c1;

    FILE *fp = fopen("umbral.dat", "wb");
    if(fp==NULL){
        perror("Error al abrir");
        return -1;
    }

    c=fwrite(M, sizeof(M), 1, fp);
    if(c!=1){
        perror("Error al escribir");
        return -1;
    }

    c1=fclose(fp);
    if(c1!=0){
        perror("Error al cerrar");
        return -1;
    }
}

//MENU
void menu(int M[][4], int M2[][4]){
    int op, causa, anio;
    do{
        printf("\n\n- - - - - MENU - - - - - ");
        printf("\n 1.Mostrar");
        printf("\n 2.Promedio de causa");
        printf("\n 3.Cantidad total de incendios por año");
        printf("\n 4.Causa más importante de incendios");
        printf("\n 5.Desestimación de causas menores a 10");
        printf("\nElige una opcion:\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            mostrar(M);
            break;
        case 2:
            printf("Elige una causa:\n 1) Negligencia, 2) Intencionalidad , 3) Causas naturales y 4) Desconocidas\n");
            scanf("%d", &causa);
            printf("El promedio de la causa seleccionada es %.2f\n", promedioCausa(M, causa-1));
            break;
        case 3:
            printf("Elige un anio entre 1993 y 2019: \n");
            scanf("%d", &anio);
            anio = 2019 - anio;
            anio = 26 - anio;
            printf("El total de incendios es %d\n", totalAnual(M, anio));
            break;
        case 4:
            printf("\nElige un anio entre 1993 y 2019: \n");
            scanf("%d", &anio);
            anio = 2019 - anio;
            anio = 26 - anio;
            causaImportante(M, anio);
            break;
        case 5:
            umbralMatriz(M, M2);
            mostrar(M2);
            guardarMatriz(M2);
            break;
        case 0:
            break;
        }
    }while(op!=0);
}

int main()
{
    int M[26][4], M2[26][4], c, c1;

    FILE *fp = fopen("incendios.dat", "rb");
    if(fp==NULL){
        perror("Error al abrir");
        return -1;
    }

    c = fread(M, sizeof(M), 1, fp);
    if(c != 1){
        perror("Error al leer");
        return -1;
    }

    menu(M, M2);

    c1 = fclose(fp);
    if(c1 != 0){
        perror("Error al cerrar");
        return -1;
    }

    return 0;
}
