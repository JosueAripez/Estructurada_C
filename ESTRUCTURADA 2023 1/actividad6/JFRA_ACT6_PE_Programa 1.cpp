#include <stdio.h>
#include <stdlib.h>


int msges();
void menu();
void Fibonacci (void);
void Factorial (void);
void Digitos (void);

int main()
{
   menu();

	return 0;
}

int msges()
{ int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- FIBONACCI \n");
  printf("2.- FACTORIAL \n");
  printf("3.- DIGITOS \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
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
              Fibonacci();
              break;
        case 2:
              Factorial();
              break;
        case 3:
              Digitos();
              break;
      }
    }while (op != 0);
}

void Fibonacci (void)
{
    int num, i, anterior=0, actual=1, siguiente; 
    
    system ("CLS");
    
    printf("Ingresa la cantidad de terminos que quieres calcular: ");
    scanf("%d", &num);

    printf("Serie de fibonacci:\n");

    for (i = 0; i < num; i++) 
    {
        printf("%d ", anterior);
        siguiente = anterior + actual;
        anterior = actual;
        actual = siguiente;
    }
   
    printf("   FIBONACCI\n"); 
    system ("PAUSE");
}

void Factorial (void)
{
    int n, i;
    float factorial = 1; 
    
    system ("CLS");

     printf("Ingresa un numero que sea entero y positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: el numero ingresado es negativo\n");
    }
    else
    {
        for (i = 1; i <= n; ++i)
        {
            factorial *= i;
        }

        printf("El factorial de %d es %f\n", n, factorial);
    }

    printf("   FACTORIAL\n"); 
    system ("PAUSE");
}

void Digitos (void)
{
    int num, digitos = 0;

    system ("CLS");

     printf("Ingresa un numero: ");
    scanf("%d", &num);
    
    while(num != 0)
    {
        digitos++;
        num /= 10;
    }
    
    printf("El numero ingresado tiene %d digitos.\n", digitos);

    printf("   DIGITOS\n"); 
    system ("PAUSE");

}