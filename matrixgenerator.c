#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char **argv){

  if(argc < 4){
    printf("matrixgenerator <fout> <size> <1 chance [0..100]>\n");
      return 0;
  }
  FILE *f = fopen(argv[1],"w");
  int n = atoi(argv[2]);
  int chanceTo1 = atoi(argv[3]);
  srand(time(NULL));   // Initialization, should only be called once.
  int i,j,r;

  for(i=0;i<n;i++){
    for(j=0;j<n-1;j++){
      r= rand()%100+1 <= chanceTo1 ? 1 : 0;
      fprintf(f,"%d ",r);
    }
    r= rand()%100+1 <= chanceTo1 ? 1 : 0;
    fprintf(f,"%d\n",r);
  }
  fclose(f);
}
