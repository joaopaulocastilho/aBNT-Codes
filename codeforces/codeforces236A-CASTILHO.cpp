#include <stdio.h>
#include <string.h>

int main(void) {
  char c; int flag[112], resp = 0;
  memset(flag, 0, sizeof(flag));
  while ((c = getchar()) != EOF) {
    if (c == '\n') continue;
    if (!flag[c - 'a']) resp++;
    flag[c - 'a'] = 1;
  }
  printf("%s\n", (resp & 1) ? "IGNORE HIM!" : "CHAT WITH HER!");
  return 0;
}
