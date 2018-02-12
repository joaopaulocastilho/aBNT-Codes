#include <stdio.h>

int main(void) {
  int ins, aa, da, la, ab, db, lb, bonus, va, vb;
  scanf("%d", &ins);
  while (ins--) {
    scanf("%d", &bonus);
    scanf("%d %d %d", &aa, &da, &la);
    scanf("%d %d %d", &ab, &db, &lb);
    va = (aa + da) / 2;
    if (!(la & 1)) va += bonus;
    vb = (ab + db) / 2;
    if (!(lb & 1)) vb += bonus;
    if (va == vb) printf("Empate\n");
    else if (va > vb) printf("Dabriel\n");
    else printf("Guarte\n");
  }
  return 0;
}
