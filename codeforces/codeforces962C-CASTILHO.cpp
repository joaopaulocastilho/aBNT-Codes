#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX 12

int for_num(char s[], int f[], int tam) {
  int i, ret = 0, mul = 1, first = 1;
  for (i = 0; i < tam; i++) {
    if (!f[i]) continue;
    if (first) {
      first = 0;
      if (s[i] == '0') return 10;
    }
    ret *= mul;
    ret += s[i] - '0';
    mul = 10;
  }
  return ret;
}

int main(void) {
  int qtd, tam, flag, i, na, raiz, pert[MAX];
  char numb[MAX];
  fgets(numb, MAX, stdin);
  numb[strlen(numb) - 1] = '\0'; tam = strlen(numb);
  for (qtd = 0, flag = 1; qtd < tam; qtd++) {
    for (i = 0; i < qtd; i++) pert[i] = 0;
    for ( ; i < tam; i++) pert[i] = 1;
    do {
      na = for_num(numb, pert, tam);
      raiz = sqrt(na);
      if (raiz * raiz == na) { flag = 0; break; }
    } while (next_permutation(pert, pert + tam));
    if (!flag) break;
  }
  printf("%d\n", qtd == tam ? -1 : qtd);
  return 0;
}
