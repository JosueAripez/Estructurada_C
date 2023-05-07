#include <stdio.h>

main()
{
	
	int hrs, hrs2, hrsT ;
	float sal, salN, sal2, salT, total;
	
	printf("Ingresa las horas que trabajo durante la semana: ");
	scanf("%d",&hrs);

	printf("Ingrese su salario por hora: ");
	scanf("%f",&sal);
	
	hrs2 = 40;
	hrsT = 49;
	
	printf("Horas que se trabajaron: %d\n",hrs);
	
	if(hrs > hrs2)
	{
		printf("Horas normales: 40 ");
		if(hrs > hrsT)
		{
			
			salN = sal * 40;
			sal2 = (sal * 2) * 9;
			salT = (hrs - hrsT) * (sal * 3);
			total = salN + sal2 + salT;
		
			printf("Horas dobles: 9\n");
			printf("Salario por 9 horas dobles trabajadas: %.2f\n",sal2);
			printf("Salario por %d horas triples trabajdas: %.2f\n",(hrs - 49), salT);
			
		}
		else
		{
			
			salN = sal * 40;
			sal2 = (hrs - hrs2) * (sal * 2);
			total = salN + sal2 ;
			printf("Salario por %d horas dobles trabajadas: %.2f\n",(hrs - 40), sal2);
			
		}
	}
	else
	{
		salN = hrs * sal;
	}
	
	printf("Salario normal: %.2f ", salN);
	printf("Salario extra: %.2f ",(sal2+salT));
	printf("Salario total: %.2f ",total);
	
	return 0;
}
