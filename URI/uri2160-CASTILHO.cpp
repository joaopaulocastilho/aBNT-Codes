#include <stdio.h>
#include <string.h>

#define MAX 512

int main(void) {
  char str[MAX];
  fgets(str, MAX, stdin);
  printf("%s\n", ((strlen(str) - 1) > 80) ? "NO" : "YES");
  return 0;
}
