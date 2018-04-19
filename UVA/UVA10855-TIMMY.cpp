#include <cstdio>

#define MAX 1123

char matrix[MAX][MAX], smatrix[MAX][MAX], rmatrix[MAX][MAX];
int n, N;

void matrixRotate(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      rmatrix[j][(n-1)-i] = smatrix[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      smatrix[i][j] = rmatrix[i][j];
      //printf("%c", smatrix[i][j]);
    }
    //printf("\n");
  }
}

int find(){
  int count = 0, flag;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      flag = 1;
      for(int k = 0; k < n; k++){
	for(int l = 0; l < n; l++){
	  if(matrix[i+k][j+l] != smatrix[k][l]) flag = 0;
	}
      }
      if(flag) count++;
    }
  }
  return count;
}

int main(void){
  int r1, r2, r3, r4;
  while(scanf("%d%d", &N, &n), N+n != 0){
    for(int i = 0; i < N; i++){
      getchar();
      for(int j = 0; j < N; j++){
	scanf("%c", &matrix[i][j]);
      }
    }
    for(int i = 0; i < n; i++){
      getchar();
      for(int j = 0; j < n; j++){
	scanf("%c", &smatrix[i][j]);
      }
    }  
#ifdef DEBUG
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
	printf("%c", matrix[i][j]);
      }
      printf("\n");
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
	printf("%c", smatrix[i][j]);
      }
      printf("\n");
    }
#endif
    r1 = find();
    matrixRotate();
    r2 = find();
    matrixRotate();
    r3 = find();
    matrixRotate();
    r4 = find();
    printf("%d %d %d %d\n", r1, r2, r3, r4);
  }
  return 0;
}
