#include<stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  if (n > 2 && !(n & 1)) printf("YES\n");
  else printf("NO\n");
  return 0;
}
