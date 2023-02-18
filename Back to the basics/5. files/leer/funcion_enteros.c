//6.4. Escribir un programa que realice las siguientes tareas:
//a) Leer el archivo enteros.dat
//b) Llamar a la función int suma (int vec[ ], int n)
//c) Informar el resultado de la suma de todos los números.


#include <stdio.h>

int suma(int v[], int n){
    int suma = 0;
    for(int i=0; i<n; i++){
        suma += v[i];
    }
    return suma;
}

int main()
{
    int c, c1;
    int v[10];

    FILE *fp;
    fp=fopen("enteros.dat", "rb");

    if(fp==NULL){
        perror("Error al abrir");
        return(-1);
    }

    c = fread(v, sizeof(int), 10, fp);
    if(c!=10){
        perror("Error al leer");
        return(-1);
    }
    else{
        printf("La suma de enteros.dat es %d", suma(v, 10));
        c1 = fclose(fp);
        if(c1!=0){
            perror("Error al cerrar");
            return(-1);
        }
    }
    return 0;
}
