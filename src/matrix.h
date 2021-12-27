#ifndef MATRIX_H
#define MATRIX_H
#include <stdint.h>
#include <stddef.h>
int8_t** newMatrix(int n);
int freeMatrix(int8_t** m,int n);
int8_t getCellWithCheck(int8_t** m,int n,int i,int j);
#endif
