//6.2. Dado un triángulo rectángulo cuyos lados son: base=3, altura=4, hipot=5.
//Calcular matemáticamente los ángulos. Repetir el ejercicio para base=5, altura=2, hipot=5.38


#include <stdio.h>
#include <stdlib.h>

int main()
{
    float co=4,h=5,ca=5,hip=5.38,recto=90;
	float angulo1,angulo2,angulo,x,y,arc;
	x=co/h;
	angulo=asin(x);
	angulo1=angulo*180/3.1415;
	angulo2=recto-angulo1;
	printf("Los ángulos internos del triàngulo cuya altura es %.2f y de hipotenusa igual a %.2f son: %.2f, %.2f y %.2f grados\n",co,h,angulo1,angulo2,recto);
	y=ca/hip;
	arc=asin(y);
	angulo1=arc*180/3.1415;
	angulo2=recto-angulo1;
	printf("Los ángulos del nuevo triàngulo que tiene base igual a %.2f y valor de hipotenusa igual %.2f son: %.2f, %.2f y %.2f grados\n",ca,hip,angulo1,angulo2,recto);
return 0;
}
