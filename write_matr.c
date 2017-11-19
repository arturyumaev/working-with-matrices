#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h>

#include "functions.h"

void write_matr(float** data, int m, int n)
{
    char result_name[] = "result.txt";

    FILE* result = fopen(result_name, "w");

    for(int i = 0; i < m; i++)     
    {
        for(int j = 0; j < n; j++)  
        {              
            fprintf(result, "%9.2f ", data[i][j]);
        }
        fprintf(result, "\n");
    }

    fclose(result);
}