/*Escribir un programa que presente un menú con las siguientes opciones, el menú debe repetirse hasta que el usuario indique lo contrario:

1. -[0.5p]Preguntar al usuario cuantos vectores desea usar: de 1 a 5 (inclusive)
2. -[0.5p]Preguntar la Longitud de c/u de ellos. Pueden tener hasta 5 posiciones c/u.
3. -[1p]Elegir un vector y cargar desde teclado los datos.
4. -[1p]Mostrar por pantalla Todos los vectores ingresados.
5. [1,5p]Indicar el valor máximo y mínimo de todo el sistema indicando en que vector se encuentran
6. -[1p]Indicar el valor la Media de un vector en particular.
7. -[1p]Reemplazar un vector definido por el usuario por uno nuevo.
8. -[1.5p]Ordenar todos los valores de los vectores de menor a mayor.
9. [1.5p]Pedir al usuario un valor e indicar si se encuentra en alguna posición de alguno de los vectores cargados e indicar en cual.
10. -[0.5p]Salir del menú.
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

void ingresar(int vector[], int longitud, int num){
    for(int i=0; i<longitud; i++){
        printf("Ingresa componente %i del vector %d ", i, num);
        scanf("%d", &vector[i]);
    }
}

void mostrar(int vector[], int longitud){
    printf("\n[ ");
    for(int i=0; i<longitud; i++){
        printf("%d ", vector[i]);
    }
    printf("]\n");
}

int maximo(int vector[], int longitud){
    int max = 0;
    for(int i=0; i<longitud; i++){
        if(vector[i]>max){
            max = vector[i];
        }
    }
    return max;
}

int minimo(int vector[], int longitud, int max){
    int min = max;
    for(int i=0; i<longitud; i++){
        if(vector[i]< min){
            min = vector[i];
        }
    }
    return min;
}

void maximoTotal(int vector[], int longitud){
    int max = 0, v = 0;
    for(int i=0; i<longitud; i++){
        if(vector[i]>max){
            max = vector[i];
            v = i+1;
        }
    }
    printf("El maximo es %d en el vector %d\n", max, v);
}

void media(int vector[], int longitud){
    int suma = 0;
    float promedio;
    for(int i=0; i<longitud; i++){
        suma+=vector[i];
    }
    promedio = suma/longitud;

    printf("La media del vector es %.2f\n", promedio);
}

void menorAMayor(int array[], int longitud){
    int temp;
    for(int i=0; i<longitud-1; i++){ //N-1 porque después hacemos j+1
        for(int j=0; j<longitud-1-i; j++){
            if(array[j]>array[j+1]){
                int temp = array[j]; // Guardo el 48
                array[j]=array[j+1]; // [37, 37, ...]
                array[j+1]=temp; // [37, 48, ...]
            }
        }
    }
    return array;
}

int busquedaBinaria(int vector[], int num, int longitud){
    int buscado;
    printf("Ingrese el numero que desea buscar: ");
    scanf("%d", &buscado);

    int bajo = 0;
    int alto = longitud - 1;
    int centro = (bajo+alto)/2;

    while (bajo <= alto) {
       if (vector[centro] == buscado) {
         printf("%d esta presente en el indice %d del vector %d.\n", buscado, centro, num);
         break;
      }
      else if (vector[centro] < buscado)
         bajo = centro + 1;
      else
         alto = centro - 1;
        centro = (bajo + alto)/2;
   }

   if (bajo > alto)
      printf("No encontrado! %d no esta presente en el vector %d\n", buscado, num);
   return 0;
}


int main()
{
    int op, cant, o, ingresados = 1, len;
    int longitud[4], v1[N], v2[N], v3[N], v4[N], v5[N], maximos[5], minimos[5];
    do{
        printf("\n\n- - - - - - - - MENU - - - - - - - \n");
        printf("1. Ingresar cantidad de vectores \n ");
        printf("2. Informar longitud de cada vector \n ");
        printf("3. Elegir un vector y cargar desde teclado los datos \n ");
        printf("4. Mostrar por pantalla Todos los vectores ingresados \n ");
        printf("5. Indicar el valor máximo y mínimo de todo el sistema e indicar en que vector se encuentran \n ");
        printf("6. Indicar el valor la Media de un vector en particular \n ");
        printf("7. Reemplazar un vector ya definido por uno nuevo \n ");
        printf("8. Ordenar todos los valores de los vectores de menor a mayor \n ");
        printf("9. Pedir al usuario un valor e indicar si se encuentra en alguna posición de alguno de los vectores cargados e indicar en cual \n ");
        printf("0. Salir \n\n ");

        scanf("%d", &op);
        printf("\n");

        switch(op){
        case 1: //CANT VECTORES A USAR
            printf("Ingrese cantidad de vectores a usar del 1 al 5: \n");
            scanf("%d", &cant);
            while(cant<1||cant>5){
                printf("Debe ser una cantidad entre 1 y 5 inclusive: \n");
                scanf("%d", &cant);
            }
            break;
        case 2: //LONGITUD VECTORES
            for(int i=0; i<cant; i++){
                printf("Ingrese la longitud del vector %i: \n", i+1);
                scanf("%d", &len);
                while(len>N || len<1){
                    printf("Ingrese la longitud del vector %i, entre 1 y %d: \n", i+1, N);
                    scanf("%d", &len);
                }
                longitud[i]=len;
            }
            break;
        case 3: //INGRESAR VECTORES
            printf("Elige un vector para ingresar: ");
            scanf("%d", &o);
            while(o<1 || o>cant){
                printf("Debe ser del 1 al %d\n", cant);
                scanf("%d", &o);
            }
            while(o!=ingresados){
                printf("Primero debe completar el vector %d \n", ingresados);
                o = ingresados;
            }
            switch(o){
            case 1:
                ingresar(v1, longitud[0], 1);
                ingresados++;
                break;
            case 2:
                ingresar(v2, longitud[1], 2);
                ingresados++;
                break;
            case 3:
                ingresar(v3, longitud[2], 3);
                ingresados++;
                break;
            case 4:
                ingresar(v4, longitud[3], 4);
                ingresados++;
                break;
            case 5:
                ingresar(v5, longitud[4], 5);
                ingresados++;
                break;
            }
            break;
        case 4: //MOSTRAR VECTORES
            switch(ingresados-1){
            case 0:
                printf("Aun no ha ingresado vectores");
                break;
            case 5:
                mostrar(v5, longitud[4]);
            case 4:
                mostrar(v4, longitud[3]);
            case 3:
                mostrar(v3, longitud[2]);
            case 2:
                mostrar(v2, longitud[1]);
            case 1:
                mostrar(v1, longitud[0]);
                break;
            }
            break;
        case 5: //MAXIMO Y MINIMO TOTAL
            switch(ingresados-1){
            case 0:
                printf("Aun no ha ingresado vectores");
                break;
            case 5:
                maximos[4] = maximo(v5, longitud[4]);
                minimos[4] = minimo(v5, longitud[4], maximos[4]);
                len=4;
            case 4:
                maximos[3] = maximo(v4, longitud[3]);
                minimos[3] = minimo(v4, longitud[3], maximos[3]);
                len=3;
            case 3:
                maximos[2] = maximo(v3, longitud[2]);
                minimos[2] = minimo(v3, longitud[2], maximos[2]);
                len=2;
            case 2:
                maximos[1] = maximo(v2, longitud[1]);
                minimos[1] = minimo(v2, longitud[1], maximos[1]);
                len=1;
            case 1:
                maximos[0] = maximo(v1, longitud[0]);
                minimos[0] = minimo(v1, longitud[0], maximos[0]);
                len=0;
                break;
            }
            maximoTotal(maximos, len);
            break;
        case 6: //MEDIA DE UN VECTOR
            printf("Elige un vector para saber su media: ");
            scanf("%d", &o);
            switch(o){
            case 1:
                media(v1, longitud[0]);
                break;
            case 2:
                media(v2, longitud[1]);
                break;
            case 3:
                media(v3, longitud[2]);
                break;
            case 4:
                media(v4, longitud[3]);
                break;
            case 5:
                media(v5, longitud[4]);
                break;
            }
            break;
        case 7: //EDITAR VECTOR
            printf("Elige un vector para ingresar: ");
            scanf("%d", &o);
            while(o<1 || o>(ingresados-1)){
                scanf("%d", &o);
            }
            switch(o){
            case 1:
                ingresar(v1, longitud[0], 1);
                break;
            case 2:
                ingresar(v2, longitud[1], 2);
                break;
            case 3:
                ingresar(v3, longitud[2], 3);
                break;
            case 4:
                ingresar(v4, longitud[3], 4);
                break;
            case 5:
                ingresar(v5, longitud[4], 5);
                break;
            }
            break;
        case 8:
            switch(ingresados-1){
            case 0:
                printf("Aun no ha ingresado vectores");
                break;
            case 5:
                menorAMayor(v5, longitud[4]);
            case 4:
                menorAMayor(v4, longitud[3]);
            case 3:
                menorAMayor(v3, longitud[2]);
            case 2:
                menorAMayor(v2, longitud[1]);
            case 1:
                menorAMayor(v1, longitud[0]);
                break;
            }
            break;
        case 9:
            switch(ingresados-1){
            case 0:
                printf("Aun no ha ingresado vectores");
                break;
            case 5:
                busquedaBinaria(v5, 5, longitud[4]);
            case 4:
                busquedaBinaria(v4, 4, longitud[3]);
            case 3:
                busquedaBinaria(v3, 3, longitud[2]);
            case 2:
                busquedaBinaria(v2, 2, longitud[1]);
            case 1:
                busquedaBinaria(v1, 1, longitud[0]);
                break;
            }
            break;
        }
    }while(op!=0);
    return 0;
}
