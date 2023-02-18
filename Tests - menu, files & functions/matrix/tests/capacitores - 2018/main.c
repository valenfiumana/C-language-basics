#include <stdio.h>

//MOSTRAR
void mostrar(int M[][10]){
    for(int i =0; i<20; i++){
        printf("\n\t");
        for(int j=0; j<10; j++){
            printf(" %d \t", M[i][j]);
        }
    printf("\n");
    }
}


//NOMINAL IGUAL REAL
void igualNominal(int M[][10], int nominal){
    for(int i =0; i<20; i++){
        for(int j=0; j<10; j++){
            if(M[i][j]==nominal){
                printf("Capacitor %d - Lote %d\n", i, j);
            }
        }
    }
}

//MENU
void menu(int M[][10], int nominal){
    int op;

    do{
        printf("\n\n - - - - MENU - - - - - - -");
        printf("\n1. Mostrar todo \n2. Mostrar numero capacitor y lote de dispositivos cuyo valor nominal es igual al real");
        printf("\n3. Crear archivo con datos punto 2. \n4. Indicar cuantos capacitores poseen desviacion del 5 del nominal");
        printf("\n5. Pares estacion-hora mayores o iguales en no mas del 15 porciento al minimo del conjunto");
        printf("\n6. Desviacion promedio de cada lote\n7. Minima capacidad de lote ingresado y su numero(s) de capacitor");
        printf("\n8. Mayores al nominal \n 0. Salir");

        printf("\nElige una opcion: \n");
        scanf("%d", &op);

        switch(op){
        case 1:
            mostrar(M);
            break;
        case 2:
            igualNominal(M, nominal);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 0:
            break;
        }
    } while(op!=0);
}

int main()
{
    int M[20][10], c, c1, nominal;

    FILE * fp = fopen("mica.bin", "rb");
    if(fp==NULL){
        perror("Error al abrir");
        return -1;
    }

    c = fread(M, sizeof(M), 1, fp);
    if(c!=1){
        perror("Error al leer");
        return -2;
    }

    printf("Ingrese capacidad nominal: \n");
    scanf("%d", &nominal);

    menu(M, nominal);

    c1=fclose(fp);
    if(c1!=0){
        perror("Error al cerrar");
        return -3;
    }

    return 0;
}

