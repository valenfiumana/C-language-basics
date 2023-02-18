/*Crear un programa que:

A-pida al usuario tres palabras, solo se deben admitir palabras donde la primer letra sea mayuscula

B-permita al usuario consultar el numero de veces que aparece una letra, sin distinguir mayusculas o minusculas

C-borrar las apariciones de una letra en una de las palabras

D-unir todas las palabras en una frase, agregando dos conectores

tendría  que agregar dos strings mas,  Ej: "quizas" "flores" "marchitan" = "quizas las flores se marchitan")*/

#include <stdio.h>
#include <stdlib.h>
#define N 20

void ingresar(char str[]){
    printf("Ingresa una palabra: \n");
    scanf("%s", str);

    while(str[0]>='a' && str[0]<='z'){
        printf("La primera letra debe ser mayuscula. Intente de nuevo\n");
        scanf("%s", str);
    }
}

void aparicionesLetra(char c, char str[]){
    int contador = 0, i=0;
    char C;
    if(c>='A' && c<='Z'){ //Si esta en mayus, paso a minus
        C = c + 32;
    }
    else if(c>='a' && c<='z'){ //Si esta en minus, paso a mayus
        C = c - 32;
    }
    while(str[i]!='\0'){
        if(str[i]==c || str[i]==C){ //Me fijo apariciones del caracter en mayus o minus
            contador++;
        }
        i++;
    }
    printf("La letra %c aparece %i veces en %s\n", c, contador, str);
}

void borrarApariciones(char c, char str[]){
    int i=0, j=i+1;
    int len = strlen(str);
    for(i=0; i<len; i++){
        if(str[i] == c){
            for(j=i; j<len; j++){
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }
    printf("Al borrar apariciones de letra %c, la palabra quedaria %s", c, str);
}



int main()
{
    int opcion, o;
    char str1[N], str2[N], str3[N], str4[N], str5[N], ch;
    do{
        printf("\n \n Menu \n");
        printf("1. Ingresar 3 palabras \n ");
        printf("2. Consultar apariciones de una letra \n ");
        printf("3. Borrar las apariciones de una letra en una de las palabras \n ");
        printf("4. Unir todas las palabras en una frase, agregando dos conectores  \n ");
        printf("0. Salir \n \n \n ");

        printf("Seleccione una opcion: \n ");
        scanf("%i", &opcion);
        printf("");

        switch(opcion){
        case 0:
            break;
        case 1:
            ingresar(str1);
            ingresar(str2);
            ingresar(str3);
            break;
        case 2:
            printf("Ingrese que letra quiere buscar en las palabras: ");
            scanf(" %c", &ch); //SI NO HAY \N ANTES DEL SACNF, PONER UN ESPACIO ANTES DEL %
            aparicionesLetra(ch, str1);
            break;
        case 3:
            printf("Ingrese de que palabra quiere borrar una letra: \n");
            scanf("%d", &o);

            while(o<1 || o>3){
                printf("Debe ser del 1 al 3: \n");
                scanf("%d", &o);
            }
            //
            printf("Ingrese que letra quiere borrar: ");
            scanf(" %c", &ch); //SI NO HAY \N ANTES DEL SACNF, PONER UN ESPACIO ANTES DEL %

            switch(o){
            case 1:
                borrarApariciones(ch, str1);
                break;
            case 2:
                borrarApariciones(ch, str2);
                break;
            case 3:
                borrarApariciones(ch, str3);
                break;
            }
            break;
        case 4:
            printf("Ingrese un conector para unir '%s' y '%s', y otro para unir '%s' y '%s':\n", str1, str2, str2, str3);
            scanf("%s", str4);
            scanf("%s", str5);
            strcat(str1, " ");
            strcat(str2, " ");
            strcat(str3, " ");
            strcat(str1, str4);
            strcat(str1, " ");
            strcat(str2, str5);
            strcat(str1, str2);
            strcat(str1, " ");
            strcat(str1, str3);
            printf("%s \n", str1);
            break;

        }
    }
    while(opcion!=0);
    return 0;
}
