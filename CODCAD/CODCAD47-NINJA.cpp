#include <stdio.h>
#include <stdlib.h>

#define MAX 112345

int n, m;

int cmp(const void *a, const void *b){
  int ai = *(int*)a;
  int bi = *(int*)b;
  if(ai % m > bi % m) return -1;
  else if(ai % m < bi % m) return 1;
  else if(ai/m > bi/m) return -1;
  else if(ai/m < bi/m) return 1;
  else return 0;
}

int main(void){
  int i, prop[MAX];

  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++) scanf("%d", &prop[i]);

  qsort(prop, n, sizeof(int), &cmp);
  for(i = 0; i < n; i++)
    printf("%s%d", i ? " " : "", prop[i]);
  printf("\n");
  
  return 0;
}
