#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define MAX 112
#define MAXE 11234

typedef vector< vector<int> > vvi;

int LG[MAX][MAXE], dg[MAX], ok[MAX], vis[MAX];
int m, n, comp_vert[MAX], cor[MAX];
vector<int>tmp;

void bcomp(int u, vvi &comp, int id) {
  int i;
  if (vis[u]) return;
  comp_vert[u] = id; vis[u] = 1;
  comp[id].push_back(u);
  for (i = 0; i < dg[u]; i++) bcomp(LG[u][i], comp, id);
}

int viz_ok(int u) {
  int i;
  for (i = 0; i < dg[u]; i++)
    if (cor[LG[u][i]]) return 0;
  return 1;
}

void bt(int u, vector<int>&s, int com) {
  int i, j;
  if (s.size() > tmp.size()) {
    tmp.clear();
    for (i = 0; i < (int)s.size(); i++)
      tmp.push_back(s[i]);
  }
  for (i = 0; i < n; i++) {
    if (viz_ok(i) && ok[i] && comp_vert[i] == com) {
      ok[i] = 0; cor[i] = 1;
      for (j = 0; j < dg[i]; j++) ok[LG[i][j]] = 0;
      s.push_back(i);
      bt(i, s, com);
      s.pop_back(); cor[i] = 0;
      for (j = 0; j < dg[i]; j++) ok[LG[i][j]] = 1;
      ok[i] = 1;
    }}}

int main(void) {
  int i, u, v, j, k, casos, ncomp;
  scanf("%d", &casos);
  while (casos--) {
    scanf("%d %d", &n, &m);
    memset(dg, 0, sizeof(dg));
    for (i = 0; i < m; i++) {
      scanf("%d %d", &u, &v); u--; v--;
      LG[u][dg[u]++] = v;
      LG[v][dg[v]++] = u;
    }
    vvi comp(n);
    memset(vis, 0, sizeof(vis));
    for (ncomp = i = 0; i < n; i++)
      if (!vis[i]) bcomp(i, comp, ncomp++);
    vector<int>resp;
    for (i = 0; i < ncomp; i++) {
      for (j = 0; j < n; j++) ok[j] = 1;
      memset(cor, 0, sizeof(cor));
      tmp.clear();
      vector<int>s;
      bt(0, s, i);
      for (k = 0; k < (int)tmp.size(); k++) {
        resp.push_back(tmp[k]);
      }
    }
    printf("%d\n", (int)resp.size());
    for (i = 0; i < (int)resp.size(); i++) {
      if (i) printf(" ");
      printf("%d", resp[i] + 1);
    }
    printf("\n");
  }
  return 0;
}
