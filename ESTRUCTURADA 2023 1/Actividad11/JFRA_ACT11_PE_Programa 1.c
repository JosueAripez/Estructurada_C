#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Rojapez.h"

#define N 2000

typedef struct _alumno
{
	char Estatus;
    char estado;
	long matricula;
	long Matricula;
	char Nombre_s[30];
	char Apellido_Paterno[30];
	char Apellido_Materno[30];
	int Edad;
	char Sexo;
} Tsalumno;

int msges();
void menu();

Tsalumno Registro_Aleatorio();
void Elim_Reg(Tsalumno v[],int n);
void Ordena_Registro(Tsalumno v[],int n);
void Busca_Registro(Tsalumno v[],int n,int op);
void Imprime_Registro(Tsalumno v[],int n);
void Gen_Txt(Tsalumno v[],int n);

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
	printf ("------------Menu---------- \n");
    printf("1.- Cargar\n");
    printf("2.- Eliminar\n");
    printf("3.- Buscar\n");
    printf("4.- Ordenar\n");
    printf("5.- Imprimir\n");
    printf("6.- Archivo de texto\n");
    printf("0.- Salir\n\n");
    op = Vali_Num(0,6,"Ingresa una opcion","Esa opcion no es valida");
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
    			printf("Cargando....\n");
				if(i < N-100)
				{
					for(j=0; j<100; j++, i++)
					{
						vect[i] = Registro_Aleatorio();
					}
				}
				system("\nPAUSE\n");
    			break;
              
            case 2:
				system("CLS");
    			printf("Eliminando....\n");
    			Elim_Reg(vect,n);
				system("PAUSE");
    			break;
              
            case 3:
				system("CLS");
    			printf("Buscando....\n");
    			Busca_Registro(vect,i,op);
				system("PAUSE");
    			break;
              
            case 4:
				system("CLS");
    			printf("Ordenando....\n");
    			Ordena_Registro(vect,i);
    			system("PAUSE");
    			break;
              
            case 5:
				system("CLS");
    			printf("Imprimiendo....\n");
    			Imprime_Registro(vect,i);
    			system("PAUSE");
    			break;
            
			case 6:
				system("CLS");
    			printf("Creando archivo de texto....\n");
    			Gen_Txt(vect,n);
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

void Elim_Reg(Tsalumno v[],int n)
{
	int i;
	long matricula;
	bool encon;
	
	system("CLS");
	matricula = Vali_Long(300000,100000000,"¿Que matricula buscas? ","Ese numero no es valido");
	
	for(i=0;(i<n )&&(v[i].matricula != matricula);i++)
	{
	}
	if(i == n)
	{
		printf("Esa matricula no se encuentra en el sistema.\n");
	}
	else
	{
		v[i].estado = 'I';
		printf("\nEstado: Inactivo\n");
	}
	
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
	printf("%8s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\n","Estatus","Matricula","Nombre (s)","Ap Paterno","Ap Materno","Edad","Sexo");
	for(i=0;i < n;i++)
	{
		if (v[i].Estatus == 'A')
		{
			printf("%8c\t%8ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",v[i].Estatus,v[i].Matricula,v[i].Nombre_s,v[i].Apellido_Paterno,v[i].Apellido_Materno,v[i].Edad,v[i].Sexo);
		}
	}
}
void Gen_Txt(Tsalumno v[],int n)
{
	int i;
	bool stat = false;
	char nom_archi[24];
	FILE * archi;
	system("CLS");
	
	do
	{
		printf("Ingresa el nombre de su archivo: ");
		fflush(stdin);
		gets(nom_archi);
		stat = ValidTxt(nom_archi);
	}while (stat==true);
	
	strcat(nom_archi,".txt\0");
	printf("\nEl nuevo nombre del archivo es: %s\n",nom_archi);
	
	archi = fopen(nom_archi,"w");
	if (archi == NULL)
    {
        printf("No se puede abrir el archivo");
    }
	
	for(i = 0;i < n;i++)
	{
		if (v[i].estado == 'A')
		{
			fprintf(archi,"%8d\t%8ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",i,v[i].matricula,v[i].nombre,v[i].ap_pa,v[i].ap_ma,v[i].edad,v[i].sexo);
		}
	}
	fclose(archi);
}
