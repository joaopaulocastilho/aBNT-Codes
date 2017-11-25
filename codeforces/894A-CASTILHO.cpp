#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void) {
  int n, i, j, k, resp = 0; char str[MAX];
  scanf("%s", str); n = strlen(str);
  for (i = 0; i < n; i++) {
    if (str[i] != 'Q') continue;
    for (j = i + 1; j < n; j++) {
      if (str[j] != 'A') continue;
      for (k = j + 1; k < n; k++)
        resp += (str[k] == 'Q');
    }}
  printf("%d\n", resp);
  return 0;
}
