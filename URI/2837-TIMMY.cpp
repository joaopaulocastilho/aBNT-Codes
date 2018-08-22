#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;
const int MAXI = 60;
const int INF = 1123456789;

int v[MAXV], vis[MAXV][MAXI], memo[MAXV][MAXI], m[MAXV];
int n, l, h;

int pd(int idx, int qtd){
  if(qtd > h) return -INF;
  if(idx >= n){
    if(qtd < l) return -INF;
    return 0;
  }

  if(vis[idx][qtd] != -1) return memo[idx][qtd];

  if(qtd >= l)
    memo[idx][qtd] = max( pd(idx+1, qtd+(m[idx] == 1))+v[idx], 0);
  else
    memo[idx][qtd] = pd(idx+1, qtd+(m[idx] == 1))+v[idx];
  vis[idx][qtd] = 1;
  //cout << memo[idx][qtd] << endl;
  return memo[idx][qtd];
}

int main(void){
  cin >> n >> l >> h;
  int ans = -INF;
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) cin >> m[i];
  memset(vis, -1, sizeof(vis));
  for(int i = 0; i < n; i++){
    ans = max(ans, pd(i, 0));
  }

  cout << ans << endl;
  return 0;
}
