/* LISTA DE ADJACÊNCIAS DE UM GRAFO SIMPLES */
typedef vector<int>vi;
typedef vector<vi>vvi;

vvi LG(MAXV);
/* ---------------------------------------- */

//DFS que retorna a existência de um ciclo em um grafo simples
int temCiclo(int u, int p) { //vértice analisado e quem chamou (parent)
  int i, v;
  vis[u] = 1; //antes de tudo inicializa com 0
  for (i = 0; i < (int)LG[u].size(); i++) {
    v = LG[u][i];
    if (vis[v] && v != p) return 1;
    if (!vis[v] && temCiclo(v, u)) return 1;
  }
  return 0;
}
/* -------------------------------------------------------- */

//Função main para ver se o grafo é uma árvore (ÁRVORE, NÃO FLORESTA!)
int main(void) {
  int n, m, i, u, v, ans;
  scanf("%d %d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &u, &v); u--; v--;
    LG[u].push_back(v);
    LG[v].push_back(u);
  }
  memset(vis, 0, sizeof(vis));
  for (ans = temCiclo(0, 0), i = 0; !ans && i < n; i++)
    ans |= !vis[i];
  printf("%s\n", ans ? "NO" : "YES");
  return 0;
}
/* --------------------------------------------------------------- */
