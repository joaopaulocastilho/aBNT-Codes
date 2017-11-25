#include<stdio.h>
#include<string.h>

#define MAX 1123

int main(void) {
  int n, size, i, flag[MAX], resp = 1;
  char s[MAX];
  scanf("%s %d", s, &n);
  memset(flag, 0, sizeof(flag));
  size = strlen(s);
  if (s[0] == '?') { s[0] = '1'; flag[0] = 1; }
  for (i = 1; i < size; i++)
    if (s[i] == '?') { s[i] = '0'; flag[i] = 1; }
  if (calculamod(s) == 0) { printf("%s\n", s); resp = 0; }
  for (i = size - 1; resp && i >= 0; i--) {
    if (!flag[i]) continue;
    for (j = 0; j < 9; j++) {
      s[i]++;
      if (calculamod(s) == 0) resp = 0;
    }

  }
  return 0;
}
