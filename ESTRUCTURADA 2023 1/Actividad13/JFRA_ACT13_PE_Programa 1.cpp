#include "Rojapez.h"

typedef struct _tdato
{
	int status;
	int matriz;
	char nombre[30];
	char appaterno[30];
	char apmaterno[30];
	int edad;
	char sexo;
}Tdato;

Tdato add_auto(Tdato reg);
Tdato add_manual(Tdato reg, int j);

void impreg(Tdato reg);
int menu();
void opcion();
int buscar(Tdato vec[], int tam, int id);
void eliminar(Tdato vec[], int tam, int id, Tdato reg);
void crear_tex(Tdato vect[], int tam, char nombre[]);
void crear_bin(Tdato vect[], int tam, char nombre[]);
void nomtex(char nombre[], int tam);
void nombin(char nombre[], int tam);
void imparch();
void ordenar(Tdato vect[], int tam);
void editar(Tdato vect[], int tam, int id);

int main()
{
	opcion();
	return 0;
}

Tdato add_auto(Tdato reg)
{
	
	int i, n, x;
	char nombres[][30] = {"Josue","Francisco","Blanca","Brisa","Fernanda","Abraham","Daniel","Jessica","Estela","Maria","Allison"};
	char appaterno[][30] = {"Bustamante","Trujillo","Ybarra","Robins","Wilson","Grey","Shepherd","Herrera"};
	char apmaterno[][30] = {"Rojas","Aripez","Rojapez","BaÃ±uelos","Escamilla","Beristain","Leyva"};
	
	reg.status = 1;
	reg.matriz = (rand()%4001) + 1000;
	n = rand()%8;
	strcpy(reg.nombre, nombres[n]);
	strcpy(reg.appaterno, appaterno[n]);
	strcpy(reg.apmaterno, apmaterno[n]);
	reg.edad = (rand()%30) + 18;
	x = rand()%2;
	if (x == 0)
	{
		reg.sexo = 'H';
	}
	else
	{
		reg.sexo = 'M';
	}
	return reg;
}

Tdato add_manual(Tdato reg, int j)
{
	int x;
	
	reg.status = 1;
	printf("\nNombre: ");
	fflush(stdin);
	gets(reg.nombre);
	system("CLS");
	printf("\nApellido Paterno: ");
	fflush(stdin);
	gets(reg.appaterno);
	system("CLS");
	printf("\nApellido Materno: ");
	fflush(stdin);
	gets(reg.apmaterno);
	system("CLS");
	reg.edad = vali_num(18, 61, "\nEdad: ");
	system("CLS");
	x = vali_num(1, 2, "\n| 1.- Hombre | 2.- Mujer |: ");
	if (x == 1)
	{
		reg.sexo = 'H';
	}
	else
	{
		reg.sexo = 'M';
	}
	
	system("CLS");
	reg.matriz = vali_num(1000, 5000, "Matricula: ");
	system("CLS");
	return reg;
}

int buscar(Tdato vec[], int tam, int id)
{
	int i, j;
	printf("%5s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\n","No.Registro","Matricula","Nombre","Ap Paterno","Ap Materno","Edad","Sexo");
	
	for(i = 0; i < tam; i++)
	{
		if(vec[i].matriz == id)
		{
			system("CLS");

			printf("%5d\t%8s\t%8s\t%8s\t%8d\t%8c\n",vec[i].matriz,vec[i].nombre,vec[i].appaterno,vec[i].apmaterno,vec[i].edad,vec[i].sexo);
			system("pause");
			return i;
		}
	}
	printf("Matricula inexsistente\n");
	j = -1;
	return j;
	
}

void ordenar(Tdato vect[], int tam)
{
	int i, j, aux;
	
	for(i = 0; i < tam; i++)
	{
		for(j = 0; j < tam-1; j++)
		{
		
			if(vect[j].matriz > vect[j+1].matriz)
			{			
				aux = vect[j].matriz;
				vect[j].matriz = vect[j+1].matriz;
				vect[j+1].matriz = aux;
			}
		}
	}
}

void eliminar(Tdato vec[], int tam, int id, Tdato reg)
{
	int x, lugar;
	lugar = buscar(vec, tam, id);
	x = vali_num(1, 2,"\n¿Eliminar Registro? | 1.- SI | 2.- NO | ");
	if(x == 1)
	{
		vec[lugar].status = 0;
		printf("Registro eliminado");
	}
	else
	{
		printf("No se elimino el registro");
	}
}
void impreg(Tdato vect[], int tam)
{
	int i=0;
	printf("%5s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\n","No.Registro","Matricula","Nombre","Ap Paterno","Ap Materno","Edad","Sexo");
	
	for(i = 0; i < tam; i++)
	{
		if(vect[i].status == 1)
		{

			
			printf("%5d\t%8s\t%8s\t%8s\t%8d\t%8c\n",vect[i].matriz,vect[i].nombre,vect[i].appaterno,vect[i].apmaterno,vect[i].edad,vect[i].sexo);
		}
	}
}

