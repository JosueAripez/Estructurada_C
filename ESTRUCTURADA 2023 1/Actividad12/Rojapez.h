#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define ENCONTRADO 1
#define NOENCONTRADO 0
#define ESP 32
#define ENTER 13
#define ESC 27

bool ValidTxt(char *cadena)
{
    int i = 0;
    bool status = false;

	do
	{
	   	if (isalpha(cadena[i]) || cadena[i]=='_' || cadena[i]=='-' || isdigit(cadena[i]))
	   	{
	   		cadena[i] == cadena [i];
	   		status = false;
	   		i++;
		}
		else
		{
			printf("Los nombres de archivos .txt solamente aceptan caracteres alfanum%cricos y guiones.\n\n",130);
			status = true;
		}
	}while(cadena[i]!='\0' && status == false);

	return status;
}

int Val_Int(int ri,int rf,char msge[],char msgeError[])
{
	int num;
	char xnum[30];
	
	do
	{
		puts(msge);
		fflush(stdin);
		gets(xnum);
		num = atoi(xnum);
		
		if(num < ri || num > rf)
		{
			printf("%s",msgeError);
			printf("\n");
		}
	}while(num < ri || num > rf);
	
	return num;
}

long Val_Long(long ri,long rf,char msge[],char msgeError[])
{
	long num;
	char xnum[30];
	
	do
	{
		puts(msge);
		fflush(stdin);
		gets(xnum);
		num = atoi(xnum);
		
		if(num < ri || num > rf)
		{
			printf("%s",msgeError);
			printf("\n");
		}
	}while(num < ri || num > rf);
	
	return num;
}

void Val_Cadena(char * cadena,char msge[])
{
	int i=0;
	char ola;
	puts(msge);
	do
	{
		ola = getc(stdin);
		if((ola>='a' && ola<='z') || (ola>='A' && ola<='Z' || ola == ' '))
		{
			if (cadena[i-1] == ' ' && ola == ' ')
		  	{
			}
			else
			{
				if (ola == ' ' && i == 0)
				{
				}
				else
				{
					cadena[i] = ola;
		  			i++;
				}
			}
		}
	}while (ola!='\n');
	
	if (cadena[i-1] == ' ')
	{
	   	cadena[i-1] = '\0';
	}
	cadena [i] = '\0';
}

int busqSecOrd(int v[],int n,int num)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		if(v[n] <= num)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
	
	return -1;
}

int busqSec(int v[],int n,int num)
{
	int i;
	
	for(i = 0;i < n;i++)
	{
		if(num == v[i])
		{
			return i;
		}
	}
	
	return -1;
}

void OrdVec(int vect[],int tam)
{
	int i, temp, j = 0;
    
    for (i = 0; i <= tam; i++)
    {
    	for (j = 0; j <= tam; j++)
		{
			if (vect[i] < vect[j])
			{
				temp = vect[i];
				vect[i] = vect[j];
				vect[j] = temp;	
			}	
		}	
	}
}

void Mayus(char * cadena)
{
	int i;
	
	for(i = 0;cadena[i] != '\0';i++)
	{
	   	if (cadena[i] >= 'a' && cadena[i] <= 'z')
	   	{
	   		cadena[i] -= 32;
		}
	}
}

void Espacios(char * cadena)
{
	int i;

    for(i = 0;cadena[i] != '\0';i++)
    {
       	if(cadena[i] != ' ')
       	{
       	    printf("%c",cadena[i]);
		}
	}
}

int check (int n, int vect[], int tama)
{
	int i;
	for (i=0; i<=tama; i++)
	{
		if (n==vect[i])
		{
			return 1;
		}
	}
	return 0;
}

/*----------------------------------------------------------------------------------------------------                                                                            
                                                                                           
          JJJJJJJJJJJ                                                                      
          J:::::::::J                                                                      
          J:::::::::J                                                                      
          JJ:::::::JJ                                                                      
            J:::::J   ooooooooooo       ssssssssss   uuuuuu    uuuuuu      eeeeeeeeeeee    
            J:::::J oo:::::::::::oo   ss::::::::::s  u::::u    u::::u    ee::::::::::::ee  
            J:::::Jo:::::::::::::::oss:::::::::::::s u::::u    u::::u   e::::::eeeee:::::ee
            J:::::jo:::::ooooo:::::os::::::ssss:::::su::::u    u::::u  e::::::e     e:::::e
            J:::::Jo::::o     o::::o s:::::s  ssssss u::::u    u::::u  e:::::::eeeee::::::e
JJJJJJJ     J:::::Jo::::o     o::::o   s::::::s      u::::u    u::::u  e:::::::::::::::::e 
J:::::J     J:::::Jo::::o     o::::o      s::::::s   u::::u    u::::u  e::::::eeeeeeeeeee  
J::::::J   J::::::Jo::::o     o::::ossssss   s:::::s u:::::uuuu:::::u  e:::::::e           
J:::::::JJJ:::::::Jo:::::ooooo:::::os:::::ssss::::::su:::::::::::::::uue::::::::e          
 JJ:::::::::::::JJ o:::::::::::::::os::::::::::::::s  u:::::::::::::::u e::::::::eeeeeeee  
   JJ:::::::::JJ    oo:::::::::::oo  s:::::::::::ss    uu::::::::uu:::u  ee:::::::::::::e  
     JJJJJJJJJ        ooooooooooo     sssssssssss        uuuuuuuu  uuuu    eeeeeeeeeeeeee  

/---------------------------------------------------------------------------------------------------*/