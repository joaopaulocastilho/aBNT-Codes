#include <stdio.h>

int main(void) {
  int i;
  for (i = 0; i < 39; i++) printf("-");
  printf("\n");
  printf("|");
  for (i = 0; i < 8; i++) printf(" ");
  printf("Roberto");
  for (i = 0; i < 39 - 17; i++) printf(" ");
  printf("|\n");
  printf("|");
  for (i = 0; i < 37; i++) printf(" ");
  printf("|\n");
  printf("|");
  for (i = 0; i < 8; i++) printf(" ");
  printf("5786");
  for (i = 0; i < 39 - 14; i++) printf(" ");
  printf("|\n");
  printf("|");
  for (i = 0; i < 37; i++) printf(" ");
  printf("|\n");
  printf("|");
  for (i = 0; i < 8; i++) printf(" ");
  printf("UNIFEI");
  for (i = 0; i < 39 - 16; i++) printf(" ");
  printf("|\n");
  for (i = 0; i < 39; i++) printf("-");
  printf("\n");
  return 0;
}
