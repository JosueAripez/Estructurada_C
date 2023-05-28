#include "Rojapez.h"
#define N 3500

typedef struct _index{
	int index;
	long matricula;
}Tindex;

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

void Ord_Reg(Tindex ind[],int n,bool orden);
void Busc_Reg(Tsalumno v[],int n,bool orden);
void Gen_Txt(Tsalumno v[],int n);
int Cargar_Bin(Tindex ind[], int n);
void Elim_Reg(Tsalumno v[],int n);
void Imprimir_Bin(Tsalumno v[],int n);
Tsalumno Bin_Ord(int pos);
void Empaquetar_Archi();

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
	printf ("-----------------MENU-----------------\n");
    printf("1.- Agregar\n");
    printf("2.- Eliminar\n");
    printf("3.- Buscar\n");
    printf("4.- Ordenar\n");
    printf("5.- Imprimir Resgistros Archivo Original\n");
	printf("6.- Imprimir Resgistros Archivo Ordenado\n");
    printf("7.- Generar Archivo de Texto\n");
    printf("8.- Empaquetar \n");
    printf("0.- Salir\n\n");
    op = Val_Int(0,8,"Ingresa una opcion","Opcion no valida");
    return op;
}

void menu()
{
	bool ord = false;
	int op,op_2;
	int i = 0,j,num,cont = 2500,aux;
	Tsalumno vect[N],reg;
	Tindex ind[N];
    do
	{
     	op = msges();
        switch (op)
        {
           	case 1:
           	  	system("CLS");
           	  	printf("| 1.- Aleatorio | 2.- Manual |\n");
                op_2 = Val_Int(0,2,"Ingresa una opcion","Opcion no valida");
				if(op_2 == 1)
				{
					if(i < N-10)
					{
					    for(j=0; j<10; j++, i++)
						{
						   	vect[i] = Gen_Aleatorio();
						   	ind[N].index = cont;
						   	ind[N].matricula = vect[N].matricula;
						   	cont = cont  + 1;
						}
					}
						   
				}
				if(op_2 == 2)
				{
					if(i < N-1)
					{
					    for(j=0;j<1;j++,i++)
						{
						   	vect[i] = Gen_Manual();
						   	ind[N].index = cont;
						   	ind[N].matricula = vect[N].matricula;
						   	cont = cont  + 1;
						}
					}
				}
				printf("Registro Generado Correctamente\n",164);
				ord = false;
				system("PAUSE");
            break;
              
            case 2:
                printf("\nEliminando....\n");
              	Elim_Reg(vect,i);
              	system("PAUSE");
            break;
              
            case 3:
              	printf("\nBuscando....\n");
              	Busc_Reg(vect,i,ord);
              	system("PAUSE");
            break;
              
            case 4:
            	printf("\nOrdenando....\n");
              	Ord_Reg(ind,cont,ord);
              	ord = true;
              	system("PAUSE");
            break;
              
            case 5:
              	printf("\nImprimiendo....\n");
              	system("CLS");
				Imprimir_Bin(vect,i);
              	system("PAUSE");
            break;
              
            case 6:
              	printf("\nImprimiendo....\n");
              	for(i=0; i<cont; i++)
				{
				   	aux = ind[i].index;
				   	vect[i] = Bin_Ord(aux);
					printf("%5d\t%8c\t%16ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",i,vect[i].estado,vect[i].matricula,vect[i].nombre,vect[i].ap_pa,vect[i].ap_ma,vect[i].edad,vect[i].sexo);
	
				}
              	system("PAUSE");
            break;
              
            case 7:
              	printf("\nGenerando Archivo de Texto....\n");
              	Gen_Txt(vect,i);
              	system("PAUSE");
            break;

			case 8:
				printf("\nEmpaqutando....\n");
              	Empaquetar_Archi();
              	system("PAUSE");
			break;
        }

    }while (op != 0);
}

int Cargar_Bin(Tindex ind[], int n)
{
	FILE *fa;
	Tsalumno reg;
	int i=0;
	fa = fopen("registros.dat", "r+b");
	if(fa)
	{
	  	for(i=0; i<n;i++)
	  	{
			 
			fread(&reg, sizeof(struct _alumno),1,fa);
			ind[i].index = i;
			ind[i].matricula = reg.matricula;
		}
		for(i=0; i<n; i++)
		{
		   	printf("%d %ld %c \n ",ind[i].index,ind[i].matricula);
		}
	}
	else
	{
	  	printf("El archivo no existe");
	}	
	fclose(fa);
}

