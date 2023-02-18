//5.5. Leer el archivo enteros.dat e informar los pares e impares.

#include <stdio.h>

int main()
{
    int c, c1, par=0, impar=0;
    int v[10];

    FILE *fp;
    fp = fopen("enteros.dat", "rb");

    if(fp == NULL){
        perror("Error al abrir archivo");
        return(-1);
    }

    c = fread(v, sizeof(int), 10, fp);
    if(c!=10){
        perror("Error al leer archivo");
        return(-2);
    }
    else{
        for(int i=0; i<10; i++){
            printf("%d\n", v[i]);
            if(v[i]%2==0){
                par++;
            }
            else if(v[i]==0){
            }
            else{
                impar++;
            }
        }

        printf("Los pares son %d, los impares %d \n", par, impar);

        c1 = fclose(fp);
        if(c1!=0){
            perror("Error al cerrar archivo");
            return(-3);
        }
    }
    return 0;
}
