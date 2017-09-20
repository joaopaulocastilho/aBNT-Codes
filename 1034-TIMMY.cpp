#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 1123456
#define INF 112345678

int qtd[MAX], a[26], n, m;

int compare(const void* a, const void* b){ return (*(int*)b - *(int*)a); }


int pd(int i, int j){
  if(j < 0 || i >= n || (i == n-1 && j >= a[i-1])) return INF;
  if(qtd[j] != -1) return qtd[j];
  if(j == 0) return 0;
  return qtd[j] = min(pd(i+1, j), pd(i, j-a[i]) +1);
}

int main(void){
  int t;
  scanf("%d", &t);
  while(t--){
    memset(qtd, -1, sizeof(qtd));
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
      scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    printf("%d\n", pd(0, m));
  }
  return 0;
}
