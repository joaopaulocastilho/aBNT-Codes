#include <stdio.h>

int main(void) {
  int i;
  for (i = 0; i < 39; i++) printf("-");
  printf("\n|x = 35 |");
  for (i = 0; i < 30; i++) printf(" ");
  printf("\n");
  printf("| |\n");
  printf("| x = 35 |\n");
  printf("| |\n");
  printf("| x = 35|\n");
  for (i = 0; i < 39; i++) printf("-");
  printf("\n");
  return 0;
}
