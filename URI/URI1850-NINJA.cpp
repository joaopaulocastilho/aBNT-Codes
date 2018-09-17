#include <bits/stdc++.h>

#define valido(i, j) (i >= 0 && j >= 0 && i < n && j < m && lab[i][j] != '#')

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iv;

const int INF = 112345678;
const int MAXN = 112;
const int MAXB = 256;

int n, m;
int dist[MAXN][MAXN][MAXB];
char lab[MAXN][MAXN];

int diri[] = {0, -1, 0, 1};
int dirj[] = {1, 0, -1, 0};

int bfs(int si, int sj, int di, int dj){
  int i, j, k, b, d, ni, nj, gotKey;
  queue<iv> q;
  
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
      for(k = 0; k < MAXB; k++) dist[i][j][k] = INF;
  q.push(iv(ii(si, sj), ii(0, 0)));
  while(!q.empty()){
    i = q.front().first.first;
    j = q.front().first.second;
    b = q.front().second.first;
    d = q.front().second.second;
    q.pop();
    if(dist[i][j][b] != INF) continue;
    dist[i][j][b] = d;
    if(i == di && j == dj) return dist[di][dj][b];
    if(lab[i][j] >= 'a' && lab[i][j] <= 'g') b |= 1 << (lab[i][j] - 'a');
    for(k = 0; k < 4; k++){
      ni = i + diri[k]; nj = j + dirj[k];
      if(valido(ni, nj) && dist[ni][nj][b] == INF){
	if(lab[ni][nj] >= 'A' && lab[ni][nj] <= 'G'){
	  gotKey = 1 & (b >> (lab[ni][nj] - 'A'));
	  if(gotKey) q.push(iv(ii(ni, nj), ii(b, d+1)));
	}
	else q.push(iv(ii(ni, nj), ii(b, d+1)));
      }
    }
  }
  return INF;
}

int main(void){
  int i = 0, j, si, sj, di, dj, ans;
  
  while(scanf("%s", lab[i++]) != EOF) n++; 
  m = strlen(lab[0]);
  si = sj = di = dj = 0;
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
      if(lab[i][j] == '@'){ si = i; sj = j; }
      else if(lab[i][j] == '*') { di = i; dj = j; }
  //printf("aiaiai\n");
  ans = bfs(si, sj, di, dj);
  if(ans == INF) printf("--\n");
  else printf("%d\n", ans);
  return 0;
}
