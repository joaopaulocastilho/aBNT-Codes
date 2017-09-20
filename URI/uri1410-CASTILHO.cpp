#include <stdio.h>
#include <stdlib.h>

#define INF 11234

int cmp(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

int main(void){
  int A, D, b, v[15], mea, cont;
  while(scanf("%d%d", &A, &D), A && D){
    mea=INF;
    cont=0;
    while(A--){
      scanf("%d", &b);
      if(b<mea) mea=b;
    }
    while(D--) scanf("%d", &v[cont++]);
    qsort(v, cont, sizeof(int), &cmp);
    printf("%c\n", (v[0]<=mea && v[1]<=mea) ? 'N' : 'Y');
  }
  return 0;
}
