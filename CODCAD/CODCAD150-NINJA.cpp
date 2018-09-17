#include <bits/stdc++.h>

#define valido(i, j) (i >= 0 && i < n && j >= 0 && j < m)

const int MAX = 1123;

int mapa[MAX][MAX];

int dirx[] = {1, 0, -1, 0};
int diry[] = {0, -1, 0, 1};

int main(void){
  int n, m, i, j, k, ni, nj, ans, flag;
  char c;
  
  scanf("%d %d ", &n, &m);
  //getchar();
  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      scanf("%c", &c);
      mapa[i][j] = c == '.' ? 0 : 1;
    }
    getchar();
  }
  for(ans = i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      if(mapa[i][j] == 0) continue;
      for(flag = 0, k = 0; k < 4; k++){
	ni = i + dirx[k]; nj = j + diry[k];
	if(!valido(ni, nj) || mapa[ni][nj] == 0) flag = 1;
      }
      ans += flag;
    }
  }
  printf("%d\n", ans);
  
  return 0;
}
