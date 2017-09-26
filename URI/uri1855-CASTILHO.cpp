#include<stdio.h>
#include<string.h>

#define MAX 112
#define valida(x, y) ((x) > 0) || ( (x) < (y))

int n, m, vis[MAX][MAX], resp;
char MA[MAX][MAX];

void dfs(int u, int v, int x, int y) {
  if (!valida(u, m) || !valida(v, n)) return;
  if (vis[u][v]) return;
  if (MA[u][v] == '*') resp = 1;
  vis[u][v] = 1;
  if (MA[u][v] == '>') { x = 1; y = 0; }
  else if (MA[u][v] == '<') { x = -1; y = 0; }
  else if (MA[u][v] == 'v') { x = 0; y = 1; }
  else if (MA[u][v] == '^') { x = 0; y = -1; }
  dfs(u + x, v + y, x, y);
}

int main(void) {
  int i;
  scanf("%d %d ", &n, &m);
  for (i = 0; i < m; i++) {
    fgets(MA[i], MAX, stdin);
    MA[i][strlen(MA[i]) - 1] = '\0';
  }
  resp = 0; memset(vis, 0, sizeof(vis));
  dfs(0, 0, 0, 0);
  printf("%c\n", resp ? '*' : '!');
  return 0;
}
