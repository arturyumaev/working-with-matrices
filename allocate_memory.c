#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

float** allocate_memory(int m, int n)
{
    float** data = (float**) malloc(n * sizeof(float*) + n * m * sizeof(float));

    if (!data)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        data[i] = (float*)((char*) data + n * sizeof(float*) + i * m * sizeof(float));
    }

    return data;
}