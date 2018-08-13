#include<bits/stdc++.h>

using namespace std;

const int MAXV = 112;
const char p[] = "cobol";

int minu(char c) {
  if (c == '-') return 0;
  if (c >= 'A' && c <= 'Z') return (c - 'A') + 'a';
  return c;
}

int main(void) {
  int i, j, k, ans, first, last;
  char linha[MAXV];
  while (scanf("%s", linha) != EOF) {
    for (ans = 1, j = i = 0; i < 5; i++) {
      for (k = 0; j < (int)strlen(linha) && linha[j] != '-'; j++, k++) {
        if (k == 0) first = minu(linha[j]);
      }
      last = minu(linha[j - 1]); j++;
      //printf("%c %c, %d\n", first, last, j);
      ans &= (first == p[i] || last == p[i]);
    }
    printf("%s\n", (ans) ? "GRACE HOPPER" : "BUG");

  }
  return 0;
}
