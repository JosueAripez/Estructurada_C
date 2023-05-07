#include <stdio.h>
#include <stdlib.h>
#define alumnos 40
#define unidades 5
#define max_turistas 10
#define max_peso 700
#define sobrepesos 0.15

int msges();
void menu();
void Examen_nivelacion (void);
void Tabla_multiplicar (void);
void Rango (void);
void Embarcacion (void);
void Examen_materia (void);

int main()
{
   menu();

    return 0;
}

int msges()
{ int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- Examen de Nivelacion \n");
  printf("2.- Tabla de Multiplicar \n");
  printf("3.- Rango \n");
  printf("4.- Embarcacion\n");
  printf("5.- Examen Materia\n");
  printf("0.- Salir  \n");
  printf("Escoga una opcion: ");
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
              Examen_nivelacion();
              break;
        case 2:
              Tabla_multiplicar();
              break;
        case 3:
              Rango();
              break;
        case 4:
              Embarcacion();
              break;
        case 5:
              Examen_materia();
      }

    }while (op != 0);


}

void Examen_nivelacion (void)
{
    float calificaciones[alumnos][unidades];
    int no_derecho = 0;

    system ("CLS");

    for (int i = 0; i < alumnos; i++) 
    {
        printf("Calificaciones del alumno %d:\n", i + 1);
        for (int j = 0; j < unidades; j++) 
        {
            printf("Unidad %d: ", j + 1);
            scanf("%f", &calificaciones[i][j]);
        }
    }

    for (int i = 0; i < alumnos; i++) 
    {
        float promedio = 0.0;

        for (int j = 0; j < unidades; j++) 
        {
            promedio += calificaciones[i][j];
        }
        promedio /= unidades;
        if (promedio < 50) 
        {
            no_derecho++;
        }
    }

    printf("Numero de alumnos que no tienen derecho al examen de nivelacion: %d\n", no_derecho);
    
    printf("   EXAMEN NIVELACION\n"); 
    system ("PAUSE");
}

void Tabla_multiplicar (void)
{
    int i, j; 

    system ("CLS");

    for (i = 1; i <= 10; i++) 
    {
      printf("Tabla del %d:\n", i);
      for (j = 1; j <= 10; j++) 
      {
         printf("%d x %d = %d\n", i, j, i * j);
      }
      printf("\n");
    }

    printf("   TABLA DE MULTIPLICAR\n"); 
    system ("PAUSE");
}

void Rango (void)
{
    int n, rango_min, rango_max, numero, suma = 0, contador = 0;
    float media;

    system ("CLS");

    printf("Ingresa la cantidad de numeros que quiere leer: ");
    scanf("%d", &n);

    printf("Ingresa el rango minimo: ");
    scanf("%d", &rango_min);

    printf("Ingresa el rango maximo: ");
    scanf("%d", &rango_max);

    printf("Ingrese los numeros separados por espacios:\n");

    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &numero);
        if (numero >= rango_min && numero <= rango_max) 
        {
            suma += numero;
            contador++;
        }
    }

    if (contador > 0) 
    {
        media = (float) suma / contador;
        printf("La suma de tdos los numeros dentro del rango es: %d\n", suma);
        printf("La media de todos los numeros dentro del rango es: %.2f\n", media);
    } 
    else 
    {
        printf("Numeros fuera del rango\n");
    }

    printf("   RANGO\n"); 
    system ("PAUSE");
}

void Embarcacion (void)
{
    int num_turistas = 0;
    float peso_total = 0;
    float peso_promedio;
    int sobrepeso = 0;

    system ("CLS");

    printf("Ingresa el peso de cada turista en kg:\n");
    
    while (num_turistas < max_turistas && peso_total < max_peso) 
    {
        float peso;
        printf("Turista %d: ", num_turistas + 1);
        scanf("%f", &peso);
        if (peso_total + peso <= max_peso * (1 + sobrepesos)) 
        {
            num_turistas++;
            peso_total += peso;
        } 
        else 
        {
            sobrepeso = 1;
            break;
        }
    }

    peso_promedio = peso_total / num_turistas;

    printf("Turistas: %d\n", num_turistas);
    printf("Peso total: %.2f kg\n", peso_total);
    printf("Peso promedio: %.2f kg\n", peso_promedio);
    if (sobrepeso) 
    {
        printf("La embarcacion ya no puede llevar mas pasajeros esto por el sobrepeso.\n");
    } 
    else 
    {
        printf("La embarcacion ya no puede llevar mas pasajeros, has alcanzado el limite de turistas\n");
    }

    printf("   EMBARCACION\n"); 
    system ("PAUSE");
}

void Examen_materia (void)
{
    float promedio;
    int oportunidades = 0;
    int cal1, cal2, cal3;

    system ("CLS");

    while (oportunidades < 3) 
    {
        printf("Ingresa tu calificacion de tu primer examen: ");
        scanf("%d", &cal1);
        printf("Ingresa tu calificacion de tu segundo examen: ");
        scanf("%d", &cal2);
        printf("Ingresa tu calificacion de tu tercer examen: ");
        scanf("%d", &cal3);
    
        promedio = (cal1 + cal2 + cal3)/3;
    
        printf("Promedio de: %f\n", promedio);

        if (promedio >= 70) 
        {
            printf("Felicidades aprobaste la materia, avanzas al siguiente semestre\n");
            break;
        }
        else 
        {
            oportunidades++;

            if (oportunidades == 3) 
            {
                printf("Has reprobado la misma materia tres veces, eres Baja Academica\n");
            }
            else 
            {
                printf("Tu promedio no es suficiente, repite la materia\n");
            }
        }
    }

    printf("   EXAMEN MATERIA\n"); 
    system ("PAUSE");
}