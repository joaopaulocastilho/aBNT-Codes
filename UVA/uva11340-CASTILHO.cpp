#include <stdio.h>
#include <string.h>

#define MAXP 112
#define MAX 11234

int value[MAXP];
char pay[MAXP];

int price_f(char c, int t) {
  int i;
  for (i = 0; i < t; i++)
    if (pay[i] == c) return value[i];
  return 0;
}

int main(void) {
  int casos, k, i, tam, d, price, m;
  char line[MAX];
  scanf("%d", &casos);
  while (casos--) {
    scanf("%d", &k);
    for (i = 0; i < k; i++) scanf(" %c %d", &pay[i], &value[i]);
    scanf("%d ", &m);
    for (price = 0; m--; ) {
      fgets(line, MAX, stdin);
      tam = strlen(line);
      for (i = 0; i < tam; i++) price += price_f(line[i], k);
    }
    d = price / 100;
    price = price % 100;
    printf("%d.%.2d$\n", d, price);
  }
  return 0;
}
