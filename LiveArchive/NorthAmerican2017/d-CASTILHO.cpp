#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112345;

int pega_num(int &i, char s[]) {
  int ret, mul = 10;
  for (ret = 0; s[i] != ' ' && s[i] != '\0'; i++) {
    ret *= mul;
    ret += s[i] - '0';
  }
  return ret;
}

int main(void) {
  int n, k, i, ans, qtd, tam, fmul;
  char com[MAXV];
  while (scanf("%d %d ", &n, &k) != EOF) {
    vector<int>op;
    fgets(com, MAXV, stdin); com[tam = strlen(com) - 1] = '\0';
    for (i = 0; i < tam; i++) {
      if (com[i] == ' ') continue;
      if (com[i] == 'u') {
        i += 5;
        qtd = pega_num(i, com);
        while (qtd--) op.erase(op.begin() + (op.size() - 1));
        continue;
      }
      if (com[i] == '-') { fmul = -1; i++; }
      else fmul = 1;
      qtd = pega_num(i, com) * fmul;
      op.push_back(qtd);
    }
    for (ans = i = 0; i < (int)op.size(); i++) {
      ans = (((ans + op[i]) % n) + n) % n;
    }
    printf("%d\n", ans);
  }
  return 0;
}
