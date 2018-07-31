#include <stdio.h>
#include <string.h>

#define MAX 112345

int main(void) {
  int n, i;
  char p[MAX];
  fgets(p, MAX, stdin); p[strlen(p) - 1] = 0;
  n = strlen(p);
  for (i = 0; i < n; ) {
    if (i < n - 3 && p[i] == p[i + 2] && p[i + 1] == p[i + 3]) i += 2;
    for ( ; p[i] != ' ' && i < n; i++) printf("%c", p[i]);
    if (p[i] == ' ') { printf("%c", p[i]); i++; }
  }
  printf("\n");
  return 0;
}
