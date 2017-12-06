#include <cstdio>
#include <cstring>
#include <utility>

#define MAX 1123456
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1

using namespace std;

typedef pair< int, int > pii;

pii st[4*MAX];
int lazy[4*MAX];
char ans[MAX];

void build(int p, int l, int r){
  if(l == r){
    st[p].first = (ans[l] == '1' ? 1 : 0);
    st[p].second = (ans[l] == '0' ? 1 : 0);
    return;
  }
  build(left(p), l, (l+r)/2);
  build(right(p), (l+r)/2 + 1, r);
  st[p].first = st[left(p)].first + st[right(p)].first;
  st[p].second = st[left(p)].second + st[right(p)].second;
}

pii rmq(int p, int l, int r, int i, int j){
  pii p1, p2, armq;
  int temp;
  
  if(lazy[p] != 0){ // Atualizar
    if(lazy[p] == 1){
      st[p].first += st[p].second;
      st[p].second = 0;
    }
    else if(lazy[p] == 2){
      st[p].second += st[p].first;
      st[p].first = 0;
    }
    else if(lazy[p] == 3){
      temp = st[p].first;
      st[p].first = st[p].second;
      st[p].second = temp;
    }
    if(l != r){
      // testa o lado esquerdo
      if(lazy[p] == 1) lazy[left(p)] = 1;
      else if(lazy[p] == 2) lazy[left(p)] = 2;
      else if(lazy[p] == 3 && lazy[left(p)] == 1) lazy[left(p)] = 2;
      else if(lazy[p] == 3 && lazy[left(p)] == 2) lazy[left(p)] = 1;
      else if(lazy[p] == 3 && lazy[left(p)] == 3) lazy[left(p)] = 0;
      else if(lazy[p] == 3 && lazy[left(p)] == 0) lazy[left(p)] = 3;
      // testa o lado direito
      if(lazy[p] == 1) lazy[right(p)] = 1;
      else if(lazy[p] == 2) lazy[right(p)] = 2;
      else if(lazy[p] == 3 && lazy[right(p)] == 1) lazy[right(p)] = 2;
      else if(lazy[p] == 3 && lazy[right(p)] == 2) lazy[right(p)] = 1;
      else if(lazy[p] == 3 && lazy[right(p)] == 3) lazy[right(p)] = 0;
      else if(lazy[p] == 3 && lazy[right(p)] == 0) lazy[right(p)] = 3;
    }
    lazy[p] = 0;
  }
  if(i > r || j < l){ // Fora do intervalo;
    armq.first = armq.second = -1;
    return armq;
  }
  if(l >= i && r <= j) return st[p];  // Tá dentro do intervalo.
  p1 = rmq(left(p), l, (l+r)/2, i, j);
  p2 = rmq(right(p), (l+r)/2 + 1, r, i, j);
  if(p1.first == -1) return p2;
  if(p2.first == -1) return p1;
  armq.first = p1.first + p2.first;
  armq.second = p1.second + p2.second;
  return armq;
}

void update(int p, int l, int r, int i, int j, int op){
  pii armq;
  int temp;
  
  if(lazy[p] != 0){ // Atualizar
    if(lazy[p] == 1){
      st[p].first += st[p].second;
      st[p].second = 0;
    }
    else if(lazy[p] == 2){
      st[p].second += st[p].first;
      st[p].first = 0;
    }
    else if(lazy[p] == 3){
      temp = st[p].first;
      st[p].first = st[p].second;
      st[p].second = temp;
    }
    if(l != r){
      // testa o lado esquerdo
      if(lazy[p] == 1) lazy[left(p)] = 1;
      else if(lazy[p] == 2) lazy[left(p)] = 2;
      else if(lazy[p] == 3 && lazy[left(p)] == 1) lazy[left(p)] = 2;
      else if(lazy[p] == 3 && lazy[left(p)] == 2) lazy[left(p)] = 1;
      else if(lazy[p] == 3 && lazy[left(p)] == 3) lazy[left(p)] = 0;
      else if(lazy[p] == 3 && lazy[left(p)] == 0) lazy[left(p)] = 3;
      // testa o lado direito
      if(lazy[p] == 1) lazy[right(p)] = 1;
      else if(lazy[p] == 2) lazy[right(p)] = 2;
      else if(lazy[p] == 3 && lazy[right(p)] == 1) lazy[right(p)] = 2;
      else if(lazy[p] == 3 && lazy[right(p)] == 2) lazy[right(p)] = 1;
      else if(lazy[p] == 3 && lazy[right(p)] == 3) lazy[right(p)] = 0;
      else if(lazy[p] == 3 && lazy[right(p)] == 0) lazy[right(p)] = 3;
    }
    lazy[p] = 0;
  }
  if(i > r || j < l) return;
  if(l >= i && r <= j){
    if(op == 1){
      st[p].first += st[p].second;
      st[p].second = 0;
    }
    if(op == 2){
      st[p].second += st[p].first;
      st[p].first = 0;
    }
    if(op == 3){
      temp = st[p].first;
      st[p].first = st[p].second;
      st[p].second = temp;
    }
    if(l != r){
      // testa o lado esquerdo
      if(op == 1) lazy[left(p)] = 1;
      else if(op == 2) lazy[left(p)] = 2;
      else if(op == 3 && lazy[left(p)] == 1) lazy[left(p)] = 2;
      else if(op == 3 && lazy[left(p)] == 2) lazy[left(p)] = 1;
      else if(op == 3 && lazy[left(p)] == 3) lazy[left(p)] = 0;
      else if(op == 3 && lazy[left(p)] == 0) lazy[left(p)] = 3;
      // testa o lado direito
      if(op == 1) lazy[right(p)] = 1;
      else if(op == 2) lazy[right(p)] = 2;
      else if(op == 3 && lazy[right(p)] == 1) lazy[right(p)] = 2;
      else if(op == 3 && lazy[right(p)] == 2) lazy[right(p)] = 1;
      else if(op == 3 && lazy[right(p)] == 3) lazy[right(p)] = 0;
      else if(op == 3 && lazy[right(p)] == 0) lazy[right(p)] = 3; 
    }
    return;
  }
  update(left(p), l, (l+r)/2, i, j, op);
  update(right(p), (l+r)/2 + 1, r, i, j, op);
  st[p].first = st[left(p)].first + st[right(p)].first;
  st[p].second = st[left(p)].second + st[right(p)].second;
}

int main(void){
  int t,m,a, caso = 1, n, q, i, j, o;
  char s[51], c;
  pii armq;
  scanf("%d", &t);
  while(t--){
    n = 1;
    o = 0;
    printf("Case %d:\n", caso);
    memset(lazy, 0, sizeof(lazy));
    scanf("%d", &m);
    while(m--){
      scanf("%d", &a);
      scanf(" %s", s);
      while(a--)
	for(int k = 0; s[k] != '\0'; k++)
	  ans[o++] = s[k];
    }
    build(1, 0, o-1);
    scanf("%d", &q);
    while(q--){
      scanf(" %c %d %d", &c, &i, &j);
      if(c == 'F') update(1, 0, o-1, i, j, 1);
      else if(c == 'E') update(1, 0, o-1, i, j, 2);
      else if(c == 'I') update(1, 0, o-1, i, j, 3);
      else{
	armq = rmq(1, 0, o-1, i, j);
	printf("Q%d: %d\n", n++, armq.first);
      } 
    }
    caso++;
  }
  return 0;
}
