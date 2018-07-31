#include <stdio.h>

int main(void) {
  int n, i, l1 = 0, l2 = 0, r1 = 0, r2 = 0;
  char o1[11], o2[11];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %s", o1, o2);
    if (o1[0] == o2[0] && o1[0] == 'c') {
      if (l1 == 0) { r1++; l1++; }
    } else if (o1[0] == 'c') {
      if (l1 == 0) r1++;
      else l1--;
      l2++;
    } else if (o2[0] == 'c') {
      if (l2 == 0) r2++;
      else l2--;
      l1++;
    }
  }
  printf("%d %d\n", r1, r2);
  return 0;
}
