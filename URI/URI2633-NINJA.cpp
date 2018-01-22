#include <stdio.h>
#include <stdlib.h>

#define MAX 112

typedef struct {
  char nome[MAX];
  int validade;
}carne_t;

int cmp(const void* a, const void* b){
  return ((carne_t*)a)->validade - ((carne_t*)b)->validade;
}

int main(void){
  int i, n;
  carne_t carnes[MAX];
  
  while(scanf("%d ", &n) != EOF){
    for(i = 0; i < n; i++)
      scanf("%s %d ", carnes[i].nome, &carnes[i].validade);
    qsort(carnes, n, sizeof(carne_t), &cmp);
    for(i = 0; i < n; i++) printf("%s%s", i ? " " : "", carnes[i].nome);
    printf("\n");
  }

  return 0;
}
