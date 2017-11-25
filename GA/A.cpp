#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void) {
  int pesos[31], i, resp = 0;
  char str[MAX];
  scanf("%s", str);
  for (i = 0; i < 26; i++) scanf("%d", &pesos[i]);
  for (i = 0; i < (int)strlen(str); i++)
    resp += pesos[str[i] - 'a'];
  printf("%d\n", resp);
  return 0;
}
