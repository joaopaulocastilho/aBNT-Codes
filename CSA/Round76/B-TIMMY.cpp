#include <cstdio>

#define MAX 800

int h, w, x, y;

int valido(int i, int j){
  if(i < h && i >= x && j < w && j >= y)
    return 1;
  return 0;
}
  
int main(void){
  int A[MAX][MAX], B[MAX][MAX];
  scanf("%d %d %d %d", &h, &w, &x, &y);
  for(int i = 0; i < h+x; i++){
    for(int j = 0; j < w+y; j++){
      scanf("%d", &B[i][j]);
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      A[i][j] = B[i][j] - ((valido(i, j) ? A[i-x][j-y] : 0));
    }
    //printf("\n");
  }
  for(int i = 0;i < h; i++){
    for(int j = 0; j < w; j++)
      printf("%d ", A[i][j]);
    printf("\n");
  } 
  return 0;
}
