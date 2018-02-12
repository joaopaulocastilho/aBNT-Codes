#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void) {
  int n, i, s0, s1, flag = 1; char str[MAX];
  scanf("%s", str); n = strlen(str);
  for (s0 = s1 = i = 0; flag && i < n; i++) {
    if (str[i] == '0') { s0++; s1 = 0; }
    else { s1++; s0 = 0; }
    if (s0 == 7 || s1 == 7) { flag = 0; printf("YES\n"); }
  }
  if (flag) printf("NO\n");
  return 0;
}
