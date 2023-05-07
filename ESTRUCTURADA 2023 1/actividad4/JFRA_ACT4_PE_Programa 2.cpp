#include <stdio.h>

int main() 
{
    int opcion;
    float medida;

    printf("Ingresa la medida que quiere convertir: ");
    scanf("%f ", &medida);

    printf("Seleccione una opcion: 1)cm a pulgadas 2)cm a pies 3) km a millas 4)pulgadas a cm 5)pies a cm 6)millas a km ");
    scanf("%d ", &opcion);

    switch (opcion) 
    {
        case 1:
            printf("%.2f cm = %.2f pulgadas", medida, medida / 2.54);
            break;
       
        case 2:
            printf("%.2f cm = %.2f pies", medida, medida / 30.48);
            break;
        
        case 3:
            printf("%.2f Km = %.2f millas", medida, medida / 1.609);
            break;
        
        case 4:
            printf("%.2f pulgadas = %.2f cm", medida, medida * 2.54);
            break;
       
        case 5:
            printf("%.2f pies = %.2f cm", medida, medida * 30.48);
            break;
       
        case 6:
            printf("%.2f millas = %.2f Km", medida, medida * 1.609);
            break;
       
        default:
            printf("Error");
            break;
    }

    return 0;
}
