#include <stdio.h>

int main()
{
	float r, h, volumen;
	float pi = 3.1416;

	printf("Ingrese el radio\n");
	scanf("%f",&r);

	printf("Ingrese la altura\n");
	scanf("%f",&h);

	volumen = pi * r * r * h;

	printf("El volumen es: %f\n", volumen);

	return 0;
}