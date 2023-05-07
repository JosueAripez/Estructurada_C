#include <stdio.h>

main()
{
	
	int llamada, min ;
	float total, subtotal, iva;
	
	printf("Llamadas: ");
	printf("1)Llamada local ");
	printf("2)Llamada Nacional ");
	printf("3)Llamada Internacional ");
	
	printf("Seleccione la llamada que hara ");
	scanf("%d",&llamada);

	printf("Cantidad de minutos hablados ");
	scanf("%d",&min);
	
	if(llamada == 1)
	{
		
		printf("Llamada Local ");
		subtotal = min * 3;
		
	}
	
	if(llamada == 2)
	{
		printf("Llamada Nacional ");
		if(min > 3)
		{
			
			subtotal = (min-3) * 2;
			subtotal = subtotal + 21;
			
		}
		else
		{
			subtotal = min * 7;
		}
	}
	
	if(llamada == 3)
	{
		printf("Llamada Internacional ");
		if(min > 2)
		{
			
			subtotal = (min-2) * 4;
			subtotal = subtotal + 18;
			
		}
		else
		{
			subtotal = min * 9;
		}
	}
	
	iva = subtotal * 0.16;
	total = iva + subtotal;
	
	printf("El subtotal es: %.2f ", subtotal);
	printf("IVA: %.2f ", iva);
	printf("Su total: %.2f ", total);
	
	return 0;
	
}
