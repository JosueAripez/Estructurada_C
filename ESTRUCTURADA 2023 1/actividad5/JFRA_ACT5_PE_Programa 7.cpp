#include <stdio.h>

int main() 
{
    int dia, mes;

    printf("Ingresa el dia de naciemineto\n");
    scanf("%d", &dia);
    printf("Ingresa el mes de nacimiento\n");
    scanf("%d", &mes);
    
    if ((mes == 1 && dia >= 20) || (mes == 2 && dia <= 18)) 
    {
        printf("Su signo es Acuario\n");
        printf("Acuario: Tu creatividad estará en su punto máximo hoy.\n");
    } 
    else if ((mes == 2 && dia >= 19) || (mes == 3 && dia <= 20)) 
    {
        printf("Su signo es Piscis\n");
        printf("Piscis: Deberías tomarte un tiempo para ti mismo y reflexionar sobre tu vida.\n");
    } 
    else if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 19)) 
    {
        printf("Su signo es Aries\n");
        printf("Aries: Hoy es un buen día para tomar riesgos y aventurarte fuera de tu zona de confort.\n");
    } 
    else if ((mes == 4 && dia >= 20) || (mes == 5 && dia <= 20)) 
    {
        printf("Su signo es Tauro\n");
        printf("Tauro: Tu perseverancia y dedicación te llevarán lejos hoy.\n");
    } 
    else if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20)) 
    {
        printf("Su signo es Geminis\n");
        printf("Géminis: Hoy es un buen día para conectarte con tus amigos y familiares.\n");
    } 
    else if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 22)) 
    {
        printf("Su signo es Cancer\n");
        printf("Cáncer: Es importante que tomes decisiones informadas hoy.\n");
    } 
    else if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 22)) 
    {
        printf("Su signo es Leo\n");
        printf("Leo: Tu entusiasmo y optimismo te ayudarán a superar cualquier obstáculo.\n");
    } 
    else if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22)) 
    {
        printf("Su signo es Virgo\n");
        printf("Virgo: La organización y la planificación serán clave para el éxito hoy.\n");
    } 
    else if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22)) 
    {
        printf("Su signo es Libra\n");
        printf("Libra: Deberías considerar hacer algo para ayudar a los demás hoy.\n");
    } 
    else if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21)) 
    {
        printf("Su signo es Escorpio\n");
        printf("Escorpio: Hoy es un buen día para enfrentar tus miedos y superarlos.\n");
    } 
    else if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21)) 
    {
        printf("Su signo es Sagitario\n");
        printf("Sagitario: Tu sentido de la aventura te llevará a nuevas experiencias hoy.\n");
    } 
    else if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 19)) 
    {
        printf("Su signo es Capricornio\n");
        printf("Capricornio: Hoy es un buen día para hacer planes a largo plazo.\n");
    } 
    else 
    {
        printf("Fecha de nacimiento invalida\n");
    }

    return 0;
}       