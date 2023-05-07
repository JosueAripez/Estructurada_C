#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rojapez.h"

#define N 500

typedef struct _alumno
{
	char Estatus;
	long Matricula;
	char Nombre_s[30];
	char Apellido_Paterno[30];
	char Apellido_Materno[30];
	int Edad;
	char Sexo;
} Tsalumno;

int msges();
void menu();

Tsalumno Registro_Manual();
Tsalumno Registro_Aleatorio();
void Imprime_Registro(Tsalumno v[],int n);
void Ordena_Registro(Tsalumno v[],int n);
void Busca_Registro(Tsalumno v[],int n,int op);

int main()
{
	srand(time(NULL));
	menu();	
	return 0;
}

int msges()
{
	int op;
	system("CLS");
	printf ("--------------MENU--------------\n");
    printf("1.- Agregar (Automatico 10 registros)\n");
    printf("2.- Agregar Manual\n");
    printf("3.- Eliminar Registro \n");
    printf("4.- Buscar\n");
    printf("5.- Ordenar\n");
    printf("6.- Imprimir\n");
    printf("0.- Salir\n");
    op = Vali_Num(0,6,"Ingresa una opcion","Opcion invalida");
    return op;
}

void menu()
{
	int op;
	int i = 0, j, num;
	Tsalumno vect[N],reg;
    do
	{
     	
        op = msges();
        switch (op)
        {
           	case 1:
				system("CLS");
           	  	printf("1.- Agregar (Automatico 10 registros)\n");
				if(i < N-10)
				{
					for(j=0; j<10; j++, i++)
					{
						vect[i] = Registro_Aleatorio();
					}
				}
				printf("\nSe crearon 10 registros\n",164);
				system("\nPAUSE\n");
              	break;
              
            case 2:
				system("CLS");
              	printf("2.- Agregar Manual\n");
				printf("\n¿Cuantos registros desea generar?\n");
				scanf("%d",&num);
				  
				if(i < N-num)
				{
					for(j = 0;j < num;j++,i++)
				 	{
						vect[i] = Registro_Manual();
					}
				}
				system("PAUSE");
              	break;
              
            case 3:
				system("CLS");
              	printf("3.- Eliminar Registro \n");
              	Busca_Registro(vect,i,op);
              	system("PAUSE");
              	break;
              
            case 4:
				system("CLS");
              	printf("4.- Buscar\n");
              	Busca_Registro(vect,i,op);
              	system("PAUSE");
              	break;
              
            case 5:
				system("CLS");
              	printf("5.- Ordenar\n");
              	Ordena_Registro(vect,i);
              	system("PAUSE");
              	break;
            
			case 6:
				system("CLS");
              	printf("6.- Imprimir\n");
              	Imprime_Registro(vect,i);
              	system("PAUSE");
              	break;
        }

    }while (op != 0);
}

Tsalumno Registro_Aleatorio()
{
	Tsalumno reg;
	int sex;
	char Nombre_s[15][20];
	char Nom_Muj[20][15] = {"Blanca","Estela","Brisa","Fernanda","Yuniva","Dayany","Dayana","Jessica","America","Alexia","Julia","Ashley","Alexa","Maria","Keyla"};
	char Nom_Homb[20][15]  = {"Josue","Francisco","Nilton","Daniel","Isaac","Abraham","Jose","Roberto","Gerrardo","Alex","Henrry","Thomas","Agustin","Norberto","Carlos"};
	char Apell[20][15] = {"Rojas","Aripez","Rojapez","Bañuelos","Escamilla","Beristain","Leyva","Bustamante","Trujillo","Ybarra","Robins","Wilson","Grey","Shepherd","Herrera"};

	system("CLS");
	printf("Registro creado aleatoriamente");
	sex = rand()%2;
	
	if(sex == 0) 
	{
	  	strcpy(reg.Nombre_s,Nom_Muj[rand()%15]);
	} 
	else 
	{
	  	strcpy(reg.Nombre_s,Nom_Homb[rand()%15]);
	} 
	  
	if (sex == 0)
	{
		reg.Sexo = 'M';
	}
	else
	{
		reg.Sexo = 'H';
	}  
	
	strcpy(reg.Apellido_Paterno,Apell[rand()%15]);
	strcpy(reg.Apellido_Materno,Apell[rand()%15]);
	reg.Matricula = rand()%70000 + 330000;
	reg.Estatus = 'A';
	reg.Edad = rand()%8 + 18;
	return reg;
}

