#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void) {
  int n, tama, tamb, i, j;
  char a[MAX], b[MAX];
  scanf("%d ", &n);
  while (n--) {
    scanf("%s %s ", a, b);
    tama = strlen(a); tamb = strlen(b);
    for (j = 0, i = tama - tamb; i < tama; i++, j++)
      if (a[i] != b[j]) { printf("nao "); break; }
    printf("encaixa\n");
  }
  return 0;
}
