#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "Rojapez.h"


#define DERECHA 77
#define IZQUIERDA 75
#define ENTER 13
#define ESC 27
#define TAB 9
void LeerApellidoMaterno(char am[]);
void ApellidoPaterno(char ap[]);
void Nombres(char c1[], char c2[]);
void Fecha(char Fc[]);
void ImprCurp(char c1[], char c2[], char ap[],char am[], char Fc[],int sexo, char EntFed[]);
void Datos_CURP();
int Sexo();
int LeerEntFed(char EntFed[]);

int main()
{
	bool salir = false;
	char op;
	do
	{
		Datos_CURP();
		system("PAUSE");
		system("CLS");	
		printf("¿Deseas consultar otra CURP? (Y/N)");
		fflush(stdin);
		op = getch();
		printf("%c",op);
		if (op == 'N' || op == 'n')
		{
			salir = true;
		}
	}while (!salir);
	return 0;
}

void Datos_CURP()
{
	char c1[20], c2[20], ap[20], am[20], Fc[9],EntFed[2];
	int sexo;
	strcpy(c1,"JOSE");
	strcpy(c2,"ANDRES");
	strcpy(ap,"DE LA LOMA");
	strcpy(am,"XIU");
	Nombres(c1,c2);
	ApellidoPaterno(ap);
	LeerApellidoMaterno(am);
	Fecha(Fc);
	sexo = Sexo();
	LeerEntFed(EntFed);
	ImprCurp(c1,c2,ap,am,Fc,sexo,EntFed);
}

void Nombres(char c1[], char c2[])
{
	char n1[20],n2[20],Esp[1], a[2];
	int carac, i=0, DobEsp, EspI, j, Espp=0,k=0, carA;
	bool ValA=false;
	i=0;
	k=0;
	Espp=0;
	system ("CLS");
	printf("Bienvenido a la Consulta del CURP. Ingresa los datos que se le pidan\n");
	printf("\n");
	system("PAUSE");
	system("CLS");
	printf("Ingresa Nombres (s): ");
	do
	{
		carac = getch();
			
		if(carac == 8 && i!= 0 && Espp == 0 && k==0)
		{
			i=i-1;
			system ("CLS");
			printf("Ingresa Nombres (s): ");
			for(j = 0;j <= i-1 ;j++)
			{
				printf("%c",n1[j]);
			}
		}
		if(carac == 8 && k!=0 && Espp == 1)
		{
			k = k-1;
			system ("CLS");
			printf("Ingresa Nombres (s): ");
			
			for(j = 0;j <= i-1 ;j++)
			{
				printf("%c",n1[j]);
			}  
				
			for(j = 0;j <= k-1 ;j++)
			{
				printf("%c",n2[j]);
			}  
				   
			if(k == 0)
			{
				Espp = 0;
			}
		}
		else
		{
			if(carac >= 97 && carac <=122)
			{
				carac = carac - 32;
			}	
			if((carac >= 65 && carac <= 90) || carac == 32)
			{
				if(i == 0 && carac == ' ')
				{
					EspI=1;
				}
					
				if(carac ==' ')
				{
					Espp = 1;
				}
				else
				{
					EspI = 0;
				}	
				if(EspI==0 && Espp==0)
				{
					if(n1[i-1]==' ' && carac == ' ')
					{
						DobEsp=1;
					}
					else 
					{ 
						DobEsp=0;
					}		
					if(DobEsp==0)
					{
						printf("%c",carac);
						n1[i]=carac;
						i++;
					}
				}
				if(Espp==1)
				{
					if(n1[k-1]==' ' && carac==' ')
					{
						DobEsp=1;
					}
					else 
					{
						DobEsp=0;
					}
						  
					if(DobEsp==0)
					{
						printf("%c",carac);
						n2[k]=carac;
						k++;
					}
				}
			}
		}
	}while(carac != ENTER && i!=20 && Espp!=2);
	
	n1[i]='\0';
	n2[k]='\0';
	fflush(stdin);
	
	if(i>=20)
	{
		printf("\nLimite de caracteres alcanzado :(\n");
	}

/*	for(j=0;j<k;j++)
	{
		n2[j]=n2[j+1];
	}*/
	strcpy(c1,n1);
	strcpy(c2,n2);
}