int menu()
{
	printf ("-----------------MENU-----------------\n");
    printf("1.- Agregar\n");
    printf("2.- Editar Registro\n");
    printf("3.- Eliminar Registro\n");
    printf("4.- Buscar\n");
    printf("5.- Ordenar\n");
    printf("6.- Imprimir\n");
    printf("7.- Generar Archivo de Texto\n");
    printf("8.- Ver Archivo de Texto\n");
    printf("9.- Crear Archivo Binario\n");
    printf("10.- Cargar Archivo Binario\n");
    printf("0.- Salir\n\n");
}

void crear_tex(Tdato vect[], int tam, char nombre[])
{
	int i, j=0;
	
	FILE *arch;
	arch=fopen(nombre, "rb");
	if(arch == NULL)
	{
		arch=fopen(nombre, "wb");
	}
	else
	{
		printf("Ya existe un archivo con este nombre\n");
	}
	fclose(arch);

	
	arch=fopen(nombre, "ab");
	if(arch == NULL)
	{
		exit(1);
	}
	
	Tdato vector2[tam];
	
	for(i = 0; i < tam; i++)
	{
		vector2[i].status = vect[i].status;
		vector2[i].matriz = vect[i].matriz;
		strcpy(vector2[i].nombre, vect[i].nombre);
		strcpy(vector2[i].appaterno, vect[i].appaterno);
		strcpy(vector2[i].apmaterno, vect[i].apmaterno);
		vector2[i].edad = vect[i].edad;
		vector2[i].sexo = vect[i].sexo;
		fwrite(&vector2[i], sizeof(Tdato), 1, arch);
	}
	fclose(arch);
	
}


void crear_bin(Tdato vect[], int tam, char nombre[])
{
	int i, j=0;
	
	FILE *arch;
	arch=fopen(nombre, "rb");
	if(arch == NULL)
	{
		arch=fopen(nombre, "wb");
	}
	else
	{
		printf("Ya existe un archivo con este nombre\n");
	}
	fclose(arch);

	
	arch=fopen(nombre, "ab");
	if(arch == NULL)
	{
		exit(1);
	}
	
	Tdato vector2[tam];
	
	for(i = 0; i < tam; i++)
	{
		vector2[i].status = vect[i].status;
		vector2[i].matriz = vect[i].matriz;
		strcpy(vector2[i].nombre, vect[i].nombre);
		strcpy(vector2[i].appaterno, vect[i].appaterno);
		strcpy(vector2[i].apmaterno, vect[i].apmaterno);
		vector2[i].edad = vect[i].edad;
		vector2[i].sexo = vect[i].sexo;
		fwrite(&vector2[i], sizeof(Tdato), 1, arch);
	}
	fclose(arch);
	
}

void imparch(char nombre[])
{
	system("CLS");
	
	FILE *arch;
	arch=fopen(nombre, "rb");
	if(arch == NULL)
	{
		printf("No existe un archivo de texto\n");
	}
	
	Tdato reg;
	printf("%5s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\n","No.Registro","Matricula","Nombre","Ap Paterno","Ap Materno","Edad","Sexo");
	fread(&reg, sizeof(Tdato), 1, arch);
	while(!feof(arch))
	{

		
		printf("%5d\t%8d\t%8s\t%8s\t%8s\t%8d\t%8c\n",reg.status,reg.matriz,reg.nombre,reg.apmaterno,reg.appaterno,reg.edad,reg.sexo);
		
		fread(&reg, sizeof(Tdato), 1, arch);
	}
	fclose(arch);
	printf("Presione enter para continuar\n");
	system("pause");	
}

void opcion()
{
	Tdato reg, vect[2500];
	char nombre_txt[50], nombre_bin[50];
	int op = 3, i, j=0, id;
	menu();
	
	while(op != 0)
	{
		system("CLS");
		menu();
		op = vali_num(0, 10, "Eliga una opcion ");
		
		switch(op)
		{
			case 1:
				printf("Se agregaron 100 registros\n");
				for(i = 0; i < 100; i++)
				{
					reg = add_auto(reg);
					vect[j] = reg;
					j++;
				}
				system("pause");
				break;
				
			case 2:
				id = vali_num(1000, 5000, "Matricula: ");
				editar(vect, j, id);
				break;
				
			case 3:
				id = vali_num(1000, 5000, "Matricula:");
				eliminar(vect, j, id, reg);
				j--;
				system("pause");
				break;
				
			case 4:
				id = vali_num(1000, 5000, "Matricula: ");
				buscar(vect, j, id);
				break;
			case 5:
				ordenar(vect, j);
				printf("Ordenado\n");
				system("pause");
				break;
				
			case 6:
				system("CLS");
				impreg(vect, j);
				system("pause");
				break;
				
			case 7:
				nomtex(nombre_txt, 50);
				crear_tex(vect, j, nombre_txt);
				system("pause");
				break;
			case 8:
				imparch(nombre_txt);
				break;
			case 9:
				nombin(nombre_bin, 50);
				crear_bin(vect, j, nombre_bin);
				system("pause");
				break;
			case 10:
				imparch(nombre_bin);
				break;
			case 0:
				
				op = 0;
				break;
		}
	} 
}

