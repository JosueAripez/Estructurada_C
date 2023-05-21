#include "Rojapez.h"
#define N 2500

typedef struct _alumno{
	
	char estado;
	long matricula;
	char nombre[30];
	char ap_pa[30];
	char ap_ma[30];
	int edad;
	char sexo;

} Tsalumno;

int msges();
void menu();

Tsalumno Gen_Manual();
Tsalumno Gen_Aleatorio();
void Imprim_Reg(Tsalumno v[],int n);
void Ord_Reg(Tsalumno v[],int n,bool orden);
void Busc_Reg(Tsalumno v[],int n,bool orden);
void Gen_Txt(Tsalumno v[],int n);
void Ver_Txt(Tsalumno v[],int n);
void Gen_Bin(Tsalumno v[],int n);
void Cargar_Bin(Tsalumno v[],int n);
void Elim_Reg(Tsalumno v[],int n);

int main()
{
	srand(time(NULL));
	menu();	
	return 0;
}

int msges()
{
	int op;
	system("CLS");
	printf ("------------Menu---------- \n");
    printf("1.- Agregar \n");
    printf("2.- Agregar Manual \n");
    printf("3.- Eliminar registro \n");
    printf("4.- Buscar \n");
    printf("5.- Ordenar \n");
    printf("6.- Imprimir \n");
    printf("7.- Generar Archivo de Texto \n");
    printf("8.- Ver Archivo de Texto \n");
    printf("9.- Generar Archivo Binario \n");
    printf("10.- Cargar Archivo Binario \n");
    printf("0.- Salir\n\n");
    op = Val_Int(0,10,"Ingresa una opcion","Esa opcion no es valida");
    return op;
}

void menu()
{
	bool ord = false;
	bool arch_carg = false;
	int op;
	int i = 0,j,num;
	Tsalumno vect[N],reg;
    do
	{
     	
        op = msges();
        switch (op)
        {
           	case 1:
           	  	printf("\n-------Agregar------\n");
				if(i < N-2200)
				{
					for(j=0;j<2200;j++,i++)
					{
						vect[i] = Gen_Aleatorio();
					}
				}
				printf("2200 registros creados\n");
				ord = false;
				system("PAUSE");
            break;
              
            case 2:
              	printf("\n-------Agregar Manual------\n");
				printf("Cuantos registros desea ingresar?\n");
				scanf("%d",&num);
				  
				if(i < N-num)
				{
					for(j = 0;j < num;j++,i++)
				 	{
						vect[i] = Gen_Manual();
					}
				}
				ord = false;
				system("PAUSE");
            break;
              
            case 3:
              	printf("\n-------Eliminar------\n");
              	Elim_Reg(vect,i);
              	system("PAUSE");
            break;
              
            case 4:
              	printf("\n-------Buscar------\n");
              	Busc_Reg(vect,i,ord);
              	system("PAUSE");
            break;
              
            case 5:
              	printf("\n-------Ordenar------\n");
              	Ord_Reg(vect,i,ord);
              	ord = true;
              	system("PAUSE");
            break;
              
            case 6:
              	printf("\n-------Imprimir-------\n");
              	Imprim_Reg(vect,i);
              	system("PAUSE");
            break;
              
            case 7:
              	printf("\n-------Generar Archivo de Texto-------\n");
              	Gen_Txt(vect,i);
              	system("PAUSE");
            break;
              
            case 8:
              	printf("\n-------Ver Archivo de Texto---------\n");
              	Ver_Txt(vect,i);
              	system("PAUSE");
            break;
              
            case 9:
              	printf("\n--------Generar Archivo Binario-------\n");
              	Gen_Bin(vect,i);
              	system("PAUSE");
            break;

            case 10:
              	printf("\n--------Cargar Archivo Binario---------\n");
              	Cargar_Bin(vect,i);
              	system("PAUSE");
            break;
		}

    }while (op != 0);
}

