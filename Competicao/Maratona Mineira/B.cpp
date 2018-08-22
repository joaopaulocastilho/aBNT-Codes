#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 5123
#define INF 112345678
int adj[MAX][MAX];
int preco[MAX], qtd[MAX], visitado[MAX];
int n, d;
int memo[MAX][MAX];

int dfs(int x, int y, int l){
  int atingiu = 0;
  visitado[x] = 1;
  if(x == y){
    qtd[x] += l;
    return 1;
  }
  for(int i = 0; i < n && !atingiu; i++){
    if(adj[x][i] == 1 && !visitado[i]){
      atingiu = atingiu || dfs(i, y, l);
    }
  }
  if(atingiu){  qtd[x] += l; }
  return atingiu;
}

int pd(int i, int grana){
  if(i == n) return 0;
  if(memo[i][grana] != -INF) return memo[i][grana];
  if(grana + preco[i] > d || preco[i] == 0)
    return memo[i][grana] = pd(i + 1, grana);
  return memo[i][grana] =
    max(pd(i+1, grana + preco[i]) + qtd[i], pd(i+1, grana));
}

int main(void){
  cin >> n >> d;
  memset(adj, -1, sizeof(adj));
  memset(preco, 0, sizeof(preco));
  memset(qtd, 0, sizeof(qtd));
  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }
  /*
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << (adj[i][j] == -1 ? 0 : 1) << " ";
    }
    cout << endl;
  }
  */
  int m; cin >> m;
  for(int i = 0; i < m; i++){
    int c, v; cin >> c >> v;
    c--;
    preco[c] = v;
  }
  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int x, y, l; cin >> x >> y >> l;
    x--; y--;
    memset(visitado, 0, sizeof(visitado));
    dfs(x, y, l);
  }

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n ; j++)
      memo[i][j] = -INF;
  long long int ans = 0;
  ans = pd(0, 0);
  cout << ans << endl;
  return 0;
}
