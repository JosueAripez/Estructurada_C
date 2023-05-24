#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Rojapez.h"

#define N 2000

typedef struct _alumno{
	
	char estado;
	long matricula;
	char nombre[30];
	char ap_pa[30];
	char ap_ma[30];
	int edad;
	char sexo;
} Tsalumno;

int msges();
void menu();


Tsalumno Gen_Aleatorio();
void Elim_Reg(Tsalumno v[],int n);
void Busc_Reg(Tsalumno v[],int n,bool orden);
void Ord_Reg(Tsalumno v[],int n);
void Imprim_Reg(Tsalumno v[],int n);
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
	bool ord = false;
	bool arch_carg = false;
	int op;
	int i = 0,j,num;
	Tsalumno vect[N],reg;
    do
    {
     	
        op = msges();
        switch (op)
        {
           	case 1:
				if(i < N-100)
				{
					for(j=0; j<100; j++, i++)
					{
						vect[i] = Gen_Aleatorio();
					}
				}
				printf("Se crearon 1500 registros correctamente\n");
				ord = false;
				system("PAUSE");
            break;
              
            case 2:
					Elim_Reg(vect,i);
				system("PAUSE");
            break;
              
            case 3:
              	Busc_Reg(vect,i,ord);
              	system("PAUSE");
            break;
              
            case 4:
              	Ord_Reg(vect,i);
              	system("PAUSE");
            break;
              
            case 5:
              	Imprim_Reg(vect,i);
              	system("PAUSE");
            break;
              
            case 6:
              	Gen_Txt(vect,i);
              	system("PAUSE");
            break;
        }
    }while (op != 0);
}

Tsalumno Gen_Aleatorio()
{
	Tsalumno reg;
	int sex;
	char nombre[15][20];
	char Nom_Muj[20][15] = {"Blanca","Estela","Brisa","Fernanda","Yuniva","Dayany","Dayana","Jessica","America","Alexia","Julia","Ashley","Alexa","Maria","Keyla"};
	char Nom_Homb[20][15]  = {"Josue","Francisco","Nilton","Daniel","Isaac","Abraham","Jose","Roberto","Gerrardo","Alex","Henrry","Thomas","Agustin","Norberto","Carlos"};
	char Apell[20][15] = {"Rojas","Aripez","Rojapez","Bañuelos","Escamilla","Beristain","Leyva","Bustamante","Trujillo","Ybarra","Robins","Wilson","Grey","Shepherd","Herrera"};

	system("CLS");
	
	sex = rand()%2;
	if(sex == 0) 
	{
	  	strcpy(reg.nombre,Nom_Muj[rand()%15]);
	  	reg.sexo = 'M';
	} 
	else 
	{
	  	strcpy(reg.nombre,Nom_Homb[rand()%15]);
	  	reg.sexo = 'H';
	} 
	
	strcpy(reg.ap_pa,Apell[rand()%15]);
	strcpy(reg.ap_ma,Apell[rand()%15]);
	reg.matricula = rand()%70000 + 330000;
	reg.estado = 'A';
	reg.edad = rand()%8 + 18;
	return reg;
}

void Elim_Reg(Tsalumno v[],int n)
{
	int i;
	long matricula;
	bool encon;
	
	system("CLS");
	matricula = Val_Long(300000,100000000,"¿Que matricula buscas? ","Matricula no encontrada");
	
	for(i=0;(i<n )&&(v[i].matricula != matricula);i++)
	{
	}
	if(i == n)
	{
		printf("Matricula inexsistente\n");
	}
	else
	{
		v[i].estado = 'I';
		printf("\nEstado: Inactivo\n");
	}
	
}

void Busc_Reg(Tsalumno v[],int n,bool orden)
{
    bool encon;
	int i,band,sup,inf,med;
	long matricula;
	
	system("CLS");
	band = TRUE;
	matricula = Val_Long(300000,100000000,"¿Que matricula buscas? ","Matricula no encontrada");
	
	for(i=0;(i<n)&&(encon == false);i++)
	{
		if(matricula == v[i].matricula)
		{
			printf("%5s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\n","No.Registro","Matricula","Nombre","Ap Paterno","Ap Materno","Edad","Sexo");
			printf("%5d\t%16ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",i,v[i].matricula,v[i].nombre,v[i].ap_pa,v[i].ap_ma,v[i].edad,v[i].sexo);
			printf("\n");
			encon = true;
		}
	}
	if(encon == false)
	{
	    printf("Matricula inexsistente\n");
	}	
}

void Ord_Reg(Tsalumno v[],int n)
{
	int i,j;
	long temp = 0;
	Tsalumno tempo;
	printf("Se ha ordenado\n");
    for (i = 0; i <= n; i++)
    {
    	for (j = 0; j <= n - i; j++)
		{
			if (v[j].matricula < v[j + 1].matricula)
			{
				tempo = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tempo;	
			}	
		}	
	}
}

void Imprim_Reg(Tsalumno v[],int n)
{
	int i;
	system("CLS");
	printf("%5s\t%10s\t%8s\t%8s\t%8s\t%8s\t%8s\n","No.Registro","Matricula","Nombre","Ap Paterno","Ap Materno","Edad","Sexo");
	for(i=0;i < n;i++)
	{
	    if (v[i].estado == 'A')
	    {
	   		printf("%5d\t%16ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",i,v[i].matricula,v[i].nombre,v[i].ap_pa,v[i].ap_ma,v[i].edad,v[i].sexo);
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
		printf("Ingrese el nombre de su archivo: ");
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