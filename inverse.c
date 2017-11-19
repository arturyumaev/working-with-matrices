#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <string.h>

#include "functions.h"

int inverse(float** main_A, float** result, int n)
{
    /* What issue function solve:
        Task: find the inverse matrix X of base matrix A
        Method: Gauss method
        Steps:
         - Split equations:
            A*x(1) = e(1)
                ...
            A*x(n) = e(n), where x(n), e(n) - n-th column of X and E

         - Find x(n) with Gauss elimination method (http://matworld.ru/gauss-method.php)
                x(n) = GaussElimination(x(n), e(n))

         - Group all columns x(1), ..., x(n) in matrix called "inverse_matrix" */

    /* Fill E */
    float** E = (float**) allocate_memory(n + 1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                E[i][j] = 1.0;
            }
            else
            {
                E[i][j] = 0.0;
            }
        }
    }

    int i, j, k; /* Indexes */
    float** A = (float**) allocate_memory(n + 1, n + 2);
    float c, x[n + 1], sum = 0.0;

    for (int stage = 1; stage <= n; stage++) /* Resolve all equations */
    {
        for (int p = 1; p <= n; p++) /* Rewrite base A to temp */
        {
            for (int q = 1; q <= n; q++)
            {
                A[p][q] = main_A[p - 1][q - 1];
            }
        }

        for (int p = 1; p <= n; p++) /* Fill last column */
        {
            A[p][n + 1] = E[p][stage];
        }

        /* Forward way */    
        for (j = 1; j <= n; j++)
        {
            for (i = 1; i <= n; i++)
            {
                if (i > j)
                {
                    c = A[i][j] / A[j][j];
                    for (k = 1; k <= n + 1; k++)
                    {
                        A[i][k] = A[i][k] - c * A[j][k];
                    }
                }
            }
        }

        x[n] = A[n][n + 1] / A[n][n];
        
        /* Reverse way */
        for (i = n - 1; i >= 1; i--)
        {
            sum = 0.0;
            for (j = i + 1; j <= n; j++)
            {
                sum = sum + A[i][j] * x[j];
            }
            x[i] = (A[i][n + 1] - sum) / A[i][i];
        }

        for (int p = 0; p < n; p++)
        {
            result[p][stage - 1] = x[p + 1];
        }
    }

    free(E);
    free(A);

    return SUCCESS;
}