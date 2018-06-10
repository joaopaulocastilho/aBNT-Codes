#include <stdio.h>
#include <string.h>

#define MAX 1123
#define INF 112345678

int main(void) {
  int i, j, tam, caso = 1, qtd, ind, menor;
  char conta[MAX], topos[MAX];
  while (scanf("%s ", conta), conta[0] != 'e') {
    tam = strlen(conta);
    topos[0] = conta[0];
    for (qtd = 1, i = 1; i < tam; i++) {
      for (ind = -1, menor = INF, j = 0; j < qtd; j++) {
        if (conta[i] <= topos[j] && topos[j] - conta[i] < menor) {
          ind = j; menor = topos[j] - conta[i];
        }}
      if (ind == -1) topos[qtd++] = conta[i];
      else topos[ind] = conta[i];
    }
    printf("Case %d: %d\n", caso, qtd); caso++;
  }
  return 0;
}
