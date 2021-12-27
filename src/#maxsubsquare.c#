#include "maxsubsquare.h"
#include <stdlib.h>
#include "io.h"
#include <stdio.h>
#define min3(a,b,c) (min(min(a,b),c))
enum Corners{LeftBottom,LeftTop,RightTop,RightBottom};
// Macro version of checksubsquarecorner for performance
#define CHECK_SUBSQUARE_CORNER(m,y,x,area,corner,isAllSet)		\
  int tempi;								\
  int yAdd= corner==LeftBottom||corner==RightBottom ? area-1 : 0,	\
    xAdd= corner==RightTop || corner==RightBottom ? area-1 : 0;		\
  isAllSet=true;							\
  for(tempi=x;tempi<x+area;tempi++)					\
    if(!m[y+yAdd][tempi]){						\
      isAllSet=false;							\
      break;								\
    }									\
  if(isAllSet)								\
    for(tempi=y;tempi<y+area;tempi++)					\
      if(!m[tempi][x+xAdd]){						\
	isAllSet=false;							\
	break;								\
      }									\

int min(int a, int b) {
  return a<b?a:b;
}

struct square{
  int order,i,j;
};

Square* newSquare(void){
  Square* sqr = malloc(sizeof(Square));
  if(sqr != NULL){
    sqr->order = 0;
    sqr->i = 0;
    sqr->j = 0;
  }
  return sqr;
}

int freeSquare(Square* sqr){
  if(sqr == NULL)
    return FAIL;
  free(sqr);
  return SUCCESS;
}

int getSqrOrder(Square *sqr){
  return sqr->order;
}

int getSqrI(Square *sqr){
  return sqr->i;
}

int getSqrJ(Square *sqr){
  return sqr->j;
}

bool checkSubSquare(int8_t** m,int y,int x,int area){
  int i,j;
  for(i=y;i<y+area;i++)
    for(j=x;j<x+area;j++)
      if(!m[i][j])
	return false;
  return true;
}

// function of checksubsquarecorner
// more intuitive but worse because there is a lot of overhead because it is called several times
// equivalent to the macro version
bool checkSubSquareCorner(int8_t** m,int y,int x,int area,enum Corners corner){
  int i;
  int yAdd= corner==LeftBottom||corner==RightBottom ? area-1 : 0,
    xAdd= corner==RightTop || corner==RightBottom ? area-1 : 0;
  for(i=x;i<x+area;i++)
    if(!m[y+yAdd][i])
      return false;
  for(i=y;i<y+area;i++)
    if(!m[i][x+xAdd])
      return false;
  return true;
}
Square *maxSubSquareBruteForce(int8_t** m,int n){
  int i,j,area;
  bool isAllSet;
  Square *maxSqr=newSquare();
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++){
      if(m[i][j] == 1){
	if(maxSqr->order < 1){
	  maxSqr->order = 1;
	  maxSqr->i=i;
	  maxSqr->j=j;
	}
	for(area = 2;area<=n;area++){
	  
	  if(i <= n-area && j <= n-area){
	    CHECK_SUBSQUARE_CORNER(m,i,j,area,RightBottom,isAllSet);
	    if(!isAllSet)
	      break;
	    if(maxSqr->order < area){
	      maxSqr->order=area;
	      maxSqr->i=i;
	      maxSqr->j=j;
	    }
	  }else
	    break;
	}
      }
    }
  return maxSqr;
}
Square *maxSubSquareBranchnBound(int8_t** m,int n){
  int i,j,area;
  bool isAllSet;
  Square *maxSqr=newSquare();
  for (i = 0; i < n-maxSqr->order; i++)
    for (j = 0; j < n-maxSqr->order; j++)
      if(m[i][j] == 1){
	if(maxSqr->order < 1){
	  maxSqr->order = 1;
	  maxSqr->i=i;
	  maxSqr->j=j;
	}
	for(area = 2;area<=n;area++){
	  if(i <= n-area && j <= n-area){
	    CHECK_SUBSQUARE_CORNER(m,i,j,area,RightBottom,isAllSet);
	    if(!isAllSet)
	      break;
	    if(maxSqr->order < area){
	      maxSqr->order=area;
	      maxSqr->i=i;
	      maxSqr->j=j;
	    }
	}else
	   break;
      }
}
return maxSqr;
}

