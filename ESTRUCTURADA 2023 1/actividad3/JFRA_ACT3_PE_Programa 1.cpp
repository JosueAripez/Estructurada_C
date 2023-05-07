#include <stdio.h>

main()
{
	
	int cal1, cal2, cal3, cal4, prom;
	
	printf("Ingresa la calificacion 1: ");
	scanf("%d",&cal1);

	printf("Ingresa la calificacion 2: ");
	scanf("%d",&cal2);
	
	printf("Ingresa la calificacion 3: ");
	scanf("%d",&cal3);

	printf("Ingresa la calificacion 4: ");
	scanf("%d",&cal4);
	
	prom = (cal1 + cal2 + cal3 + cal4) / 4;
	
	if(prom >= 60)
	{
		printf("Aprobado con promedio de: %d",prom);
	}
	
	if(prom < 60)
	{
		printf("Reprobado con promedio de: %d",prom);
	}
	
	return 0;
}
