#include <stdio.h>

int main()
{
	int edad, hrs_dormidas;

	printf("Ingresa tu edad en años\n");
	scanf("%d",&edad);

	hrs_dormidas = edad * 365 * 8;

	printf("Horas totales dormidas en toda tu vida %d\n",hrs_dormidas );

	return 0;
}