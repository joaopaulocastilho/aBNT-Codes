#include <stdio.h>
#include <string.h>

#define MAX 89
#define MAXP 1123

typedef struct { int ra; char name[MAX]; double price, comp; } prop_t;

int main(void) {
  int n, p, i, j, resp, caso = 0; char trash[MAX];
  prop_t ps[MAXP];
  while (scanf("%d %d ", &n, &p), n) {
    caso++;
    for (i = 0; i < n; i++) fgets(trash, MAX, stdin);
    for (resp = i = 0; i < p; i++) {
      fgets(ps[i].name, MAX, stdin);
      ps[i].name[strlen(ps[i].name) - 1] = '\0';
      scanf("%lf %d ", &ps[i].price, &ps[i].ra);
      for (j = 0; j < ps[i].ra; j++) fgets(trash, MAX, stdin);
      if (ps[i].ra > ps[resp].ra) resp = i;
      else if (ps[i].ra == ps[resp].ra && ps[i].price < ps[resp].price)
        resp = i;
    }
    if (caso > 1) printf("\n");
    printf("RFP #%d\n%s\n", caso, ps[resp].name);
  }
  return 0;
}
