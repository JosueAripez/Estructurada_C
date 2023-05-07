#include <stdio.h>


main()
{
	int num;
	
	printf("Ingrese un numero que sea entero: ");
	scanf("%d",&num);
	
	if(num %2 == 0)
	{
		printf("Es numero par.");
	}
	
	if(num %2!= 0)
	{
		printf("Es numero impar.");
	}
	
	return 0;
}
