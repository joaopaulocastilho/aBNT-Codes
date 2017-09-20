#include <stdio.h>
#include <stdlib.h>

#define MAX 112

int cmp(const void* a, const void* b){
  return *(int *)b - *(int *)a;
}

int main(void){
  int n, q, tmp, cida[MAX];

  while(scanf("%d %d", &n, &q) != EOF){
    for(int i = 0; i < n; i++) scanf("%d", &cida[i]);
    qsort(cida, n, sizeof(int), &cmp);

    while(q--){
      scanf("%d", &tmp);
      printf("%d\n", cida[tmp-1]);
    }
  }

  return 0;
}
