#include <stdio.h>

int numero_del_medio(int a, int b, int c) {
    if ((a >= b && b >= c) || (c >= b && b >= a)) 
    {
        return b;
    } 
    else
    {
        if (((b >= a && a >= c) || (c >= a && a >= b)))
        {
            return a;
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
    printf("Ingresa el segundo numero: ");
    scanf("%d", &num2);
    printf("Ingresa el tercer numero: ");
    scanf("%d", &num3);
    
    int medio = numero_del_medio(num1, num2, num3);
    
    printf("El numero del medio es: %d\n", medio);
    
    return 0;

}
