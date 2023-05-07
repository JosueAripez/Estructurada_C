#include <stdio.h>

int max(int a, int b, int c) 
{
    if (a > b && a > c) 
    {
        return a;
    } 
    else
    {
        if (b > a && b > c)
        {
         return b;
        }
        else
        {
            return c;
        }
    }

}

int main() 
{
    int num1, num2, num3;
   
    printf("Ingresa el primer numero: ");
    scanf("%d", &num1);
    printf("Ingresa el segunfo numero: ");
    scanf("%d", &num2);
    printf("Ingresa el tercer numero: ");
    scanf("%d", &num3);
    
    printf("El numero mayor es: %d\n", max(num1, num2, num3));
    
    return 0;
}



