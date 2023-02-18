//FILAS: estaciones (15)
//COLUMNAS: horas (4-11hs) (8)
#include <stdio.h>

//MOSTRAR
void mostrar(float M[][8]){
    for(int i =0; i<15; i++){
        printf("\n\t");
        for(int j=0; j<8; j++){
            printf(" %.2f \t", M[i][j]);
        }
    printf("\n");
    }
}

//MOSTRAR
void mostrarInt(int M[][8]){
    for(int i =0; i<15; i++){
        printf("\n\t");
        for(int j=0; j<8; j++){
            printf(" %d \t", M[i][j]);
        }
    printf("\n");
    }
}


//PROMEDIO MATRIZ
void promedio(float M[][8]){
    float suma = 0;
    for(int i=0; i<15; i++){
        for(int j=0; j<8; j++){
            suma += M[i][j];
        }
    }
    printf("El promedio de todos los tiempos de procesos es %.2f", (float)suma/(15*8));
}

//MINIMO MATRIZ
void minimo(float M[][8]){
    float min = M[0][0];
    for(int i=0; i<15; i++){
        for(int j=0; j<8; j++){
            if(M[i][j]<min){
                min = M[i][j];
            }
        }
    }

    printf("El minimo es %.2f en: \n", min);
    for(int i=0; i<15; i++){
        for(int j=0; j<8; j++){
            if(M[i][j]==min){
                printf("ESTACION %d - %dhs\n", i, j+4);
            }
        }
    }
}

//MAXIMO FILA
void maximoEstacion(float M[][8]){
    int e;
    float max;

    do{
        printf("Ingrese numero de estacion: \n");
        scanf("%d", &e);
    } while(e<1 || e>14);

    max = M[e][0];

    for(int j=0; j<8; j++){
        if(M[e][j]>max){
            max = M[e][j];
        }
    }

    printf("El maximo en la estacion %d es %.2f\n", e, max);
}

//PROMEDIO INTERVALO COLUMNAS
void promedioIntervalo(float M[][8]){
    int horaI, horaF;
    float suma = 0;

    do{
        printf("Ingrese hora de inicio y fin de intervalo (entre 4-11hs): \n");
        scanf("%d %d", &horaI, &horaF);
    } while(horaI>horaF || horaI<4 || horaF>11);

    horaI-=4;
    horaF-=4;

    for(int i=0; i<15; i++){
        for(int j=horaI; j<=horaF; j++){
            suma+=M[i][j];
        }
    }

    printf("Promedio en intervalo %d-%dhs: %.2f", horaI+4, horaF+4, suma/(15*(horaF-horaI)));
}

//MAYOR HASTA MINIMO + 15% (115% minimo)
void debajo115Min(float M[][8], int A[][8]){
    float min = M[0][0];
    int k=0, t=0;

    for(int i=0; i<15; i++){
        for(int j=0; j<8; j++){
            if(M[i][j]<min){
                min = M[i][j];
            }
        }
    }

    min = min + (min*15/100);
    printf("Por debajo de %.2f estan: \n", min);

    for(int i=0; i<15; i++){
        for(int j=0; j<8; j++){
            if(M[i][j]<=min){
                printf("EST %d - %dhs con %.2f\n ", i, j, M[i][j]);
                A[k][t] = i;
                A[k][t+1] = j;
                k++;
                if(k==15){
                    k=0;
                    t+=2;
                }
            }
            else{
                A[k][t] = 0;
                A[k][t+1] = 0;
            }
        }
    }
}

void guardarArchivo(int A[][8]){
    int c, c1;

    FILE * fp = fopen("peorest.dat", "wb");
    if(fp==NULL){
        perror("Error al abrir");
        return -1;
    }

    c = fwrite(A, sizeof(A), 1, fp);
    if(c!=1){
        perror("Error al leer");
        return -2;
    }

    mostrarInt(A);

    c1=fclose(fp);
    if(c1!=0){
        perror("Error al cerrar");
        return -3;
    }
}

//MENU
void menu(float M[][8]){
    int op, flag = 0, A[15][8];

    do{
        printf("\n\n - - - - MENU - - - - - - -");
        printf("\n1. Tiempo de proceso promedio de todo. \n2. Tiempo minimo y pares estacion-hora de esas mediciones");
        printf("\n3. Tiempo maximo de estacion ingresada \n4. Tiempo promedio en intervalo horario ingresado");
        printf("\n5. Pares estacion-hora mayores o iguales en no mas del 15 porciento al minimo del conjunto");
        printf("\n6. Archivo con datos del punto 5. \n7. Salir");

        printf("\nElige una opcion: \n");
        scanf("%d", &op);

        switch(op){
        case 1:
            promedio(M);
            break;
        case 2:
            minimo(M);
            break;
        case 3:
            maximoEstacion(M);
            break;
        case 4:
            promedioIntervalo(M);
            break;
        case 5:
            debajo115Min(M, A);
            flag=1;
            break;
        case 6:
            if(flag!=1){
                printf("Debe hacer primero el punto 5\n");
                break;
            }
            else{
                guardarArchivo(A);
            }
            break;
        case 7:
            break;
        }
    } while(op!=7);
}

int main()
{
    int c, c1;
    float M[15][8];

    FILE * fp = fopen("tproduccion.dat", "rb");
    if(fp==NULL){
        perror("Error al abrir");
        return -1;
    }

    c = fread(M, sizeof(M), 1, fp);
    if(c!=1){
        perror("Error al leer");
        return -2;
    }

    mostrar(M);
    menu(M);

    c1=fclose(fp);
    if(c1!=0){
        perror("Error al cerrar");
        return -3;
    }

    return 0;
}
