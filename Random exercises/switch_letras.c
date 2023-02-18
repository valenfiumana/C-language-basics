#include <stdio.h>
#include <stdlib.h>
void esVocal(char c){
    switch(c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("Es vocal\n");
            break;
        default:
            printf("Es consonante\n");
            break;
    }
}

void esPositivo(int n){
    switch(n>0){
    case 1:
        printf("Es positivo\n");
        break;
    case 0:
        switch(n==0){
        case 1:
            printf("Es cero\n");
            break;
        case 0:
             printf("Es negativo\n");
            break;
        }
    }
}

int main()
{
    char letra;
    int num;

    printf("Ingresa una letra: \n");
    scanf("%c", &letra);
    esVocal(letra);

    printf("\nIngresa un numero: \n");
    scanf("%i", &num);
    esPositivo(num);

    return 0;
}
