#include"creatingfile.h"

int main(void)
{
    FILE * fptr;
    fptr = fopen("newfile.txt", "w");
    if (fptr == NULL) puts("file couldnt be opened");
    Employee p[] = {
        {123, 456, 100},
        {345, 837, 200},
        {555, 637, 300},
        {213, 786, 400},
        {321, 129, 500},
    };

    printArrayinFile(fptr, p);
    fclose(fptr);
}