#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char **argv){

  if(argc < 3){
    printf("matrixgenerator <fout> <size>\n");
      return 0;
  }
  FILE *f = fopen(argv[1],"w");
  int n = atoi(argv[2]);
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n-1;j++){
    if(i==0 && j==0)
      fprintf(f,"1 ");
    else
      fprintf(f,"0 ");
    }
    if(i==0 && j==0)
      fprintf(f,"1\n");
    else
    fprintf(f,"0\n");
  }
  fclose(f);
}
