#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define MAX 1123
#define MAXN 112
#define REP 1123

int main(void) {
  int n, i, m, rec, n_ing, ti, nt, id_ing, gar, qtd = 0;
  char ing[MAXN], ing_atual[MAXN];
  int receitas[MAX][MAX], receita_id[MAX];
  scanf("%d", &n);
  map<string, int>ingrediente;
  map<int, int>tipo;
  vector<string>nomes;
  for (i = 0; i < n; i++) {
    scanf("%s", ing);
    if (ingrediente.find(string(ing)) == ingrediente.end()) {
      ingrediente[string(ing)] = qtd++;
      tipo[ingrediente[string(ing)]] = 1;
      nomes.push_back(string(ing));
    }}
  scanf("%d ", &m);
  for (rec = 0; rec < m; rec++) {
    scanf("%s %d ", ing, &n_ing);
    receitas[rec][0] = n_ing;
    for (ti = nt = i = 0; i < n_ing; i++) {
      scanf("%s ", ing_atual);
      if (ingrediente.find(string(ing_atual)) == ingrediente.end()) {
        ingrediente[string(ing_atual)] = qtd++;
        tipo[ingrediente[string(ing_atual)]] = 0;
        nomes.push_back(string(ing_atual));
      }
      if (tipo[ingrediente[string(ing_atual)]] == 1) ti++;
      else nt++;
      receitas[rec][i + 1] = ingrediente[string(ing_atual)];
    }
    if (ingrediente.find(string(ing)) == ingrediente.end()) {
      ingrediente[string(ing)] = qtd++;
      nomes.push_back(string(ing));
    }
    receita_id[rec] = ingrediente[string(ing)];
    tipo[ingrediente[string(ing)]] = (ti > nt);
  }
  for (gar = 0; gar < REP; gar++) {
    for (rec = 0; rec < m; rec++) {
      for (ti = nt = i = 0; i < receitas[rec][0]; i++) {
        id_ing = receitas[rec][i + 1];
        if (tipo[id_ing] == 1) ti++;
        else nt++;
      }
      tipo[receita_id[rec]] = (ti > nt);
    }
  }
  for (i = 0; i < m; i++)
    printf("porcao %s\n", (tipo[receita_id[i]] == 1) ? "tipica" : "comum");
  return 0;
}
