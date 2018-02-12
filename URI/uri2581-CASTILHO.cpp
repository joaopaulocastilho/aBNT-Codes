#include <stdio.h>

#define MAX 1123456

int main(void) {
  int n; char str[MAX];
  scanf("%d ", &n);
  while (n--) {
    printf("I am Toorg!\n");
    fgets(str, MAX, stdin);
  }
  return 0;
}
