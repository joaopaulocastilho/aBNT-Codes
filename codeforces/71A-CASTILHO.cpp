#include<stdio.h>
#include<string.h>

#define MAX 112

int main(void) {
  int n, i;
  char str[MAX];
  scanf("%d ", &n);
  for (i = 0; i < n; i++) {
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0';
    if (strlen(str) > 10)
      printf("%c%d%c\n", str[0], (int)strlen(str) - 2, str[strlen(str) - 1]);
    else printf("%s\n", str);
  }
  return 0;
}
