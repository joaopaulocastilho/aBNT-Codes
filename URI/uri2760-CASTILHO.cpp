#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void) {
  int i;
  char a[MAX], b[MAX], c[MAX];
  fgets(a, MAX, stdin);
  fgets(b, MAX, stdin);
  fgets(c, MAX, stdin);
  a[strlen(a) - 1] = '\0';
  b[strlen(b) - 1] = '\0';
  c[strlen(c) - 1] = '\0';
  printf("%s%s%s\n", a, b, c);
  printf("%s%s%s\n", b, c, a);
  printf("%s%s%s\n", c, a, b);
  for (i = 0; i < (int)strlen(a) && i < 10; i++) printf("%c", a[i]);
  for (i = 0; i < (int)strlen(b) && i < 10; i++) printf("%c", b[i]);
  for (i = 0; i < (int)strlen(c) && i < 10; i++) printf("%c", c[i]);
  printf("\n");
  return 0;
}
