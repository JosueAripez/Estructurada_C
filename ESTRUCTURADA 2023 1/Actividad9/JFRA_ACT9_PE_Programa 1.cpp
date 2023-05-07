#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Rojapez.h"

# define N 15
# define M 4

int msges();
void menu();
void llena_Vector(int vec[],int ri, int rf);
void llena_Matriz(int matriz[M][M], int ri, int rf);
void imprime_Vector(int vec[]);
void imprime_Matriz(int matriz[][M]);
void burbuja(int vec[]);
void buscar(int vec[]);
int busqueda_Sec(int vec[], int num);

int main()
{
   menu();

	return 0;
}

int msges()
{ 
  int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- Llenar Vector\n"); 
  printf("2.- Llenar Matriz\n");
  printf("3.- Imprimir Vector\n");
  printf("4.- Imprimir Matriz\n");
  printf("5.- Ordenar Vector\n");
  printf("6.- Buscar Valor En Vector\n");
  printf("0.- Salir\n");
  printf("Elige Una Opcion: ");
  scanf ("%d",&op);
  return op;
}

void menu()
{
    int op; 
	int llenado_V = false; 
	int llenado_M = false;
    int vec[N];
    int matriz[M][M];
    
    do{
        op=msges();
        switch (op)
        {
        case 1:
            llena_Vector(vec, 100, 200);
            llenado_V = true;
            break;
        case 2:
            llena_Matriz(matriz, 1, 16);
            llenado_M = true;
            break;
        case 3:
            imprime_Vector(vec);
            break;
        case 4:
            imprime_Matriz(matriz);
            break;
        case 5:
            burbuja(vec);
            break;
        case 6:
            buscar(vec);
            break;
        }
    system ("PAUSE");
    }while (op != 0);
}

void llena_Vector(int vec[],int ri, int rf)
{
    int  i, j, band, num, rango;
    rango = (rf-ri)+1;
    if(rango >= N)
    {
        for(i=0; i<N; i++)
        {
            do{
                num = (rand()%rango) + ri;
                j = 0;
                band = false;
                while(j<i and band == false)
                {
                    if(num == vec[j])
                    {
                        band = true;
                    }
                    j += 1;
                }
            }while(band == true);
            vec[i] = num;
        }
        printf("El vector esta lleno\n");
    }
   
}

void llena_Matriz(int matriz[M][M], int ri, int rf)
{
    int  i, j, num=0, rango;
int usar[M*M]={0};
    rango = (rf-ri)+1;
    srand(time(0));
    for(i=0;i<M;i++)
    {
        for(j=0; j<M; j++)
        {
            do{
                num = rand()%rango + 1;
            }while(usar[num-1]);
           
		    usar[num-1] = 1;
            matriz[i][j] = num;
        }
    }
    printf("La matriz esta llena\n");
}

void imprime_Vector(int vec[])
{
    int i;
    for(i=0; i<N; i++)
    {
        printf("%2d : [%4d]\n",i,vec[i]);
    }
}

void imprime_Matriz(int matriz[][M])
{
    int i, j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<M; j++)
        {
            printf("[%3d]",matriz[i][j]);
        }
        printf("\n");
    }
}

void burbuja(int vec[])
{
    int i,j;
    int b;

    for(i=0; i<N-1; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(vec[j] < vec[i])
            {
                b = vec[j];
                vec[j] = vec[i];
                vec[i] = b;
            }
        }
    }
    printf("Vector ordenado.\n");
}

void buscar(int vec[])
{
    int pos, num;
    char msge[50]=("Ingresa el numero que quieres bucar: ");
    num = vali_num(100,200,"Ingresa numero a buscar ");
    pos = busqueda_Sec(vec, num);

    if(pos != -1)
    {
        printf("El numero %d se encontro en el indice %d \n",num,pos);
    }
    else
    {
        printf("El numero %d no se encontro\n",num);
    }
    
}

int busqueda_Sec(int vec[], int num)
{
    int i;
    for(i=0; i<N; i++)
    {
       
        if(num == vec[i])
        {
            return i;
        }
    }
    return -1;
}
