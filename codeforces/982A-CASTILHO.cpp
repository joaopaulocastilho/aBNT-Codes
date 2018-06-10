#include <stdio.h>

#define MAX 1123

int main(void) {
  int n, i, resp;
  char s[MAX];
  scanf("%d ", &n);
  scanf("%s", s);
  for (resp = i = 1; resp && i < n; i++)
    if (s[i - 1] == '1' && s[i] == '1') resp = 0;
  for (i = 2; resp && i < n; i++)
    if (s[i - 2] == '0' && s[i - 1] == '0' && s[i] == '0') resp = 0;
  if ((s[n - 1] == '0' && s[n - 2] == '0') || (s[0] == '0' && s[1] == '0')) resp = 0;
  if (n == 1 && s[0] == '0') resp = 0;
  printf("%s\n", resp ? "Yes" : "No");
  return 0;
}
