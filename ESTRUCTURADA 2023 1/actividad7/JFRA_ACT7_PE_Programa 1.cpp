#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 50

int msges();
void menu();
void Salida_1(void);
void Salida_2(void);
void Salida_3(void);
void Salida_4(void);
void Salida_5(void);
void Salida_6(void);
void Salida_7(void);
void Salida_8(void);
void Salida_9(void);
void Salida_10(void);

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
    printf("\n1)Salida de cadena\n");
    printf("2)Salida al reves\n");
    printf("3)Salida en vertical\n");
    printf("4)Salida en vertical al reves \n");
    printf("5)Salida en cascada\n");
    printf("6)Salida en cascada al reves\n");
    printf("7)Salida en cascada 2\n");
    printf("8)Salida en cascada 2 al reves\n");
    printf("9)Salida de consonates\n");
    printf("10)Salida de vocales\n");
    printf("11)Salir\n");
    printf("\nEliga una opcion: ");
    
  scanf ("%d",&op);
    
  return op;
}

void menu()
{
  int op;
    do
  {
    op = msges();
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
              
            case 10:
                Salida_10();
            break;
        } 
  }while (op != 11);
    
}

void Salida_1(void)
{
  char cad[N];
    system ("CLS");
    printf("\nEscriba una palabra: ");
    scanf("%s",cad);
    puts(cad);
    system ("PAUSE");
}

void Salida_2(void)
{
  char cad[N]; 
    system ("CLS");
    printf("\nEscriba una palabra: ");
    scanf("%s",cad);
    strrev(cad);
    puts(cad);
    system ("PAUSE");
}

void Salida_3(void)
{
  int i;
    char cad[N];
    system ("CLS");
    printf("\nEscriba una palabra: ");
    scanf("%s",cad);
    printf("\n");
    
    for(i = 0; i < strlen(cad); i++)
    {
      printf("%c\n",cad[i]);
  }
    system ("PAUSE");
}

void Salida_4(void)
{
  int i;
    char cad[N];
    system ("CLS");
    printf("\nEscriba una palabra: ");
    scanf("%s",cad);
    strrev(cad);
    
    for(i = 0;i < strlen(cad);i++)
    {
      printf("%c \n",cad[i]);
  }
    system ("PAUSE");
}

void Salida_5(void)
{
  int i,j;
    char cad[N];
    system ("CLS");
    printf("\nEscriba una palabra: ");
    scanf("%s",cad);
    
    for(i = strlen(cad);i > 0;i--)
    {
    printf("\n");
    
    for(j = 0;j < i;j++)
    {
        printf("%c",cad[j]);
    }
      
  }
  
  printf("\n");
    system ("PAUSE");
}

void Salida_6(void)
{
  int i,j;
    char cad[N];
    system ("CLS");
    printf("\nEscriba una palabra: ");
    scanf("%s",cad);
    strrev(cad);
    
  for(i = strlen(cad);i > 0;i--)
    {
    printf("\n");
    
    for(j = 0;j < i;j++)
    {
      printf("%c",cad[j]);
    }   
  }
  
  printf("\n");
    system ("PAUSE");
}

void Salida_7(void)
{
  int i,j;
    char cad[N]; 
    system ("CLS");
    printf("\nEscriba una palabra: ");
    scanf("%s",cad);  
    strrev(cad);
    
  for(i = strlen(cad);i > 0;i--)
    {
    printf("\n");
    
    for(j = i;j >= 0;j--)
    {
      printf("%c",cad[j-1]);
    }
  }
  
  printf("\n");
    system ("PAUSE");
}

void Salida_8(void)
{
  int i,j;
    char cad[N];
    system ("CLS");
    printf("\nEscriba una palabra: ");
    scanf("%s",cad);
    
    for(i = strlen(cad);i > 0;i--)
    {
    printf("\n");
    
    for(j=i;j>=0;j--)
    {
      printf("%c",cad[j-1]);
    }
  }
  
  printf("\n");
    system ("PAUSE");
}

void Salida_9(void)
{
  int i;
    char cad[N];
    system ("CLS");
    printf("\nEscriba una palabra: ");
    scanf("%s",cad);
    
    for (i = 0;i < strlen(cad);i++)
    {
        if (cad[i] =='a' || cad[i] =='e' || cad[i] =='i' || cad[i] =='o' || cad[i] =='u')
        {
          continue;
    }
    if (cad[i] =='A' || cad[i] =='E' || cad[i] =='I' || cad[i] =='O' || cad[i] =='U')
        {
          continue;
    }
    printf("%c",cad[i]);
  }
  
  printf("\n");
    system ("PAUSE");
}

void Salida_10(void)
{
  int i;
    char cad[N];
    system ("CLS");
    printf("\nEscriba una palabra: ");
    scanf("%s",cad);
    
    for (i = 0;i < strlen(cad);i++)
    {
        if (cad[i] =='a' || cad[i] =='e' || cad[i] =='i' || cad[i] =='o' || cad[i] =='u')
        {
          printf("%c",cad[i]);
    }
    if (cad[i] =='A' || cad[i] =='E' || cad[i] =='I' || cad[i] =='O' || cad[i] =='U')
        {
          printf("%c",cad[i]);
    }
  }
  
  printf("\n");
    system ("PAUSE");
}

