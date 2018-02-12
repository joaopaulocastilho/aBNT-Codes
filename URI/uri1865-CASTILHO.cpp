#include <stdio.h>
#include <string.h>

#define MAX 1123456

int main(void) {
  int n, f; char nome[MAX];
  scanf("%d", &n);
  while (n--) {
    scanf(" %s %d", nome, &f);
    printf("%c\n", !strcmp(nome, "Thor") ? 'Y' : 'N');
  }
  return 0;
}
