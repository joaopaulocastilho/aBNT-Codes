#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 112

typedef struct { int id, solved, total_time; }con;

int for_num(int &i, char linha[]) {
  int mul = 1, ret = 0;
  for ( ; linha[i] != ' '; i++) {
    ret *= mul;
    ret += linha[i] - '0';
    mul = 10;
  }
  i++;
  return ret;
}

bool comp(con i, con j) {
  if (i.solved == j.solved && i.total_time == j.total_time)
    return i.id < j.id;
  if (i.solved == j.solved) return i.total_time < j.total_time;
  return i.solved > j.solved;
}

int main(void) {
  int i, tests, n_sub[MAX][11], c, p, t, f_sub[MAX], first = 1;
  int f_cor[MAX][11];
  char linha[MAX], op;
  scanf("%d ", &tests);
  while (tests--) {
    if (first) first = 0;
    else printf("\n");
    memset(n_sub, 0, sizeof(n_sub));
    memset(f_cor, 0, sizeof(f_cor));
    memset(f_sub, 0, sizeof(f_sub));
    vector<con>v(MAX);
    for (i = 0; i < MAX; i++)
      { v[i].id = v[i].solved = v[i].total_time = 0; }
    while (fgets(linha, MAX, stdin)) {
      if (linha[0] == '\n') break;
      linha[strlen(linha) - 1] = '\0';
      c = for_num(i = 0, linha);
      p = for_num(i, linha);
      t = for_num(i, linha);
      op = linha[i];
      f_sub[c] = 1;
      v[c].id = c;
      if (op == 'I') n_sub[c][p]++;
      else if (op == 'C') {
        if (f_cor[c][p]) continue;
        f_cor[c][p] = 1;
        v[c].solved++;
        v[c].total_time += t + n_sub[c][p] * 20;
      }
    }
    sort(v.begin(), v.end(), comp);
    for (i = 0; i < MAX; i++) {
      if (f_sub[v[i].id])
        printf("%d %d %d\n", v[i].id, v[i].solved, v[i].total_time);
    }
  }
  return 0;
}
