//5.3. Leer el archivo enteros.dat e informar la suma de los números positivos y la de los negativos.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, c1, pos=0, neg=0;
    int numeros[10];

    FILE *fp;
    fp = fopen("enteros.dat", "rb");

    if(fp == NULL){
        perror("No se pudo abrir enteros.dat");
        return(-1);
    }
    else{
        c = fread(numeros, sizeof(int), 10, fp);

        if(c != 10){
        perror("Error al leer");
        return(-2);
        }

        for(int i=0; i<10; i++){
            printf("%d\n", numeros[i]);
            if(numeros[i]>0){
                pos+=numeros[i];
            }
            else if(numeros[i]<0){
                neg+=numeros[i];
            }
        }
        printf("La suma de positivos es: %d\n", pos);
        printf("La suma de negativos es: %d\n", neg);

        c1 = fclose(fp);
        if(c1 != 0){
            perror("Error al cerrar");
            return(-2);
        }

    }
    return 0;
}
