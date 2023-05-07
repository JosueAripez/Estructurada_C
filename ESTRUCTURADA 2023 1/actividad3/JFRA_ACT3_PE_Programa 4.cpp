#include <stdio.h>

main()
{
	int opcion;
	
	printf("Seleccione la opcion segun su sexo: ");

	printf("1)Hombre 2)Mujer ");
	scanf("%d",&opcion);
	
	if(opcion == 1)
	{
		printf("Hola, eres Hombre ");
	}
	else
	{
		printf("Hola, eres Mujer ");
	}
	
	return 0;
}
