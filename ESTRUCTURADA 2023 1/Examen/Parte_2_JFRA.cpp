#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Rojapez.h"

typedef struct _tusuario
{
	int status;
	char nombre[30];
	char usuario[30];
	char cont[30];
	int cont_nv;

}Tusuario;

int msges();
void Gen_U();
void Agrega_U();
void Imprime_U();
int menu();

int main()
{
	Gen_U();
	menu();
	return 0;
}

int msges()
{	
	int op;
	system("CLS");
	printf ("--------------MENU--------------\n");
    printf("1.- Agregar Usuario\n");
    printf("2.- Mostrar Usuarios\n");
    printf("0.- Salir\n");
	op = vali_num(0,2,"Ingresa una opcion");
    return op;
}

int menu()
{
	int op;
	int i = 0, j;
	
	do
	{
		system("CLS");
		op = msges();
		
		switch(op)
		{
			case 1:
				system("CLS");
				Agrega_U();
				system("PAUSE");
				break;
			case 2:
				system("CLS");
				Imprime_U();
				system("PAUSE");
				break;
		}
	} while (op != 0);
	
}

void Gen_U()
{
	FILE *arch;
	arch = fopen("registros.dat", "rb");
	if(arch == NULL)
	{
		arch = fopen("registros.dat", "wb");
	}
	else
	{
		exit;
	}
	fclose(arch);
}

void Agrega_U()
{
	system("CLS");
	
	FILE *arch;
	arch = fopen("registros.dat", "ab");
	if(arch == NULL)
	{
		exit(1);
	}
	
	Tusuario reg;
	char caracter, cont[30];
	int cnt=0, i, j=0;
	
	for(i = 0; i < 28; i++)
	{
		reg.nombre[i] = 0;
		reg.nombre[i+1] = '\0';
		reg.cont[i] = 0;
		reg.cont[i+1] = '\0';
		reg.usuario[i] = 0;
		reg.usuario[i+1] = '\0';
	}
	
	reg.status = 1;
	printf("\nNombre:\n");
	fflush(stdin);
	gets(reg.nombre);
	
	printf("\nUsuario:\n");
	fflush(stdin);
	gets(reg.usuario);
	
	reg.cont_nv = vali_num(1, 3, "\nSelecciona el nivel de contrsaña: | 1.- Bajo | 2.- Medio | 3.-Alto\n");
	
	switch(reg.cont_nv)
	{
		case 1:
			while(cnt != 1)
			{
				printf("\nContraseña:\n");
				while(caracter = getch())
				{
					if(caracter == 13)
					{
						cont[j] = '\0';
						break;
					}
					else
					{
						printf("*");
						cont[j] = caracter;
						j++;
					}
				}
		
				cnt = vali_Cont1(cont, 8, 300);	
			}
			strcpy(reg.cont, cont);
			break;
		case 2:
			while(cnt != 1)
			{
				printf("\nContraseña:\n");
				while(caracter = getch())
				{
					if(caracter == 13)
					{
						cont[j] = '\0';
						break;
					}
					else
					{
						printf("*");
						cont[j] = caracter;
						j++;
					}
				}
				
				cnt = vali_Cont2(cont, 10, 300);
			}
			strcpy(reg.cont, cont);
			break;
		case 3:
			while(cnt != 1)
			{
				printf("\nContraseña:\n");
				while(caracter = getch())
				{
					if(caracter == 13)
					{
						cont[j] = '\0';
						break;
					}
					else
					{
						printf("*");
						cont[j] = caracter;
						j++;
					}
				}
				
				cnt = vali_Cont3(cont, 12, 300);
			}
			strcpy(reg.cont, cont);
			break;	
	}
	fwrite(&reg, sizeof(Tusuario), 1, arch);
	fclose(arch);
	printf("\nRegistro Completo\n");
	system("PAUSE");
	system("CLS");
}

void Imprime_U()
{
	system("CLS");
	
	FILE *arch;
	arch = fopen("registros.dat", "rb");
	if(arch == NULL)
	{
		exit(1);
	}
	
	Tusuario reg;
	
	fread(&reg, sizeof(Tusuario), 1, arch);
	while(!feof(arch))
	{
		printf("Status: %d\n", reg.status);
		printf("Nombre: %s\n", reg.nombre);
		printf("Usuario: %s\n", reg.usuario);
		printf("Contraseña: %s\n", reg.cont);
		printf("Nivel Contraseña: %d\n\n", reg.cont_nv);
		
		fread(&reg, sizeof(Tusuario), 1, arch);
	}
	fclose(arch);
	system("PAUSE");	
}