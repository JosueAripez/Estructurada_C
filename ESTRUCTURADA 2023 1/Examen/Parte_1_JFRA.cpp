#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Rojapez.h"

typedef struct _tdatos
{
	int status;
	char nombre[30];
	char usuario[30];
	char cont[30];
	int nivel;

}Tdato;

int Bienvenida();

int main()
{
	int exit = 3;
	
	while(exit != 1)
	{
		exit = Bienvenida();
	}

	return 0;
}

int Bienvenida()
{
	FILE *arch;
	arch = fopen("registros.dat", "rb");
	if(arch == NULL)
	{
		exit(1);
	}
	
	char caracter, usuario[30], cont[30];
	int j=0, i=0, var0=5, var02=5;
	Tdato reg;
	
	for(i = 0; i < 29; i++)
	{
		reg.cont[i] = 0;
		reg.cont[i+1] = '\0';
		reg.usuario[i] = 0;
		reg.usuario[i+1] = '\0';
	}
	
	printf("Iniciando Sesion....\n");
	printf("Usuario: ");
	fflush(stdin);
	gets(usuario);
	
	fread(&reg, sizeof(Tdato), 1, arch);
	while(!feof(arch))
	{
		
		var0 = strcmp(usuario, reg.usuario);
		
		if(var0 == 0)
		{
			printf("contseña: ");
			fflush(stdin);
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
			
			var02 = strcmp(cont, reg.cont);
			if(var02 == 0)
			{
				printf("\nBienvenido %s", reg.nombre);
				break;
			}
			else
			{
				printf("\nLa contseña ingresada es incorrecta\n");
				system("pause");
				return 0;
			}	
		}
		else
		{
			fread(&reg, sizeof(Tdato), 1, arch);
		}
	}
	fclose(arch);
	return 1;
}