#include <stdio.h>
#include <string.h>

int main(void) {
  int c; char str[11];
  scanf("%d", &c);
  while (c--) {
    scanf(" %s", str);
    if (strlen(str) != 3) printf("3\n");
    else if ((str[0] == 'o' && str[1] == 'n') ||
             (str[0] == 'o' && str[2] == 'e') ||
             (str[1] == 'n' && str[2] == 'e'))
      printf("1\n");
    else printf("2\n");
  }
  return 0;
}
