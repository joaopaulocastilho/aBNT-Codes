#include <stdio.h>

int main(void){
  int x, i;
  while (scanf("%d", &x), x) {
    for (i = 1; i <= x; i++) {
      if (i > 1) printf(" ");
      printf("%d", i);
    }
    printf("\n");
  }
  return 0;
}
