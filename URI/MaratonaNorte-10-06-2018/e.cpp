#include <stdio.h>
#include <string.h>

#define MAX 1123

char norte[][MAX] =
  { "roraima", "acre", "amapa", "amazonas", "para", "rondonia", "tocantins" };


int main(void) {
  int resp, i;
  char estado[MAX];
  scanf("%s", estado);
  for (resp = i = 0; !resp && i < 7; i++)
    if (strcmp(estado, norte[i]) == 0) resp = 1;
  printf("%s\n", resp ? "Regiao Norte" : "Outra regiao");
  return 0;
}
