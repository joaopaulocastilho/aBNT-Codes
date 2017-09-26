#include<stdio.h>
#include<string.h>

#define MAX 512

typedef struct { int v, esq, dir; }arv_t;

int prox;
arv_t arvore[MAX];

void inicializa() {
  int i;
  for (i = 0; i < MAX; i++) {
    arvore[i].v = -1;
    arvore[i].dir = arvore[i].esq = 0;
  }
}

void insere(int n) {
  int i;
  for (i = 1; arvore[i].v != -1; ) {
    if (n > arvore[i].v) {
      if (!arvore[i].dir) arvore[i].dir = ++prox;
      i = arvore[i].dir;
    } else {
      if (!arvore[i].esq) arvore[i].esq = ++prox;
      i = arvore[i].esq;
    }
  }
  arvore[i].v = n;
}

void pre_order(int n) {
  if (arvore[n].v == -1) return;
  printf(" %d", arvore[n].v);
  if (arvore[n].esq) pre_order(arvore[n].esq);
  if (arvore[n].dir) pre_order(arvore[n].dir);
}

void in_order(int n) {
  if (arvore[n].v == -1) return;
  if (arvore[n].esq) in_order(arvore[n].esq);
  printf(" %d", arvore[n].v);
  if (arvore[n].dir) in_order(arvore[n].dir);
}

void post_order(int n) {
  if (arvore[n].v == -1) return;
  if (arvore[n].esq) post_order(arvore[n].esq);
  if (arvore[n].dir) post_order(arvore[n].dir);
  printf(" %d", arvore[n].v);
}

int main(void) {
  int c, n, caso, i, val;
  scanf("%d", &c);
  for (caso = 1; caso <= c; caso++) {
    scanf("%d", &n); inicializa();
    for (prox = 1, i = 0; i < n; i++) { scanf("%d", &val); insere(val); }
    printf("Case %d:\n", caso);
    printf("Pre.:"); pre_order(1);
    printf("\nIn..:"); in_order(1);
    printf("\nPost:"); post_order(1);
    printf("\n\n");
  }
  return 0;
}
