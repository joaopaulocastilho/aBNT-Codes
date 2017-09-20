#include<stdio.h>
#include<string.h>

int digitos[11];

void conta_digitos(int n) {
  int di;
  memset(digitos, 0, sizeof(digitos));
  while (n) {
    di = n % 10; n /= 10;
    digitos[di]++;
  }
}

int main(void) {
  int n, m, i, j, flag, resp;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (resp = 0, i = n; i <= m; i++) {
      conta_digitos(i);
      for (flag = 1, j = 0; j < 10; j++) flag &= (digitos[j] < 2);
      resp += flag;
    }
    printf("%d\n", resp);
  }
  return 0;
}
