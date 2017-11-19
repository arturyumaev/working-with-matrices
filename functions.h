#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

/* Constants declaration. */
#define SUCCESS     0
#define GLOBAL_ERR -1 // Not important type error, all types error
#define SHAPE_ERR  -2 // Matrices shape error

float** read_matr(FILE *file, int* m, int* n);
int get_shape(FILE* file, int* m, int* n);
int addition(float** a, float** b, float** c, int m, int n);
int multiplication(float** a, float** b, float** c, int m, int n);
int inverse(float** al, float ** result, int m);
void write_matr(float** data, int m, int n);
float** allocate_memory(int m, int n);

#endif