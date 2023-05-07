#include <stdio.h>

int main() 
{
    float precio, subtotal, iva, total;
    int cantidad;

    printf("Ingresa el precio del producto: ");
    scanf("%f", &precio);
   
    printf("Ingresa la cantidad a comprar: ");
    scanf("%d", &cantidad);

    subtotal = precio * cantidad;
    iva = subtotal * 0.16;
    total = subtotal + iva;

    printf("El subtotal es %.2f\n", subtotal);
    printf("El IVA (16%%): %.2f\n", iva);
    printf("El total es: %.2f\n", total);

    return 0;
}
