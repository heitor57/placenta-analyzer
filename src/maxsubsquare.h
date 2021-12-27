#ifndef MAXSUBSQUARE_H
#define MAXSUBSQUARE_H
#include "matrix.h"
#include <stdio.h>
typedef struct square Square;
Square* newSquare(void);
int freeSquare(Square* sqr);
int getSqrOrder(Square *sqr);
int getSqrI(Square *sqr);
int getSqrJ(Square *sqr);
Square *maxSubSquareBruteForce(int8_t **m,int n);
Square *maxSubSquareDynamic(int8_t **m,int n);
Square *maxSubSquareGreedy(int8_t **m,int n);
Square *maxSubSquareBranchnBound(int8_t **m,int n);

#endif
