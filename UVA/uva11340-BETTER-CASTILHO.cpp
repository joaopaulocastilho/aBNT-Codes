#include <stdio.h>
#include <string.h>

#define MAXP 112
#define MAX 11234
#define ASCTAM 260

int value[MAXP];
char pay[MAXP];

int price_f(char c, int t) {
  int i;
  for (i = 0; i < t; i++)
    if (pay[i] == c) return value[i];
  return 0;
}

int main(void) {
  int casos, k, i, tam, d, price, m, asc[ASCTAM], vals[ASCTAM], val;
  char line[MAX], c;
  scanf("%d", &casos);
  while (casos--) {
    memset(asc, 0, sizeof(asc));
    memset(vals, 0, sizeof(vals));
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
      scanf(" %c %d", &c, &val);
      vals[(int)c] = val;
    }
    scanf("%d ", &m);
    for (price = 0; m--; ) {
      fgets(line, MAX, stdin);
      tam = strlen(line);
      for (i = 0; i < tam; i++) {
	if ((int)line[i] <= 0 || (int)line[i] > 255) continue;
	asc[(int)line[i]]++;
      }
    }
    for (i = 0; i < ASCTAM; i++) price += asc[i] * vals[i];
    d = price / 100;
    price = price % 100;
    printf("%d.%.2d$\n", d, price);
  }
  return 0;
}
