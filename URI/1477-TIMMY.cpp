#include <cstdio>
#include <utility>
#include <cstring>

#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1
#define MAX 112345 

using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > ppii;

ppii st[4*MAX];
int lazy[4*MAX];

void build(int p, int l, int r){
  if(l == r){
    st[p].first = 1;
    st[p].second.first = 0;
    st[p].second.second = 0;
    return;
  }
  build(left(p), l, (l+r)/2);
  build(right(p), (l+r)/2 + 1, r);
  st[p].first = st[left(p)].first + st[right(p)].first;
  st[p].second.first = st[left(p)].second.first + st[right(p)].second.first;
  st[p].second.second = st[left(p)].second.second + st[right(p)].second.second;
}
 0

ppii rmq(int p, int l, int r, int i, int j){
  ppii p1, p2, armq;
  int temp;
  if(i > r || j < l){ //Fora do intervalo;
    armq.first = -1;
    armq.second.first = -1;
    armq.second.second = -1;
    return armq;
  }
  if(lazy[p] != 0){ // Se tem que atualizar alguma coisa, atualiza agora.
    lazy[p] = lazy[p] % 3;
    if(l != r){
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    while(lazy[p]){
      temp = st[p].first;
      st[p].first = st[p].second.second;
      st[p].second.second = st[p].second.first;
      st[p].second.first = temp; 
      lazy[p]--;
    }
  }
  if(l >= i && r <= j){ // Tá dentro do intervalo.
    armq.first = st[p].first;
    armq.second.first = st[p].second.first;
    armq.second.second = st[p].second.second;
    return armq;
  }
  p1 = rmq(left(p), l, (l+r)/2, i, j);
  p2 = rmq(right(p), (l+r)/2 + 1, r, i, j);
  if(p1.first == -1) return p2;
  if(p2.first == -1) return p1;
  armq.first = p1.first + p2.first;
  armq.second.first = p1.second.first + p2.second.first;
  armq.second.second = p1.second.second + p2.second.second;
  return armq;
}

void update(int p, int l, int r, int i, int j){
  int temp;
  if(lazy[p] != 0){ // Se tem que atualizar uma ou mais vezes...
    lazy[p] = lazy[p] % 3;
    if(l != r){
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    while(lazy[p]){ // Enquanto tem que trocar
      temp = st[p].first;
      st[p].first = st[p].second.second;
      st[p].second.second = st[p].second.first;
      st[p].second.first = temp;
      lazy[p]--;
    }
  }
  if(i > r || j < l) return; // Fora do espaco;
  if(l >= i && r <= j){ // Ta totalmente dentro.
    temp = st[p].first;
    st[p].first = st[p].second.second;
    st[p].second.second = st[p].second.first;
    st[p].second.first = temp;

    if(l != r){
      lazy[left(p)] += 1;
      lazy[right(p)] += 1;
    }
    return;
  }
  update(left(p), l, (l+r)/2, i, j);
  update(right(p), (l+r)/2 + 1, r, i, j);
  st[p].first = st[left(p)].first + st[right(p)].first;
  st[p].second.first = st[left(p)].second.first + st[right(p)].second.first;
  st[p].second.second = st[left(p)].second.second + st[right(p)].second.second;
}

int main(void){
  int a, b, m, n;
  char o;
  ppii armq;
  while(scanf("%d %d", &n, &m) != EOF){
    memset(lazy, 0, sizeof(lazy));
    build(1, 0, n-1);
    while(m--){
      scanf(" %c %d %d", &o, &a, &b);
      if(o == 'C'){
	armq = rmq(1, 0, n-1, --a,--b);
	printf("%d %d %d\n", armq.first, armq.second.first, armq.second.second);
      }
      else {
	a--; b--;
	update(1, 0, n-1, a, b);
      }
    }
    printf("\n");
  }
  return 0;
}
