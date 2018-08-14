#include <stdio.h>

int main(void) {
  double n1, n2;
  char op;
  scanf("%c %lf %lf", &op, &n1, &n2);
  printf("%.2lf\n", op == 'M' ? n1 * n2 : n1 / n2);
  return 0;
}
