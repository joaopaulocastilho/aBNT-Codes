#include <stdio.h>

int main(void) {
  int i, j, cont = 0;
  double num, resp = 0.0;
  char op;
  scanf("%c", &op);
  for (i = 0; i < 12; i++)
    for (j = 0; j < 12; j++) {
      scanf("%lf", &num);
      if (j > i) { resp += num; cont++; }
    }
  printf("%.1lf\n", op == 'S'? resp : resp / cont);
  return 0;
}
