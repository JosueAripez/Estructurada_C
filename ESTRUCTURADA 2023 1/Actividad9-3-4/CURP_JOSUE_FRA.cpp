#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <ctime>
#include <time.h>
#include "Rojapez.h"

void Datos_CURP();
int Entidad_Federativa();
int Nombre_D(char Nombre[]);
int Palabras_Inco(char Blq_uno[]);
int Consonates(char cadena[], int indice);
void Bloque_Uno(char Apellido_Paterno[], char Apellido_Materno[], char Nombre[]);
void Bloque_Dos(char Jahr[], char Mes[], char Dia[]);
void Bloque_Tres(int Sexo);
void Bloque_Cuatro(int Ef);
void Bloque_Cinco(char Apellido_Paterno[], char Apellido_Materno[], char Nombre[]);
void Bloque_Seis(int Jahr2);
void Bloque_Random();

main()
{	
	system("CLS");
    int op;
    char msge[]={": "};
    do{
        system("CLS");
        Datos_CURP();
        
        printf("\n�Quieres consultar otro CURP?\n");
        printf("Ingresa una opcion, 1.- Si | 2.-No ");
        op = vali_Num(1,2,msge);
    }while(op == 1);

    return 0;
}

void Datos_CURP()
{
    char Nombre[50], Nombre2[50], Apellido_Paterno[20], Apellido_Materno[20];
    char msge[10]={": "};
    int Mes2, Jahr2, Sexo, Ef, entrar=0;
    char Jahr[5], Mes[5], Dia[5];

    system ("\nCLS");
	printf("Bienvenido a la Consulta del CURP. Ingresa los Datos_CURP que se le pidan\n");
	printf("\n");
	system("PAUSE");
	system("CLS");
       
	printf("Nombre");
    vali_Cadena(Nombre, msge);
    system("CLS");
    printf("Segundo Nombre");
    vali_Cadena(Nombre2, msge);
    system("CLS");
    printf("Apellido Paterno");
    vali_Cadena(Apellido_Paterno, msge);
    system("CLS");
    
    printf("�Cuenta con segundo Apellido?\n");
    printf("Ingresa una opcion, 1.- Si | 2.-No ");
    entrar = vali_Num(1,2,msge);
    if(entrar == 1)
    {
        printf("\nApellido Materno");
        vali_Cadena(Apellido_Materno, msge);
    }
    else
    {
        Apellido_Materno[0] = 'X';
        Apellido_Materno[1] = '\0';
    }
	system("CLS");
    
    printf("Dia de Nacimiento (DD)");
    if((Mes2<=7 and Mes2 %2!= 0) and (Mes2>=8 and Mes2 %2 == 0))
    {
        vali_NumSC(Dia, 1, 31, msge);
    }
    else
    {
    	if(Mes2 == 2)
        {
            if(Jahr2%4 == 0)
            {
                vali_NumSC(Dia, 1, 29, msge);
            }
            else
            {
                vali_NumSC(Dia, 1, 28, msge);
            }   
        }
        else
        {
            if(Mes2==1 or Mes2==12)
            {
                vali_NumSC(Dia, 1, 31, msge);
            }
            else
            {
                vali_NumSC(Dia, 1, 30, msge);
            }
        }
    }
    system("CLS");
    printf("Mes de Nacimiento (MM)");
    vali_NumSC(Mes, 1, 12, msge);
    Mes2 = atoi(Mes);
	system("CLS");
    printf("A�o de Nacimiento (AAAA)");
    vali_NumSC(Jahr, 1900, 2023, msge);
    Jahr2 = atoi(Jahr);
	system("CLS");
    
	printf("Selecciona tu Sexo, 1.- Hombre | 2.-Mujer:\n");
    printf("Ingresa el numero segun tu Sexo");
    Sexo = vali_Num(1,2,msge);
    system("CLS");
    
    printf("\nEstado de Nacimiento.\n");
    Ef = Entidad_Federativa();
    system("CLS");

    entrar = Nombre_D(Nombre);
	printf("\nSu CURP: ");
	
    if(entrar == 1)
    {
        Bloque_Uno(Apellido_Paterno, Apellido_Materno, Nombre2);
    }
    else
    {
        Bloque_Uno(Apellido_Paterno, Apellido_Materno, Nombre);
    }
    Bloque_Dos(Jahr, Mes, Dia);
    Bloque_Tres(Sexo);
    Bloque_Cuatro(Ef);
    if(entrar == 1)
    {
        Bloque_Cinco(Apellido_Paterno, Apellido_Materno, Nombre2);
    }
    else
    {
        Bloque_Cinco(Apellido_Paterno, Apellido_Materno, Nombre);
    }
    Bloque_Seis(Jahr2);
    Bloque_Random();
	printf("\n");
	printf("\n");
    system("PAUSE");
    system("CLS");
}

