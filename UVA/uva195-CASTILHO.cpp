#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>

using namespace std;

#define MAX 11234

typedef vector<int> vi;

char map[61];

void monta_map() {
  int i, inv, cont;
  char C, c;
  for (cont = 0, inv = 1, c = 'a', C= 'A'; i < 52; inv = !inv, cont++, i++)
    if (inv) { map[cont] = C; C++; }
    else { map[cont] = c; c++; }
}

int mapeia(char c) {
  if (c >= 'A' && c <= 'Z') return ((c - 'A') * 2);
  return (((c - 'a') * 2) + 1);
}

void mapeia_str(char str[], vi &str_cod) {
  int i, tam = strlen(str);
  for (i = 0; i < tam; i++) str_cod[i] = mapeia(str[i]);
}

void gera_comb(vi str, int l, int r, set<vi>&codes) {
  int i;
  if (codes.find(str) != codes.end() || l > r) return;
  if (l == r)
    codes.insert(str);
  else {
    for (i = l; i <= r; i++) {
      swap((str[l]), (str[i]));
      gera_comb(str, l + 1, r, codes);
      swap((str[l]), (str[i]));
    }}}

int main(void) {
  int casos, i, tam, aux;
  char str[MAX];
  monta_map();
  scanf("%d ", &casos);
  while (casos--) {
    set<vi>codes;
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0'; tam = strlen(str);
    vi str_cod(tam);
    mapeia_str(str, str_cod);
    gera_comb(str_cod, 0, tam - 1, codes);
    for (set<vi>::iterator it = codes.begin(); it != codes.end(); ++it) {
      for (i = 0; i < tam; i++) { aux = (*it)[i]; printf("%c", map[aux]); }
      printf("\n");
    }}
  return 0;
}
