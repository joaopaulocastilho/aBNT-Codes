#include<stdio.h>

int main(void) {
  int n, a = 0, g = 0, d = 0;
  while (scanf("%d", &n), n != 4) {
    switch (n) {
    case 1: a++; break;
    case 2: g++; break;
    case 3: d++; break;
    }
  }
  printf("MUITO OBRIGADO\n");
  printf("Alcool: %d\nGasolina: %d\nDiesel: %d\n", a, g, d);
  return 0;
}
