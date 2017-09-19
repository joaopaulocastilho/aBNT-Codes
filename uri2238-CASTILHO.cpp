#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX 112345

typedef struct { int f, m; }fator;

int PI[MAX], pi, cm, divisores[MAX], ndiv, carry[MAX];
int a, b, c, d;
fator fat[MAX];

int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }

void crivo(int n) {
  int i, j, primo, raiz;
  PI[0] = 2; pi = 1;
  for (i = 3; i < n; i++) {
    primo = 1; raiz = sqrt(i);
    for (j = 0; primo && j < pi && PI[j] <= raiz; j++) {
      if (i % PI[j] == 0) primo = 0;
    }
    if (primo) PI[pi++] = i;
  }}

void fatora(int n) {
  int i, raiz, flag;
  cm = -1; raiz = sqrt(n);
  for (i = 0; PI[i] <= raiz; i++) {
    flag = 1;
    while (n % PI[i] == 0) {
      if(flag) { fat[++cm].f = PI[i]; flag = 0; }
      (fat[cm].m)++;
      n /= PI[i];
    }}
    if (n > 1) { fat[++cm].f = n; (fat[cm].m)++; }
    cm++;
}

int expbin(int a, int b){
  int y;
  if (b == 0) return 1;
  if (b & 1) return a * expbin(a, b - 1);
  y = expbin(a, b >> 1);
  return y * y;
}

int mult() {
  int i, ret = 1;
  for (i = 0; i < cm; i++) ret *= expbin(fat[i].f, carry[i]);
  return ret;
}

int sucessor() {
  int i, p = cm - 1;
  while (p >= 0 && carry[p] == fat[p].m) p--;
  if (p < 0) return 0;
  carry[p] += 1;
  for (i = p + 1; i < cm; i++) carry[i] = 0;
  return 1;
}

void gera_divisores(int n) {
  ndiv = 0;
  memset(carry, 0, sizeof(carry));
  while (1) {
    divisores[ndiv++] = mult();
    if (!sucessor()) break;
  }}

int adivinhou(int n) {
  if (n % a == 0 && n % b != 0 && c % n == 0 && d % n != 0) return 1;
  return 0;
}

int main(void) {
  int i;
  crivo(MAX);
  scanf("%d %d %d %d", &a, &b, &c, &d);
  memset(fat, 0, sizeof(fat));
  fatora(c); gera_divisores(c);
  qsort(divisores, ndiv, sizeof(int), &cmp);
  for (i = 0; i < ndiv; i++) {
    if (adivinhou(divisores[i])) { printf("%d\n", divisores[i]); break; }
  }
  if (i == ndiv) printf("-1\n");
  return 0;
}
