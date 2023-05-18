#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

int vali_num(int ri, int rf, char msg[])
{
	int num;
	char letra[20];
	
	do
	{
		printf("%s", msg);
		fflush(stdin);
		gets(letra);
		num = atoi(letra);
		
		if(num < ri || num > rf)
		{
			printf("Error (%d a %d)", ri, rf);
			system("pause");
		}
	}
	while(num < ri || num > rf);
	return num;
}

int vali_Cont1(char conts[], int ri, int rf)
{
	int cnt;
	
	cnt = strlen(conts);

	if(cnt < ri)
	{
		system("CLS");
		printf("Minimo %d caracteres\n", ri);
		return 0;
	}
	else
	{
		if(cnt > rf)
		{
			system("CLS");
			printf("Maximo %d caracteres\n", rf);
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

int vali_Cont2(char conts[], int ri, int rf)
{
	int cnt, i, digito, minimo;
	
	cnt = strlen(conts);

	if(cnt < ri)
	{
		system("CLS");
		printf("Minimo %d caracteres\n", ri);
		return 0;
	}
	else
	{
		if(cnt > rf)
		{
			system("CLS");
			printf("Maximo %d caracteres\n", rf);
			return 0;
		}
		else
		{
			minimo = 1;
		}
	}
	
	for(i = 0; i < cnt; i++)
	{
		if(isdigit(conts[i]))
		{
			digito = 1;
			break;
		}
		else
		{
			digito = 0;
		}
	}
	
	if(digito == 1 && minimo == 1)
	{
		return 1;
	}
	else
	{
		printf("Minimo 1 digito\n");
		return 0;
	}
}

int vali_Cont3(char conts[], int ri, int rf)
{
	int cnt, i, digito, minimo, especial, mayus;
	
	cnt = strlen(conts);

	if(cnt < ri)
	{
		system("CLS");
		printf("Minimo %d caracteres\n", ri);
		return 0;
	}
	else
	{
		if(cnt > rf)
		{
			system("CLS");
			printf("Maximo %d caracteres\n", rf);
			return 0;
		}
		else
		{
			minimo = 1;
		}
	}
	
	for(i = 0; i < cnt; i++)
	{
		if(isdigit(conts[i]))
		{
			digito = 1;
			break;
		}
		else
		{
			digito = 0;
		}
	}
	
	for(i = 0; i < cnt; i++)
	{
		if(conts[i] == '-' || conts[i] == '_' || conts[i] == '&' || conts[i] == '#')
		{
			especial = 1;
			break;
		}
		else
		{
			especial = 0;
		}
	}
	
	for(i = 0; i < cnt; i++)
	{
		if(isupper(conts[i]))
		{
			mayus = 1;
			break;
		}
		else
		{
			mayus = 0;
		}
	}
	if(digito == 1 && minimo == 1 && especial == 1 && mayus == 1)
	{
		return 1;
	}
	else
	{
		if(digito == 0)
		{
			printf("Minimo 1 digito\n");
		}
		if(especial == 0)
		{
			printf("Minimo 1 caracter especial (- _ & #)\n");
		}
		if(mayus == 0)
		{
			printf("Minimo 1 letra mayuscula\n");
		}
		return 0;
	}
}


long vali_long(long ri,long rf,char msge[],char msgeError[])
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

void vali_cadena(char * cadena,char msge[])
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
	} while (ola!='\n');
	
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

void ordVec(int vect[],int tam)
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

void vali_espacios(char * cadena)
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
