#include <stdio.h>

int main()
{
	
	int cal1, cal2, cal3;
	float promedio;

	printf("Ingresa la calificacion 1\n");
	scanf("%d", &cal1);
	printf("Ingresa la calificacion 2\n");
	scanf("%d", &cal2);
	printf("Ingresa la calificacion 3\n");
	scanf("%d", &cal3);

	promedio = (cal1 + cal2 + cal3)/3;

	if(promedio < 30)
    {
        printf("Repetir");
    }
    else
    {
        if(promedio < 60)
        {
            printf("Extraordinario");
        }
        else
        {
            if(promedio < 70)
            {
                printf("Suficiente");
            }
            else
            {
                if(promedio < 80)
                {
                    printf("Regular");
                }
                else
                {
                    if(promedio < 90)
                    {
                        printf("Bien");
                    }
                    else
                    {
                        if(promedio < 98)
                        {
                            printf("Muy bien");
                        }
                        else
                        {
                            if(promedio <= 100)
                            {
                                printf("Excelente");
                            }
                            else
                            {
                                printf("Error en el promedio");
                            }
                        }
                    }
                }
            }
        }
    }

	return 0;
}