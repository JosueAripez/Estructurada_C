#include <stdio.h>

void ordenar(int a, int b, int c) 
{
   int min, med, max;
   
   if (a < b && a < c) 
   {
      min = a;
      if (b < c) 
      {
         med = b;
         max = c;
      }
      else 
      {
         med = c;
         max = b;
      }
   }
   else
   {
      if (b < a && b < c)
      {
         min = b;
         if (a < c) 
         {
            med = a;
            max = c;
         }
         else 
         {
            med = c;
            max = a;
         }
      }
      else
      {
         min = c;
         if (a < b) 
         {
            med = a;
            max = b;
         }
         else 
         {
            med = b;
            max = a;
         }
      }
   }
   
}

void main() 
{
    int min, med, max;

    printf("Ingresa el primer numero: ");
    scanf("%d", &min);
    printf("Ingresa el segundo numero: ");
    scanf("%d", &med);
    printf("Ingresa el tercer numero: ");
    scanf("%d", &max);
    
    
    
    printf("Los numeros ordenados son: %d, %d, %d\n", min, med, max);

}
