#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <ctime>
#include <time.h>

int vali_Num(int ri, int rf, char msge[])
{
    int num_Valido=0, band, tam=0,i=0;
    char num[30];
    
    do{
        band = false;
        printf("%s",msge);
        fflush(stdin);
        gets(num);
        tam = strlen(num);
        
        for(i=0;i<tam;i++)
        {
            if(!(isdigit(num[i])))
            {
                band = true;
                printf("Ingresa Numeros Enteros\n");
                break;
            }
        }

        if(band == false)
        {
            num_Valido = atoi(num);
            if(num_Valido<ri or num_Valido>rf)
            {
                printf("Fuera del Rango\n");
                band = true;
            }
        }
    }while(band);

    return num_Valido;
}

char* vali_NumSC(char num[], int ri, int rf, char msge[])
{
    int num_Valido=0, band, tam=0,i=0;
    
    do{
        band = false;
        printf("%s",msge);
        fflush(stdin);
        gets(num);
        tam = strlen(num);
        
        for(i=0;i<tam;i++)
        {
            if(!(isdigit(num[i])))
            {
                band = true;
                printf("Ingresa Numeros Enteros\n");
                break;
            }
        }

        if(band == false)
        {
            num_Valido = atoi(num);
            if(num_Valido<ri or num_Valido>rf)
            {
                printf("Fuera del Rango\n");
                band = true;
            }
        }
    }while(band);

    return num;
}

char* vali_Cadena(char cadena[], char msge[])
{
    int band, tam=0, i;
    char cambiar=165, cambiar2=164;
    do{
        band = false;
        printf("%s", msge);
        fflush(stdin);
        gets(cadena);
        tam = strlen(cadena);
        
        for(i=0;i<tam;i++)
        {
            if(isdigit(cadena[i]))
			{
				printf("Error\n",cadena[i]);
				band = true;
			}

            if(ispunct(cadena[i]))
            {
                printf("Error\n",cadena[i]);
                band = true;
            }

            if(isspace(cadena[i]))
			{
				if(isspace(cadena[i+1]))
				{
					printf("Ingresate Doble espacio\n");
                    band = true;
				}
			}

            if(isspace(cadena[0]))
            {
                printf("Error\n");
                band = true;
                break;
            }

            if (cadena[i] == cambiar or cadena[i] == cambiar2 )
			{
                cadena[i] = 'X';
			}
		}
    }while(band);
    strupr(cadena);
    return cadena;
}

int vali_Espacios(char cadena[])
{
    int tam, i, indice=0;
    tam = strlen(cadena);

    for(i=0;i<tam;i++)
    {
        if(isspace(cadena[i]))
        {
            if(i < (tam-1))
            {
                indice = i+1;
            }
        }
    }
    return indice;
}
