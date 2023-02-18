  #include <stdio.h>
  int main()
    {
        int contador = 1;
        int i = 0;
		char cadena[60]="el sol es grande y maravilloso y luminoso";


        while (cadena[i] != '\0')
        {

            if(cadena[i] == ' ' && (cadena[i+1] != ' '))
            {

                contador ++;
            }

        i++;
        }

        printf("la cantidad de palabras es %d \n", contador++);
    return 0;
    }
