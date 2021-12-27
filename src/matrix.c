#include "matrix.h"
#include <stdlib.h>
#include "io.h"

int8_t** newMatrix(int n){
  if(n <= 0)
    return 0;
  int8_t **m = malloc(sizeof(int8_t*)*n);
  for(int i=0;i<n;i++)
    m[i]=malloc(sizeof(int8_t)*n);
  return m;
}

int freeMatrix(int8_t** m,int n){
  if(m == NULL)
    return FAIL;
  for(int i=0;i<n;i++)
    free(m[i]);
  free(m);
  return SUCCESS;
}
int8_t getCellWithCheck(int8_t** m,int n,int i,int j){
  if(i < 0 || i >= n || j < 0 || j >= n)
    return 0;
  return m[i][j];
}