Tsalumno Registro_Manual()
{
	Tsalumno reg;
	int sex, Edad;
	long Matricula;
	char Nombre_s[20], Apellido_Paterno[20], Apellido_Materno[20],Sexo;
	system("CLS");
	fflush(stdin);
	printf("2.- Agregar Manual\n");
	printf("Creando registro manualmente\n");
	Vali_Cadena(reg.Nombre_s,"\nNombre (s): ");
	fflush(stdin);
	system("CLS");
	Vali_Cadena(reg.Apellido_Paterno,"Apellido Paterno: ");
	fflush(stdin);
	system("CLS");
	Vali_Cadena(reg.Apellido_Materno,"Apellido Materno: ");
	system("CLS");
	reg.Estatus = 'A';
	system("CLS");
	reg.Matricula = Vali_Long(0, 100000000, "Matricula: ", "Matricula invalida");
	system("CLS");
	reg.Edad = Vali_Num(0,100,"Edad: ","Edad No Valida");
	system("CLS");
	sex = Vali_Num(1,2,"Selecciona tu sexo | 1.- Mujer | 2.- Hombre: ","Opcion invalida");
	system("CLS");
	
	if (sex == 1)
	{
		reg.Sexo = 'M';
	}
	else
	{
		if (sex == 2)
		{
			reg.Sexo = 'H';
		}
		else
		{
			printf("Opcion invalida\n");
		}
	}
	return reg;
}

void Busca_Registro(Tsalumno v[],int n,int op)
{
	int i;
	long Matricula;
	
	system("CLS");
	Matricula = Vali_Long(300000,100000000,"Ingresa matricula a buscar: ","Ese numero no es valido");
	for(i = 0;(i < n ) && (v[i].Matricula != Matricula);i++)
	{
	}
	
	if(i>=n)
	{
		printf("Matricula no registrada\n");
	}
	else
	{
		printf("%8s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\n","Estatus","Matricula","Nombre_s","Ap Paterno","Ap Materno","Edad","Sexo");
		printf("%8c\t%8ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",v[i].Estatus,v[i].Matricula,v[i].Nombre_s,v[i].Apellido_Paterno,v[i].Apellido_Materno,v[i].Edad,v[i].Sexo);
	}
	
}

void Ordena_Registro(Tsalumno v[],int n)
{
	int i,j;
	long temp = 0;
	Tsalumno tempo;
	printf("Se ha ordenado\n");
    for (i = 0; i <= n; i++)
    {
    	for (j = 0; j <= n - i; j++)
		{
			if (v[j].Matricula < v[j + 1].Matricula)
			{
				tempo = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tempo;	
			}	
		}	
	}
}

void Imprime_Registro(Tsalumno v[],int n)
{
	int i;
	system("CLS");
	printf("6.- Imprimir\n");
	printf("Imprimiendo\n");
	printf("%8s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\n","Estatus","Matricula","Nombre (s)","Ap Paterno","Ap Materno","Edad","Sexo");
	for(i=0;i < n;i++)
	{
	   	if (v[i].Estatus == 'A')
	   	{
	   		printf("%8c\t%8ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",v[i].Estatus,v[i].Matricula,v[i].Nombre_s,v[i].Apellido_Paterno,v[i].Apellido_Materno,v[i].Edad,v[i].Sexo);
		}
	}
}
