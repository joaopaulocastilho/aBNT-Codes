#include <stdio.h>
#include <queue>

using namespace std;

typedef struct { int x, y; }coord;

#define MAX 112
#define INF 112345678

int n, m, MA[MAX][MAX];
int dist[MAX][MAX];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };  

int valido(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m && MA[x][y] != 2) return 1;
  return 0;
}

int bfs(coord s) {
  int i, j; coord v, aux;
  queue<coord> q;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) dist[i][j] = INF;
  dist[s.x][s.y] = 0; q.push(s);
  while (!q.empty()) {
    v = q.front(); q.pop();
    for (i = 0; i < 4; i++) {
      if (valido(v.x + dx[i], v.y + dy[i]) && dist[v.x + dx[i]][v.y + dy[i]] == INF) {
	aux.x = v.x + dx[i]; aux.y = v.y + dy[i]; 
	q.push(aux);
	dist[v.x + dx[i]][v.y + dy[i]] = dist[v.x][v.y] + 1;
	if (!MA[v.x + dx[i]][v.y + dy[i]]) return dist[v.x + dx[i]][v.y + dy[i]];
      }
    }
  }
  return -1;
}

int main(void) {
  int i, j;
  coord s;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      scanf("%d", &MA[i][j]);
      if (MA[i][j] == 3) { s.x = i; s.y = j; } 
    }
  printf("%d\n", bfs(s));
  return 0;
}
