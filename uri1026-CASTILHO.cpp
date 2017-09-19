#include<stdio.h>

int main(void) {
  unsigned int n1, n2;
  while (scanf("%u %u", &n1, &n2) != EOF) {
    printf("%u\n", n1 ^ n2);
  }
  return 0;
}
