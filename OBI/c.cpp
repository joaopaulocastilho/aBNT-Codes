#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

int vogal(char c) {
  if (c == 'a') return 1;
  if (c == 'e') return 1;
  if (c == 'i') return 1;
  if (c == 'o') return 1;
  if (c == 'u') return 1;
  return 0;
}

char codifica(char c, char c_des) {
  int tmp = c - 'a', des = c_des - 'a';
  //printf("CIFRANDO: %c %c\n", c, c_des);
  return ((tmp + des) % 26) + 'a';
}

int main(void) {
  int i, n, point, cifra, flag, tam;
  char c, k[MAXV];
  fgets(k, MAXV, stdin); k[tam = strlen(k) - 1] = '\0';
  scanf("%d ", &n);
  for (point = 0, cifra = 0, flag = 1, i = 0; i < n; ) {
    c = getchar();
    if (c == '\n') { point = 0; flag = 1; printf("%c", c); i++; continue; }
    if (c == ' ') { printf("%c", c); flag = 1; continue; }
    if (flag) {
      flag = 0;
      if (vogal(c)) cifra = 0;
      else cifra = 1;
    }
    if (cifra) { printf("%c", codifica(c, k[point])); point = (point + 1) % tam; }
    else printf("%c", c);
  }
  return 0;
}
