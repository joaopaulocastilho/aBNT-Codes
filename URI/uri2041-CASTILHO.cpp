#include<stdio.h>
#include<string.h>

//#define DEBP

char S[41][1123456];

void gera() {
  int i, j, flag, pos, cont;
  char cc;
  S[1][0] = '3'; S[1][1] = '\0';
  for (i = 2; i <= 40; i++) {
    flag = 0; pos = 0;
    for (j = 0; j <= (int)strlen(S[i-1]); j++) {
      if (!flag) {
        cont = 0; flag = 1; cc = S[i-1][j];
      }
      if (flag && S[i-1][j] != cc) {
        S[i][pos++] = cont + '0'; S[i][pos++] = cc;
        cc = S[i-1][j]; cont = 0;
      }
      cont++;
    }
    S[i-1][pos] = '\0';
  }}

int main(void) {
  int n;
  gera();
#ifdef DEBP
  int i;
  for (i = 1; i <= 40; i++)
    printf("%d: %s\n", i, S[i]);
#endif
  while (scanf("%d", &n) != EOF) printf("%s\n", S[n]);
  return 0;
}
