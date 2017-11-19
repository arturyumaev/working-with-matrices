#include <stdio.h>
#include <stdlib.h>    

#include "functions.h"

float** read_matr(FILE *file, int* m, int* n)
{
    fscanf(file, "%d", m);
    fscanf(file, "%d", n);

    float** p_matr = allocate_memory(*m, *(m) + 1);
    for (int i = 0; i < *m; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            fscanf(file, "%f", &(p_matr[i][j]));
        }
    }
    
    return p_matr;
}