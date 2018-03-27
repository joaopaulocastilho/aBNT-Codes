#include <stdio.h>
#include <string.h>

#define MAX 51
#define AB 0
#define A 1
#define B 2
#define O 3

int tipo(char str[]) {
  if (str[0] == 'A' && str[1] == 'B') return AB;
  if (str[0] == 'A') return A;
  if (str[0] == 'B') return B;
  return O;
}

int gera_comb(int pai, int mae, char filho[MAX][5]) {
  int qtd = 0;
  if (pai == AB || mae == AB) {
    strcpy(filho[qtd++], "A"); strcpy(filho[qtd++], "B");
    if (pai == A || pai == B || mae == A || mae == B ||
        (pai == AB && mae == AB))
      strcpy(filho[qtd++], "AB");
  } else {
    strcpy(filho[qtd++], "O");
    if (pai == A || mae == A) strcpy(filho[qtd++], "A");
    if (pai == B || mae == B) strcpy(filho[qtd++], "B");
    if ((pai == A && mae == B) || (pai == B && mae == A))
      strcpy(filho[qtd++], "AB");
  }
  return qtd;
}

int ver_rh(char s1[], char s2[]) {
  if (s1[1] == '+' || s1[2] == '+' || s2[1] == '+' || s2[2] == '+') return 2;
  return 1;
}

int verifica_comb(int pai, int tfilho, char filho[MAX][5]) {
  int qtd = 0;
  if ((pai == AB && tfilho == O) || (pai == O && tfilho == AB)) return 0;
  if ((pai == A && tfilho == A) || (pai == B && tfilho == B) || (pai == AB && (tfilho == A || tfilho == B)))
    { strcpy(filho[qtd++], "A");  strcpy(filho[qtd++], "B"); strcpy(filho[qtd++], "AB"); strcpy(filho[qtd++], "O"); }
  else if (tfilho == O) { strcpy(filho[qtd++], "A"); strcpy(filho[qtd++], "B"); strcpy(filho[qtd++], "O"); }
  else if (pai == A || (pai == O && tfilho == B)) { strcpy(filho[qtd++], "AB"); strcpy(filho[qtd++], "B"); }
  else if (pai == B || (pai == O && tfilho == A)) { strcpy(filho[qtd++], "AB"); strcpy(filho[qtd++], "A"); }
  else if (pai == AB) { strcpy(filho[qtd++], "AB"); strcpy(filho[qtd++], "A"); strcpy(filho[qtd++], "B"); }
  return qtd;
}

int rh_t(char str[]) {
  if (str[1] == '+' || str[2] == '+') return 1;
  return 0;
}

int main(void) {
  int i, first, pai, mae, tam, qtd_rh, tfilho, rh_pai, rh_filho, caso = 1;
  char tp1[5], tp2[5], tf[5], filho[MAX][5];
  while (scanf(" %s %s %s", tp1, tp2, tf), tp1[0] != 'E') {
    printf("Case %d: ", caso); caso++;
    if (tf[0] == '?') {
      pai = tipo(tp1); mae = tipo(tp2);
      tam = gera_comb(pai, mae, filho);
      qtd_rh = ver_rh(tp1, tp2);
      printf("%s %s ", tp1, tp2);
      if (tam > 1 || qtd_rh == 2) printf("{");
      for (first = 1, i = 0; i < tam; i++) {
        if (first) first = 0;
        else printf(", ");
        if (qtd_rh == 2) printf("%s+, ", filho[i]);
        printf("%s-", filho[i]);
      }
      if (tam > 1 || qtd_rh == 2) printf("}");
      printf("\n");
    } else {
      if (tp2[0] == '?') { rh_pai = rh_t(tp1); pai = tipo(tp1); }
      else { rh_pai = rh_t(tp2); pai = tipo(tp2); }
      rh_filho = rh_t(tf); tfilho = tipo(tf);
      tam = verifica_comb(pai, tfilho, filho);
      if (tp2[0] == '?') printf("%s ", tp1);
      if (tam) printf("{");
      for (first = 1, i = 0; i < tam; i++) {
        if (first) first = 0;
        else printf(", ");
        if (!(rh_pai == 0 && rh_filho == 1))
          printf("%s-, ", filho[i]);
        printf("%s+", filho[i]);
      }
      if (!tam) printf("IMPOSSIBLE ");
      else printf("} ");
      if (tp1[0] == '?') printf("%s ", tp2);
      printf("%s\n", tf);
    }
  }
  return 0;
}
