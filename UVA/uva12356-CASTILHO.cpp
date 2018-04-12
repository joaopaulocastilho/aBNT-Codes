#include <stdio.h>
#include <string.h>

#define MAX 112345

typedef struct { int esq, dir; }soldado;

int main(void) {
  int s, b, i, e, d;
  soldado sol[MAX];
  while (scanf("%d %d", &s, &b), s) {
    memset(sol, -1, sizeof(sol));
    for (i = 0; i < s; i++) { sol[i].esq = i - 1; sol[i].dir = i + 1; }
    sol[i - 1].dir = -1;
    while (b--) {
      scanf("%d %d", &e, &d); e--; d--;
      if (sol[e].esq != -1) printf("%d ", sol[e].esq + 1);
      else printf("* ");
      if (sol[d].dir != -1) printf("%d\n", sol[d].dir + 1);
      else printf("*\n");
      if (sol[e].esq != -1) sol[sol[e].esq].dir = sol[d].dir;
      if (sol[d].dir != -1) sol[sol[d].dir].esq = sol[e].esq;
    }
    printf("-\n");
  }
  return 0;
}
