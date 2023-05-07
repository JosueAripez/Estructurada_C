#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
#define FALSE 0
#define TRUE 1

int msges();
void menu();
void Salida_1(void);
void Mayus(char * cadena);
void Salida_2(void);
void Minus(char * cadena);
void Salida_3(void);
void Capital(char * cadena);
void Salida_4(void);
int Num_Carac(char * cadena);
void Salida_5(void);
void Inversa(char cadena[]);
void Salida_6(void);
void Espacios(char * cadena);
void Salida_7(void);
void Valid_Cad(char * cadena);
void Salida_8(void);
void Salida_9(void);
void Palindromo(char * cadena);
void Valid_Num(void);

int main()
{
  menu();
  
  return 0;
}

int msges()
{
  int op;
  system("CLS");
  printf ("          M E N U\n");
    printf("\n1)Mayusculas\n");
    printf("2)Minusculas\n");
    printf("3)Generar $Capital$\n");
    printf("4)Cantidad de caracteres de la cadena\n");
    printf("5)Al reves\n");
    printf("6)Sin espacios\n");
    printf("7)Solo letras\n");
    printf("8)Combo de cadena\n");
    printf("9)Palindromo\n");
    printf("10)Salir\n");
    printf("\nEliga una opcion: ");
    scanf ("%d",&op);
    return op;
}

void menu()
{
  int op;
    do{
      
      op=msges();
        switch (op)
        {
            case 1:
                Salida_1();
            break;
        
        case 2:
                Salida_2();
            break;
        
        case 3:
                Salida_3();
            break;
              
            case 4:
                Salida_4();
            break;
              
            case 5:
                Salida_5();
            break;
              
            case 6:
                Salida_6();
            break;
              
            case 7:
                Salida_7();
            break;
              
            case 8:
                Salida_8();
            break;
              
            case 9:
                Salida_9();
            break;
        }
  }while (op != 10);
}

void Salida_1(void)
{
  char cad[N];
    system ("CLS");
    fflush (stdin);
    printf("\nEscriba una cadena: ");
    gets(cad);
    Mayus(cad);
    printf("\n%s\n",cad);
    system ("PAUSE");
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

void Salida_2(void)
{
  char cad[N]; 
    system ("CLS");
    fflush (stdin);
  printf("\nEscriba una cadena: ");
    gets(cad);
    Minus(cad);
    printf("\n%s\n",cad);
    system ("PAUSE");
}

void Minus(char * cadena)
{
  int i;
  
  for(i = 0;cadena[i] != '\0';i++)
  {
    if (cadena[i] >= 'A' && cadena[i] <= 'Z')
    {
      cadena[i] += 32;
    }
  }
}

void Salida_3(void)
{
  int i;
    char cad[N];
    system ("CLS");
    fflush (stdin);
  printf("\nEscriba una cadena: ");
    gets(cad);
    printf("\n");
    Capital(cad);
    printf("%s\n\n",cad);
    system ("PAUSE");
}

void Capital(char * cadena)
{
  int i;

  if (cadena[0] >= 'a' && cadena[0] <= 'z')
  {
    cadena[i] -= 32;
  }

  for(i = 1;cadena[i] != '\0';i++)
  {
    if (cadena[i] >= 'A' && cadena[i] <= 'Z')
    {
      cadena[i] += 32;
    }
  }
}

void Salida_4(void)
{
  int i,n;
    char cad[N];
    system ("CLS");
    fflush (stdin);
  printf("\nEscriba una cadena: ");
    gets(cad);
    n = Num_Carac(cad);
    printf("\nLa cadena tiene %d caracteres\n\n",n);
    system ("PAUSE");
}

int Num_Carac(char * cadena)
{
  int i;
    
    for(i = 0;cadena[i] != '\0';i++)
    {
  }
    return i;
}

void Salida_5(void)
{
  int i,j;
    char cad[N];
    system ("CLS");
    fflush (stdin);
  printf("\nEscriba una cadena: ");
    gets(cad); 
    Inversa(cad);
    printf("\n");
    puts(cad);
    printf("\n");
    system ("PAUSE");
}

void Inversa(char cadena[])
{
  int i;
  int longi = strlen(cadena);
    
    for (i = 0; i < strlen(cadena) / 2; i++)
    {
        char temp = cadena[i];
        cadena[i] = cadena[longi - i - 1];
        cadena[longi - i - 1] = temp;
    }
}


void Salida_6(void)
{
  int i,j;
    char cad[N];
    system ("CLS");
    fflush (stdin);
  printf("\nEscriba una cadena: ");
    gets(cad);
    printf("\n");
  Espacios(cad);
  printf("\n\n");
    system ("PAUSE");
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

void Salida_7(void)
{
  int i,j;
    char cad[N]; 
    system ("CLS");
    Valid_Cad(cad);
    printf("%s.\n",cad);
  printf("\n");
    system ("PAUSE");
}

void Valid_Cad(char * cadena)
{
  int i=0;
  char fn;
  fflush (stdin);
  printf("\nEscriba una cadena: ");
  do
  {
    
    fn = getc(stdin);
    if((fn>='a' && fn<='z') || (fn>='A' && fn<='Z' || fn == ' '))
    {
      if (cadena[i-1] == ' ' && fn == ' ')
      {
      }
      else
      {
        if (fn == ' ' && i == 0)
        {
        }
        else
        {
          cadena[i] = fn;
          i++;
        }
      }
    }
  } while (fn!='\n');
  
  if (cadena[i-1] == ' ')
     {
      cadena[i-1] = '\0';
     }
  cadena [i] = '\0';
}

void Salida_8(void)
{
  int i,j;
    char cad[N];
    system ("CLS");
    fflush (stdin);
  printf("\nEscriba una cadena: ");
    gets(cad);
    
    Mayus(cad);
    printf("Mayusculas: %s\n", cad);
    
    Minus(cad);
    printf("Minusculas: %s\n", cad);
    
    Capital(cad);
    printf("$Capital$: %s\n", cad);
    
    printf("Sin espacios: ");
    Espacios(cad);
    
    Inversa(cad);
    printf("\nInvertida: %s\n", cad);
    system ("PAUSE");
}

void Salida_9(void)
{
  int i;
    char cad[N];
    system ("CLS");
  fflush (stdin);
    Valid_Cad(cad);
    Mayus(cad);
    printf("\nPalabra ingresada:  %s",cad);
    Palindromo(cad);
  printf("\n");
    system ("PAUSE");
}

void Palindromo(char * cadena)
{
  int i,j,num,band;
    char cad_cop[N];  
  num = Num_Carac(cadena);
  
  for(i = 0,j = 0,band = TRUE;i < num/2 && band == TRUE;i++,j++)
  {
    if (cadena[i] == ' ')
    {
      i++;
    }
    if (cadena[num-j-1] == ' ')
    {
      j++;
    }
    if (cadena[i] == cadena [num-j-1])
    {
      band = TRUE;
    }
    else
    {
      band = FALSE;
    }
  }
  if (band == TRUE)
  {
    printf("\nSi es un palindromo.\n");
  }
  else
  {
    printf("\nNo es un palindromo.\n");
  }
    
}