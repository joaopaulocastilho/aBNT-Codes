#include <bits/stdc++.h>

#define valido(i, j) (i >= 0 && j >= 0 && i < row && j < col)

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAXT = 1123456;
const int MAX  = 512;
const int INF = 112345678;

int row, col, island[MAX][MAX], vis[MAX][MAX];

int dirx[] = {1, 0, -1, 0};
int diry[] = {0, -1, 0, 1};

void bfs(int i, int j, int t){
  int k, ni, nj;
  
  queue<iii> q;
  memset(vis, 0, sizeof(vis));
  if(t < island[i][j]) q.push(iii(ii(i, j), t));
  while(!q.empty()){
    i = q.front().first.first;
    j = q.front().first.second;
    t = q.front().second;
    q.pop();
    if(vis[i][j]) continue;
    vis[i][j] = 1;
    for(k = 0; k < 4; k++){
      ni = i + dirx[k]; nj = j + diry[k];
      if(valido(ni, nj)  && island[ni][nj] > t+1)
	q.push(iii(ii(ni, nj), t+1));
    }
  }
}

void dfs(int i, int j, int t){
  int ni, nj, k;

  vis[i][j] = 1;
  for(k = 0; k < 4; k++){
    ni = i + dirx[k]; nj = j + diry[k];
    if(valido(ni, nj) && !vis[ni][nj] && island[ni][nj] > t+1)
      dfs(ni, nj, t+1);
  }
}

int bbin(int l, int r){
  int m, ans = -INF;

  while(l <= r){
    m = (l+r)/2;
    //bfs(0, 0, m);
    memset(vis, 0, sizeof(vis));
    dfs(0, 0, m);
    if(vis[row-1][col-1]){
      ans = max(ans, m);
      l = m+1;
    }
    else r = m-1;
  }
  return ans == -INF ? -1 : ans;
}

int main(void){
  int i, j;
  
  scanf("%d %d", &row, &col);
  for(i = 0; i < row; i++)
    for(j = 0; j < col; j++)
      scanf("%d", &island[i][j]);
  printf("%d\n", bbin(0, MAXT));

  return 0;
}
