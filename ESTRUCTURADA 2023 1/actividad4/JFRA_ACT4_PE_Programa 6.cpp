#include<stdio.h>

main()
{
    float consumo, metrosEx, subtotal, iva, total;
    
    printf("Ingresa la cantidad de metros de agua que consumiste: ");
    scanf("%f ",&consumo);
    
    if(consumo > 4)
    {
        if(consumo > 15)
        {
            if(consumo > 50)
            {
                metrosEx = consumo - 50;
                subtotal = 50 + (11 * 8) + (35 * 10) + (metrosEx * 11);
            }
            else
            {
                metrosEx = consumo - 15;
                subtotal = 50 + (11 * 8) + (metrosEx * 10);
            }
        }
        else
        {
            metrosEx = consumo - 4;
            subtotal = 50 + (metrosEx * 8);
        }
    }
    else
    {
        subtotal = 50;
    }
   
    iva = subtotal * 0.16;
    total = subtotal + iva;
    
    printf("Subtotal: $%.2f\n", subtotal);
    printf("IVA (16%): $%.2f\n", iva);
    printf("Total: $%.2f\n", total);

    return 0;
}