Tsalumno Gen_Aleatorio()
{
Tsalumno reg;
	int sex;
	char nombre[15][20];
	char Nom_Muj[20][15] = {"Blanca","Estela","Brisa","Fernanda","Yuniva","Dayany","Dayana","Jessica","America","Alexia","Julia","Ashley","Alexa","Maria","Keyla"};
	char Nom_Homb[20][15]  = {"Josue","Francisco","Nilton","Daniel","Isaac","Abraham","Jose","Roberto","Gerrardo","Alex","Henrry","Thomas","Agustin","Norberto","Carlos"};
	char Apell[20][15] = {"Rojas","Aripez","Rojapez","Bañuelos","Escamilla","Beristain","Leyva","Bustamante","Trujillo","Ybarra","Robins","Wilson","Grey","Shepherd","Herrera"};

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
	
	FILE *fa;
	fa = fopen("registros.dat","a+b");
	{
		fwrite(&reg,sizeof(struct _alumno), 1, fa);
	}
	fclose(fa);
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
	Val_Cadena(reg.nombre,"Nombres (s): ");
	fflush(stdin);
	Val_Cadena(reg.ap_pa,"Apellido Paterno: ");
	fflush(stdin);
	Val_Cadena(reg.ap_ma,"Apellido Materno: ");
	reg.estado = 'A';
	reg.matricula = Val_Long(0, 100000000, "Matricula: ", "Matricula inexsistente");
	reg.edad = Val_Int(0,100,"Edad: ","Edad invalida");
	sex = Val_Int(0,1,"Sexo: | 0.- Mujer | 1.- Hombre | ","Opcion no valida");
	
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
	
	FILE *fa;
	fa = fopen("registros.dat","a+b");
	{
		fwrite(&reg,sizeof(struct _alumno), 1, fa);
	}
	fclose(fa);
	return reg;
}

void Elim_Reg(Tsalumno v[],int n)
{
	int i;
	long matricula;
	bool encon;
	
	system("CLS");
	matricula = Val_Long(300000,100000000,"¿Que matricula buscas? ","Numero no valido");
	
	for(i=0;(i<n )&&(v[i].matricula != matricula);i++)
	{
	}
	if(i == n)
	{
		printf("Matricula inexsistente\n");
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
	int i;
	long matricula;
	
	system("CLS");
	matricula = Val_Long(300000,100000000,"¿Que matricula buscas? ","Numero no valido");
	
	for(i=0;(i<n)&&(encon == false);i++)
	{
		if(matricula == v[i].matricula)
		{
			printf("\nRegistro:\n");
			printf("%5s\t%8s\t%8s\t%8s\t%8s\t%8s\t%8s\n","No.Registro","Matricula","Nombre","Ap Paterno","Ap Materno","Edad","Sexo");
			printf("%5d\t%16ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",i,v[i].matricula,v[i].nombre,v[i].ap_pa,v[i].ap_ma,v[i].edad,v[i].sexo);
			printf("\n");
			encon = true;
		}
	}				
	if(encon == false)
	{
		printf("EMatriclua inexsistente\n");
	}	
}

void Ord_Reg(Tindex ind[],int n,bool orden)
{
	int i,j;
	long temp = 0;
	Tindex tempo;
    
    if(orden == false)
    {
		for (i = 0; i < n; i++)
        {
    	    for (j = 0; j < n - i; j++)
	        {
			    if (ind[j].matricula < ind[j + 1].matricula)
			    {
				    tempo = ind[j];
				    ind[j] = ind[j + 1];
				    ind[j + 1] = tempo;	
			    }  	
		    } 	
	    }
	}
	else
    {
  	    printf(" Vector ya Ordenado\n");
    }
}

Tsalumno Bin_Ord(int pos)
{
	FILE* fa;
	Tsalumno reg;
	fa = fopen("registros.dat","r+b");
	if (fa)
	{
		fseek(fa, pos*(sizeof(struct _alumno)), SEEK_SET);   
	    fread(&reg, sizeof(struct _alumno),1,fa);           
	    fclose(fa);                                        
	    return reg;
	}        
	else
	{
		printf("El archivo no existe");
	}             
}

void Imprimir_Bin(Tsalumno v[],int n)
{
	int i;
	i = n;
	FILE* archi;
	Tsalumno reg;
	system("CLS");
	archi = fopen("registros.dat","r+b");
	
	if (archi)
	{
		printf("%5s\t%8s\t%10s\t%8s\t%8s\t%8s\t%8s\t%8s\n","No.Registro","Estatus","Matricula","Nombre","Ap Paterno","Ap Materno","Edad","Sexo");
	   	while (fread(&reg,sizeof(struct _alumno), 1, archi))
	   	{
			printf("%5d\t%8c\t%16ld\t%8s\t%8s\t%8s\t%8d\t%8c\n",i,v[i].estado,v[i].matricula,v[i].nombre,v[i].ap_pa,v[i].ap_ma,v[i].edad,v[i].sexo);
	   	    v[i] = reg;
	   	    i++;
		}
		close(archi);
		printf("\n");
	}
	else
	{
	    printf("\nEl archivo no existe\n ");
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
		printf("Ingresa el nombre de su archivo: ");
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

void Empaquetar_Archi()
{
	FILE *bin;
    FILE *ftemp;
 
    Tsalumno reg;
 
    ftemp = fopen("temp.dat", "w+b");
    bin = fopen("registros.dat", "r+b");
    if (bin)
    {
    	while(fread(&reg, sizeof (struct _alumno),1,bin))
    	{
    	    if (reg.estado == 'A')
    	    {
    	     	fwrite(&reg, sizeof(struct _alumno),1,ftemp);
			}
		}
     	system("PAUSE");
	    fclose(bin);
	    fclose(ftemp);
	    system("del temp.bak");
	    system("rename registros.dat temp.bak");
	    system("rename temp.dat registros.dat");		 
	}
    else
    {
    	printf("No existe el archivo");
	}
}