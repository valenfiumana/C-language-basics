//5.4. Leer el archivo reales.dat e informar el producto de los que se hallan en las posiciones 1, 3, 5, 7, 9.
#include <stdio.h>

int main()
{
    int c, c1;
    float v[10], prod = 1;

    FILE *fp;
    fp = fopen("reales.dat", "rb");

    if(fp==NULL){
        perror("Error al abrir el archivo");
        return(-1);
    }

    c = fread(v, sizeof(float), 10, fp);
    if(c!=10){
        perror("Error al leer el archivo");
        return(-2);
    }
    else{
        for(int i=0; i<10; i=i+2){
            printf("%f \n", v[i]);
            prod = prod * v[i];
        }

        printf("El producto de las posiciones 1, 3, 5, 7, 9 es %f\n", prod);

        c1 = fclose(fp);
        if(c1!=0){
            perror("Error al cerrar archivo");
            return(-3);
        }
    }

    return 0;
}
