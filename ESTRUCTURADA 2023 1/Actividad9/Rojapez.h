#include <stdio.h>
#include <stdlib.h>

int vali_num(int ri,int rf,const char msge[])
{
	int num;
    char xnum[30];
    
    do{
        printf("%s:",msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        
		if (num < ri || num > rf)
        {
            printf("Fuera de rango(%d a %d) \n",ri,rf);
            system("PAUSE");
        }
        
    }while(num < ri || num > rf);
    
	return num;
}