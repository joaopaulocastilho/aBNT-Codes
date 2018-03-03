#include <cstdio>
#include <cstring>

#define MAX 112

int bound(int i, int j, int m, int n){
  if(i >= 0 && i < m && j >= 0 && j < n)
    return 1;
  return 0;
}

int main(void){
  char matrix[MAX][MAX];
  int m, n, nmatrix[MAX][MAX], count = 1;
  while(scanf("%d %d", &m, &n), m != 0){
    if(count > 1) printf("\n");
    printf("Field #%d:\n", count++);
    memset(matrix, 0, sizeof(matrix));
    memset(nmatrix, 0, sizeof(nmatrix));
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
	scanf(" %c", &matrix[i][j]);
    /*
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++)
	printf("%c", matrix[i][j]);
      printf("\n");
    }
    */	       
    for(int i = 0 ; i < m; i++)
      for(int j = 0; j < n; j++)
	if(matrix[i][j] == '*'){
	  for(int k = j-1; k <= j+1; k++){
	    if(bound(i-1, k, m, n)) nmatrix[i-1][k]++;
	    if(bound(i+1, k, m, n)) nmatrix[i+1][k]++;
	  }
	  if(bound(i, j-1, m, n)) nmatrix[i][j-1]++;
	  if(bound(i, j+1, m, n)) nmatrix[i][j+1]++;
	}
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++)
	if(matrix[i][j] == '*') printf("*");
	else printf("%d", nmatrix[i][j]);
      printf("\n");
    }
  }
  return 0;
}
