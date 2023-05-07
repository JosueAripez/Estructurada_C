#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  
    int jugador, computadora;
    
   
    srand(time(0)); 
    computadora = rand() % 3 + 1;
    
    
    printf("Selecciona una opcion:\n");
    printf("1. Piedra\n");
    printf("2. Papel\n");
    printf("3. Tijera\n");
    scanf("%d", &jugador);
    
   
    switch (jugador) 
    {
        case 1: 
            printf("Jugador: Piedra\n");
            switch (computadora) 
           
            {
                case 1:
                    printf("Computadora: Piedra\nEmpate\n");
                    break;
                case 2:
                    printf("Computadora: Papel\nComputadora gana\n");
                    break;
                case 3:
                    printf("Computadora: Tijera\nJugador gana\n");
                    break;
            }
            break;
        case 2: 
           
            printf("Jugador: Papel\n");
            switch (computadora) 
            
            {
                case 1:
                    printf("Computadora: Piedra\nJugador gana\n");
                    break;
                case 2:
                    printf("Computadora: Papel\nEmpate\n");
                    break;
                case 3:
                    printf("Computadora: Tijera\nComputadora gana\n");
                    break;
            }
            break;
        case 3: 
            printf("Jugador: Tijera\n");
            switch (computadora) 

            {
                case 1:
                    printf("Computadora: Piedra\nComputadora gana\n");
                    break;
                case 2:
                    printf("Computadora: Papel\nJugador gana\n");
                    break;
                case 3:
                    printf("Computadora: Tijera\nEmpate\n");
                    break;
            }
            break;
        default:
            printf("Opcion invalida\n");
    }
    
    return 0;
}
