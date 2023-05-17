#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rojapez.h"

#define N 100

typedef struct _alumno
{
	char Estatus;
	char Nombre_s[30];
	char Usuario[30];
	char Contrasena[30];
    
} Tsalumno;

int msges();
void menu();

Tsalumno Registro_Manual();
void Imprime_Registro(Tsalumno v[],int n);
int Bienvenida();


int main()
{
	srand(time(NULL));
	Bienvenida();	
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
    op = Vali_Num(0,2,"Ingresa una opcion","Opcion invalida");
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
           	  	printf("Agregando....\n");
				printf("\n¿Cuantos registros desea generar?\n");
				scanf("%d",&num);
				  
				if(i < N-num)
				{
					for(j = 0;j < num;j++,i++)
				 	{
						vect[i] = Registro_Manual();
					}
				}
				system("\nPAUSE\n");
              	break;
              
            case 2:
				system("CLS");
              	printf("Imprimiendo....\n");
				Imprime_Registro(vect,i);
				system("PAUSE");
              	break;
        }

    }while (op != 0);
}

int Bienvenida()
{

    int usuario, cont;

    printf("\nIngresa Tu Usuario (72)\n"),
    scanf("%d",&usuario);
    printf("\nIngrsa tu contrsaeña (123)\n");
    scanf("%d",&cont);

    if(usuario == 72 && cont == 123)
    {
        menu();
    }
    else
    {
        printf("\nUsuario o Contraseña incorrecta\n");
    }
}

Tsalumno Registro_Manual()
{
	Tsalumno reg;
    int Estat, nivel;
	char Nombre_s[20], Usuario[20], Contrasena[20], Estatus, Sexo;
	system("CLS");
	fflush(stdin);
	printf("2.- Agregar Manual\n");
	printf("Creando registro manualmente\n");
	Vali_Cadena(reg.Nombre_s,"\nNombre (s): ");
	fflush(stdin);
	system("CLS");
	Vali_Cadena(reg.Usuario,"Usuario: ");
	fflush(stdin);
	system("CLS");
	Vali_Cadena(reg.Contrasena,"Contraseña: ");
   /* printf("Selecciona el nivel de contrsaña: | 1.- Bajo | 2.- Medio | 3.-Alto");
   scanf("%d",&nivel);
     switch (nivel)
        {
           	case 1:
                printf("Imgresa")
              	break;
            case 2:
                reg.Estatus = "I";
              	break;
            case 3:
                reg.Estatus = "B";
                break;
            default:
            printf("Opcipon no valida");
            
                
        }
    */
	system("CLS");
	Estat = Vali_Num(1,3,"Selecciona tu Estatus | 1.- Activo | 2.- Inactivo o dado de Baja | 3.- Bloqueado ","Opcion invalida");
	system("CLS");

    switch (Estat)
        {
           	case 1:
                reg.Estatus = "A";
              	break;
            case 2:
                reg.Estatus = "I";
              	break;
            case 3:
                reg.Estatus = "B";
                break;
            default:
            printf("Opcipon no valida");
            
                
        }
	return reg;
}

void Imprime_Registro(Tsalumno v[],int n)
{
	int i;
	system("CLS");
    printf("%8s\t%8s\t%8s\t%8s\t","Estatus","Nombre (s)","Usuario","Contraeña\t");
	for(i=0;i < n;i++)
	{
	   	if (v[i].Estatus == 'A')
	   	{
            printf("%8s\t%8s\t%8s\t%8s\n",v[i].Estatus,v[i].Nombre_s,v[i].Usuario,v[i].Contrasena);
		}
	}
}