void ApellidoPaterno(char ap[])
{
	int car, i=0, j, a[2];
	char AP[20],Esp[1], carA;
	bool ValA=false;
	i=0;
	system ("CLS");
	printf("Apellido paterno:");
	
	do{
		car=getch();
		
		if(car==8 && i!=0)
		{
			i=i-1;
			system ("CLS");
			printf("Apellido paterno:");
			for(j=0;j<=i-1 ;j++)
			{
				printf("%c",AP[j]);
			}
		}
		else
		{
			if(car >=97 && car <=122)
			{
				car = car-32;
			}
			if((car>=65 && car <=90 ) || car==32)
			{
				if(i==0 && car==' ')
				{
				}
				else
				{
					if(car==' ' && AP[i-1]==' ')
					{
					}
					else
					{
						printf("%c",car);
						AP[i]=car;
						i++;
					}
				}
			}
			if(car==164 || car == 165)
			{
				printf("%c",165);
				AP[i]=165;
				i++;
			}
		}
	}while(car!=ENTER);
	AP[i]='\0';
	fflush(stdin);
	if(i>=20)
	{
		printf("\nLimite de caracteres alcanzado :(\n");
	}
	strcpy(ap,AP);
}

void LeerApellidoMaterno(char am[])
{
	int car, i=0, j, a[2];
	char AM[20],Esp[1], carA;
	bool ValA=false;

	i=0;
	system ("CLS");
	printf("Apellido materno:");
	
	do{
		car=getch();
		
		if(car==8 && i!=0)
		{
			i=i-1;
			system ("CLS");
			printf("Apellido materno:");
			for(j=0;j<=i-1 ;j++)
			{
				printf("%c",AM[j]);
			}
		}
		else
		{
			if(car >=97 && car <=122)
			{
				car = car-32;
			}
			if((car>=65 && car <=90 ) || car==32)
			{
				if(i==0 && car==' ')
				{
				}
				else
				{
					if(car==' ' && AM[i-1]==' ')
					{
					}
					else
					{
						printf("%c",car);
						AM[i]=car;
						i++;
					}
				}
			}
			if(car==164 || car == 165)
			{
				printf("%c",165);
				AM[i]=165;
				i++;
			}
		}
	}while(car!=ENTER);
	AM[i]='\0';
	fflush(stdin);
	if(i>=20)
	{
		printf("\nLimite de caracteres alcanzado :(\n");
	}
	strcpy(am,AM);
		
}

