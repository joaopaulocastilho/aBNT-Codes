#include<stdio.h>

#define MAX 112

int num[MAX], tam;

int soma1() {
  int i, carry = 1, mod3 = 0;
  for (i = tam - 1; carry && i >= 0; i--) {
    if (num[i] == 9) {
      num[i] = 0;
    } else {
      num[i]++;
      carry = 0;
    }}
  for (i = 0; i < tam; i++) mod3 += num[i];
  return mod3 % 3 == 0;
}

int main(void) {
  int mod3, resp;
  char c;
  num[0] = 0;
  for (mod3 = 0, tam = 1; (c = getchar()) != '\n'; tam++) {
    num[tam] = c - '0';
    mod3 += num[tam];
  }
  if (mod3 % 3 == 0) resp = 0;
  else if (soma1()) resp = 2;
  else resp = 1;
  printf("%d\n", resp);
  return 0;
}
