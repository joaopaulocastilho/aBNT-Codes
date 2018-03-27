#include <stdio.h>
#include <string.h>

#define MAX 112

typedef struct { int f[2], v[2]; }folha_t;

int main(void) {
  int n, i, j, livres, qtd, f_use;
  folha_t folha[MAX];
  while (scanf("%d", &n), n) {
    memset(folha, 0, sizeof(folha));
    for (livres = 0, qtd = n, f_use = 0, i = 1; qtd > livres; i += 2, f_use++) {
      livres += 2;
      folha[f_use].f[1] = i; qtd--;
      if (qtd) {
        folha[f_use].v[0] = i + 1;
        qtd--;
      }
    }
    for (j = f_use - 1; qtd > 0; i += 2, j--) {
      folha[j].v[1] = i; qtd--;
      if (qtd) {
        folha[j].f[0] = i + 1;
        qtd--;
      }
    }
    printf("Printing order for %d pages:\n", n);
    for (i = 0; i < f_use; i++) {
      if (folha[i].f[0] || folha[i].f[1]) {
        printf("Sheet %d, front: ", i + 1);
        if (folha[i].f[0]) printf("%d, ", folha[i].f[0]);
        else printf("Blank, ");
        if (folha[i].f[1]) printf("%d\n", folha[i].f[1]);
        else printf("Blank\n");
      }
      if (folha[i].v[0] || folha[i].v[1]) {
        printf("Sheet %d, back : ", i + 1);
        if (folha[i].v[0]) printf("%d, ", folha[i].v[0]);
        else printf("Blank, ");
        if (folha[i].v[1]) printf("%d\n", folha[i].v[1]);
        else printf("Blank\n");
      }
    }
  }
  return 0;
}
