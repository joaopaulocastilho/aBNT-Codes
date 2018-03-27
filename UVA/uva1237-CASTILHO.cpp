#include <stdio.h>

#define MAX 11234

typedef struct { char marca[31]; int l, h; }car_t;

int main(void) {
  int casos, q, qtd, ind, cq, d, i, j;
  car_t v[MAX];
  scanf("%d", &casos);
  while (casos--) {
    scanf("%d", &d);
    for (i = 0; i < d; i++)
      scanf(" %s %d %d", v[i].marca, &v[i].l, &v[i].h);
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
      scanf("%d", &cq);
      for (qtd = 0, j = 0; j < d; j++)
        if (v[j].l <= cq && v[j].h >= cq) { qtd++; ind = j; }
      printf("%s\n", (qtd == 1) ? v[ind].marca : "UNDETERMINED");
    }
    if (casos) printf("\n");
  }
  return 0;
}
