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
	
	printf("Numeros en orden ascendente: ");
	
	if(num1 > num2)
	{
		if(num1 > num3)
		{
			if(num2 > num3)
			{
				printf(" %d %d %d",num3, num2, num1);
			}
			else
			{
				printf(" %d %d %d",num2, num3, num1);
			}
			
		}
		else
		{
			printf(" %d %d %d",num2, num1, num3);
		}
	}
	else
	{
		if(num2 > num3)
		{
			if(num1 > num3)
			{
				printf(" %d %d %d",num3, num1, num2);
			}
			else
			{
				printf(" %d %d %d",num1, num3, num2);
			}
		}
		else
		{
			printf(" %d %d %d",num1, num2, num3);
		}
	}
	
	return 0;
}
