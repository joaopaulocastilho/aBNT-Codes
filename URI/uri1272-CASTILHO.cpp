#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

int main(void) {
  int n, i;
  char linha[MAXV];
  scanf("%d ", &n);
  while (n--) {
    fgets(linha, MAXV, stdin);
    if (linha[0] != ' ') printf("%c", linha[0]);
    for (i = 1; linha[i] != '\n'; i++)
      if (linha[i - 1] == ' ' && linha[i] != ' ') printf("%c", linha[i]);
    printf("\n");
  }
  return 0;
}
