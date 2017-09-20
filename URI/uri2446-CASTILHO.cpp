#include<stdio.h>
#include<string.h>

#define MAX 1001
#define MAXV 112345

int v, m, moedas[MAX], resp[MAXV];

int main(void) {
  int i, j;
  scanf("%d %d", &v, &m);
  memset(resp, 0, sizeof(resp)); resp[0] = 1;
  for (i = 0; i < m; i++) scanf("%d", &moedas[i]);
  for (i = 0; i < m; i++)
    for (j = v; j >= moedas[i]; j--)
      if (resp[j - moedas[i]]) resp[j] = 1;
  printf("%c\n", resp[v] ? 'S' : 'N');
  return 0;
}
