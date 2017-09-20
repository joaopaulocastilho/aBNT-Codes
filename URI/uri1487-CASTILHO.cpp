#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAX 112

typedef struct{ int d, p; }bri;

int n;
bri li[MAX];

int cmp(const void *a, const void *b){
  bri *l1 = (bri*)a, *l2 = (bri*)b;
  if(l2->p == l1->p) return l1->d - l2->d;
  return l2->p - l1->p;
}

int tot(int i, int t){
  int ttot, mult;
  if(i==n) return 0;
  if(li[i].d>t) return tot(i+1, t);
  mult = t/li[i].d;
  ttot = mult*li[i].d;
  return max(mult*li[i].p+tot(i+1, t-ttot), tot(i+1, t));
}

int main(void){
  int t, i, j=1, first=1;
  while(scanf("%d %d", &n, &t), n){
    //first ? first=0 : printf("\n");
    for(i=0; i<n; i++) scanf("%d %d", &li[i].d, &li[i].p);
    qsort(li, n, sizeof(bri), &cmp);
    printf("Instancia %d\n%d\n\n", j, tot(0, t));
    j++;
  }
  return 0;
}
