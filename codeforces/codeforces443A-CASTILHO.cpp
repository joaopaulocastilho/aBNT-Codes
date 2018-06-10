#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void) {
  int i, resp = 0, con[MAX];
  char c;
  memset(con, 0, sizeof(con));
  while (scanf("%c", &c), c != '}') {
    if (c >= 'a' && c <= 'z') {
      con[c - 'a']++;
    }}
  for (i = 0; i < 26; i++) if (con[i]) resp++;
  printf("%d\n", resp);
  return 0;
}
