#include <stdio.h>

int main()
{
    int edad, meses, dias;

    printf("Ingresa tu edad en años: ");
    scanf("%d", &edad);

    meses = edad * 12;
    dias = edad * 365;

    printf("Tu edad en meses es: %d\n", meses);
    printf("Tu edad en dias es: %d\n", dias);

    return 0;
}
