#include<stdio.h>
#include<string.h>

#define MAXC 1123
#define MAXN 11234

typedef struct { int pos, tam; }car;

int main(void) {
  int c, n, es[MAXC], p; car placas[MAXN];
  char op;
  memset(es, 0, sizeof(es)); memset(placas, 0, sizeof(placas));
  scanf("%d %d", &c, &n);
  while (n--) {
    scanf(" %c", &op);
    scanf("%d", p);
    switch (op) {
    case 'C':
      scanf("%d", &placas[p].tam);
      placas[p].pos = acha_livre(placas[p].tam);
      break;
    case 'S':



    }
  }
  return 0;
}
