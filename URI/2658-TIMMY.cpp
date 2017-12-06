#include <cstdio>
#include <cstring>

#define MAX 112345
#define left(p) (p) << 1
#define right(p) ((p) << 1) + 1

int st[4*MAX][9], notas[MAX], lazy[4*MAX];

void build(int p, int l, int r){
  if(l == r){
    st[p][1] = 1;
    st[p][0] = 0;
    notas[l] = 1;
    for(int i = 2; i < 9; i++) st[p][i] = 0;
    return;
  }
  build(left(p), l, (l+r)/2);
  build(right(p), (l+r)/2 + 1, r);
  for(int i = 0; i < 9; i++) st[p][i] = st[left(p)][i] + st[right(p)][i];
}

void update(int p, int l, int r, int i, int j){
  int aux[9];
  if(lazy[p]){
    for(int k = 0; k < 9; k++) aux[k] = st[p][k];
    for(int k = 0; k < 9; k++){
      st[p][k] = aux[(k-lazy[p]) % 9];
    }
    if(l != r){
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    else notas[l] = (notas[l] + lazy[p]) % 9;
    lazy[p] = 0;
  }
  if(i > r || j < l) return;
  if(l >= i && r <= j){
    int maior = -1, idx = 0;
    for(int k = 0; k < 9; k++){
      //printf("%d %d\n", st[p][k], idx);
      if(maior < st[p][k]){
	maior = st[p][k];
	idx = k;
      }
    }
    for(int k = 0; k < 9; k++) aux[k] = st[p][k];
    for(int k = 0; k < 9; k++) st[p][k] = aux[(k - idx) % 9];
    if(l != r){
      lazy[left(p)] += idx;
      lazy[right(p)] += idx;
    }
    if(l == r)
      notas[l]  = (notas[l] + idx) % 9;
    return;
  }
  update(left(p), l, (l+r)/2, i, j);
  update(right(p), (l+r)/2 + 1, r, i, j);
  for(int k = 0; k < 9; k++)
    st[p][k] = st[left(p)][k] + st[right(p)][k];  
}

int rmq(int p, int l, int r, int i, int j){
  int aux[9], p1, p2;
  if(lazy[p]){
    for(int k = 0; k < 9; k++) aux[k] = st[p][k];
    for(int k = 0; k < 9; k++){
      st[p][k] = aux[(k-lazy[p])%9];
    }
    if(l != r){
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    else notas[l] = (notas[l] + lazy[p]) % 9;
    lazy[p] = 0;
  }
  if(i > r || j < l) return -1;
  if(l >= i && r <= j){return notas[l]; }
  p1 = rmq(left(p), l, (l+r)/2, i, j);
  p2 = rmq(right(p), (l+r)/2+1, r, i, j);
  if(p1 == -1) return p2;
  if(p2 == -1) return p1;
}

int main(void){
  int n, q, a, b;
  scanf("%d %d", &n, &q);
  memset(lazy, 0, sizeof(lazy));
  build(1, 0, n-1);
  while(q--){
    scanf("%d %d", &a, &b);
    update(1, 0, n-1, a, b);
    for(int k = 0; k < n; k++) printf("%d\n", rmq(1, 0, n-1, k, k));
    printf("\n");
  }
  return 0;
}
