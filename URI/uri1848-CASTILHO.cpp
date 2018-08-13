#include<bits/stdc++.h>

using namespace std;

const int MAXV = 11;

int main(void) {
  int n = 0;
  char linha[MAXV];
  while (fgets(linha, MAXV, stdin)) {
    if (linha[0] == 'c') {
      printf("%d\n", n);
      n = 0;
      continue;
    }
    n += (linha[0] == '*') ? 4 : 0;
    n += (linha[1] == '*') ? 2 : 0;
    n += (linha[2] == '*') ? 1 : 0;
  }
  return 0;
}
