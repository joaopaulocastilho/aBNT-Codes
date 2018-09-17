#include <bits/stdc++.h>

using namespace std;

const int MAX = 11234;

int n, m, visNum = 0, vis[MAX];
vector<int> AL[MAX];

void dfs(int u){
  int i;
  
  vis[u] = 1;
  visNum++;
  for(i = 0; i < AL[u].size(); i++)
    if(!vis[AL[u][i]]) dfs(AL[u][i]);
}

int main(void){
  int i, u, v;

  memset(vis, 0, sizeof(vis));
  scanf("%d %d", &n, &m);
  for(i = 0; i < m; i++){
    scanf("%d %d", &u, &v); u--; v--;
    AL[u].push_back(v);
    AL[v].push_back(u);
  }
  dfs(0);
  
  printf("%s\n", m == n-1 && visNum == n ? "YES" : "NO");

  return 0;
}
