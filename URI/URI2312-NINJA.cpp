#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1123

typedef struct{
  char nome[MAX];
  int ouro, prata, bronze;
}pais_t;

int cmp( const void* a, const void* b){
  pais_t *pa, *pb;
  pa = (pais_t *) a; pb = (pais_t *) b;
  if(pa->ouro != pb->ouro) return pb->ouro - pa->ouro;
  if(pa->prata != pb->prata) return pb->prata - pa->prata;
  if(pa->bronze != pb->bronze) return pb->bronze - pa->bronze;
  else return strcmp(pa->nome, pb->nome);
}

int main(void){
  int n, i;
  pais_t paises[MAX];
  
  scanf("%d ", &n);
  for(i = 0; i < n; i++)
    scanf("%s %d %d %d ", paises[i].nome, &paises[i].ouro, &paises[i].prata, &paises[i].bronze); 
  qsort(paises, n, sizeof(pais_t), &cmp);
  for(i = 0; i < n; i++)
    printf("%s %d %d %d\n", paises[i].nome, paises[i].ouro, paises[i].prata, paises[i].bronze);
  
  return 0;
}
