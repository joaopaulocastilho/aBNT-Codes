#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void) {
  int n, i, oc[MAX];
  char s[MAX];
  memset(oc, 0, sizeof(oc));
  scanf("%d", &n);
  scanf(" %s", s);
  for (i = 0; i < n; i++) oc[s[i] - 'a']++;
  for (i = 0; i < n; i++)
    if (oc[s[i] - 'a'] == 1) { printf("%c\n", s[i]); break; }
  if (i == n) printf("-1\n");
  return 0;
}