Square *maxSubSquareDynamic(int8_t **m,int n){
  int i,j;
  Square *maxSqr=newSquare();
  int **table = malloc(sizeof(int*)*n);//dynamic allocation to support large files
  for ( i = 0; i < n ; i++)
    table[i] = malloc(sizeof(int)*n);
  for(i = 0;i < n; i++)// Complete first column and line
  {
    table[i][0] = m[i][0];
    if(table[i][0] == 1){
      maxSqr->order = 1;
      maxSqr->i=i;
      maxSqr->j=0;
    }
    table[0][i] = m[0][i];
    if(table[0][i] == 1){
      maxSqr->order = 1;
      maxSqr->i=0;
      maxSqr->j=i;
    }
  }

  for(i=1;i<n;i++){
    for(j=1;j<n;j++){
      if(m[i][j]==0){
	table[i][j] = 0;
      }else{
	table[i][j]=1+min3(table[i-1][j],table[i-1][j-1],table[i][j-1]);//1 + min of 3
	if(table[i][j] > maxSqr->order){
	  maxSqr->order= table[i][j]; // change max
	  maxSqr->i = i-maxSqr->order+1;
	  maxSqr->j = j-maxSqr->order+1;
	}
      }
    }
  }
  for ( i = 0; i < n ; i++)
    free(table[i]);
  free(table);

  return maxSqr;
}

void subSquarePoint(int8_t **m,int n,Square* maxSqr){
  //Corners of the solution square
  int bestLine=maxSqr->i,
    bestColumn=maxSqr->j,
    right=bestColumn,
    left=bestColumn,
    top=bestLine,
    bottom=bestLine;
  bool moved,isAllSet;
  enum Corners corner=LeftBottom;
  while(corner <= RightBottom){
    moved=false;
    // Do the move
    if(getCellWithCheck(m,n,bestLine,right+1) && getCellWithCheck(m,n,top-1,bestColumn) && corner==RightTop){
      right++;
      top--;
      moved = true;
    }else if(getCellWithCheck(m,n,bestLine,left-1) && getCellWithCheck(m,n,top-1,bestColumn) && corner==LeftTop){
      left--;
      top--;
      moved = true;
    }else if(getCellWithCheck(m,n,bestLine,right+1) && getCellWithCheck(m,n,bottom+1,bestColumn) && corner==RightBottom){
      right++;
      bottom++;
      moved = true;
    }else if(getCellWithCheck(m,n,bestLine,left-1) && getCellWithCheck(m,n,bottom+1,bestColumn) && corner==LeftBottom){
      left--;
      bottom++;
      moved = true;
    }

    if(moved){
      CHECK_SUBSQUARE_CORNER(m,top,left,right-left+1,corner,isAllSet);
      if(isAllSet){
	// include to solution
	maxSqr->order = right-left+1;
	maxSqr->i = top;
	maxSqr->j = left;
      }else{
	// go to next move
	switch(corner)
	{
	case RightTop:
	  right--;
	  top++;
	  break;
	case LeftTop:
	  left++;
	  top++;
	  break;
	case RightBottom:
	  right--;
	  bottom--;
	  break;
	case LeftBottom:
	  left++;
	  bottom--;
	  break;
	}
	corner++;
      }
    }else
      corner++;
  }
}

Square *maxSubSquareGreedy(int8_t **m,int n){
  int i,j,bestLine=0,bestColumn=0,bestLineQnt=0,bestColumnQnt=0;

  int tempQnt=0; // quantity of sequential 1's in lines/columns
  // Get quantity of 1 in lines
  for(i=0;i<n;i++){
    tempQnt=0;
    for(j=0;j<n;j++){
      tempQnt+= m[i][j];
      if(!m[i][j]){
	if(tempQnt>bestLineQnt){
	  bestLineQnt = tempQnt;
	  bestLine = i;
	}
	tempQnt=0;
      }
    }
    if(tempQnt>bestLineQnt){
      bestLineQnt = tempQnt;
      bestLine = i;
    }

    tempQnt=0;
    for(j=0;j<n;j++){
      tempQnt+= m[j][i];
      if(!m[j][i]){
	if(tempQnt>bestColumnQnt){
	  bestColumnQnt = tempQnt;
	  bestColumn = i;
	}
	tempQnt=0;
      }
    }
    if(tempQnt>bestColumnQnt){
      bestColumnQnt = tempQnt;
      bestColumn = i;
    }

  }

  // find max sub square matrix in this line
  Square *maxSqr= newSquare();
  maxSqr->order = m[bestLine][bestColumn];
  maxSqr->i = bestLine;
  maxSqr->j = bestColumn;
  if(m[bestLine][bestColumn])
    subSquarePoint(m,n,maxSqr);
  return maxSqr;
}
