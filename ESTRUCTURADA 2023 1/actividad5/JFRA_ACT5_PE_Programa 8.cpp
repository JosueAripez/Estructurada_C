#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float uno() 
{
    int nums[40];
    int i, even_count = 0, odd_count = 0, even_sum = 0, odd_sum = 0;
    srand(time(NULL));
    
    printf("Los números aleatorios son: ");
    for (i = 0; i < 40; i++) 
    {
        nums[i] = rand() % 201;
        printf("%d ", nums[i]);
        
        if (nums[i] % 2 == 0) 
        { 
            even_count++;
            even_sum += nums[i];
            printf("(par) ");
        } 
        else 
        { 
            odd_count++;
            odd_sum += nums[i];
            printf("(impar) ");
        }
    }
    
   
    printf("\nHay %d numeros pares con una suma de: %d\n ", even_count, even_sum);
    printf("Hay %d numeros impares con una suma de: %d\n ", odd_count, odd_sum);

}

float dos() 
{
    int i, num, mayor, menor;
    srand(time(NULL)); 

    num = rand() % 101 + 100;
    mayor = menor = num;
    printf("%d ", num);

    for(i = 1; i < 35; i++) {
        num = rand() % 101 + 100;
        printf("%d ", num);
        if(num > mayor) mayor = num;
        if(num < menor) menor = num;
    }  

    printf("\nEl numero mayor es: %d", mayor);
    printf("\nEl numero menor es: %d", menor);
}

int main(int argc, char const *argv[])
{
    printf("%f ", uno());
    printf("%f ", dos());
}