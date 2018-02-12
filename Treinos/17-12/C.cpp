#include <stdio.h>

int main(void) {
  int i, n, d, e, f, v;
  char op, j, ja;
  scanf("%d %d", &i, &n);
  d = e = f = i;
  while (n--) {
    scanf(" %c %c", &op, &j);
    switch (op) {
    case 'C':
      scanf("%d", &v);
      if (j == 'D') d -= v;
      else if (j == 'E') e -= v;
      else f -= v;
      break;
    case 'V':
      scanf("%d", &v);
      if (j == 'D') d += v;
      else if (j == 'E') e += v;
      else f += v;
      break;
    case 'A':
      scanf(" %c %d", &ja, &v);
      if (j == 'D') d += v;
      else if (j == 'E') e += v;
      else f += v;
      if (ja == 'D') d -= v;
      else if (ja == 'E') e -= v;
      else f -= v;
      break;
    }
  }
  printf("%d %d %d\n", d, e, f);
  return 0;
}