int Nombre_D(char Nombre[])
{
    char no_Usar[][6] ={"MARIA", "MA", "JOSE", "JO"};
    int x, i=0, band=0;

    do{
        x = strcmpi(Nombre, no_Usar[i]);
        if(x == 0)
        {
            band = 1;
        }
        i += 1;
    }while(i<=4 and band==0);

    return band;
}

int Palabras_Inco(char Blq_uno[])
{
    char Palabrotas[][5]={"BACA","BAKA","BUEI","BUEY","CACA","CACO","CAGA","CAGO","CAKA","CAKO","COGE","COGI","COJA","COJE","COJI","COJO","COLA","CULO","FALO","FETO","GETA","GUEI","GUEY","JETA","JOTO","KACA","KACO","KAGA","KAGO","KAKA","KAKO","KOGE","KOGI","KOJA","KOJE","KOJI","KOJO","KOLA","KULO","LILO","LOCA","LOCO","LOKA","LOKO","MAME","MAMO","MEAR","MEAS","MEON","MIAR","MIAR","MION","MOCO","MOKO","MULA","MULO","NACA","NACO","PEDA","PEDO","PENE","PIPI","PITO","POPO","PUTA","PUTO","QULO","RATA","ROBA","ROBE","ROBO","RUIN","SENO","TETA","VACA","VAGA","VAGO","VAKA","VUEI","VUEY","WUEI","WUEY"};
    int x, i=0, band=0;

    do{
        x = strcmpi(Blq_uno, Palabrotas[i]);
        if(x == 0)
        {
            band = 1;
        }
        i += 1;
    }while(i<=82 and band==0);

    return band;
}

void Bloque_Uno(char Apellido_Paterno[], char Apellido_Materno[], char Nombre[])
{
    char Blq_uno[5], vocales[7] = {"AEIOU"};
    int i, tam, band=0, vocal=0, indice=0;
    tam = strlen(Apellido_Paterno);

    indice = vali_Espacios(Apellido_Paterno);
    Blq_uno[0] = Apellido_Paterno[indice];

    for(i = indice; i < tam; i++) 
    {
        if(strchr(vocales, Apellido_Paterno[i])) 
        {
            if(i > 0)
            {
                vocal = 1;
                Blq_uno[1] = Apellido_Paterno[i] ;
                break;
            }
        }
    }
    if(vocal == 0)
    {
        Blq_uno[1] = 'X';
    }
    
    indice = vali_Espacios(Apellido_Materno);
    Blq_uno[2] = Apellido_Materno[indice];

    indice = vali_Espacios(Nombre);
    Blq_uno[3] = Nombre[indice];

    band = Palabras_Inco(Blq_uno);
    if(band == 1)
    {
        Blq_uno[1] = 'X';
        
    }
    Blq_uno[4] = '\0';

    printf("%s",Blq_uno);
}

void Bloque_Dos(char Jahr[], char Mes[], char Dia[])
{
    char Blq_Dos[7];
    int tam=0;

    Blq_Dos[0] = Jahr[2];
    Blq_Dos[1] = Jahr[3];

    tam = strlen(Mes);
    if(tam==2)
    {
        Blq_Dos[2] = Mes[0];
        Blq_Dos[3] = Mes[1];
    }
    else
    {
        Blq_Dos[2] = '0';
        Blq_Dos[3] = Mes[0];
    }

    tam = strlen(Dia);
    if(tam==2)
    {
        Blq_Dos[4] = Dia[0];
        Blq_Dos[5] = Dia[1];
    }
    else
    {
        Blq_Dos[4] = '0';
        Blq_Dos[5] = Dia[0];
    }
    Blq_Dos[6] = '\0';
    
    printf("%s",Blq_Dos);
}

void Bloque_Tres(int Sexo)
{
    char Blq_Tres[2];
    
    if(Sexo == 1)
    {
        Blq_Tres[0] = 'H';
    }
    else
    {
        Blq_Tres[0] = 'M';
    }
    Blq_Tres[1] = '\0';

    printf("%s",Blq_Tres);
}

