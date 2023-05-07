#include <stdio.h>

int main() 
{

    int opcion, num1, num2;
    float resultado;
   
   printf("Ingresa un numero ");
   scanf("%d ", &num1);
   printf("Ingresa un numero ");
   scanf("%d ", &num2);

   printf("Selecciona una opcion 1)Suma 2)Resta 3)Multiplicacion 4)Division\n");
   scanf("%d ", &opcion);

    switch(opcion) 
    {
        case 1:
            resultado = num1 + num2;
            printf("\nLa suma de %d y %d es %.2f\n", num1, num2, resultado);
            break;
       
        case 2:
            resultado = num1 - num2;
            printf("\nLa resta de %d y %d es %.2f\n", num1, num2, resultado);
            break;
       
        case 3:
            resultado = num1 * num2;
            printf("\nLa multiplicacion de %d y %d es %.2f\n", num1, num2, resultado);
            break;
        
        case 4:
           
            if(num2 == 0) 
            {
                printf("\nNo se puede dividir entre cero\n");
            } 
            else 
            {
                resultado = (float) num1 / num2;
                printf("\nLa division de %d entre %d es %.2f\n", num1, num2, resultado);
            }
            
            break;
        
        default:
            printf("\nIntente de nuevo\n");
    }

    return 0;
}
