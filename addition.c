#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int addition(float** a, float** b, float** c, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

	return SUCCESS;
}