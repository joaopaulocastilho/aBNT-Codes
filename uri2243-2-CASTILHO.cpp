#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 51234

int main(void) {
  int n, muro[MAX], i, j, esq[MAX], dir[MAX], resp;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &muro[i]);
  esq[0] = dir[n - 1] = 1;
  for (i = 0, j = n - 1; i < n - 1; i++, j--) {
    esq[i + 1] = min(esq[i] + 1, muro[i + 1]);
    dir[j - 1] = min(dir[j] + 1, muro[j - 1]);
  }
  for (resp = i = 0; i < n; i++) {
    resp = max(resp, min(esq[i], dir[i]));
  }
  printf("%d\n", resp);
  return 0;
}
