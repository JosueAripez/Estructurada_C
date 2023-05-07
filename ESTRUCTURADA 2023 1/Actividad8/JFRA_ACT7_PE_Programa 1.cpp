#include <stdio.h>
#include <stdlib.h>
#define N10
void vector3();
void vector2();




int main()
{
   menu();

	return 0;
}

int msges()
{ int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1)Llenar el Vector 1 (Manualmete) ");
  printf("2)Llenar el vector 2 Aleatoriamnete");
  printf("3)Imprimir vectores ");
  printf("4)Llena matriz 4 X 4 ");
  printf("5)Imprimir matriz ");
  printf("0)Salir ");
  printf("Escoge una opcion" );
  scanf("%d", &op);

  return op;
}

void menu()
{
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
              vector1();
              break;
        case 2:
              vector2();
              break;
        case 3:
              
              break;
        case 4:

              break;
        case 5:
              
              break;
        case 6:
              
              break;

      }

    }while (op != 0);
}

void vector1()
{

  int vector [10];

  int vector [10];
  int tam, i, j;

  for ( i = 0; i < tam; i++)
  {
    for ( j = 0; j < tam; j++)
    {
      /* code */
    }
    
  }

}

void add_vectSR(int v[], int m, int ri, int rf)
{

  int i, rango, j, band;

  rango = (rf- ri)+1;

  if (rango >= m)
  {
    for (i = 0; i < m; i++)
    {
      do
      {
        num = (rand()%)
      } while (band == true);
      
    }
    
  }
  
}