Tsalumno Gen_Aleatorio()
{
	Tsalumno reg;
	int sex;
	char nombre[15][20];
	char Nom_Muj[20][15] = {"Karina","Martha","Elizabeth","Maria","Lucia","Daniela","Luisa","Rebeca","Alejandra","Karla","Andrea","Ana","Julia","Victoria","Alicia"};
	char Nom_Homb[20][15]  = {"Jorge","Alejandro","Enrique","Luis","Miguel","Angel","Victor","Sebastian","Jose","Lucas","Isaac","Eduardo","Andres","Juan","Jesus","Pedro"};
	char Apell[20][15] = {"Vargas","Hernandez","Perez","Mora","Rivera","Juarez","Orozco","Gonzalez","Flores","Cortez","Sanchez","Diaz","Campos","Vallejo","Sosa"};

	system("CLS");
	
	sex = rand()%2;
	if(sex == 0) 
	{
	  	strcpy(reg.nombre,Nom_Muj[rand()%15]);
	  	reg.sexo = 'M';
	} 
	else 
	{
	  	strcpy(reg.nombre,Nom_Homb[rand()%15]);
	  	reg.sexo = 'H';
	} 
	
	strcpy(reg.ap_pa,Apell[rand()%15]);
	strcpy(reg.ap_ma,Apell[rand()%15]);
	reg.matricula = rand()%70000 + 330000;
	reg.estado = 'A';
	reg.edad = rand()%8 + 18;
	return reg;
}

Tsalumno Gen_Manual()
{
	Tsalumno reg;
	int sex,edad;
	long matricula;
	char Nombre[20], Ap_Pat[20], Ap_Ma[20],sexo;
	system("CLS");
	fflush(stdin);
	Val_Cadena(reg.nombre,"Dame tu nombre: ");
	fflush(stdin);
	Val_Cadena(reg.ap_pa,"Dame tu apellido paterno: ");
	fflush(stdin);
	Val_Cadena(reg.ap_ma,"Dame tu apellido materno: ");
	reg.estado = 'A';
	reg.matricula = Val_Long(0, 100000000, "Dame tu matricula: ", "Esa matricula no es valida");
	reg.edad = Val_Int(0,100,"Dame tu edad: ","Esa edad no es valida");
	sex = Val_Int(0,1,"Dame tu sexo (0.- Mujer, 1.- Hombre): ","Esa no es una opcion");
	
	if (sex == 0)
	   {
			reg.sexo = 'M';
	   }
	else
	{
		if (sex == 1)
		   {
				reg.sexo = 'H';
		   }
		   else
		   {
			   printf("Esa no es opcion.\n");
		   }
	}
	
	return reg;
}

void Elim_Reg(Tsalumno v[],int n)
{
	int i;
	long matricula;
	bool encon;
	
	system("CLS");
	matricula = Val_Long(300000,100000000,"¿Que matricula buscas? ","Ese numero no es valido");
	
	for(i=0;(i<n )&&(v[i].matricula != matricula);i++)
	{
	}
	if(i == n)
	{
		printf("Esa matricula no se encuentra en el sistema.\n");
	}
	else
	{
		v[i].estado = 'I';
		printf("\nEstado: Inactivo\n");
	}
	
}

void Busc_Reg(Tsalumno v[],int n,bool orden)
{
    bool encon;
	int i,band,sup,inf,med;
	long matricula;
	
	system("CLS");
	band = TRUE;
	matricula = Val_Long(300000,100000000,"¿Que matricula buscas? ","Ese numero no es valido");
	
	for(i=0;(i<n)&&(encon == false);i++)
	{
		if(matricula == v[i].matricula)
		{
			printf("\n------Registro Encontrado------\n");
			printf("%5s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\n","No.Registro","Matricula","Nombre","Ap Paterno","Ap Materno","Edad","Sexo");
			printf("%5d\t%16ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",i,v[i].matricula,v[i].nombre,v[i].ap_pa,v[i].ap_ma,v[i].edad,v[i].sexo);
			printf("\n");
			encon = true;
		}
	}
	if(encon == false)
	{
		printf("Esa matricula no se encuentra en el sistema\n");
	}	
}

void Ord_Reg(Tsalumno v[],int n,bool orden)
{
	int i,j,k;
	long temp = 0;
	Tsalumno tempo;
    
    if(orden == false)
    {
    	if(N <= 500)
	    {
		    for (i = n/2; i > 0; i = i / 2)
    		{
       			for (j = i; j < n; j++)
        		{
            		for(k = j - i; k >= 0; k = k - i)
            		{
                		if (v[k+i].matricula >= v[k].matricula)
                		{
                			break;
						}
                		else
                		{
                   			tempo = v[k];
                			v[k] = v[k+i];
                   			v[k+i] = tempo;
                		}
            		}
        		}
    		}
	    }
	    else
	    {
		    if(N > 500)
		    {
			    for (i = 0; i <= n; i++)
                {
    	            for (j = 0; j <= n - i; j++)
	                {
			            if (v[j].matricula < v[j + 1].matricula)
			            {
				            tempo = v[j];
				            v[j] = v[j + 1];
				            v[j + 1] = tempo;	
			            }  	
		            } 	
	            }
		    }
	    }
	}
	else
    {
  	   printf("No es necesario ordenarlo, ya lo esta\n\n");
    }
}

