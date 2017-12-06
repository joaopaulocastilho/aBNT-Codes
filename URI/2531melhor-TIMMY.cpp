#include <cstdio>
#include <cstdlib>
#include <utility>

#define MAX 112345
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1
#define pii pair< int, int >

using namespace std;

pii st[4*MAX];

int a[MAX], n;

void build(int p, int l, int r){
  int p1, p2;

  if(l == r){ st[p].first = st[p].second = l; return; }
  build(left(p), l, (l+r)/2);
  build(right(p), (l+r)/2 + 1, r);
  p1 = st[left(p)].first; p2 = st[right(p)].first;
  st[p].first = (a[p1] <= a[p2] ? p1 : p2);
  p1 = st[left(p)].second; p2 = st[right(p)].second;
  st[p].second = (a[p1] >= a[p2] ? p1 : p2);
}

pii rmq(int p, int l, int r, int i, int j){
  pii p1, p2, armq;
  if(i > r || j < l){
    armq.first = armq.second = -1;
    return armq; //Esse segmento não está no intervalo necessario
  }
  if(l >= i && r <= j){ //Esse segmento esta inteiro na query
    armq.first = st[p].first;
    armq.second = st[p].second;
    return armq;
  }
  p1 = rmq(left(p), l, (l+r)/2, i, j);
  p2 = rmq(right(p), (l+r)/2 + 1, r, i, j);
  if(p1.first == -1) return p2;
  if(p2.first == -1) return p1;
  armq.first = a[p1.first] <= a[p2.first] ? p1.first : p2.first;
  armq.second = a[p1.second] >= a[p2.second] ? p1.second : p2.second;
  return armq;
}

void update(int p, int l, int r, int i){
  if(i > r || i < l) return; //Fora do escopo.
  if(l == i && r == i){ //Eh a folha que eu quero;
    for(int j = p >> 1; j >= 1; j = j >> 1){ // Sobe ate a raiz atualizando rmq.
      int p1 = st[left(j)].first, p2 = st[right(j)].first;
      st[j].first = (a[p1] <= a[p2] ? p1 : p2);
      p1 = st[left(j)].second; p2 = st[right(j)].second;
      st[j].second = (a[p1] >= a[p2] ? p1 : p2);
    }
    return;
  }
  update(left(p), l, (l+r)/2, i);
  update(right(p), (l+r)/2 + 1, r, i);
}

int main(void){
  int n, r, s, t, q;
  pii armq;
  
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    build(1, 0, n-1);
    scanf("%d", &q);
    while(q--){
      scanf("%d %d %d", &r, &s, &t);
      if(r == 1){
	a[--s] = t;
	update(1, 0, n-1, s);
      }
      else{
	armq = rmq(1, 0, n-1, --s, --t);
	printf("%d\n", abs(a[armq.first] - a[armq.second]));
      }
    }
  }
  return 0;
}
