#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
using namespace std;

#define MAX 112345
#define INF 1123456789
//#define DEBP

typedef vector<int> vi;
typedef pair<int, int> ii;

int ncomp, d[MAX], low[MAX], seen[MAX], st[MAX], comp[MAX], sn, tempo;
int ld[MAX], lp[MAX], li, vistp[MAX], tp[MAX], itp;

void tarjan(int u, vector<vi> &LG) {
  int i, v;
  st[sn++] = u; seen[u] = 1;
  d[u] = low[u] = tempo++;
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i];
    if (!seen[v]) { tarjan(v, LG); low[u] = min(low[u], low[v]); }
    else { low[u] = min(low[u], d[v]); }
  }
  if (d[u] == low[u]) {
    do { v = st[--sn]; comp[v] = ncomp; d[v] = INF; } while (v != u);
    ncomp++;
    }}

void dfs(int u, vector<vi> &DAG) {
  int i, v;
  vistp[u] = 1;
  for (i = 0; i < (int)DAG[u].size(); i++) {
    v = DAG[u][i];
    if (!vistp[v]) dfs(v, DAG);
  }
  tp[itp--] = u;
}

int main(void) {
  int n, m, a, b, u, i, v, bolada;
  scanf("%d %d", &n, &m);
  vector<vi> LG(n);
  for (u = 0; u < m; u++) {
    scanf ("%d %d", &a, &b); a--; b--;
    LG[a].push_back(b);
  }
  memset(d, 0, sizeof(d)); memset(low, 0, sizeof(low));
  memset(seen, 0, sizeof(seen));
  for (tempo = 1, u = ncomp = sn = 0; u < n; u++)
    if (!d[u]) tarjan(u, LG);
  vector<vi> DAG(ncomp);
  set<ii> LDAG;
  memset(ld, -1, sizeof(ld)); memset(lp, 0, sizeof(lp));
  for (u = 0; u < n; u++)
    for (li = i = 0; i < (int)LG[u].size(); i++) {
      v = LG[u][i];
      if (comp[u] != comp[v] && LDAG.find(ii(comp[u], comp[v])) == LDAG.end()) {
        LDAG.insert(ii(comp[u], comp[v]));
	DAG[comp[u]].push_back(comp[v]);
      }}
  memset(vistp, 0, sizeof(vistp));
  for (itp = ncomp - 1, u = 0; u < ncomp; u++)
    if (!vistp[u]) dfs(u, DAG);
  for (bolada = 1, i = 0; i < ncomp - 1; i++)
    bolada &= (LDAG.find(ii(tp[i], tp[i + 1])) != LDAG.end());
  printf("%sBolada\n", bolada ? "" : "Nao ");
  return 0;
}
