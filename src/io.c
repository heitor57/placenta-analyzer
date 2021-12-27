#include "io.h"
#include <getopt.h>
#include <stdlib.h>
bool DEBUG = false;
char PARADIGM = ' ';
void printUsage(){
  printf("placenta-analyzer -i <entry file> -o <out file> -d (DEBUG) -p <Paradigm>\n"
    "Possible paradigms\n"
    "-p b(Brute Force) d(Dynamic programming) g(Greedy)\n"
    "-p n(Branch and bound) a(All)\n"
    "Examples: placenta-analyzer -i in.txt -o out.txt -d -p d\n"
    "placenta-analyzer -i in.txt -o out.txt\n"
    "placenta-analyzer -i in.txt\n");
  exit(ENOENT);
}

void entryRead(int argc, char* argv[],FILE** fin,FILE** fout){
  int option;
  if(argc < 2)
  {
    printUsage();
  }
  while((option = getopt(argc,argv,"i:o:dp:")) != -1){
    switch(option){
    case 'i':
      if(!(*fin = fopen(optarg,"r"))){
	error("Input file open error.");
	exit(ENOENT);
      }
      break;
    case 'o':
      if(!(*fout = fopen(optarg,"w"))){
	error("Output file open error.");
	exit(ENOENT);
      }
      break;
    case 'd':
      DEBUG=true;
      break;
    case 'p':
      PARADIGM= optarg[0];
      break;
    }
  }
}
int8_t** getMatrixFromFile(FILE *f,int n){
  int i=0,j;
  int8_t** m = newMatrix(n),val;//matrixOrder is the size of the matrix
  
  while(!feof(f) && i<n){
    for(j=0;j<n-1;j++){
      fscanf(f,"%hhd ",&val);// Get value from file
      m[i][j] = val;// Set value on cell m[i][j]
    }
    fscanf(f,"%hhd",&val);
    m[i][j] = val;
    if(fgetc(f) == '\n')
      i++;//next line
  }
  rewind(f);
  return m;

}
int matrixOrder(FILE* f){
  int i=0;
  char c;
  while(!feof(f) && (c=fgetc(f)) != '\n'){
    if(c=='1' || c=='0')
      i++;
  }
  rewind(f);
  return i;
}

void printMatrix(int8_t** m,int n){
  int i,j;
  //first line print
  printf("+---+");
  for(i=0;i<n-1;i++)
    printf("---+");
  printf("\n");
  //first line print
  for(i =0;i<n;i++){
    // Values print
    for(j = 0;j<n;j++)
      printf("| %d ",m[i][j]);
    // Values print
    // Separating bar print
    printf("|\n+---+");
    for(j=0;j<n-1;j++)
      printf("---+");
    printf("\n");
    // Separating bar print
  }
  printf("\n\n");
}

void printSquare(int8_t **m,int n,FILE* fout,Square* sqr)
{
  int i,j,max = getSqrOrder(sqr),max_i = getSqrI(sqr),max_j = getSqrJ(sqr);
  char c='a';
  for(i=0;i<n;i++,c++)
    fprintf(fout,"%c ",c);
  fprintf(fout,"\n");
  c='a';
  for(i =0;i<n;i++,c++){
    fprintf(fout,"%c",c);
    for(j = 0;j<n;j++){
      if(i>=max_i && i<max_i+max && j>=max_j && j<max_j+max)
	fprintf(fout," %d",m[i][j]);
      else
	fprintf(fout,"  ");
    }
    fprintf(fout,"\n");
  }
}

void printAlgorithmTime(const algorithm_time *algo_time,FILE* f){
  fprintf(f,"User time %.6fs, System time %.6fs, Total Time %.6fs\n",get_utime(algo_time), get_stime(algo_time), get_total_time(algo_time));
}

