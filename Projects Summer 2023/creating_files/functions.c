#include "creatingfile.h"


void printArrayinFile(FILE * fptr, Employee p[])
{
    for(int i = 0; i<5; i++)
    {
        fprintf(fptr,"ID[%d] = %d\n", i+1, p[i].ID);
        fprintf(fptr,"SSN[%d] = %d\n", i+1, p[i].SSN);
        fprintf(fptr,"salary[%d] = %d\n", i+1, p[i].salary);
        fprintf(fptr,"-----------------\n");
    }
}





