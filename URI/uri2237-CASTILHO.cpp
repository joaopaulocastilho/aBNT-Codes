#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 40321
#define INF 1123456789

typedef pair<int, int>ii;
typedef pair<int, string>pis;
typedef pair<int, pis>ipis;
typedef vector<ipis>vipis;

int cs[10], ct[10];
int cvert = 0;
int trocas[10][2] = { {0, 1}, {0, 4}, {1, 2}, {1, 5}, {2, 3}, {2, 6},
                      {3, 7}, {4, 5}, {5, 6}, {6, 7} };
map<string, pis> vertices;

void int_str(int n, char str[], int &pos) {
  int ntmp = n, first = 1, tmp;
  while (ntmp) {
    ntmp /= 10;
    if (first) first = 0;
    else pos++;
  }
  tmp = pos;
  while (n) {
    ntmp = n % 10;
    n /= 10;
    str[pos--] = '0' + ntmp;
  }
  pos = tmp + 1;
}

void nome_vert(int v[], char vert_str[], int &cont_vert_str) {
  int first, i;
  cont_vert_str = 0;
  for (first = 1, i = 0; i < 8; i++) {
    if (first) first = 0;
    else vert_str[cont_vert_str++] = '-';
    int_str(v[i], vert_str, cont_vert_str);
  }
  vert_str[cont_vert_str] = 0;
}

int monta_adj(int i, string atual, char n[]) {
  int coc[10], natual = 0; //Configuração do Container
  int contaux = 0, tamanho_nova;
  char tmp;
  for (string::iterator it = atual.begin(); it != atual.end(); ++it) {
    tmp = *it;
    if (tmp != '-') {
      natual *= 10;
      natual += tmp - '0';
    } else {
      coc[contaux++] = natual;
      natual = 0;
    }
  }
  coc[contaux++] = natual;
  swap(coc[trocas[i][0]], coc[trocas[i][1]]);
  nome_vert(coc, n, tamanho_nova);
  return coc[trocas[i][0]] + coc[trocas[i][1]];
}

int dijkstra(char s[], char t[]) {
  int dist[MAX], i, vis[MAX], u, v, peso;
  char str[112];
  for (i = 0; i < MAX; i++) dist[i] = INF;
  dist[vertices[string(s)].first] = 0;
  memset(vis, 0, sizeof(vis));
  priority_queue < ipis, vipis, greater<ipis> >PQ;
  pis z = pis(vertices[string(s)]);
  PQ.push(ipis(0, pis(z)));
  while (!PQ.empty()) {
    u = PQ.top().second.first;
    string aux = PQ.top().second.second;
    PQ.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (i = 0; i < 10; i++) {
      peso = monta_adj(i, aux, str);
      if (vertices.find(string(str)) == vertices.end()) {
        v = cvert;
        vertices[string(str)] = pis(cvert++, string(str));
      } else v = vertices[string(str)].first;
      if (!vis[v] && dist[v] > dist[u] + peso) {
        dist[v] = dist[u] + peso;
        PQ.push(ipis(dist[u] + peso, pis(v, string(str))));
      }}}
  return dist[vertices[string(t)].first];
}


int main(void) {
  int i, conts, contt;
  char s[112], t[112];
  for (i = 0; i < 8; i++) scanf("%d", &cs[i]);
  for (i = 0; i < 8; i++) scanf("%d", &ct[i]);
  nome_vert(cs, s, conts);
  nome_vert(ct, t, contt);
  vertices[string(s)] = pis(cvert++, string(s));
  vertices[string(t)] = pis(cvert++, string(t));
  printf("%d\n", dijkstra(s, t));
  return 0;
}
