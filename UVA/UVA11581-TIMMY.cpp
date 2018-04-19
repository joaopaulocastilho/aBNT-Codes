#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAX 5

int matrix[MAX][MAX], auxmatrix[MAX][MAX];

int confere(){
  int flag = 1;
  for(int i = 0; i < 3 && flag; i++)
    for(int j = 0; j < 3 && flag; j++)
      if(matrix[i][j] == 1) flag = 0;
  return flag;
}

int verifica(int i, int j){
  if(i >= 0 && i < 3 && j >= 0 && j < 3)
    return matrix[i][j];
  return 0;
}

void funcao(){
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      auxmatrix[i][j] = (verifica(i+1, j) + verifica(i-1, j) + verifica(i, j+1) + verifica(i, j-1))%2;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      matrix[i][j] = auxmatrix[i][j];
}

int main(void){
  int tc, count;
  char cmatrix[MAX][MAX];
  scanf("%d ", &tc);
  while(tc--){
    count = -1;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
	scanf(" %c", &cmatrix[i][j]);
	matrix[i][j] = cmatrix[i][j] - '0';
      }
    }
    while(!confere()){
      funcao();
      count++;
    }
    printf("%d\n", count);
  }

  return 0;
}
