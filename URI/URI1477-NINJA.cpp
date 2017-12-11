#include <stdio.h>
#include <string.h>

#define MAX 112345
#define left(x) 2 * (x)
#define right(x) 2 * (x) + 1

typedef struct{int h, e, r;} player_t;

player_t st[4*MAX], zero;
int lazy[4*MAX];

void build(int node, int l, int r);
player_t query(int node, int l, int r, int i, int j);
void update(int node, int l, int r, int i, int j);

int main(void){
  int n, m, i, j;
  char op;
  player_t ans;

  zero.h = zero.e = zero.r;
  while(scanf("%d %d", &n, &m) != EOF){
    memset(lazy, 0, sizeof(lazy));
    build(1, 0, n-1);
    //for(int i = 1; i <= 9; i++) printf("(H:%d,E:%d,R:%d) ", st[i].h, st[i].r, st[i].e ); printf("\n");
    while(m--){
      scanf(" %c %d %d", &op, &i, &j); i--; j--;
      if(op == 'C'){
        ans = query(1, 0, n-1, i, j);
        printf("%d %d %d\n", ans.h, ans.e, ans.r);
      }
      else{
        update(1, 0, n-1, i, j);
        //for(int i = 1; i <= 9; i++) printf("(H:%d,E:%d,R:%d) ", st[i].h, st[i].e, st[i].r); printf("\n");
      }
    }
    printf("\n");
  }

  return 0;
}

void build(int node, int l, int r){
  player_t p1, p2;
  if(l == r){
    st[node].h = 1;
    st[node].e = st[node].r = 0;
    return;
  }
  build(left(node), l, (l+r)/2);
  build(right(node), (l+r)/2 + 1, r);
  p1 = st[left(node)]; p2 = st[right(node)];
  st[node].h = p1.h + p2.h;
  st[node].e = st[node].r = 0;
}

player_t query(int node, int l, int r, int i, int j){
  player_t ans;
  int mid = (l+r)/2;
  if(lazy[node]){
    if(l != r){
      lazy[left(node)] += lazy[node];
      lazy[right(node)] += lazy[node];
    }
    int qtd = lazy[node] % 3;
    while(qtd--){
      int tmp = st[node].r;
      st[node].r = st[node].e;
      st[node].e = st[node].h;
      st[node].h = tmp;
    }
    lazy[node] = 0;
  }
  if(l > r || l > j || i > r) return zero;
  if(i <= l && r <= j) return st[node];
  player_t leftsum = query(left(node), l, mid, i, j);
  player_t rightsum = query(right(node), mid+1, r, i, j);
  ans.h = leftsum.h + rightsum.h;
  ans.e = leftsum.e + rightsum.e;
  ans.r = leftsum.r + rightsum.r;
  return ans;
}

void update(int node, int l, int r, int i, int j){
  int mid = (l+r)/2;
  int copia[9];
  if(lazy[node]){
    if(l != r){
      lazy[left(node)] += lazy[node];
      lazy[right(node)] += lazy[node];
    }
    int qtd = lazy[node] % 3;
    while(qtd--){
      int tmp = st[node].r;
      st[node].r = st[node].e;
      st[node].e = st[node].h;
      st[node].h = tmp;
    }
    lazy[node] = 0;
  }
  if(l > r || l > j || i > r) return;
  if(i <= l && r <= j){
    int tmp = st[node].r;
    st[node].r = st[node].e;
    st[node].e = st[node].h;
    st[node].h = tmp;
    if(l != r){
      lazy[right(node)]++;
      lazy[left(node)]++;
    }
  }
  else{
    update(left(node), l, mid, i, j);
    update(right(node), mid+1, r, i, j);
    st[node].h = st[left(node)].h + st[right(node)].h;
    st[node].e = st[left(node)].e + st[right(node)].e;
    st[node].r = st[left(node)].r + st[right(node)].r;
  }
}
