#include <stdio.h>
#include <string.h>

#define MAX 112

int eh_maiuscula(char c) { return (c >= 'A' && c <= 'Z'); }

void imprime(char str[]) {
  int i, tam = strlen(str);
  for (i = 0; i < tam; i++)
    if (eh_maiuscula(str[i])) printf("%c", (str[i] - 'A') + 'a');
    else printf("%c", (str[i] - 'a') + 'A');
  printf("\n");
}

int main(void) {
  int i, tam, flag;
  char str[MAX];
  fgets(str, MAX, stdin); str[strlen(str) - 1] = '\0';
  tam = strlen(str);
  for (flag = i = 1; flag && i < tam; i++)
    flag &=  (eh_maiuscula(str[i]) || str[i] == ' ');
  if (flag) imprime(str);
  else printf("%s\n", str);
  return 0;
}
