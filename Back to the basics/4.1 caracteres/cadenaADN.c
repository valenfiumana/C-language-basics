//Salida/escritura y entrada/lectura caracteres

#include <stdio.h>

int main()
{
    char carrera[20] = "Ingenieria";
    char escuela[30] = "Ciencia y Tecnologia";
    char universidad[40] = "Universidad Nacional de San Martin";
    char ingenieria[20]; // Reservo 19 caracteres + caracter nulo

    printf("Escribe la ingenieria que esta cursando: \n");
    scanf("%s", ingenieria);


    printf("%s %s - Escuela de %s, %s. \n", carrera, ingenieria, escuela, universidad);
    return 0;
}