void Fecha(char Fc[])
{
	
	bool Val = true, ValA=false;
	int car, i=0, DobEsp, EspI, j, a[2];
	char D[3],M[3],Y[20],Esp[1],c2[20], carA;

	
	i=0;
	system ("CLS");
	do
	{
		if(Val==false)
		{
			i=0;
		}
		system("CLS");
		printf("Fecha de nacimiento:   /  /    ");
		if(Val==false)
		{
			printf("\nFecha invalida ");
		}
		do
		{
			car=getch();
		
			if(car>=48 && car<=57 || car==8)
			{
				if(car==8 && i!=0)
				{
					i=i-1;
					if(i==0)
					{
						system("CLS");
						printf("Fecha de nacimiento:   /  /    ");
					}
					if(i!=0 && i<=2)
					{
						system("CLS");
						if(i-1==0)
						{
							printf("Fecha de nacimiento: %c /  /    ",D[0]);
						}
						if(i-1==1)
						{
							printf("Fecha de nacimiento: %c%c/  /    ",D[0],D[1]);
						}
					}
					if(i>=3 && i<=4)
					{
						system("CLS");
						if(i-1==2)
						{
							printf("Fecha de nacimiento: %c%c/%c /    ",D[0],D[1],M[0]);
						}
						if(i-1==3)
						{
							printf("Fecha de nacimiento: %c%c/%c%c/    ",D[0],D[1],M[0],M[1]);
						}
					}	
					if(i>=5 && i<=9)
					{
						system("CLS");
						if(i-1==4)
						{
							printf("Fecha de nacimiento: %c%c/%c%c/%c   ",D[0],D[1],M[0],M[1],Y[0]);
						}
						if(i-1==5)
						{
							printf("Fecha de nacimiento: %c%c/%c%c/%c%c  ",D[0],D[1],M[0],M[1],Y[0],Y[1]);
						}
						if(i-1==6)
						{
							printf("Fecha de nacimiento: %c%c/%c%c/%c%c%c ",D[0],D[1],M[0],M[1],Y[0],Y[1],Y[2]);
						}
						if(i-1==7)
						{
							printf("Fecha de nacimiento: %c%c/%c%c/%c%c%c%c",D[0],D[1],M[0],M[1],Y[0],Y[1],Y[2],Y[3]);
						}
					}
				}
				else
				{
					if(i==0)
					{
						system("CLS");
						printf("Fecha de nacimiento:   /  /    ");
					}
					if(car==' ')
					{
						EspI=1;
					}
					else
					{
						EspI=0;
					}
					if(EspI==0 && car!=8)
					{
						if(i<=1)
						{
							system("CLS");
							D[i]=car;
							if(i==0)
							{
								printf("Fecha de nacimiento: %c /  /    ",D[0]);
							}
							if(i==1)
							{
								printf("Fecha de nacimiento: %c%c/  /    ",D[0],D[1]);
							}
						}
						if(i>=2 && i<=3)
						{
							system("CLS");
							M[i-2]=car;
							if(i==2)
							{
								printf("Fecha de nacimiento: %c%c/%c /    ",D[0],D[1],M[0]);
							}
							if(i==3)
							{
								printf("Fecha de nacimiento: %c%c/%c%c/    ",D[0],D[1],M[0],M[1]);
							}
						}
						if(i>=4 && i<=8)
						{
							system("CLS");
							Y[i-4]=car;
							if(i==4)
							{
								printf("Fecha de nacimiento: %c%c/%c%c/%c   ",D[0],D[1],M[0],M[1],Y[0]);
							}
							if(i==5)
							{
								printf("Fecha de nacimiento: %c%c/%c%c/%c%c  ",D[0],D[1],M[0],M[1],Y[0],Y[1]);
							}
							if(i==6)
							{
								printf("Fecha de nacimiento: %c%c/%c%c/%c%c%c ",D[0],D[1],M[0],M[1],Y[0],Y[1],Y[2]);
							}
							if(i==7)
							{
								printf("Fecha de nacimiento: %c%c/%c%c/%c%c%c%c",D[0],D[1],M[0],M[1],Y[0],Y[1],Y[2],Y[3]);
							}
						}
						c2[i]=car;
						i++;
					}
				}
			}
		}while( i!=8 );
		int Dia = (int) strtol(D, NULL, 10);
		int Mes = (int) strtol(M, NULL, 10);
		int Year = (int) strtol(Y, NULL, 10);
		if (Year>=1900 && Year<=2021)
		{
			if(Mes==1 || Mes==3 || Mes==5 || Mes==7 || Mes==8 || Mes==10 || Mes==12)
			{
				if(Dia>=1 && Dia<=31)
				{
					Val=true;
				}
				else
				{
					Val=false;
				}
			}
			if(Mes==4 || Mes==6 || Mes==9 || Mes==11)
			{
				if(Dia>=1 && Dia<=30)
				{
					Val=true;
				}
				else
				{
					Val=false;
				}
			}
			if(Mes==2)
			{
				if ( Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0)
				{
					if(Dia>=1 && Dia<=29)
					{
		    			Val=true;
					}
					else
					{
		    			Val=false;
					}
				}
				else
				{
					if(Dia>=1 && Dia<=28)
					{
				    	Val=true;
					} 
					else
					{
						Val=false;
					}
				}
			}
			if(Mes > 12)
			{
				Val=false;
			}
			if(Dia>31)
			{
				Val=false;
			}
		}
		else
		{
			Val=false;
		}
		printf("\n%d/%d/%d\n",Dia,Mes,Year);
	}while(Val!=true);
	
	c2[i]='\0';
	fflush(stdin);
	if(i>=20)
	{
		printf("\nLimite de caracteres alcanzado :(\n");
	}
	printf("\n%c%c/%c%c/%c%c%c%c\n",c2[0],c2[1],c2[2],c2[3],c2[4],c2[5],c2[6],c2[7]);
	strcpy(Fc,c2);

	
}