void nomtex(char nombre[], int tam)
{
	int i, j=0;
	printf("Dame el nombre que quieres para el archivo de texto: ");
	fflush(stdin);
	gets(nombre);
	
	for(i = 0; i < tam; i++)
	{
		if(isalpha(nombre[i]) || isdigit(nombre[i]))
		{
			
		}
		else
		{
			while(j != 2)
			{
				nombre[i] = '.';
				nombre[i+1] = 't';
				nombre[i+2] = 'x';
				nombre[i+3] = 't';
				nombre[i+4] = '\0';
				j = 2;
			}
		}
	}
}

void nombin(char nombre[], int tam)
{
	int i, j=0;
	printf("Dame el nombre que quieres para el archivo de texto: ");
	fflush(stdin);
	gets(nombre);
	
	for(i = 0; i < 50; i++)
	{
		if(isalpha(nombre[i]) || isdigit(nombre[i]))
		{
			
		}
		else
		{
			while(j != 2)
			{
				nombre[i] = '.';
				nombre[i+1] = 'd';
				nombre[i+2] = 'a';
				nombre[i+3] = 't';
				nombre[i+4] = '\0';
				j = 2;
			}
		}
	}
}

void editar(Tdato vect[], int tam, int id)
{
	int x, op, lugar, i, edad;
	char nombre[30];
	char appaterno[30], apmaterno[30];
	char sexo;
	
	lugar = buscar(vect, tam, id);
	if(lugar == -1)
	{
		system("pause");
	}
	else
	{
		while(op != 0)
		{
		
	
			printf("\n1.- Status\n2.- Matricula\n3.- Nombre\n4.- Apellido paterno\n5.- Apellido materno\n6.- Edad\n7.- Sexo\n8.- Ninguno\n ");
			op = vali_num(1, 8, "Eliga campo a editar: ");
	
			switch(op)
			{
				case 1:
					system("CLS");
					printf("\n1.- Si\n2.- No");
					x = vali_num(1, 2, "\nDesactivar registro?: ");
					if(x == 1)
					{
						vect[lugar].status = 0;
						printf("\nRegistro desactivado\n");
						system("pause");
						break;
					}
					else
					{
						break;
					}
				case 2:
					system("CLS");
					printf("\n1.- Si\n2.- No");
					x = vali_num(1, 2, "\nCambiar matricula?: ");
					if(x == 1)
					{
						x = vali_num(1000, 5000, "Escribe la nueva matricula: ");
						for(i = 0; i < tam; i++)
						{
							if(x == vect[i].matriz)
							{
								printf("\nLa matricula ya existe, intenta de nuevo\n");
								break;
							}
							else
							{
								vect[i].matriz = x;
								printf("Matricula cambiada\n");
								system("pause");
								break;
							}
						}
						break;
					}
				case 3:
					system("CLS");
					printf("\n1.- Si\n2.- No");
					x = vali_num(1, 2, "\nCambiar nombre?: ");
					if(x == 1)
					{
						printf("Escribe el nuevo nombre: \n");
						fflush(stdin);
						gets(nombre);
						strcpy(vect[lugar].nombre, nombre);
						printf("\nNombre cambiado\n");
						system("pause");
						break;
					}
					else
					{
						break;
					}	
				case 4:
					system("CLS");
					printf("\n1.- Si\n2.- No");
					x = vali_num(1, 2, "\nCambiar Ap.Paterno?: ");
					if(x == 1)
					{
						printf("Escribe el nuevo apellido: \n");
						fflush(stdin);
						gets(appaterno);
						strcpy(vect[lugar].appaterno, appaterno);
						printf("\nApellido cambiado\n");
						system("pause");
						break;
					}
					else
					{
						break;
					}
				case 5:
					system("CLS");
					printf("\n1.- Si\n2.- No");
					x = vali_num(1, 2, "\nCambiar Ap.Materno?: ");
					if(x == 1)
					{
						printf("Escribe el nuevo apellido: \n");
						fflush(stdin);
						gets(appaterno);
						strcpy(vect[lugar].apmaterno, apmaterno);
						printf("\nApellido cambiado\n");
						system("pause");
						break;
					}
					else
					{
						break;
					}
				case 6:
					system("CLS");
					printf("\n1.- Si\n2.- No");
					x = vali_num(1, 2, "\nCambiar matricula?: ");
					if(x == 1)
					{
						edad = vali_num(18, 61, "\nEscribe la nueva edad: ");
						vect[lugar].edad = edad;
						printf("Matricula cambiada\n");
						system("pause");
						break;
					}
					else
					{
						break;
					}
				case 7:
					system("CLS");
					printf("\n1.- Si\n2.- No");
					x = vali_num(1, 2, "\nCambiar Sexo?: ");
					if(x == 1)
					{
						if(vect[lugar].sexo == 'H')
						{
							vect[lugar].sexo = 'M';
						}
						else
						{
							vect[lugar].sexo = 'H';
						}
						printf("\nSexo cambiado\n");
						system("pause");
						break;
					}
					else
					{
						break;
					}
				case 8:
					op = 0;
					break;
			}
		}
	}
}