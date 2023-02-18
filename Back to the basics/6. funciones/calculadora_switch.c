//6.3. Escribir un programa que realice las siguientes tareas:
//a) Leer 2 números reales
//b) Llamar a la función menu() la cual debe recibir los dos operandos y mostrar un menú con 4 opciones: + - * /.
// c) El programa principal debe mostrar el resultado en la pantalla.

#include <stdio.h>
#include <stdlib.h>

void menu(float a, float b){
    int opcion;
    printf("- - - - CALCULADORA - - - -");
    printf("\n 1. Suma");;
    printf("\n 2. Resta");
    printf("\n 3. Producto");
    printf("\n 4. Division \n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("%.2f + %.2f = %.2f", a, b, a+b);
            break;
        case 2:
            printf("%.2f - %.2f = %.2f", a, b, a-b);
            break;
        case 3:
            printf("%.2f * %.2f = %.2f", a, b, a*b);
            break;
        case 4:
            printf("%.2f / %.2f = %.2f", a, b, a/b);
            break;
        default:
            printf("No se ha ingresado una opcion correcta");
    }

}

int main()
{
    float a, b;
    printf("Ingrese dos numeros reales: \n");
    scanf("%f %f", &a, &b);
    menu(a, b);
    return 0;
}
