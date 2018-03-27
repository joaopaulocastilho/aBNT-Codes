#include <stdio.h>

#define MAX 12

int main(void) {
  int i, j, cont = 0;
  double num, acum = 0.0;
  char c;
  scanf("%c", &c);
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++) {
      scanf("%lf", &num);
      if (i > j) { acum += num; cont++; }
    }
  printf("%.1lf\n", c == 'S' ? acum : acum / cont);
  return 0;
}
