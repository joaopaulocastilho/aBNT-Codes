#include <stdio.h>

int main(void) {
  int i;
  for (i = 0; i < 39; i++) printf("-");
  printf("\n");
  printf("|x = 35");
  for (i = 0; i < 31; i++) printf(" ");
  printf("|\n");
  printf("|");
  for (i = 0; i < 37; i++) printf(" ");
  printf("|\n");
  printf("|");
  for (i = 0; i < 15; i++) printf(" ");
  printf("x = 35");
  for (i = 0; i < 39 - 23; i++) printf(" ");
  printf("|\n");
  printf("|");
  for (i = 0; i < 37; i++) printf(" ");
  printf("|\n");
  printf("|");
  for (i = 0; i < 31; i++) printf(" ");
  printf("x = 35|\n");
  for (i = 0; i < 39; i++) printf("-");
  printf("\n");
  return 0;
}
