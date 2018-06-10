#include <stdio.h>
#include <string.h>

#define MAX 55

int eh_palindromo(char s[]) {
  int i, j, flag;
  for (flag = 1, i = 0, j = strlen(s) - 1; i <= j; i++, j--)
    flag &= (s[i] == s[j]);
  return flag;
}

int main(void) {
  int i, n, flag;
  char s[MAX];
  fgets(s, MAX, stdin); s[strlen(s) - 1] = '\0';
  n = strlen(s);
  for (flag = i = 1; i < n; i++) flag &= (s[i - 1] == s[i]);
  if (flag) printf("0\n");
  else if (!eh_palindromo(s)) printf("%d\n", n);
  else printf("%d\n", n - 1);
  return 0;
}
