#include <stdio.h>
#include <string.h> //para funciones de strings

//LONGITUD = STRLEN "STRING LENGTH"
void longitud(char palabra[]){
    int length = strlen(palabra);
    printf("La longitud de %s es %d \n\n", palabra, length);
}

//COPIAR TEXTO EN VARIABLE = STRCPY = "STRING COPY"
void copiarEn(){
    char src[15] = "Veggie";
    char dest[15] = "";
    char dest2[15] = "Hola";

    printf("Copiando palabra'%s' en nuevo string vacio...\n", src);
    strcpy(dest, src);
    printf("El origen sigue siendo '%s' y el destino es '%s'\n", src, dest);
    strcpy(dest2, src);
    printf("Copiando palabra '%s' en string destino 'Hola'.. Ahora el destino es '%s'\n\n", src, dest2);
}

//CONCATENAR = STRCAT = "STRING CONCATENADO"
void concatenar(){
    char destino[] = "Valen";
    char fuente[] = "Fiumana";
    strcat(destino, fuente);
    printf("Cadena concatenada: %s\n", destino);
}

// COMPARACION = STRCMP = "STRING COMPARATION"
///If length of string1 < string2, it returns < 0 value.
///If length of string1 > string2, it returns > 0 value.
///If string1 == string 2, it returns zero.
void comparacion(char str1[], char str2[]){
    int result = strcmp(str1, str2);

   if(result > 0) {
      printf("%s > %s\n", str1, str2);
   } else if(result < 0) {
      printf("%s < %s\n", str1, str2);
   } else {
      printf("%s == %s\n", str1, str2);
   }
}

//INT Y FLOAT A STRING = "SPRINTF"
void intAString(){
    char string[100] = "Palabra";
    int dia = 7;
    float hora = 3.9339f; //completa con ceros para 6 decimales
    printf("\nString antes de usar sprintf: '%s'\n", string);
    sprintf(string, "Dia %d, Hora %f \n", dia, hora);
    printf("String despues de usar sprintf: %s\n", string);
}

//CONCATENAR STRING CON INT
void concatenarStringInt(){
    char cadena[20];
    char auxiliar[20];
    char numeros[20];
    for(int i=0; i<5; i++){
        strcpy(auxiliar, cadena); //copio cadena en auxiliar
        sprintf(numeros, "%d.txt", i+1); //convierto int a string --> lo guardo en cadena numeros
        strcat(auxiliar, numeros); //concateno auxiliar y numeros
        printf("%s\n", auxiliar);
    }
}

//INVERTIR PALABRA
void invertir(char str[]){
    char temp;
    int i=0, j;

    j = strlen(str) - 1; //-1 para no contar el final '/0'

    //ej: valen
    //str[0] = v
    //str[5] = n
    while (i < j) {
        temp = str[i]; //temp = v
        str[i] = str[j]; // str[0] = n --> 'nalen'
        str[j] = temp; // str[5] = v --> 'nalev'
        i++;
        j--;
    }
    printf("\nEl string invertido es: %s\n", str);

}

//BUSCAR CARACTER
void buscarCaracter(char str[], char c){
    int len = strlen(str);
    int true = 0;

    for(int i=0; i<len; i++){
        if(str[i]==c){
            printf("\nLa letra %c se encuentra en %s\n", c, str);
            true = 1;
        }
    }
    if(true==0){
        printf("\nLa letra %c no se encuentra en %s\n", c, str);
    }
}

//ES PALINDROMO
void esPalindromo(char cad[]){
    int i;
    int len = strlen(cad);

    for(i=0; i<len/2; i++){
        if(cad[i] != cad[len-1-i]) {
            printf("\n%s no es palindromo\n", cad);
            return;
        }
    }
    printf("\n%s es palindromo\n", cad);
}

//MINUS A MAYUS
void aMinuscula(char str[]){
    for (int i=0; i<=strlen(str); i++){
        if (str[i] >= 'A' && str[i] <= 'Z') //'A' = 65 y 'Z' = 90
            str[i] = str[i] + 32; //sumamos 32 para hacerlo mayuscula
    }
    printf (" \n Mayuscula a minuscula: %s", str);
}

// MAYUS A MINUS
void aMayuscula(char str[]){
    for (int i=0; i<=strlen(str); i++){
        if (str[i] >= 'a' && str[i] <= 'z') //'A' = 65 y 'Z' = 90
            str[i] = str[i] - 32; //restamos 32 para hacerlo minuscula
    }
    printf (" \n Minuscula a mayuscula: %s", str);
}

int main()
{
    char palabra[15] = "Veggie", nombre[20]="valentina", word[20]="AMamOS";
    longitud(palabra);
    copiarEn();
    concatenar();

    comparacion("hola", "hoLa");
    comparacion("planta", "planta");
    comparacion("It's funny", "because it's true");
    comparacion("manzana", "hola");

    intAString();

    concatenarStringInt();

    invertir(palabra);

    buscarCaracter(nombre, 'e');
    buscarCaracter(nombre, 'x');

    esPalindromo("radar");
    esPalindromo("valentina");

    aMinuscula(word);
    aMayuscula(word);
    return 0;
}
