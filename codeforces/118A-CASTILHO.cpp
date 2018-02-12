#include <stdio.h>

int vogal(char c) {
  if (c == 'A' || c == 'O' || c == 'Y' || c == 'E' || c == 'U'
      || c == 'I' || c == 'a' || c == 'o' || c == 'y' || c == 'e'
      || c == 'u' || c == 'i') return 1;
  return 0;
}

void imprime(char c) {
  if (c >= 'A' && c <= 'Z') {
    c = (c - 'A') + 'a';
  }
  printf("%c", c);
}

int main(void) {
  char c;
  while ((c = getchar()) != '\n') {
    if (vogal(c)) continue;
    printf(".");
    imprime(c);
  }
  printf("\n");
  return 0;
}
