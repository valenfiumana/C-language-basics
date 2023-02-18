//5.6. Leer el archivo reales.dat, intercambiar los números de las posiciones 2 y 8,
//luego listar el vector modificado, y grabarlo con el nombre reales2.dat

#include <stdio.h>

int main()
{
    float v[10], v2[10];
    int c1, c2, d1, d2;

    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("reales.dat", "rb");
    fp2 = fopen("reales2.dat", "wb");

    if(fp1==NULL || fp2==NULL ){
        perror("Error al abrir");
        return(-1);
    }

    c1 = fread(v, sizeof(float), 10, fp1);

    if(c1!=10){
        perror("Error al leer");
        return(-2);
    }
    else{

        for(int i=0; i<10; i++){
            if(i==2){
                v2[i]=v[8];
            }
            else if(i==8){
                v2[i]=v[2];
            }
            else{
                v2[i]=v[i];
            }
        }

        printf("\nVECTOR 1: \n");
        for(int i=0; i<10; i++){
            printf("%.2f\n", v[i]);
        }

        printf("\nVECTOR 2: \n");
        for(int i=0; i<10; i++){
            printf("%.2f\n", v2[i]);
        }


        c2 = fwrite(v2, sizeof(float), 10, fp2);

        d1 = fclose(fp1);
        d2 = fclose(fp2);
        if(d1!=0 || d2!=0){
            perror("Error al cerrar");
            return(-3);
        }
    }


    return 0;
}
