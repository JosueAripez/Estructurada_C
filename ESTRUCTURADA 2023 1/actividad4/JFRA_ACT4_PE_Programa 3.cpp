#include <stdio.h>

int main()
{
	int num1, num2, num3, num4, num5, num6, mayor;
	
	printf("Ingresa el primer numero: \n");
	scanf("%d ", &num1);
	
	printf("Ingresa el segundo numero: \n");
	scanf("%d ",&num2);
	
	printf("Ingresa el tercer numero: \n");
	scanf("%d ",&num3),
	
	printf("Ingresa el cuarto numero: \n");
	scanf("%d ",&num4);
	
	printf("Ingresa el quinto numero: \n");
	scanf("%d ",&num5);
	
	printf("Ingresa el sexto numero: \n");
	scanf("%d ",&num6);
	
	mayor = num1;

	if(num2>mayor)
	{
		mayor = num2;
	}
	
	if(num3>mayor)
	{
		mayor = num3;
	}
	
	if(num4>mayor)
	{
		mayor = num4;
	}
	
	if(num5>mayor)
	{
		mayor = num5;
	}
	
	if(num6>mayor)
	{
		mayor = num6;
	}
	
	printf("%d es el numero mayor", mayor);
	
	return 0;

}