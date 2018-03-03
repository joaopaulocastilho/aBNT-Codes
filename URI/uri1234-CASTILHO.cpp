#include <stdio.h>

#define MAX 51

void print_M(char c) {
  if (c >= 'A' && c <= 'Z') { printf("%c", c); return; }
  c -= 'a'; c += 'A';
  printf("%c", c);
}

void print_m(char c) {
  if (c >= 'a' && c <= 'z') { printf("%c", c); return; }
  c -= 'A'; c += 'a';
  printf("%c", c);
}

int main(void) {
  int maiusculo, i;
  char s[MAX];
  while (fgets(s, MAX, stdin)) {
    for (maiusculo = 1, i = 0; s[i] != '\n'; i++) {
      if (s[i] == ' ') { printf(" "); continue; }
      if (maiusculo) print_M(s[i]);
      else print_m(s[i]);
      maiusculo = !maiusculo;
    }
    printf("\n");
  }
  return 0;
}
