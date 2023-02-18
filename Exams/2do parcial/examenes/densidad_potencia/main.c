//filas = pisos: PB y 14
//columnas = deptos: A, B, C, ...., J

#include <stdio.h>

//IMPRIMIR MATRIZ
void mostrar(float M[15][10]){
    for(int i=0; i<15; i++){
        printf("\n\t");
        for(int j=0; j<10; j++){
            printf("  %.2f\t", M[i][j]);
        }
        printf("\n");
    }
}

//MOSTRAR COLUMNA
void mostrarPiso(float M[15][10], int piso){
    for(int j=0; j<10; j++){
        printf("  %.2f\t", M[piso][j]);
    }
        printf("\n");
}

//EXCEDEN LIMITE
void excedeLimite(float M[15][10], float limite){
    for(int i=0; i<15; i++){
        for(int j=0; j<10; j++){
            if(M[i][j]>limite){
                printf("\nPISO %d - DEPTO %d (densidad %.2f)\n", i, j, M[i][j]);
            }
        }
        printf("\n");
    }
}

//PROMEDIO FILA
void promedioPiso(float M[15][10]){
    float suma = 0, max = 0;
    int piso;
    for(int i=0; i<15; i++){
        for(int j=0; j<10; j++){
            suma+=M[i][j];
            if(j==9){
               printf(" piso %d - %.2f / 10 = %.2f\t\n", i, suma, (float)suma/10);

               if(suma > max){
                max = suma;
                piso = i;
               }

               suma = 0;

            }
        }
    }

    printf(" \nPISO %d - Mayor promedio (%.2f)\t\n", piso,(float)max/10);
}

//CANT. QUE EXCEDE LIMITE EN COLUMNA
void excedeLimiteDepto(float M[15][10], float limite, int depto){
    int excede = 0;
    for(int i=0; i<15; i++){
        if(M[i][depto]>limite){
            excede++;
        }
    }
    printf("En el depto %d exceden %d pisos el limite", depto, excede);
}

//PROMEDIO ENTRE EXTREMOS
void promedioEntreExtremos(float M[15][10], int inicio, int fin){
    float suma = 0;
    for(int i=inicio; i<fin; i++){
        for(int j=0; j<10; j++){
            suma+=M[i][j];
        }
    }
    printf("El promedio entre pisos %d y %d es %.2f", inicio, fin, suma/((fin-inicio)*10));
}

//MINIMO Y MAXIMO
void minimoMaximo(float M[15][10], int piso){
    float max = 0, min = 100;
    for(int j=0; j<10; j++){
        if(M[piso][j]>max){
            max = M[piso][j];
        }
        if(M[piso][j]<min){
            min = M[piso][j];
        }
    }

    printf("\tPISO %d   maximo %.2f y minimo %.2f\n", piso, max, min);
}

//DOS CONSECUTIVOS
int hayConsecutivos(float M[15][10], float limite){
    for(int i=0; i<15; i++){
        for(int j=0; j<10; j++){
            if(M[i][j]>limite && M[i+1][j]>limite){
                return 1;
            }
        }
    }
    return 0;
}

float promedios(float M[15][10], float V[10]){
    float suma = 0;
    for(int i=0; i<15; i++){
        for(int j=0; j<10; j++){
            suma+=M[i][j];
        }
        V[i] = suma / 10;
        suma = 0;
    }

    for(int i=0; i<10; i++){
        printf("%.2f\n", V[i]);
    }

    return V;
}

void guardarArchivo(float M[15][10], float V[10]){
    int c, c1;

    FILE *fp = fopen("promedios.dat", "wb");
    if(fp==NULL){
        perror("Error al abrir");
        return -1;
    }


    c = fwrite(V, sizeof(float), 10, fp);
    if(c!=10){
        perror("Error al escribir");
        return -2;
    }

    for(int i=0; i<10; i++){
        printf("%.2f\n", V[i]);
    }

    c1=fclose(fp);
    if(c1!=0){
        perror("Error al cerrar");
        return -3;
    }
}

//MENU
void menu(float M[15][10], float limite){
    int op, piso;
    char depto;
    float v[10];

    do{
        printf("\n\n\n- - - - - - - - MENU - - - - - - - ");
        printf("\n1. Mostrar densidades de potencia de piso ingresado");
        printf("\n2. Mostrar piso y depto que exceden el limite");
        printf("\n3. Determinar piso(s) con promedio mas alto de densidad");
        printf("\n4. Informe cuantos exceden el limite en un depto (columna)");
        printf("\n5. Promedio de densidad de potencia en pisos 10 al 14");
        printf("\n6. Minimo y maximo de cada piso");
        printf("\n7. Informar si hay al menos dos pisos consecutivos con viviendas que exceden el limite");
        printf("\n8. Generar un archivo con los promedios de cada piso");
        printf("\n0. Salir");
        printf("\nElegi una opcion:\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            printf("\nIngrese piso (0-14):\n");
            scanf("%d", &piso);
            mostrarPiso(M, piso);
            break;
        case 2:
            excedeLimite(M, limite);
            break;
        case 3:
            promedioPiso(M);
            break;
        case 4:
            printf("\nIngrese depto (A-J): \n");
            scanf(" %c", &depto);

            switch(depto){
            case 'A':
                excedeLimiteDepto(M, limite, 0);
                break;
            case 'B':
                excedeLimiteDepto(M, limite, 1);
                break;
            case 'C':
                excedeLimiteDepto(M, limite, 2);
                break;
            case 'D':
                excedeLimiteDepto(M, limite, 3);
                break;
            case 'E':
                excedeLimiteDepto(M, limite, 4);
                break;
            case 'F':
                excedeLimiteDepto(M, limite, 5);
                break;
            case 'G':
                excedeLimiteDepto(M, limite, 6);
                break;
            case 'H':
                excedeLimiteDepto(M, limite, 7);
                break;
            case 'I':
                excedeLimiteDepto(M, limite, 8);
                break;
            case 'J':
                excedeLimiteDepto(M, limite, 9);
                break;
            default:
                printf("Letras mayusculas de la A a la J\n");
                break;
            }

            break;
        case 5:
            promedioEntreExtremos(M, 10, 14);
            break;
        case 6:
            for(int i=0; i<15; i++){
                minimoMaximo(M, i);
            }
            break;
        case 7:
            if(hayConsecutivos(M, limite)){
                printf("SI\n");
            }
            else{
                printf("NO\n");
            }
        case 8:
            guardarArchivo(M, promedios(M, v));
            break;
        case 0:
            break;
        }
    } while(op!=0);
}

int main()
{
    float M[15][10], limite;
    int c, c1;

    FILE *fp = fopen("medicion.dat", "rb");
    if(fp==NULL){
        perror("Error al abrir");
        return -1;
    }

    c = fread(M, sizeof(M), 1, fp);
    if(c!=1){
        perror("Error al leer");
        return -1;
    }

    mostrar(M);

    printf("\nIngrese limite regulatorio de la jurisdiccion: \n");
    scanf("%f", &limite);


    menu(M, limite);

    c1=fclose(fp);
    if(c1!=0){
        perror("Error al cerrar");
        return -1;
    }

    return 0;
}
