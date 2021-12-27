#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"
#include "io.h"
#include "maxsubsquare.h"
#include "time.h"
int main(int argc,char *argv[]){
  
  struct rusage *resources= malloc(sizeof(struct rusage)); // structure to account for the time
  // auxiliar struct to get algorithm information
  algorithm_time* algo_time= new_algorithm_time();

  FILE* fin = NULL,*fout=stdout;
  // Process entry
  entryRead(argc,argv,&fin,&fout);// Open input and output file and set PARADIGM
  int n = matrixOrder(fin);// order of the matrix(in);
  int8_t **m = getMatrixFromFile(fin,n);
  time_count(resources,START,algo_time);
  int aux;// getchar() auxiliar
  bool HaveParadigm =false;
  Square *maxSubSquare,*maxSubSquare2,*maxSubSquare3,*maxSubSquare4;
  do{
    switch(PARADIGM){
    case 'b': 
      maxSubSquare=maxSubSquareBruteForce(m,n);
      HaveParadigm=true;
      break;
    case 'd': 
      maxSubSquare=maxSubSquareDynamic(m,n);
      HaveParadigm=true;
      break;
    case 'g': 
      maxSubSquare=maxSubSquareGreedy(m,n);
      HaveParadigm=true;
      break;
    case 'n': 
      maxSubSquare=maxSubSquareBranchnBound(m,n);
      HaveParadigm=true;
      break;
    case 'a':
      HaveParadigm=true;
      maxSubSquare=maxSubSquareBruteForce(m,n);
      maxSubSquare2=maxSubSquareDynamic(m,n);
      maxSubSquare3=maxSubSquareGreedy(m,n);
      maxSubSquare4=maxSubSquareBranchnBound(m,n);
      break;
    default:
      printf("Choose one paradigm\n[b] Brute force(backtracking)\n[d] Dynamic\n[g] Greedy\n[n] Branch and bound\n[a] All\n");
      PARADIGM = getchar();
      while ((aux = getchar()) != '\n' && aux != EOF);
    }
  }while(!HaveParadigm);
  // Stop counting the time
  time_count(resources,STOP,algo_time);
  // print max order of the matrix and time
  if(PARADIGM == 'a'){
    fprintf(fout,"Brute force:\n");
    printSquare(m,n,fout,maxSubSquare);

    fprintf(fout,"Dynamic:\n");
    printSquare(m,n,fout,maxSubSquare2);
    freeSquare(maxSubSquare2);
    fprintf(fout,"Greedy:\n");
    printSquare(m,n,fout,maxSubSquare3);
    freeSquare(maxSubSquare3);
    fprintf(fout,"Branch and bound:\n");
    printSquare(m,n,fout,maxSubSquare4);
    freeSquare(maxSubSquare4);
  }else
    printSquare(m,n,fout,maxSubSquare);
  if(DEBUG){
    printf("Max order: %d\n",getSqrOrder(maxSubSquare));
    printAlgorithmTime(algo_time,stdout);
  }

  freeSquare(maxSubSquare);
  free_algorithm_time(algo_time);
  free(resources);
  freeMatrix(m,n);
  fclose(fin);
  fclose(fout);
}
