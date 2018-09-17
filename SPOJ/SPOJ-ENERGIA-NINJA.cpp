#include <bits/stdc++.h>

using namespace std;

const int MAX = 112;

vector<int> AL[MAX];
int visNum, vis[MAX];

void bfs(int s){
  int i, u;
  queue<int> q;

  memset(vis, 0, sizeof(vis));
  q.push(s);
  while(!q.empty()){
    u = q.front();
    q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    visNum++;
    for(i = 0; i < AL[u].size(); i++)
      if(!vis[AL[u][i]]) q.push(AL[u][i]);
  }
}

int main(void){
  int i, n, m, u, v, teste = 1;

  while(scanf("%d %d", &n, &m), n){
    for(i = 0; i < MAX; i++) AL[i].clear();
    visNum = 0;
    
    for(i = 0; i < m; i++){
      scanf("%d %d", &u, &v); u--; v--;
      AL[u].push_back(v);
      AL[v].push_back(u);
    }
    bfs(0);
    printf("Teste %d\n", teste++);
    if(visNum == n) printf("normal\n\n");
    else printf("falha\n\n");
  }

  return 0;
}
