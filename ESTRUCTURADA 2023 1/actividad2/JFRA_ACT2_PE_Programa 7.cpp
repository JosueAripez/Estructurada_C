#include <stdio.h>
#include <math.h>

int main()
{
   
    double a, b, c;
    
    printf("Ingresa la longitud del cateto a");
    scanf("%lf",&a);
    
    printf("Ingresa la longitud del cateto b");
    scanf("%lf",&b);
    
    c = sqrt (a*a + b*b);
   
    printf("La longitud de la hipotenusa es: %.2lf\n", c);
    
    return 0;

}
