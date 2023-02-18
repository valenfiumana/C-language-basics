#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int c,cant=0, f=1,i=0;
	int vector[1000];

	FILE *id = fopen("nros.dat","wb");
	if(id == NULL){
        printf("error open");
	}

	srand(time(0));

	while(f != 0){
		vector[i]  =rand() % 21;
		printf("%d \n", vector[i]);
		c = fwrite(&vector[i], sizeof(int), 1, id);
		if(c!=1){
            printf("error escritura");
		}
		cant++;
		if(vector[i]==0){
            f=0;
		}
		i++;
    }
    printf("la cantidad elementos del vector es %d \n ",cant);
    fclose(id);
    if(c!=1){
        printf("error cierre");
    }
    return 0;
}

/// 1. Enumere todas las variables del código e indique de qué tipo son, y para que se usan en el código.
// c - variable de tipo entero. Se usa para ver la respuesta de la escritura en el archivo. Si devuelve la cantidad de datos escritos, se escribió correctamente. Sino, hubo un error.
// cant - variable de tipo entero, se la usa como contador cada vez que se escribe
// f - tipo entero, se la usa como buchón o bandera. Cuando se ingresa un cero en el vector, se deja de hacer el bucle.
// i - entero. Se usa para ingresar datos en el vector. (vector[0] = x, vector[3] = y, . . .
// vector[] - entero, para guardar cadena de datos
// FILE - para usar archivos
/// 2. Ejecute el código, y explique cómo se relaciona el tamaño del archivo con el número que se imprime por pantalla al ejecutarlo.
// Al ser un archivo binario, la cantidad de datos ingresada es igual al tamaño del archivo
// Es decir, como ingrese 4 enteros y cada entero ocupa 4 bytes, al ser 4 numeros son 16 bytes.

/// 3. Explique que pasa si la línea 9 se reemplaza por lo siguiente --> srand(300);
// Dejarían de ser numeros random y siempre que ejecute el programa se usarán los mismos numeros

