#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 21234

int p[MAX];

int exp(int a, int b) {
  if (!b) return 1;
  return a * exp(a, b -1);
}

int main(void) {
  int n, tam, i, j, x, forca[MAX], resp;
  while (scanf("%d", &n) != EOF) {
    memset(forca, 0, sizeof(forca));
    tam = exp(2, n);
    for (i = 0; i < tam; i++) scanf("%d", &p[i]);
    for (i = 0; i < tam; i++)
      for (x = 1, j = 0; j < n; j++) {
	forca[i] += p[i ^ x];
	x = x << 1;
      }
    for (resp = 0, i = 0; i < tam; i++)
      for (x = 1, j = 0; j < n; j++) {
	resp = max(resp, forca[i] + forca[i ^ x]);
	x = x << 1;
      }
    printf("%d\n", resp);
  }
  return 0;
}