int Sexo()
{
    int car, i=0, DobEsp, EspI, j, Espp=0, a[2];
	char Sexo[5],Esp[1], carA;
	int ValA=false, ValB=true;
	Sexo[0]=a;
	i=0;
	system ("CLS");
	printf("Selecciona tu Sexo:(Utilizando tab)  \n>Hombre		 Mujer");
	
	do
	{
		
		car=getch();
		
		if(car == TAB || i==0)
		{
			if(ValB==false)
			{
				system ("CLS");
				printf("Selecciona tu sexo:(Utilizando tab)  \n Hombre		>Mujer");
				strcpy(Sexo, "Mujer");
				ValB=true;
			}
			else
			{
				system ("CLS");
				printf("Selecciona tu sexo:(Utilizando tab) \n>Hombre		 Mujer");
				strcpy(Sexo, "Hombre");
				ValB=false;
			}
		}
			
		i++;
	}while(car!=ENTER);
	return ValB;
}

int LeerEntFed(char EntFed[])
{
	char sig[][33] = {"AS","BC","BS","CC","CL","CM","CS","CH","DF","DG","GT","GR","HG","JC","MC","MN","MS","NT","NL","OC","PL","QT","QR","SP","SL","SR","TC","TS","TL","VZ","YN","ZS","NE"},a[2],carA,car,cad[][33] = {"AGUASCALIENTES","BAJA CALIFORNIA","BAJA CALIFORNIA SUR","CAMPECHE","COAHUILA","COLIMA","CHIAPAS","CHIHUAHUA","DISTRITO FEDERAL","DURANGO","GUANAJUATO","GUERRERO","HIDALGO","JALISCO","MEXICO","MICHOACAN","MORELOS","NAYARIT","NUEVO LEON","OAXACA","PUEBLA","QUERETARO","QUINTANA ROO","SAN LUIS POTOSI","SINALOA","SONORA","TABASCO","TAMAULIPAS","TLAXCALA","VERACRUZ","YUCATAN","ZACATECAS","NACIDO EN EL EXTRANJERO"};
	int i,ValA=false;
	
	system("cls");
	printf("Estado de nacimiento: %s \n", cad[0]);
	printf("Utiliza las flechas de tu teclado para seleccionar el estado.\n");
	i=0;
	do
	{
		car = getch();
				
		if (car == DERECHA)
		{
			if (i == 32)
			{
				i = -1;
			}
			i++;
		}
		else
		{
			if (car == IZQUIERDA)
			{
				if (i == 0)
				{
					i = 33;
				}
				i--;
			}
		}
		system("CLS");
		printf("Estado de nacimiento: %s \n", cad[i]);
		printf("Utiliza las flechas de tu teclado para seleccionar el estado.\n");
	} while (car != ENTER);
		
	printf("\nEntidad federativa: %s\n",cad[i]);
	strcpy(EntFed,sig[i]);
}

