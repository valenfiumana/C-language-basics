//  6.5. Escribir un programa que realice las siguientes tareas:
//  a) Leer el archivo reales.dat
//  b) Llamar a la función float producto (float vec[ ], int n)
//  c) Informar el producto de todos los números.


#include <stdio.h>

float producto(float v[], int n){
    float prod = 1;
    for(int i=0; i<n; i++){
        prod = prod * v[i];
    }
    return prod;
}

int main()
{
    int c, c1;
    float v[10];

    FILE *fp;
    fp=fopen("reales.dat", "rb");

    if(fp==NULL){
        perror("Error al abrir");
        return(-1);
    }

    c = fread(v, sizeof(float), 10, fp);
    if(c!=10){
        perror("Error al leer");
        return(-1);
    }
    else{
        printf("El producto de reales.dat es %.2f", producto(v, 10));
        c1 = fclose(fp);
        if(c1!=0){
            perror("Error al cerrar");
            return(-1);
        }
    }
    return 0;
}
