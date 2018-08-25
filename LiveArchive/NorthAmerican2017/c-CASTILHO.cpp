#include <bits/stdc++.h>

using namespace std;

const int MAXV = 16234;

char ans[MAXV];

void trata(char s[], int ini, int fim) {
  int i, newc, soma = 0;
  for (i = ini; i <= fim; i++) soma += s[i] - 'A';
  for (i = ini; i <= fim; i++) {
    newc = s[i] - 'A';
    newc = (newc + soma) % 26;
    s[i] = newc + 'A';
  }
}

void merge(char s[]) {
  int i, j, newc;
  for (i = 0, j = strlen(s) / 2; i < (int)strlen(s) / 2; i++, j++) {
    newc = s[i] - 'A';
    newc = (newc + (s[j] - 'A')) % 26;
    ans[i] = newc + 'A';
  }
  ans[i] = '\0';
}

int main(void) {
  char s[MAXV];
  while (scanf("%s", s) != EOF) {
    trata(s, 0, strlen(s) / 2 - 1);
    trata(s, strlen(s) / 2, strlen(s) - 1);
    merge(s);
    printf("%s\n", ans);
  }
  return 0;
}
