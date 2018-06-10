#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
  int n, i, j, tmp, maior, resp;
  while (scanf("%d", &n), n) {
    vector<vector<int>>v(n);
    map<vector<int>, int>qtd;
    for (resp = i = 0; i < n; i++) {
      for (j = 0; j < 5; j++) { scanf("%d", &tmp); v[i].push_back(tmp); }
      sort(v[i].begin(), v[i].end());
      qtd[v[i]]++;
    }
    maior = 0;
    for (map<vector<int>, int>::iterator it = qtd.begin(); it != qtd.end(); ++it)
      maior = max(maior, it->second);
    for (map<vector<int>, int>::iterator it = qtd.begin(); it != qtd.end(); ++it)
      if (it->second == maior) resp += maior;
    printf("%d\n", resp);
  }
  return 0;
}
