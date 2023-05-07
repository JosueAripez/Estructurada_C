#include <stdio.h>

int main()
{
	int b1, b2, h, area;

	printf("Ingrese B\n");
	scanf("%d", &b1);
	
	printf("Ingrese b\n");
	scanf("%d", &b2);

	printf("Ingrese la altura\n");
	scanf("%d", &h);

	area = ((b1 + b2) * h) / 2;

	printf("El area del trapecio es :%d \n", area);

	return 0;
}