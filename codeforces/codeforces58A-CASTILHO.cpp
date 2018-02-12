#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void) {
  char s[MAX], aux[] = "hello";
  int flag, cont, i;
  scanf("%s", s);
  for (flag = 1, cont = i = 0; flag && i < (int)strlen(s); i++) {
    if (s[i] == aux[cont]) cont++;
    if (cont == (int)strlen(aux)) flag = 0;
  }
  printf("%s\n", flag ? "NO" : "YES");
  return 0;
}
