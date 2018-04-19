#include <cstdio>

#define MAX 11
#define DEBUG

typedef struct{
  int x, y;
} coord;

int m[MAX][MAX];
coord cd[MAX];

int main(void){
  int sz, tc; 
  scanf("%d", &tc);
  while(tc--){
    scanf("%d", &sz);
    for(int i = 0; i < sz; i++){
      for(int j = 0; j < sz; j++){
	scanf("%d", &m[i][j]);
      }
    }
#ifdef DEBUG
    for(int i = 0; i < sz; i++){
      for(int j = 0; j < sz; j++){
	printf("%d ", m[i][j]);
      }
      printf("\n");
    }
#endif
    do{
      for(int i = 0; i < sz; i++){
	for(int j = 0; j < sz; j++){
	  if(matrix[i][j] < colmin){
	    colmin = matrix[i][j];
	    cd.x = i; cd.y = j;
	  }
	}
	if(colmin > linemax){
	  linemax = colmin;
	  maxcd.x = cd.x; maxcd.y = cd.y;
	}
      }

    }
    
  }
  return 0;
}
