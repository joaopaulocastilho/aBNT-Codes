#include <bits/stdc++.h>

#define valido(i, j) (i) >= 0 && (j) >= 0 && (i) < n && (j) < n

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int MAXV = 21;
const int INF = 112345678;

int n, city[MAXV][MAXV][4];
int diry[] = {1, -1, 0, 0};
int dirx[] = {0, 0, -1, 1};

int bfs(int i1, int j1, int i2, int j2){
  int i, j, k, d, ni, nj, dist[MAXV][MAXV];
  queue<iii> q;

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) dist[i][j] = INF;
  q.push(iii(ii(i1, j1), 0));
  while(!q.empty()){
    i = q.front().first.first;
    j = q.front().first.second;
    d = q.front().second;
    //printf("%d %d %d\n", i, j, d);
    q.pop();
    if(dist[i][j] != INF) continue;
    dist[i][j] = d;
    for(k = 0; k < 4; k++){
      ni = i + diry[k]; nj = j + dirx[k];
      //printf("-> %d,%d -> %d\n", ni, nj, city[i][j][k]);
      if(valido(ni, nj) && dist[ni][nj] == INF && city[i][j][k])
	q.push(iii(ii(ni, nj), d+1));
    }
  }
  return dist[i2][j2];
}

int main(void){
  int q, i, j, k, i1, j1, i2, j2, ans;
  
  while(scanf("%d", &n), n){
    memset(city, 0, sizeof(city));
    for(i = n-1; i >= 0; i--)
      for(j = 0; j < n; j++)
	for(k = 0; k < 4; k++)
	  scanf("%d", &city[i][j][k]);
    scanf("%d", &q);
    while(q--){
      scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
      ans = bfs(j1, i1, j2, i2);
      if(ans == INF) printf("Impossible\n");
      else printf("%d\n", ans);
    }
    printf("\n");
  }
  return 0;
}
