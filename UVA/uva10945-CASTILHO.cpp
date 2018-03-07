#include <stdio.h>
#include <string.h>

#define MAX 1123456

int valido(char c) {
  if (c == '.' || c == ',' || c == '!' || c == '?' || c == ' ') return 0;
  return 1;
}

char minus(char c) {
  if (c < 'a' || c > 'z') c = (c - 'A') + 'a';
  return c;
}

int is_palindrome(char str[]) {
  int i, j;
  for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    if (str[i] != str[j]) return 0;
  return 1;
}

int main(void) {
  int i, tam, cont;
  char str[MAX], nova[MAX];
  while (fgets(str, MAX, stdin)) {
    str[strlen(str) - 1] = '\0';
    if (strcmp(str, "DONE") == 0) return 0;
    for (tam = strlen(str), cont = i = 0; i < tam; i++)
      if (valido(str[i])) nova[cont++] = minus(str[i]);
    nova[cont] = '\0';
    printf("%s\n", is_palindrome(nova) ? "You won't be eaten!" : "Uh oh..");
  }
  return 0;
}
