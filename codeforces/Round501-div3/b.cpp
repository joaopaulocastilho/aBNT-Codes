#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

vector<int>ans;

void troca(char s[], int ini, int fim) {
  int i;
  for (i = ini; i < fim; i++) {
    swap(s[i], s[i + 1]);
    ans.push_back(i);
  }
}

int main(void) {
  int n, flag, i, j, qtds[31], qtdt[31];
  char s[MAXV], t[MAXV];
  scanf("%d", &n);
  scanf(" %s %s", s, t);
  memset(qtds, 0, sizeof(qtds));
  memset(qtdt, 0, sizeof(qtdt));
  for (i = 0; i < n; i++) {
    qtds[s[i] - 'a']++;
    qtdt[t[i] - 'a']++;
  }
  for (flag = 1, i = 0; i < 30; i++) flag &= (qtds[i] == qtdt[i]);
  if (!flag) { printf("-1\n"); return 0; }
  for (i = n - 1; i; i--) {
    if (s[i] == t[i]) continue;
    for (j = i - 1; j >= 0; j--) if (t[i] == s[j]) break;
    troca(s, j, i);
    if (strcmp(s, t) == 0) break;
  }
  printf("%d\n", (int)ans.size());
  for (i = 0; i < (int)ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i] + 1);
  }
  printf("\n");
  return 0;
}
