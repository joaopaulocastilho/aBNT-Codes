#include <cstdio>
#include <cstring>

#define MAX 112
//#define DEBUG

char matrix[MAX][MAX][2];
int it;
int bound(int i, int j, int m, int n){
  if(i >= 0 && i < m && j >= 0 && j < n) return 1;
  return 0;
}

char fight(int di, int dj, int ai, int aj, int m){
  if(matrix[di][dj][m] == 'R'){
    if(matrix[ai][aj][m] == 'R'){ return 'L'; }
    if(matrix[ai][aj][m] == 'P'){ return 'W'; }
    if(matrix[ai][aj][m] == 'S'){ return 'L'; }
  }
  else if(matrix[di][dj][m] == 'P'){
    if(matrix[ai][aj][m] == 'R'){ return 'L'; }
    if(matrix[ai][aj][m] == 'P'){ return 'L'; }
    if(matrix[ai][aj][m] == 'S'){ return 'W'; }
  }
  else{
    if(matrix[ai][aj][m] == 'R'){ return 'W'; }
    if(matrix[ai][aj][m] == 'P'){ return 'L'; }
    if(matrix[ai][aj][m] == 'S'){ return 'L'; }
  }
  return 'a';
}

int main(void){
  int m, n, d, tc;
  int changed[MAX][MAX];
  scanf("%d", &tc);
  while(tc--){
    it = 0;
    scanf("%d %d %d", &m, &n, &d);
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++)
	scanf(" %c", &matrix[i][j][it]);
    }
    while(d--){
      memset(changed, 0, sizeof(changed));
      it = (it + 1) % 2;
      for(int i = 0; i < m; i++){
	for(int j = 0; j < n; j++){
	  if(bound(i+1, j, m, n)){
	    if(fight(i+1, j, i, j, (it+1)%2) == 'W'){ matrix[i+1][j][it] = matrix[i][j][(it+1) % 2]; changed[i+1][j] = 1; }
	    else if(!changed[i+1][j]) matrix[i+1][j][it] = matrix[i+1][j][(it+1)%2];
	  }
	  if(bound(i-1, j, m, n)){
	    if(fight(i-1, j, i, j, (it+1)%2) == 'W'){ matrix[i-1][j][it] = matrix[i][j][(it+1) % 2]; changed[i-1][j] = 1; }
	    else if(!changed[i-1][j]) matrix[i-1][j][it] = matrix[i-1][j][(it+1)%2];
	  }
	  if(bound(i, j+1, m, n)){
	    if(fight(i, j+1, i, j, (it+1)%2) == 'W'){ matrix[i][j+1][it] = matrix[i][j][(it+1) % 2]; changed[i][j+1] = 1; }
	    else if(!changed[i][j+1]) matrix[i][j+1][it] = matrix[i][j+1][(it+1)%2];
	  }
	  if(bound(i, j-1, m, n)){
	    if(fight(i, j-1, i, j, (it+1)%2) == 'W'){ matrix[i][j-1][it] = matrix[i][j][(it+1) % 2]; changed[i][j-1] = 1; }
	    else if(!changed[i][j-1]) matrix[i][j-1][it] = matrix[i][j-1][(it+1)%2];
	  }
	}
      }
#ifdef DEBUG
      for(int i = 0; i < m; i++){
	for(int j = 0; j < n; j++)
	  printf("%c", matrix[i][j][it]);
	printf("\n");
      }
      printf("\n");
#endif
    }
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
	printf("%c", matrix[i][j][it]);
      }
      printf("\n");
    }
    if(tc >= 1) printf("\n");
  }
  return 0;
}
