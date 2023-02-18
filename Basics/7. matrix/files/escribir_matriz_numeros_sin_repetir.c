#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    int c, c1;
    int v[60];
    bool unique;
    int num_random;

    FILE *fp;
    fp = fopen("matriz.dat", "wb");

    if(fp == NULL){
        perror("Error al abrir el archivo.");
        exit(1);
    }

     srand(time(0));
    for(int i=0; i<60; i++){
        do{
          num_random = rand() % 100;
          unique = true;

          for(int j=0; j<i; j++){
            if(v[j] == num_random){
                unique = false;
            }
            }
        }
        while(!unique);
        v[i] = num_random;
    }

    for(int i=0; i<60; i++){
        printf("%d \n", v[i]);
    }
    c = fwrite(v, sizeof(int), 60, fp);

	if(c != 60){
        perror("Error al guardar");
        return(-1);
    }
    c1 = fclose(fp);
    if(c1 != 0){
        perror("Error al cerrar");
        return(-2);
    }
    return 0;
}
