#include <stdio.h>
#include <stdlib.h>

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

//PROMEDIO MATRIZ
float promedioMatriz(int M[][16]){
    int suma = 0;
    float promedio;
    for(int i=1; i<25; i++){
        for(int j=1; j<16; j++){
            suma+=M[i][j];

        }
    }
    promedio = suma / (24*15);
    return promedio;
}

//MAXIMO
int maximo(int M[][16]){
    int max = 0;
    for(int i=1; i<25; i++){
        for(int j=1; j<16; j++){
            if(max<M[i][j]){
                max = M[i][j];
            }

        }
    }
    return max;
}

//PROMEDIO DIARIO
void promedioSensor(int M[][16], int sensor){
    int suma = 0;
    float promedio;
    for(int j=1; j<16; j++){
            suma+=M[sensor][j];

        }
    promedio = suma / 15;
    printf("\nEl promedio del sensor %d es %.2f\n", sensor, promedio);
}

//PROMEDIO INTERVALO
void promedioIntervalo(int M[][16], int sensor, int inicio, int fin){
    int suma = 0;
    float promedio;
    for(int j=inicio; j<=fin; j++){
        suma+=M[sensor][j];
    }
    promedio = suma / 15;
    printf("\nEl promedio del sensor %d es %.2f\n", sensor, promedio);
}

//MIX
void mayoresAnomalias(int M[][16], int max, float promedio){
    float noventaP = max * 90 / 100;
    printf("El maximo del conjunto es %d y el 90 porciento es %.2f \n", max, noventaP);
    printf("El promedio del conjunto es %.2f\n", promedio);

    for(int i=1; i<25; i++){
        for(int j=1; j<16; j++){
            if(M[i][j]<noventaP && M[i][j]>promedio){
                printf("S%d %dhs : %d\n", i, j+6, M[i][j]);
            }
        }
    }
}

//MENOR EN COLUMNA
void menorAnomalia(int M[][16], int hora){
    int min = 100, sensor;
    for(int i=1; i<25; i++){
        if(min>M[i][hora]){
            min = M[i][hora];
            sensor = i;
        }
    }
    printf("Hora %d sensor %d - minimo %d\n", hora+6, sensor, min);
}

//MENOR EN COLUMNA PARA GUARDAR
int menorAnomaliaArchivo(int M[][16], int hora){
    int min = 100, sensor;
    for(int i=1; i<25; i++){
        if(min>M[i][hora]){
            min = M[i][hora];
            sensor = i;
        }
    }
    return min;
}

//GUARDAR ARCHIVO
void guardarArchivo(int V[15]){
    int c, c1;
    FILE * fp = fopen("bajos.dat", "wb");
    if(fp == NULL){
        perror("Error al abrir");
        return -1;
    }

    c = fwrite(V, sizeof(int), 16, fp);
    if(c != 16){
        perror("Error al escribir");
        return -2;
    }
    else{
        printf("Archivo escrito correctamente");
    }

    c1 = fclose(fp);
    if(c1 != 0){
        perror("Error al cerrar");
        return -2;
    }
}

//MENU
void menu(int M[25][16]){
    int op, sensor, inicio, fin, V[15], k=1;
    do{
        printf("\n- - - - - - - - MENU - - - - - - - ");
        printf("\n1. Promedio de todas las anomalias");
        printf("\n2. Maxima anomalia");
        printf("\n3. Promedio diario para un sensor");
        printf("\n4. Promedio anomalias para intervalo horario");
        printf("\n5. Pares sensor/hora cuyas anomalias sean inferiores al '90%' del maximo y superiores al promedio gral.");
        printf("\n6. Generar un archivo 'bajos.dat' con el punto 7");
        printf("\n7. Mostrar numero de sensor que tomo menor registro de anomalias, hora por hora (16 valores)");
        printf("\n0. Salir");
        printf("\nElegi una opcion:\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            printf("\nEl promedio de todas las anomalias es %.2f\n", promedioMatriz(M));
            break;
        case 2:
            printf("\nEl maximo de todas las anomalias es %d\n", maximo(M));
            break;
        case 3:
            printf("\nIngresa numero de sensor (1 - 24):\n");
            scanf("%d", &sensor);
            promedioSensor(M, sensor);
            break;
        case 4:
            printf("\nIngresa horario de inicio del intervalo (7 - 22):\n");
            scanf("%d", &inicio);
            printf("\nIngresa horario de fin del intervalo (7 - 22):\n");
            scanf("%d", &fin);
            inicio = inicio - 6;
            fin = fin - 6;
            printf("inicio %d fin %d\n", inicio, fin);
            for(int i=1; i<16; i++){
                promedioIntervalo(M, i, inicio, fin);
            }
            break;
        case 5:
            mayoresAnomalias(M, maximo(M), promedioMatriz(M));
            break;
        case 6:
            for(int i=0; i<15; i++){
                V[i] = menorAnomaliaArchivo(M, k);
                k++;
            }
            guardarArchivo(V);
            break;
        case 7:
            for(int i=1; i<16; i++){
                menorAnomalia(M, i);
            }
            break;
        case 0:
            break;
        }
    } while(op!=0);
}


int main()
{
    int M[25][16], c, c1;

    FILE * fp = fopen("monitoreos.dat", "rb");
    if(fp == NULL){
        perror("Error al abrir");
        return -1;
    }


    c = fread(M, sizeof(M), 1, fp);
    if(c != 1){
        perror("Error al escribir");
        return -1;
    }

    mostrar(M);
    menu(M);

    c1 = fclose(fp);
    if(c1 != 0){
        perror("Error al escribir");
        return -1;
    }
    return 0;
}
