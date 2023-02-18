//5.1 Ingresar 10 números enteros y almacenarlos en el archivo enteros.dat. Verificar que el archivo contiene 40 bytes.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, c1;
    int v[10];

    FILE *fp;
    fp = fopen("enteros.dat", "wb");

    if(fp == NULL){
        perror("Error al abrir el archivo.");
        exit(1);
    }

    printf("Ingresa 10 numeros enteros: \n");
    for(int i=0; i<10; i++){
        scanf("%d", &v[i]);
    }

    c = fwrite(v, sizeof(int), 10, fp);

    if(c==10){
        printf("El archivo tiene 40 bytes\n");
    }
	else
	{
		perror("El archivo tiene menos de 40 bytes\n");
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
    return 0;
}
