  #include <stdio.h>
  int main()
    {
        int contador = 1;
        int i = 0;
		char str[60]="baby im a nigthmare dressed like a daydream";


        while (str[i] != '\0'){ //mientras no llegue al final
            if(str[i] == ' ' && (str[i+1] != ' ')){ //si hay un espacio y le continua una letra
                contador ++;
            }
            i++;
        }

        printf("La cantidad de palabras en '%s' es %d \n", str, contador);
    return 0;
    }
