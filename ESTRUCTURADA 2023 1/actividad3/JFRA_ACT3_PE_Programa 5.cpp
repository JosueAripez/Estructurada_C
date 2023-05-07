#include <stdio.h>

main()
{
	
	int cal1, cal2, cal3, promedio;
	
	printf("Ingresa la calificacion 1: ");
	scanf("%d",&cal1);

	printf("Ingresa la calificacion 2: ");
	scanf("%d",&cal2);
	
	printf("Ingresa la calificacion 3: ");
	scanf("%d",&cal3);

	promedio = (cal1 + cal2 + cal3) / 3;
	
    printf("Su promedio es: %d ", promedio);
	
	if(promedio >= 30)
	{
		if(promedio >= 60)
        {
            if(promedio >= 70)
            {
                if(promedio >= 80)
                {
                    if(promedio >= 90)
                    {
                        if(promedio >= 98)
                        {
                            if(promedio > 100)
                            {
                                printf("Error en el promedio");
                            }
                            else
                            {
                                printf("Excelente");
                            }
                        }
                        else
                        {
                            printf("Muy bien");
                        }
                    }
                    else
                    {
                        printf("Bien");
                    }
                }
                else
                {
                    printf("Regular");
                }
            }
            else
            {
                printf("Suficiente");
            }
        }
        else
        {
            printf("Extraordinario");
        }
	}
    else
    {
        printf("Repetir");
    }
	
	return 0;
}
