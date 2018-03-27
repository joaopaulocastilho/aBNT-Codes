#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAXV 25
#define MAXM 11
#define INF 412345678

struct coord_t{ int x, y; coord_t() {}
  coord_t(int _x, int _y): x(_x), y(_y) {} };

int g[MAXM][MAXM], mapam[MAXM][MAXM];
coord_t mapav[MAXV];

int dist_euc(int x1, int y1, int x2, int y2) {
  return (abs(x1 - x2) + abs(y1 - y2));
}

int calc_dist(int o[5]) {
  int i, j, k, ret, mind;
  for (ret = 0, i = 0; i < 5; i++)
    for (j = 0; j < 5; j++) {
      if (!g[i][j]) continue;
      for (mind = INF, k = 0; k < 5; k++)
	mind = min(mind, dist_euc(i, j, mapav[o[k]].x, mapav[o[k]].y) * g[i][j]);
      ret += mind;
    }
  return ret;
}

int main(void) {
  int t, ne, x, y, qtd, it[5], i, k, j, aux, dist, v[5];
  scanf("%d", &t);
  for (k = i = 0; i < 5; i++)
    for (j = 0; j < 5; j++) {
      mapav[k] = coord_t(i, j);
      mapam[i][j] = k++;
    }
  while (t--) {
    scanf("%d", &ne);
    memset(g, 0, sizeof(g));
    for (i = 0; i < ne; i++) {
      scanf("%d %d %d", &x, &y, &qtd);
      g[x][y] = qtd;
    }
    dist = INF;
    for (it[0] = 0; it[0] < MAXV - 4; it[0]++)
      for (it[1] = it[0] + 1; it[1] < MAXV - 3; it[1]++)
	for (it[2] = it[1] + 1; it[2] < MAXV - 2; it[2]++)
	  for (it[3] = it[2] + 1; it[3] < MAXV - 1; it[3]++)
	    for (it[4] = it[3] + 1; it[4] < MAXV; it[4]++)
	      if ((aux = calc_dist(it)) < dist) {
		dist = aux;
		for (i = 0; i < 5; i++) v[i] = it[i]; 
	      }
    for (i = 0; i < 5; i++) {
      if (i) printf(" ");
      printf("%d", v[i]);
    }
    printf("\n");
  }
  return 0;
}