void ImprCurp(char c1[], char c2[], char ap[],char am[], char Fc[],int sexo, char EntFed[])
{
	char curp[19] = "",dv[3];
	int i,sal=false,ano,numrandom;
	system("CLS");
	if(strstr(ap,"DE LA ")==NULL)
	{
		curp[0] = ap[0];
	}
	else
	{
		strcpy(ap,&ap[6]);
		curp[0]=ap[0];
	}
	i=1;
	do
	{
		if(ap[i]=='A' || ap[i]=='E' || ap[i]=='I' || ap[i]=='O'|| ap[i]=='U') 
		{
			curp[1]=ap[i];
			sal = true;
		}
		i++;
	}while(sal == false);
	if(strcmp(am,"")==0) 
	{
		curp[2]='X';
	}
	else
	{
		if(strstr(am,"DE LA ")==NULL)
		{
			curp[2] = am[0];
		}
		else
		{
			strcpy(am,&am[6]);
			curp[2]=am[0];
		}
	}
	if(strcmp(c1,"JOSE")==0 && strcmp(c2,"")!=0) 
	{
		strcpy(c1,c2);
	}
	if(strcmp(c1,"MARIA")==0 && strcmp(c2,"")!=0) 
	{
		strcpy(c1,c2);
	}
	
	curp [3] = c1[0];
	curp [4] = Fc[6];
	curp [5] = Fc[7];
	curp [6] = 	Fc[2];
	curp [7] = Fc[3];
	curp [8] = Fc [0];
	curp [9] = Fc[1];
	curp [10] = (sexo==true)?'M':'H';
	curp [11] = EntFed[0];
	curp [12] = EntFed[1];
	fflush(stdin);
	printf("\nDatos ingresados:\n");
	printf("\nNombre (s):%s %s ",c1,c2);
	printf("\nApellido (s):%s %s ",ap,am);
	//printf("\nFecha de nacimiento:%c%c/%c%c/%c%c%c%c ",D[0],D[1],M[0],M[1],Y[0],Y[1],Y[2],Y[3]);
	//printf("\nSexo:%d ",ValB);
	printf("\nEntidad Federativa:%s",EntFed);
	printf("\nEl CURP es: ");
	
	//D[3],M[3],Y[20],Esp[1],c2[20], carA
	
	sal = false;
	i=1;
	do
	{
		if(ap[i]=='A' || ap[i]=='E' || ap[i]=='I' || ap[i]=='O'|| ap[i]=='U') 
		{
		}
		else
		{
			curp[13]=ap[i];
			sal = true;
		}
	i++;
	}while(sal == false);
	
	if (strcmp(am,"")!=0)
	{
		sal = false;
		i=1;
		do
		{
			if(am[i]=='A' || am[i]=='E' || am[i]=='I' || am[i]=='O'|| am[i]=='U') 
			{
			}
			else
			{
				curp[14]=am[i];
				sal = true;
			}
			if(i==strlen(am))
			{
				curp[14]='X';
				sal=true;
			}
		i++;
		}while(sal == false);
	}
	else
	{
		curp[14]='X';
	}
	
	sal = false;i=1;
	do
	{
		if(c1[i]=='A' || c1[i]=='E' || c1[i]=='I' || c1[i]=='O'|| c1[i]=='U') 
		{
		}
		else
		{
			curp[15]=c1[i];
			sal = true;
		}
	i++;
	}while(sal == false);

	ano = atoi(&Fc[4]);
	if(ano<2000)
	{
		curp[16]='O';
	}
	else
	{
		curp[16]='A';
	}
	numrandom=(rand()%9)+1;
	itoa(numrandom,&dv,10);
	curp[17]=dv[0];
	
	for(i=0;i<16;i++)
	{
		if (curp[i]==-92 || curp[i]==-91 || curp[i]=='Ñ' || curp[i]=='ñ')
		{
			curp[i]='X';
		}
	}
	if(curp [0] == 'P' && curp[1]=='E' && curp[2]=='N' && curp [3]=='E')
	{
		curp[1]='X';
	}
	if(curp [0] == 'T' && curp[1]=='E' && curp[2]=='T' && curp [3]=='A')
	{
		curp[1]='X';
	}
	if(curp [0] == 'C' && curp[1]=='U' && curp[2]=='L' && curp [3]=='O')
	{
		curp[1]='X';
	}
	if(curp [0] == 'P' && curp[1]=='I' && curp[2]=='J' && curp [3]=='A')
	{
		curp[1]='X';
	}
	if(curp [0] == 'P' && curp[1]=='U' && curp[2]=='T' && curp [3]=='O' && curp[3]=='A')
	{
		curp[1]='X';
	}
	if(curp [0] == 'C' && curp[1]=='U' && curp[2]=='C' && curp [3]=='A')
	{
		curp[1]='X';
	}
	if(curp [0] == 'P' && curp[1]=='I' && curp[1]=='O' && curp[2]=='P' && curp [3]=='I' && curp [3]=='O')
	{
		curp[1]='X';
	}
	if(curp [0] == 'C' && curp[1]=='A' && curp[2]=='C' && curp [3]=='A')
	{
		curp[1]='X';
	}
	if(curp [0] == 'F' && curp[1]=='U' && curp[2]=='C' && curp [3]=='K')
	{
		curp[1]='X';
	}
	if(curp [0] == 'A' && curp[1]=='N' && curp[2]=='O' && curp [3]=='S')
	{
		curp[1]='X';
	}
	if(curp [0] == 'F' && curp[1]=='A' && curp[2]=='L' && curp [3]=='O')
	{
		curp[1]='X';
	}
	for(i=0;i<18;i++)
	{
		printf("%c",curp[i]);
	}
	printf("\n\n");
}
