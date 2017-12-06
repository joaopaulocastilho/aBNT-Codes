#include <cstdio>
#include <cstring>
#include <utility>

#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1
#define MAX 112345

using namespace std;

typedef pair< int, int > pii;

int neto[MAX], lazy[4*MAX];
pii st[4*MAX];

void build(int p, int l, int r){
  if(l == r){
    st[p].first = neto[l];
    st[p].second = l;
    return;
  }
  build(left(p), l, (l+r)/2);
  build(right(p), (l+r)/2 + 1, r);
  st[p] = st[left(p)].first > st[right(p)].first ? st[left(p)] :
    (st[left(p)].first == st[right(p)].first && st[left(p)].second < st[right(p)].second ? st[left(p)] : st[right(p)]);
}

pii rmq(int p, int l, int r, int i, int j){
  pii p1, p2, temp;
  if(i > r || j < l){ temp.first = temp.second = -1; return temp; } // Fora do intervalo
  if(lazy[p] != 0){ // Se tem que atualizar, atualiza.
    st[p].first += lazy[p];
    if(l != r){
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
  if(l >= i && r <= j) return st[p]; // Tá dentro do intervalo
  p1 = rmq(left(p), l, (l+r)/2, i, j);
  p2 = rmq(right(p), (l+r)/2 + 1, r, i, j);  
  if(p1.first == -1) return p2;
  if(p2.first == -1) return p1;
  if(p1.first > p2.first) return p1;
  if(p1.first == p2.first && p1.second < p2.second) return p1;
  return p2;
}

void update(int p, int l, int r, int i, int j, int v){
  if(lazy[p] != 0){ // Se tem que atualizar;
    st[p].first += lazy[p];
    if(l != r){
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
  if(i > r || j < l) return; // Fora do espaço;
  if(l >= i && r <=j){ // tá totalmente dentro
    st[p].first += v;
    if(l != r){
      lazy[left(p)] += v;
      lazy[right(p)] += v;
    }
    return;
  }
  update(left(p), l, (l+r)/2, i, j, v);
  update(right(p), (l+r)/2 + 1, r, i, j, v);
  st[p] = st[left(p)].first > st[right(p)].first ? st[left(p)] :
    (st[left(p)].first == st[right(p)].first && st[left(p)].second < st[right(p)].second ? st[left(p)] : st[right(p)]);
}

int main(void){
  int a, b, v, n, q;
  char c;
  pii ans;
  
  while(scanf("%d %d", &n, &q) != EOF){
    memset(lazy, 0, sizeof(lazy));
    for(int i = 0; i < n; i++) scanf("%d", &neto[i]);
    build(1, 0, n-1);
    while(q--){
      scanf(" %c", &c);
      if(c == 'C'){
	scanf("%d %d", &a, &b);
	ans = rmq(1, 0, n-1, --a, --b);
	printf("%d\n", ans.second+1);
      }
      else{
	scanf("%d %d %d", &a, &b, &v);
	update(1, 0, n-1, --a, --b, v);
      }
    }
  }
  return 0;
}