void Imprim_Reg(Tsalumno v[],int n)
{
	int i;
	system("CLS");
	printf("%5s\t%10s\t%8s\t%8s\t%8s\t%8s\t%8s\n","No.Registro","Matricula","Nombre","Ap Paterno","Ap Materno","Edad","Sexo");
	for(i=0;i < n;i++)
	{
	   	if (v[i].estado == 'A')
	   	{
	   		printf("%5d\t%16ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",i,v[i].matricula,v[i].nombre,v[i].ap_pa,v[i].ap_ma,v[i].edad,v[i].sexo);
		}
	}
}

void Gen_Txt(Tsalumno v[],int n)
{
	int i;
	bool stat = false;
	char nom_archi[24];
	FILE * archi;
	system("CLS");
	
	do
	{
		printf("Ingrese el nombre de su archivo: ");
		fflush(stdin);
		gets(nom_archi);
		stat = ValidTxt(nom_archi);
		
	}while (stat==true);
	
	strcat(nom_archi,".txt\0");
	printf("\nEl nuevo nombre del archivo es: %s\n",nom_archi);
	
	archi = fopen(nom_archi,"w");
	if (archi == NULL)
    {
        printf("No se puede abrir el archivo");
    }
	for(i = 0;i < n;i++)
	{
	   	if (v[i].estado == 'A')
	   	{
	   		fprintf(archi,"%8d\t%8ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",i,v[i].matricula,v[i].nombre,v[i].ap_pa,v[i].ap_ma,v[i].edad,v[i].sexo);
		}
	}
	fclose(archi);
}

void Ver_Txt(Tsalumno v[],int n)
{
	system("CLS");
	FILE *archi;
	char caracter;
	bool stat = false;
	
	archi = fopen("datos.txt","r");
	
	if(archi)
	{
		while(!feof(archi))
		{
		    caracter = fgetc(archi);
		    fprintf(stdout,"%c",caracter);
		}
		fclose(archi);
	}
	else
	{
	  	printf("El archivo no existe\n\n");
	}
}

void Gen_Bin(Tsalumno v[],int n)
{
	int i;
	char nom_archi[24];
	bool stat = false;
	FILE * archi;
	Tsalumno reg;
	system("CLS");
	
	do
	{
	
		printf("Ingrese el nombre de su archivo: ");
		fflush(stdin);
		gets(nom_archi);
		stat = ValidTxt(nom_archi);
		
	}while (stat == true);
	
	strcat(nom_archi,".dat\0");
	printf("\nEl nuevo nombre del archivo es: %s\n",nom_archi);
	
	archi = fopen(nom_archi,"w+b");
	printf("\n\n");
	printf("     ----> %d",n);
	for (i=0; i<n; i++)
	{
	    reg = v[i];
	    printf("%c %ld %s %s %s %d %c", reg.estado, reg.matricula, reg.nombre, reg.ap_pa, reg.ap_ma, reg.edad, reg.sexo);
	    fwrite(&reg,sizeof(struct _alumno), 1, archi);
	}
	printf("\n\n");
	fclose(archi);
}

void Cargar_Bin(Tsalumno v[],int n)
{
	int i;
	i = n;
	FILE* archi;
	Tsalumno reg;
	system("CLS");
	archi = fopen("datos_bin.dat","r+b");
	
	if (archi)
	{
	   	while (fread(&reg,sizeof(struct _alumno), 1, archi))
	   	{
	   	    printf("%c %ld %s %s %s %d %c\n", reg.estado, reg.matricula, reg.nombre, reg.ap_pa, reg.ap_ma, reg.edad, reg.sexo);
	   	    v[i] = reg;
	   	    i++;
		}
		fclose(archi);
		printf("\n");
	}
	else
	{
	    printf("\nEl archivo no existe\n ");
	}
}