int Entidad_Federativa()
{
    int op;
    char msge[]={"Ingresa el Numero del Estado Donde Naciste: "};
	printf("\n----- Ingresa el Numero del Estado Donde Naciste: -----\n");
    printf("1.-AGUASCALIENTES [AS]\t\t");
    printf("2.-BAJA CALIFORNIA [BC]\t\t");
    printf("3.-BAJA CALIFORNIA SUR [BS]\n");
    printf("4.-CAMPECHE [CC]\t\t");
    printf("5.-COAHUILA [CL]\t\t");
    printf("6.-COLIMA [C]M\n");
    printf("7.-CHIAPAS [CS]\t\t");
    printf("8.-CHIHUAHUA [CH]\t\t");
    printf("9.-DISTRITO FEDERAL [DF]\n");
    printf("10.-DURANGO [DG]\t\t");
	printf("11.-GUANAJUATO [GT]\t\t");
    printf("12.-GUERRERO [GR]\n");
    printf("13.-HIDALGO [HG]\t\t");
    printf("14.-JALISCO [JC]\t\t");
    printf("15.-MEXICO [MC]\n");
    printf("16.-MICHOACAN [MN]\t\t");
    printf("17.-MORELOS [MS]\t\t");
    printf("18.-NAYARIT [NT]\n");
    printf("19.-NUEVO LEON [NL]\t\t");
    printf("20.-OAXACA [OC]\t\t");
    printf("21.-PUEBLA [PL]\n");
    printf("22.-QUERETARO [QT]\t\t");
    printf("23.-QUINTANA ROO [QR]\t\t");
    printf("24.-SAN LUIS POTOSI [SP]\n");
    printf("25.-SINALOA [SL]\t\t");
    printf("26.-SONORA [SR]\t\t");
    printf("27.-TABASCO [TC]\n");
    printf("28.-TAMAULIPAS [TS]\t\t");
    printf("29.-TLAXCALA [TC]\t\t");
    printf("30.-VERACRUZ [VZ]\n");
    printf("31.-YUCATAN [YN]\t\t");
    printf("32.-ZACATECAS [ZS]\t\t");
    printf("33.-NACIDO EN EL EXTRANJERO [NE]\n");
	printf("\n");
	
    op = vali_Num(1, 33, msge);

    return op;
}

void Bloque_Cuatro(int op)
{
    char Blq_Cuatro[][33]={"AS","BC","BS","CC","CL","CM","CS","CH","DF","DG","GT","GR","HG","JC","MC","MN","MS","NT","NL","OC","PL","QT","QR","SP","SL","SR","TC","TS","TL","VZ","YN","ZS","NE"};

    printf("%s", Blq_Cuatro[(op-1)]);
}

int Consonates(char cadena[], int indice)
{
    int i=0, tam, indice2=-1, con=0;
    tam = strlen(cadena);

    indice += 1;
    for(i = indice; i < tam; i++)
    {
        if(isalpha(cadena[i]) && !con && !strchr("AEIOU", cadena[i]))
        {
            indice2 = i;
            con = 1;
        }
    }

    return indice2;
}

void Bloque_Cinco(char Apellido_Paterno[], char Apellido_Materno[], char Nombre[])
{
    int indice=0, index=0;
    char Blq_Cinco[3];

    indice = vali_Espacios(Apellido_Paterno);
    index = Consonates(Apellido_Paterno, indice);
    if(index == -1)
    {
        Blq_Cinco[0] = 'X';
    }
    else
    {
        Blq_Cinco[0] = Apellido_Paterno[index];
    }

    indice = vali_Espacios(Apellido_Materno);
    index = Consonates(Apellido_Materno, indice);
    if(index == -1)
    {
        Blq_Cinco[1] = 'X';
    }
    else
    {
        Blq_Cinco[1] = Apellido_Materno[index];
    }

    indice = vali_Espacios(Nombre);
    index = Consonates(Nombre, indice);
    if(index == -1)
    {
        Blq_Cinco[2] = 'X';
    }
    else
    {
        Blq_Cinco[2] = Nombre[index];
    }
    Blq_Cinco[3] = '\0';

    printf("%s",Blq_Cinco);
}

void Bloque_Seis(int Jahr2)
{
    char Blq_Seis[2];
    int num;

    if(Jahr2>=2000)
    {
        if(Jahr2<=2010)
        {
            Blq_Seis[0] = 'A';
        }
        else
        {
            if(Jahr2 <= 2020)
            {
                Blq_Seis[0] = 'B';
            }
            else
            {
                if(Jahr2 <= 2030)
                {
                    Blq_Seis[0] = 'C';
                }
            }
        }
        Blq_Seis[1] = '\0';
    }
    else
    {
        srand(time(NULL));
        num = rand()%10;
        sprintf(Blq_Seis, "%d", num);
    }

    printf("%s", Blq_Seis);
}

void Bloque_Random()
{
    int num;
    char Blq_R[2];

    srand(time(NULL));
    num = rand()%10;
    sprintf(Blq_R, "%d", num);

    printf("%s", Blq_R);
}
