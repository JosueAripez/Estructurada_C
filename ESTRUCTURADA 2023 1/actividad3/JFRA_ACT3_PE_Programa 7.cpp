#include <stdio.h>

main()
{
	
	int num1, num2, num3;
	
	printf("Ingresa un numero: ");
	scanf("%d",&num1);

	printf("Ingresa otro numero: ");
	scanf("%d",&num2);
	
	printf("Ingresa un ultimo numero: ");
	scanf("%d",&num3);
	
	if(num1 < num2)
	{
		if(num1 < num3)
		{
			printf("%d es el menor ",num1);
		}
		else
		{
			printf("%d es el menor ",num3);
		}
	}
	else
	{
		if(num2 < num3)
		{
			printf("%d es el menor ",num2);
		}
		else
		{
			printf("%d es el menor ",num3);
		}
	}
	
	return 0;
}
