#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main(int argc, char** argv)
{   
    setbuf(stdout, NULL);

    if (argc == 2) // If inverse matrix
    {
        FILE* file;
        int file_index = 1;

        file = fopen(argv[file_index], "r");

        int m, n;

        float** p_matr = (float**) read_matr(file, &m, &n);

        float** result = (float**) allocate_memory(n, n);

        inverse(p_matr, result, n);

        printf("\nResult:\n\n"); /* Inverse matrix output */
        for (int p = 0; p < n; p++)
        {
            for (int q = 0; q < n; q++)
            {
                printf("%9.1f", result[p][q]);
            }
            printf("\n");
        }
        printf("\n** See results in \"./result.txt\" **\n\n");

        write_matr(result, m, n);

        fclose(file);

        free(p_matr);
        free(result);
    }
    else
    {
        if (argc == 4)
        {
            char add[] = "-a";
            char mult[] = "-m";

            FILE* file1;
            FILE* file2;

            int file1_index = 1;
            int file2_index = 2;

            file1 = fopen(argv[file1_index], "r");
            file2 = fopen(argv[file2_index], "r");

            int m1, n1;
            int m2, n2;

            float** p_matr1 = (float**) read_matr(file1, &m1, &n1);
            float** p_matr2 = (float**) read_matr(file2, &m2, &n2);

            if ((m1 != m2) && (n1 != n2))
            {
                printf("\n%s\n\n", "Shape error");
                return SHAPE_ERR;
            }

            float** p_add = (float**) allocate_memory(m1, n1);
            float** p_mul = (float**) allocate_memory(m1, n1);

            if (strcmp(argv[3], add) == 0)
            {
                addition(p_matr1, p_matr2, p_add, m1, n1);
                write_matr(p_add, m1, n1);
                printf("%s\n", "Successful addition. Result in: ./result.txt");
            }

            if (strcmp(argv[3], mult) == 0)
            {
                multiplication(p_matr1, p_matr2, p_mul, m1, n1);
                write_matr(p_mul, m2, n2);
                printf("%s\n", "Successful multiplication. Result in: ./result.txt");
            }

            fclose(file1);
            fclose(file2);

            free(p_matr1);
            free(p_matr2);
            free(p_add);
            free(p_mul);
        }
        else
        {
            printf("%s\n", "Programm needs key.");
            printf("%s\n", "Please use -a to addition / -m to multiplication");
        }
    }

    return SUCCESS;
}
