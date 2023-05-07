#include <stdio.h>

int main()
{
    float largo, ancho, costo, area, alambre;

    printf("Ingresa el largo del terreno: ");
    scanf("%f",&largo);

    printf("Ingresa el ancho del terreno: ");
    scanf("%f",&ancho);

    printf("Ingresa el costo de metro cuadrado del pasto: ");
    scanf("%f",&costo);

    area = largo * ancho;
    alambre = 2 * (largo + ancho);

    printf("El costo para sembarar el pasto es de: $%.2f", area * costo);
    printf("Se ocupan %.2f metros de alambre para poder cercar el terreno.", alambre);

    return 0;
}
