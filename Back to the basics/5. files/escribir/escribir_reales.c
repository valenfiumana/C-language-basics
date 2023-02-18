//5.2 Ingresar 10 números reales de doble precisión y almacenarlos en el archivo reales.dat. Verificar que elarchivo contiene 80 bytes.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, c1;
    float v[10];

    FILE * fp;
    fp = fopen("reales.dat", "wb");

    if(fp == NULL){
        perror("No se pudo abrir archivo reales.dat");
        exit(1);
    }
    else{
        printf("Ingresa 10 numeros reales: \n");
        for(int i=0; i<10; i++){
            scanf("%f", &v[i]);
        }

        c = fwrite(v, sizeof(float), 10, fp);

        if(c==10){
            printf("El archivo tiene 80 bytes\n");
        }
        else{
            perror("El archivo tiene menos de 80 bytes\n");
            exit(1);
        }

        if(c != 10){
            perror("Error al guardar");
            return(-1);
        }
        c1 = fclose(fp);
        if(c1 != 0){
            perror("Error al cerrar");
            return(-2);
        }
    }
    return 0;
}
