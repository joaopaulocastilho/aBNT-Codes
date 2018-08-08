#include <bits/stdc++.h>

#define valido(i, j) (i >= 0 && j >= 0 && i < n && j < n)

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 112;

int dirx[] = {1, 0, -1, 0};
int diry[] = {0, -1, 0, 1};

int n, mina[MAX][MAX], dist[MAX][MAX];

int dijkstra(){
  int i, j, k, d, ni, nj;
  
  priority_queue<iii, vector<iii>, greater<iii> > pq; 
  pq.push(iii(0, ii(0, 0)));
  memset(dist, -1, sizeof(dist));
  while(!pq.empty()){
    i = pq.top().second.first;
    j = pq.top().second.second;
    d = pq.top().first;
    pq.pop();
    if(dist[i][j] != -1) continue;
    dist[i][j] = d;
    for(k = 0; k < 4; k++){
      ni = i + dirx[k]; nj = j + diry[k];
      if(valido(ni, nj) && dist[ni][nj] == -1)
	pq.push(iii(d + mina[ni][nj], ii(ni, nj)));
    }
  }
  return dist[n-1][n-1];
}

int main(void){
  int i, j;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) scanf("%d", &mina[i][j]);
  printf("%d\n", dijkstra());

  return 0;
}
