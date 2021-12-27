#ifndef IO_H
#define IO_H
#define ENOENT 2 /* No such file or directory */
#define SUCCESS 1
#define FAIL 0
#include <stdio.h>
#include <stdbool.h>
#include "matrix.h"
#include "time.h"
#include "maxsubsquare.h"
#define error(str, ...) {\
  fprintf(stderr,(str), ##__VA_ARGS__);\
  fprintf(stderr,"\n");\
  }
extern bool DEBUG;
extern char PARADIGM;
void entryRead(int argc, char* argv[],FILE** fin,FILE** fout);
int8_t** getMatrixFromFile(FILE *f,int n);
int matrixOrder(FILE* f);
void printMatrix(int8_t** m,int n);
void printSquare(int8_t** m,int n,FILE* fout,Square* sqr);
void printAlgorithmTime(const algorithm_time *algo_time,FILE* f);
#endif
