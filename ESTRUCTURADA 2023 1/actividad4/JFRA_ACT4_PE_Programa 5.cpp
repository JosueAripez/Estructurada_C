#include <stdio.h>

int main() 
{

    int minutos, tipoLlamada;
    float subtotal, total, iva;

    
    printf("Ingresa los minutos de la llamada: ");
    scanf("%d ", &minutos);

    printf("Seleccione el tipo de llamada:\n");
    printf("1)Llamada Local\n");
    printf("2)Llamada Nacional\n");
    printf("3)Llamada Internacional\n");
    scanf("%d ", &tipoLlamada);

    
    switch (tipoLlamada) 
    {
        case 1: subtotal = 3.00; break;
        
        case 2:
            if (minutos <= 3) 
            {
                subtotal = 7.00;
            } 
            else 
            {
                subtotal = 7.00 + 2.00 * (minutos - 3);
            }
            break;
       
        case 3:
            if (minutos <= 2) 
            {
                subtotal = 9.00;
            } 
            else 
            {
                subtotal = 9.00 + 4.00 * (minutos - 2);
            }
            break;
       
        default: printf("Error\n");
    }

    
    iva = 0.16 * subtotal;
    total = subtotal + iva;

    
    printf("Subtotal: $%.2f\n", subtotal);
    printf("IVA (16%%): $%.2f\n", iva);
    printf("Total: $%.2f\n", total);

    return 0;
}
