#include <stdio.h>
#include <string.h>

#define MAX 1123456

int main(void) {
  int round, qtds[41], acertos, erros, flag, i, tam, win, guess[41];
  char corr[MAX], c;
  while (scanf("%d ", &round), round != -1) {
    memset(qtds, 0, sizeof(qtds));
    memset(guess, 0, sizeof(guess));
    fgets(corr, MAX, stdin);
    tam = strlen(corr) - 1;
    for (i = 0; i < tam; i++) qtds[corr[i] - 'a']++;
    for (win = acertos = erros = 0, flag = 1;
         (c = getchar()) != '\n'; ) {
      if (qtds[c - 'a']) {
        acertos += qtds[c - 'a'];
        qtds[c - 'a'] = 0;
      } else
        if (!guess[c - 'a']) erros++;
      guess[c - 'a'] = 1;
      if (flag && acertos == tam) { win = 1; }
      if (acertos < tam && erros == 7) flag = 0;
    }
    printf("Round %d\n", round);
    if (win) printf("You win.\n");
    else if (!flag) printf("You lose.\n");
    else printf("You chickened out.\n");
  }
  return 0;
}
