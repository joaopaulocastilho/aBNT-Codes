#include<stdio.h>

#define MAX 1123

typedef struct { int f, val; }ads;

int main(void) {
  int k, n, v, i, j, a1, a2, c, resp;
  ads prop[MAX];
  scanf("%d", &k);
  for (i = 1; i <= k; i++) {
    scanf("%d %d", &n, &v); resp = 0;
    for (j = 1; j <= n; j++) scanf("%d %d", &prop[j].f, &prop[j].val);
    for (j = 0; j < v; j++) {
      scanf("%d %d %d", &a1, &a2, &c);
      if (prop[a1].f || c == 1) resp += prop[a1].val;
      if (prop[a2].f || c == 2) resp += prop[a2].val;
    }
    printf("Data Set %d:\n%d\n\n", i, resp);
  }
  return 0;
}
